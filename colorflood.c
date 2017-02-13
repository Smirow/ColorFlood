#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#include "util.h"
#include "board.h"
#include "game.h"
#include "colorflood.h"


static const char *argv0;

void
usage(void)
{
	die("usage: %s [OPTION] < FILE\n"
	    "  -f <file>\n"
	    "  -s <size", argv0);
}

int
main(const int argc, const char *argv[])
{
	int fd;
	Board b;

	argv0 = argv[0];
	b.size = DEFAULT_SIZE;

	if (argc == 1) {
		board_stream_init(0, &b);
	} else if (argc == 2) {
		usage();
	} else if (argc == 3) {
		close(0);
		if ((argv[1][0] == '-') && (argv[1][2] == '\0')) {
			switch (argv[1][1]) {
			case 'f':
				if ((fd = open(argv[2], O_RDONLY, 0)) < 0) {
					die("%s: open: %s: no such file", argv0, argv[2]);
				}
				board_stream_init(fd, &b);
				close(fd);
				break;
			case 's':
				board_random_init(&b, xatoi(argv[2]));
				break;
			default:
				usage();
				break;
			}
		} else {
			usage();
		}
	} else {
		usage();
	}

	board_print(&b);
	board_free(&b);

	return (EXIT_SUCCESS);
}
