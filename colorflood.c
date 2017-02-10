#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#include "util.h"
#include "board.h"
#include "colorflood.h"


int
catoi(const char *s)
{
	int i;
	const int len = strlen(s);

	for (i = 0; i < len; i++) {
		if (!isdigit(s[i])) {
			die("%s: %s: not a valid number", __func__, s);
		}
	}

	return (atoi(s));
}

int
main(const int argc, const char *argv[])
{
	Board b;

	if (argc != 2) {
		die("usage: %s <board-size>", argv[0]);
	}

	board_init(&b, catoi(argv[1]));
	board_print(&b);
	board_free(&b);

	return (EXIT_SUCCESS);
}
