#include "mylib.h"
#include <unistd.h>

int my_showtab(char *const *tab)
{
	int i = 0;

	while (tab[i])
	{
		my_putstr(tab[i]);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}