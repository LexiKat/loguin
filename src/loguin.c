#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

#include "loguin.h"

static size_t printc = 0;
static size_t warnc = 0;
static size_t fatalc = 0;

void loguin_printf(char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    fprintf(stderr, "\x1B[32m"
                    "INFO"
                    "\x1B[0m"
                    "[%04lu]"
                    " ",
            printc++);
    vfprintf(stderr, fmt, args);
    va_end(args);
}

void loguin_println(char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    fprintf(stderr, "\x1B[32m"
                    "INFO"
                    "\x1B[0m"
                    "[%04lu]"
                    " ",
            printc++);
    vfprintf(stderr, fmt, args);
    fprintf(stderr, "\n");
    va_end(args);
}

void loguin_warnf(char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    fprintf(stderr, "\x1B[33m"
                    "WARN"
                    "\x1B[0m"
                    "[%04lu]"
                    " ",
            warnc++);
    vfprintf(stderr, fmt, args);
    va_end(args);
}

void loguin_warnln(char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    fprintf(stderr, "\x1B[33m"
                    "WARN"
                    "\x1B[0m"
                    "[%04lu]"
                    " ",
            warnc++);
    vfprintf(stderr, fmt, args);
    fprintf(stderr, "\n");
    va_end(args);
}

void loguin_fatalf(char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    fprintf(stderr, "\x1B[31m"
                    "WARN"
                    "\x1B[0m"
                    "[%04lu]"
                    " ",
            fatalc++);
    vfprintf(stderr, fmt, args);
    va_end(args);
    exit(EXIT_FAILURE);
}

void loguin_fatalln(char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    fprintf(stderr, "\x1B[31m"
                    "WARN"
                    "\x1B[0m"
                    "[%04lu]"
                    " ",
            fatalc++);
    vfprintf(stderr, fmt, args);
    fprintf(stderr, "\n");
    va_end(args);
    exit(EXIT_FAILURE);
}

