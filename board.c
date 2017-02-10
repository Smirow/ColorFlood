#include <stdio.h>
#include <stdlib.h>

#include "board.h"


#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN    "\033[1;36m"
#define RESET   "\033[0m"

static void
color_uchar_print(uchar c)
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
		break;
	}
}

void
board_init(Board *b, int size)
{
	int i, len;

	len = size * size;

	b->size = size;
	b->grid = (uchar *)malloc(len * sizeof(uchar));

	for (i = 0; i < len; i++) {
		b->grid[i] = rand() % COLOR_NUMBER;
	}
}

void
board_print(Board *b)
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
board_free(Board *b)
{
	free(b->grid);
}
