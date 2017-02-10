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
board_init(Board *b, const int size)
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
	int i, j, k;

	k = b->size - 1;

	for (i = 0; i < k; i++) {
		for (j = 0; j < k; j++) {
			color_uchar_print(b->grid[XY(i, j)]);
			printf("|");
		}
		color_uchar_print(b->grid[XY(i, j)]);
		printf("\n");
		for (j = 0; j < k; j++) {
			printf("--");
		}
		printf("-\n");
	}
	for (j = 0; j < k; j++) {
		color_uchar_print(b->grid[XY(i, j)]);
		printf("|");
	}
	color_uchar_print(b->grid[XY(i, j)]);
	printf("\n");
}

void
board_free(const Board *b)
{
	free(b->grid);
}
