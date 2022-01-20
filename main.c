#include "mylib.h"
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include <ctype.h>
#include <stdbool.h>

int main(int argc, char **argv)
{
    bool op_a = false;
    bool op_A = false;
    bool op_d = false;
    bool op_l = false;
    bool op_t = false;
    bool op_r = false;
    bool falseopt = false;
    int opt;
    int nb_opts = 0;

    while ((opt = getopt(argc, argv, "aAldrt")) != -1)
    {
        nb_opts += 1;
        switch (opt)
        {
        case 'a':
            if (op_a == false)
            {
                op_a = true;
                op_A = false;
            }
            break;
        case 'A':
            if (op_A == false)
            {
                op_A = true;
                op_a = false;
            }
            break;
        case 'l':
            if (op_l == false)
            {
                op_l = true;
            }
            break;
        case 'd':
            if (op_d == false)
            {
                op_d = true;
            }
            break;
        case 't':
            if (op_t == false)
            {
                op_t = true;
            }
            break;
        case 'r':
            if (op_r == false)
            {
                op_r = true;
            }
            break;
        default:
            falseopt = true;
            break;
        }
    }
    if (falseopt)
    {
        return (0);
    }
    namefolder(argc, argv, nb_opts, op_a, op_A, op_l, op_d, op_t,op_r);
}