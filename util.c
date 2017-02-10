#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include "util.h"


void
die(const char *fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	vfprintf(stderr, fmt, ap);
	putc('\n', stderr);
	va_end(ap);
	exit(EXIT_FAILURE);
}
