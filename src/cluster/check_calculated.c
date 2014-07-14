/*
** check_calculated.c for rt in /home/chambo-e/Dropbox/epitech/raytracer/chambo_e/work_folder
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Sun Jun  1 00:50:00 2014 chambon emmanuel
** Last update Thu Jun  5 22:06:18 2014 emmanuel chambon
*/

#include "rt.h"

int		check_calculated(char *data, t_rt *rt)
{
  int		i;

  i = 0;
  while (i < (WINY * WINX))
    {
      if (data[i + 3] == -1)
	return (-1);
      i++;
    }
  return (0);
}
