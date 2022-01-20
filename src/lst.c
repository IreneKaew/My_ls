#include <time.h>
#include "mylib.h"
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>

/* int ls_t(char *dir) */
/* { */
/* 	struct dirent *dirp; */
/* 	DIR *dp = opendir(dir); */
/* 	struct timespec time; */
/* 	time.tv_sec = 56; */
/* 	time.tv_nsec = 100; */
/* 	struct timespec */
/* 	{ */
/* 		time_t tv_sec; */
/* 		long tv_nsec; */
/* 	}; */
/* 	if (!dp) */
/* 	{ */
/* 		if (errno = ENOENT) */
/* 		{ */
/* 			my_putstr("a.out: cannot access '"); */
/* 			my_putstr(dir); */
/* 			my_putstr("': No such file or directory \n"); */
/* 		} */
/* 		else */
/* 		{ */
/* 			my_putstr("Unable to read directory"); */
/* 		} */
/* 		return (0); */
/* 	} */
/* 	while ((dirp = readdir(dp)) != NULL) */
/* 	{ */
/*  */
/* 		my_put_nbr((long long)time.tv_sec); */
/* 		my_put_nbr(time.tv_sec); */
/* 		my_put_nbr(time.tv_nsec); */
/*  */
/* 	} */
/* 	while (/* condition */
/* 	{ */

/* 	} */
/* 	 */
/* 	closedir(dp); */
/* 	return (0); */
/* 	my_putstr("\n"); */
/* } */
/*  */
char *file_to_inspect(char *ls, char *file)
{
	char *str = my_strdup(ls);

	if (my_strcmp(str, ".") == 0)
	{
		str = my_strcat(str, "/");
		str = my_strcat(str, file);
		return (str);
	}
	str = my_strcat(str, "/");
	str = my_strcat(str, file);
	return (str);
}

long my_put_long(long nb)
{
	long i = 0;

	if (nb >= 10)
	{
		i += my_put_nbr(nb / 10);
		i += my_put_nbr(48 + nb % 10);
	}
	else
		i += my_put_nbr(48 + nb);
	return (i);
}

char **swap_elem(int index1, int index2, char **tab)
{
	char *tmp = my_strdup(tab[index1]);

	tab[index1] = my_strdup(tab[index2]);
	tab[index2] = my_strdup(tmp);
	free(tmp);
	return (tab);
}

char **compare_time(char **tab, char *directory)
{
	int y = 0;
	char *str = NULL;
	char *str2 = NULL;
	long tmp = 0;
	struct stat statinfo;

	while (tab[y + 1])
	{
		str = file_to_inspect(directory, tab[y]);
		str2 = file_to_inspect(directory, tab[y + 1]);
		stat(str, &statinfo);
		tmp = statinfo.st_mtime;
		stat(str2, &statinfo);
		if (tmp < statinfo.st_mtime)
		{
			swap_elem(y, y + 1, tab);
			y = 0;
			continue;
		}
		else
			y++;
	}
	return (tab);
}

int ls_t(char *dir)
{
	struct dirent *dirp;
	DIR *dp = opendir(dir);
	char **tab;
	char *names = "\0";
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
			names = my_strcat(names, dirp->d_name);
			names = my_strcat(names, "\n");
		}
	}
	tab = my_strtab(names, "\n");
	tab = compare_time(tab, dir);
	my_showtab(tab);
	closedir(dp);
	return(0);
}