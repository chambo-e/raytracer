/*
** check_calculated.c for rt in /home/chambo-e/Dropbox/epitech/raytracer/chambo_e/work_folder
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Sun Jun  1 00:50:00 2014 chambon emmanuel
** Last update Sat Jun  7 23:21:41 2014 david tran
*/

#include "client_rt.h"

int		check_calculated(char *data, t_rt_client *rt)
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
