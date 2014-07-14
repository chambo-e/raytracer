/*
** free_tab.c for RT in /home/chambo_e/Dropbox/epitech/raytracer/chambo_e
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Mon Apr 21 22:30:10 2014 chambon emmanuel
** Last update Wed May 14 22:07:10 2014 chambon emmanuel
*/

#include "rt.h"

void		free_tab(char **tab)
{
  int		i;

  i = 0;
  while (tab[i])
    free(tab[i++]);
  free(tab);
}
