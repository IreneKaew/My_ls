#include "mylib.h"
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <grp.h>
#include <pwd.h>
#include <unistd.h>
#include <time.h>
#include <termios.h>
#include <sys/ioctl.h>

// Get file type and permission
void show_rights(char *file)
{
  struct stat statinfo;

  stat(file, &statinfo);

  //  S_ISREG is it a regular file?
  if (S_ISREG(statinfo.st_mode))
    my_putchar('-');
  //  S_ISLNK symbolic link?
  else if (S_ISLNK(statinfo.st_mode))
    my_putchar('l');
  else
    my_putchar('d');
  my_putchar((statinfo.st_mode & S_IRUSR) ? 'r' : '-');
  my_putchar((statinfo.st_mode & S_IWUSR) ? 'w' : '-');
  my_putchar((statinfo.st_mode & S_IXUSR) ? 'x' : '-');
  my_putchar((statinfo.st_mode & S_IRGRP) ? 'r' : '-');
  my_putchar((statinfo.st_mode & S_IWGRP) ? 'w' : '-');
  my_putchar((statinfo.st_mode & S_IXGRP) ? 'x' : '-');
  my_putchar((statinfo.st_mode & S_IROTH) ? 'r' : '-');
  my_putchar((statinfo.st_mode & S_IWOTH) ? 'w' : '-');
  my_putchar((statinfo.st_mode & S_IXOTH) ? 'x' : '-');
  my_putstr(" ");
}

// Get hardlink
void show_link(char *file)
{
  struct stat statinfo;

  stat(file, &statinfo);
  my_putnbr(statinfo.st_nlink);
  my_putchar(' ');
}

// Get name of group
void grp_name(char *fileg)
{
  struct stat statinfo;

  stat(fileg, &statinfo);
  my_putstr(getgrgid(statinfo.st_gid)->gr_name);
}

// Get name of user
void usr_name(char *fileu)
{
  struct stat statinfo;

  stat(fileu, &statinfo);
  my_putstr(getpwuid(statinfo.st_uid)->pw_name);
}

// Return memeory to the perating system by calling Free function
void free_fnc(char **stock, char **show_stock, int nbr)
{
  for (int i = 0; i != nbr; i++)
  {
    free(stock[i]);
    free(show_stock);
  }
  free(stock);
  free(show_stock);
}

// Get date and time
void show_datime(char *file)
{
  struct stat statinfo;
  char *time;
  char *result = malloc(sizeof(char) * 12);
  int j = 0;

  stat(file, &statinfo);
  time = ctime(&statinfo.st_mtime);
  for (int i = 4; i != 16; i++, j++)
    result[j] = time[i];
  my_putstr(result);
  my_putchar(' ');
  free(result);
}

// Get byte size
void show_size(char *file)
{
  struct stat statinfo;

  stat(file, &statinfo);
  my_putnbr(statinfo.st_size);
  my_putchar(' ');
}

void show_all(char *dir)
{
  DIR *dp = opendir(dir);
  struct dirent *dirp;
  struct stat statinfo;
  char *file;
  int stock = 0;

  while ((dirp = readdir(dp)) != NULL)
  {
    file = my_strcat(dir, dirp->d_name);
    if ((lstat(file, &statinfo)) == 0)
      (dirp->d_name[0] != '.') ? stock += statinfo.st_blocks : 0;
  }
  closedir(dp);
  my_putstr("total ");
  my_putnbr(stock / 2);
  my_putchar('\n');
}

int ls_l(char *dir)
{
  DIR *dp = opendir(dir);
  struct dirent *dirp;
  show_all(dir);

  while ((dirp = readdir(dp)) != NULL)
  {
    struct stat statinfo;
    char *absolute = malloc(sizeof(char) * (my_strlen(dirp->d_name) + my_strlen(dir) + 2));
    my_strcpy(absolute, dir);
    my_strcat(absolute, "/");
    my_strcat(absolute, dirp->d_name);

    lstat(absolute, &statinfo);
    if (dirp->d_name[0] != '.')
    {
      show_rights(dirp->d_name);
      my_putchar(' ');
      show_link(dirp->d_name);
      grp_name(dirp->d_name);
      my_putchar(' ');
      usr_name(dirp->d_name);
      my_putchar(' ');
      show_size(dirp->d_name);
      show_datime(dirp->d_name);
      my_putchar(' ');
      my_putstr(dirp->d_name);
      my_putchar('\n');
    }
  }
  my_putstr("\n");
  closedir(dp);
}