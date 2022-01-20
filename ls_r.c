#include "mylib.h"
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>

int ls_r(char *dir)
{
	char **tab = my_strtab("\n", "\n");
	int y = 0;
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
		if ((dirp->d_name[0] != '.'))
		{
			tab[y] = my_strdup(dirp->d_name);
			y += 1;
		}
	}
	y -= 1;
	while (y >= 0)
	{
		my_putstr(tab[y]);
		y--;
		my_putstr("\n");
	}
	my_putstr("\n");
}