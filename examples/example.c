#include "loguin.h"
#include <stdio.h>

int main()
{
    loguin_println("A waddle of penguins emerges from the ocean");
    loguin_warnln("The waddle's number increased tremendously!");
    loguin_printf("A giant penguin of size %lu appeared!\n", (size_t) 10 );
    loguin_println("Tremendously sized walrus enters the ocean.");
    loguin_fatalln("The ice breaks!");
    return 0;
}
