#include <unistd.h>
#include "mylib.h"

 int my_strlen(char const * str)
{
  int i = 0;
  while (str[i] != '\0')
    i++;
  return i;
}