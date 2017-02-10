#include <ctype.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void *
xmalloc(const size_t size)
{
	void *p = malloc(size);

	if (!p) {
		die("malloc: out of memory");
	}

	return (p);
}

int
xatoi(const char *s)
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
