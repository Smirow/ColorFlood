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
	void *ptr = malloc(size);

	if (!ptr) {
		die("malloc: out of memory");
	}

	return (ptr);
}

void *
xrealloc(void *ptr, const size_t size)
{
	ptr = realloc(ptr, size);

	if (!ptr) {
		die("realloc: out of memory");
	}

	return (ptr);
}

int
xatoi(const char *str)
{
	int i;
	const int len = strlen(str);

	for (i = 0; i < len; i++) {
		if (!isdigit(str[i])) {
			die("%s: %s: not a valid number", __func__, str);
		}
	}

	return (atoi(str));
}
