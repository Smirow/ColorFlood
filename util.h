#ifdef _UTIL_H_
#error util.h is already included
#else
#define _UTIL_H_


#define true  1;
#define false 0;

typedef signed   char  bool;
typedef unsigned char  uchar;
typedef unsigned short ushort;
typedef unsigned int   uint;
typedef unsigned long  ulong;

void die(const char *fmt, ...);
void *xmalloc(const size_t size);
void *xrealloc(void *ptr, const size_t size);
int xatoi(const char *str);


#endif /* _UTIL_H_ */
