#ifdef __cplusplus
#include <cstdio>
#include <cstdarg>
#include <cstdlib>
#else
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#endif

#include "loguin.h"

static size_t printc = 0;
static size_t warnc = 0;
static size_t fatalc = 0;

int loguin_printf(const char *fmt, ...)
{
    int count;
    va_list args;
    va_start(args, fmt);
    count = fprintf(stderr, "\x1B[32m"
                    "INFO"
                    "\x1B[0m"
                    "[%04lu]"
                    " ",
            printc++);
    count += vfprintf(stderr, fmt, args);
    va_end(args);
    return count;
}

int loguin_println(const char *fmt, ...)
{
    int count;
    va_list args;
    va_start(args, fmt);
    count = fprintf(stderr, "\x1B[32m"
                    "INFO"
                    "\x1B[0m"
                    "[%04lu]"
                    " ",
            printc++);
    count += vfprintf(stderr, fmt, args);
    count += fprintf(stderr, "\n");
    va_end(args);
    return count;
}

int loguin_warnf(const char *fmt, ...)
{
    int count;
    va_list args;
    va_start(args, fmt);
    count = fprintf(stderr, "\x1B[33m"
                    "WARN"
                    "\x1B[0m"
                    "[%04lu]"
                    " ",
            warnc++);
    count += vfprintf(stderr, fmt, args);
    va_end(args);
    return count;
}

int loguin_warnln(const char *fmt, ...)
{
    int count;
    va_list args;
    va_start(args, fmt);
    count = fprintf(stderr, "\x1B[33m"
                    "WARN"
                    "\x1B[0m"
                    "[%04lu]"
                    " ",
            warnc++);
    count += vfprintf(stderr, fmt, args);
    count += fprintf(stderr, "\n");
    va_end(args);
    return count;
}

int loguin_fatalf(const char *fmt, ...)
{
    int count;
    va_list args;
    va_start(args, fmt);
    count = fprintf(stderr, "\x1B[31m"
                    "FATA"
                    "\x1B[0m"
                    "[%04lu]"
                    " ",
            fatalc++);
    count += vfprintf(stderr, fmt, args);
    va_end(args);
    exit(EXIT_FAILURE);
    return count;
}

int loguin_fatalln(const char *fmt, ...)
{
    int count;
    va_list args;
    va_start(args, fmt);
    count = fprintf(stderr, "\x1B[31m"
                    "FATA"
                    "\x1B[0m"
                    "[%04lu]"
                    " ",
            fatalc++);
    count += vfprintf(stderr, fmt, args);
    count += fprintf(stderr, "\n");
    va_end(args);
    exit(EXIT_FAILURE);
    return count;
}

