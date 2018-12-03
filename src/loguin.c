#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

#include "loguin.h"

static size_t printc = 0;
static size_t warnc = 0;
static size_t fatalc = 0;

int loguin_printf(char *fmt, ...)
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

int loguin_println(char *fmt, ...)
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

int loguin_warnf(char *fmt, ...)
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

int loguin_warnln(char *fmt, ...)
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

int loguin_fatalf(char *fmt, ...)
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

int loguin_fatalln(char *fmt, ...)
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

