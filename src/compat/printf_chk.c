#include <stdio.h>
#include <stdarg.h>
#include "atomic.h"

int __fprintf_chk(FILE *f, int flag, const char *fmt, ...)
{
	int ret;
	va_list ap;
	va_start(ap, fmt);
	ret = vfprintf(f, fmt, ap);
	va_end(ap);
	return ret;
}

int __printf_chk(int flag, const char *fmt, ...)
{
	int ret;
	va_list ap;
	va_start(ap, fmt);
	ret = vfprintf(stdout, fmt, ap);
	va_end(ap);
	return ret;
}

int __snprintf_chk(char *s, size_t n, int flag, size_t slen, const char *fmt, ...)
{
	int ret;
	va_list ap;
	if (n > slen) a_crash();
	ret = vsnprintf(s, slen, fmt, ap);
	va_end(ap);
	return ret;
}

int __sprintf_chk(char *s, int flag, size_t slen, const char *fmt, ...)
{
	int ret;
	va_list ap;
	if (slen == 0) a_crash();
	va_start(ap, fmt);
	ret = vsnprintf(s, slen, fmt, ap);
	va_end(ap);
	if (ret > slen) a_crash();
	return ret;
}

int __vfprintf_chk(FILE *f, int flag, const char *fmt, va_list ap)
{
	return vfprintf(f, fmt, ap);
}

int __vprintf_chk(int flag, const char *fmt, va_list ap)
{
	return vfprintf(stdout, fmt, ap);
}

int __vsnprintf_chk(char *s, size_t n, int flag, size_t slen, const char *fmt, va_list ap)
{
	if (n > slen) a_crash();
	return vsnprintf(s, n, fmt, ap);
}

int __vsprintf_chk(char *s, int flag, size_t slen, const char *fmt, va_list ap)
{
	int ret;
	if (slen == 0) a_crash();
	ret = vsnprintf(s, slen, fmt, ap);
	if (ret > slen) a_crash();
	return ret;
}
