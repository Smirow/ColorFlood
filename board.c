#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "util.h"
#include "board.h"


#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN    "\033[1;36m"
#define RESET   "\033[0m"

static void
color_uchar_print(const uchar c)
{
	switch (c) {
	case R:
		printf(RED "R" RESET);
		break;
	case G:
		printf(GREEN "G" RESET);
		break;
	case Y:
		printf(YELLOW "Y" RESET);
		break;
	case B:
		printf(BLUE "B" RESET);
		break;
	case M:
		printf(MAGENTA "M" RESET);
		break;
	case C:
		printf(CYAN "C" RESET);
		break;
	default:
		die("%s: 0x%02x: unexpected color", __func__, c);
		break;
	}
}

void
board_stream_init(const int fd, Board *b)
{
	int i, j, x, y;
	char buffer[BOARD_BUFLEN];

	x = y = 0;

	b->size = -1;
	b->grid = (uchar *)xmalloc(MAX_BOARD_SIZE * sizeof(uchar));

#define CHECK_SQUARE_SIZE(z) \
do { \
	if (((b->size < 0) && ((z) >= MAX_BOARD_SIZE)) || \
	    ((b->size > 0) && ((z) >= b->size))) { \
		die("%s: not a square board", __func__); \
	} \
} while (0)

	do {
		j = read(fd, buffer, BOARD_BUFLEN);
		if (j < 0) {
			die("%s: read: stream error", __func__);
		} else {
			for (i = 0; i < j; i++) {
				switch (buffer[i]) {
				case 'R':
					CHECK_SQUARE_SIZE(x);
					b->grid[XY(x, y)] = R;
					x++;
					break;
				case 'G':
					CHECK_SQUARE_SIZE(x);
					b->grid[XY(x, y)] = G;
					x++;
					break;
				case 'Y':
					CHECK_SQUARE_SIZE(x);
					b->grid[XY(x, y)] = Y;
					x++;
					break;
				case 'B':
					CHECK_SQUARE_SIZE(x);
					b->grid[XY(x, y)] = B;
					x++;
					break;
				case 'M':
					CHECK_SQUARE_SIZE(x);
					b->grid[XY(x, y)] = M;
					x++;
					break;
				case 'C':
					CHECK_SQUARE_SIZE(x);
					b->grid[XY(x, y)] = C;
					x++;
					break;
				case '\r': /* TODO : portabilité Mac + Windows */
				case '\n':
					if (b->size < 0) {
						b->size = x;
						b->grid = (uchar *)xrealloc((x * x) * sizeof(uchar));
					}
					if ((x != b->size) || (b->size == 0)) {
						die("%s: not a square board", __func__);
					}
					CHECK_SQUARE_SIZE(y);
					x = 0;
					y++;
					break;
				case ' ':
					break;
				default:
					die("%s: 0x%02x: unexpected color", __func__, buffer[i]);
					break;
				}
			}
		}
	} while (j > 0);

	if (y != b->size) {
		die("%s: not a square board", __func__);
	}

}

void
board_random_init(Board *b, const int size)
{
	int i, len;

	if ((size < 2) || (size > MAX_BOARD_SIZE)) {
		die("%s: %d: size should be between 2 and %d",
		    __func__, size, MAX_BOARD_SIZE);
	}

	len = size * size;
	srand((uint)time(NULL) + (uint)getpid());

	b->size = size;
	b->grid = (uchar *)xmalloc(len * sizeof(uchar));

	for (i = 0; i < len; i++) {
		b->grid[i] = rand() % COLOR_NUMBER;
	}
}

void
board_print(const Board *b)
{
	int i, x, y;

	i = b->size - 1;

	for (y = 0; y < b->size; y++) {
		for (x = 0; x < i; x++) {
			color_uchar_print(b->grid[XY(x, y)]);
			printf(" ");
		}
		color_uchar_print(b->grid[XY(x, y)]);
		printf("\n");
	}
}

void
board_free(const Board *b)
{
	free(b->grid);
}
