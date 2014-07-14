/*
** epur_str.c for Corewar in /home/chambo_e/Dropbox/Corewar/build/asm/src/base
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Sun Apr 13 19:11:14 2014 chambon emmanuel
** Last update Fri Jun 13 23:59:06 2014 chambon emmanuel
*/

#include "rt.h"

void		clean_string(char *str)
{
  int		i;
  int		j;

  i = -1;
  j = 0;
  while (str[++i])
    {
      if (str[i] != ' ' && str[i] != '\t')
        {
          str[j] = str[i];
          j++;
	  if (str[i + 1] == ' ' || str[i + 1] == '\t')
	    {
	      str[j] = ' ';
	      j++;
	    }
	}
    }
  str[j] = '\0';
  if (j > 0 && str[j - 1] == ' ')
    str[j - 1] = '\0';
}

int		no_char(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      if (str[i] > 20 && str[i] < 127)
	return (1);
      i++;
    }
  return (0);
}

char            *epur_str(char *str)
{
  if (!str)
    return (NULL);
  if (!no_char(str))
    str[0] = 0;
  else
    clean_string(str);
  return (str);
}
