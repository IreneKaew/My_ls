#include <unistd.h>
#include "mylib.h"

int	my_strcmp(char *s1, char *s2)
{
  int	e;

  e = 0;
  while ((s1[e] == s2[e]) && (s1[e] != '\0') && (s2[e] != '\0'))
    {
      e++;
    }
  return (s1[e] - s2[e]);
}