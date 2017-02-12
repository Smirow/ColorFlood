#include <stdlib.h>

#include "util.h"
#include "board.h"
#include "game.h"
#include "colorflood.h"


int
main(const int argc, const char *argv[])
{
	Board b;/*

	if (argc != 2) {
		die("usage: %s <board-size>", argv[0]);
	}*/

	board_stream_init(0, &b);/*
	board_random_init(&b, xatoi(argv[1]));*/
	board_print(&b);
	board_free(&b);

	return (EXIT_SUCCESS);
}
