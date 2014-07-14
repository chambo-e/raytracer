/*
** divide_calc.c for rt in /home/chambo-e/Dropbox/epitech/raytracer/chambo_e/work_folder
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Sun Jun  1 20:49:55 2014 chambon emmanuel
** Last update Fri Jun  6 16:59:30 2014 chambon emmanuel
*/

#include "rt.h"

void            divide_calc(t_rt *rt, int i, int share)
{
  int		nb_client;
  t_client	*tmp;

  nb_client = rt->cluster;
  nb_client += get_nb_client(rt->client);
  tmp = rt->client;
  if (nb_client > 0)
    share = (int)ceil((WINX * WINY) / nb_client);
  while (tmp && tmp->servinfo)
    {
      tmp->beg = i++ * share;
      if (rt->cluster == 0)
	tmp->end = (i * share);
      else
	tmp->end = (i * share) - 1;
      tmp = tmp->next;
    }
  if (rt->cluster == 1)
    {
      rt->beg = (i * share);
      rt->end = WINX * WINY;
    }
  else
    rt->end = 0;
}
