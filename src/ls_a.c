#include "mylib.h"
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>

char *ls_a(char *dir)
{

    struct dirent *dirp;
    DIR *dp = opendir(dir);
    if (!dp)
    {
        if (errno = ENOENT)
        {
            my_putstr("a.out: cannot access '");
            my_putstr(dir);
            my_putstr("': No such file or directory \n");
        }
        else
        {
            my_putstr("Unable to read directory");
        }
        return (0);
    }

    while ((dirp = readdir(dp)) != NULL)
    {

        my_putstr(dirp->d_name);
        my_putstr("\n");
    }
    my_putstr("\n");

    closedir(dp);

    return (0);
}
