#include "mylib.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include <getopt.h>
#include <ctype.h>
#include <stdbool.h>

bool firstcaract(char *s1, char *s2)
{
    if (s1[0] == s2[0])
    {
        return true;
    }
    else
    {
        return false;
    }
}

void namefolder(int argc, char **argv, int nb_opts, bool op_a, bool op_A, bool op_l, bool op_d, bool op_t,bool op_r)
{
    int i = 0;
    int nb_folder = 0;
    for (i = 1; i < argc; i++)
    {
        if (firstcaract(&argv[i][0], "-") == false)
        {
            nb_folder += 1;
        }
    }
    if (nb_folder > 0)
    {
        for (i = 1; i < argc; i++)
        {
            if (firstcaract(&argv[i][0], "-") == false)
            {
                if (nb_folder > 1 && !op_d)
                {
                    my_putstr(argv[i]);
                    my_putstr(" :\n");
                }
                if (op_a)
                {
                    ls_a(argv[i]);
                }
                if (op_A)
                {
                    ls_A(argv[i]);
                }
                if (op_l)
                {
                    ls_l(argv[i]);
                }
                if (op_t)
                {
                    ls_t(argv[i]);
                }
                if (op_r)
                {
                    ls_r(argv[i]);
                }
                if (op_d)
                {
                    ls_d(argv[i], argc, argv);
                }
                if (nb_opts == 0)
                {
                    ls_(argv[i]);
                }
            }
        }
    }
    else
    {
        if (op_a)
        {
            ls_a(".");
        }
        if (op_A)
        {
            ls_A(".");
        }
        if (op_d)
        {
            ls_d(".", argc, argv);
        }
        if (op_l)
        {
            ls_l(".");
        }
        if (op_r)
        {
            ls_r(".");
        }
        if (op_t)
        {
            ls_t(".");
        }
        if (nb_opts == 0)
        {
            ls_(".");
        }
    }
}
