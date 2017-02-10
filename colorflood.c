#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "util.h"
#include "board.h"
#include "colorflood.h"


int
main(int argc, char *argv[])
{
	Board b;

	if (argc != 2) {
		die("usage: %s <board-size>", argv[0]);
	}

	srand((uint)time(NULL) + (uint)getpid());

	board_init(&b, atoi(argv[1]));
	board_print(&b);
	board_free(&b);

	return (EXIT_SUCCESS);
}
