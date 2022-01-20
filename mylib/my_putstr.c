#include <unistd.h>
#include "mylib.h"

void my_putstr(const char *str)
{

    while (*str != '\0')
    {
        my_putchar(*str);
        str++;
    }
}
