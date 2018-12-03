#include "loguin.h"
#include <stdio.h>

int main()
{
    loguin_printf("Hello %s i am %02d years", "Jorge", 9);
    fprintf(stderr, " old\n");
    loguin_println("Hello %s i am %f%% done with work!", "Bob Ross", 99.99);
    
    loguin_warnf("Hello %s i am %02d years", "Jorge", 9);
    fprintf(stderr, " old\n");
    loguin_warnln("Hello %s i am %f%% done with work!", "Bob Ross", 99.99);

    // loguin_fatalf("Goodbye!");
    loguin_fatalln("Goodbye!");

    return 0;
}
