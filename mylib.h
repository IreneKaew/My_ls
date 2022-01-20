#ifndef F8E3A9A3_67E9_40B9_8E13_D93411A6714A
#define F8E3A9A3_67E9_40B9_8E13_D93411A6714A
#include <stdbool.h>

bool firstcaract(char *s1, char *s2);
void my_putchar(char c);
void my_putstr(const char *str);
void my_putnbr(int nb);
char *my_strstr(char *str, char *to_find);
int my_strcmp(char *s1, char *s2);
char *ls_a(char *dir);
char *ls_(char *dir);
char *ls_A(char *dir);
void namefolder(int argc, char **argv, int nb_opts, bool op_a, bool op_A, bool op_l, bool op_d, bool op_t,bool op_r);
char *ls_d(char *dir, int argc, char **argv);
char *my_strcat(char *dest, char const *src);
char *my_strdup(char const *src);
int ls_l(char *dir);
char *my_strcpy(char *dest, char const *src);
int my_strlen(char const * str);
void show_datime(char *file);
int ls_t(char *dir);
int my_put_nbr(int nb);
char *my_strdup(char const *src);
char **my_strtab(char *str, char *lim);
int ls_r(char *dir);
int my_showtab(char *const *tab);
#endif /* F8E3A9A3_67E9_40B9_8E13_D93411A6714A */
