/*
** my_str_to_wordtab.c for Corewar in /home/chambo_e/Dropbox/Corewar/build/asm/src/base
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Sun Apr 13 19:14:10 2014 chambon emmanuel
** Last update Fri May 23 05:39:41 2014 chambon emmanuel
*/

#include "rt.h"

int	count_words(char *str, char sep)
{
  int	i;
  int	w;

  w = 1;
  i = 0;
  while (str[i])
    {
      if (str[i] == sep)
	w++;
      i++;
    }
  return (w);
}

int	word_char(char *str, char sep, int i)
{
  int	j;

  j = 0;
  while ((str[i] != sep) && str[i])
    {
      i++;
      j++;
    }
  return (j);
}

char	**my_str_to_wordtab(char *str, char sep)
{
  int	w;
  char	**tab;
  int	i;
  int	c;
  int	count;

  c = 0;
  i = 0;
  count = 0;
  w = count_words(str, sep);
  if (!(tab = my_xmalloc((w + 1) * sizeof(char *))))
    return (NULL);
  while (count < w)
    {
      c = word_char(str, sep, i);
      if (!(tab[count] = my_xmalloc((c + 1) * sizeof(char))))
	return (NULL);
      tab[count][c] = '\0';
      strncpy(tab[count++], &str[i], c);
      i = i + c;
      while (str[i] == sep)
	i++;
    }
  tab[count] = NULL;
  return (tab);
}
