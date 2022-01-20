#include "mylib.h"
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>

char *ls_d(char *dir, int argc, char **argv)
{


    DIR *dp = opendir(dir);
    if (!dp)
    {
        my_putstr("a.out: cannot access '");
        my_putstr(dir);
        my_putstr("': No such file or directory \n");
    }
    else
    {
        my_putstr(dir);
        my_putstr("\n"); 
    }
    
}
