/*
** send_spots.c for rt in /home/chambo-e/Dropbox/epitech/raytracer/chambo_e/work_folder
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Fri May 30 20:31:13 2014 chambon emmanuel
** Last update Fri Jun  6 18:47:53 2014 chambon emmanuel
*/

#include "rt.h"

char			*get_spot_clust(t_spot *spot)
{
  char			*res;
  char			*ret;
  char			*pos;

  if (!(res = my_xmalloc((150))) || !(ret = my_xmalloc(48)))
    return (NULL);
  bzero(res, 150);
  bzero(ret, 48);
  res[0] = 'S';
  res[1] = 'P';
  res[2] = ';';
  if (!(pos = get_double_som(2, spot, NULL, NULL)))
    return (NULL);
  strcat(res, pos);
  sprintf(ret, "%d;%d;%d;%d;%d*", spot->type, spot->color->rgba[0],
          spot->color->rgba[1], spot->color->rgba[2], spot->color->rgba[3]);
  strcat(res, ret);
  free(pos);
  free(ret);
  return (res);
}

char			*concat_spot_struct(t_spot *spot)
{
  t_spot		*tmp;
  char			*res;
  char			*ret;

  if (!spot)
    return ("*");
  if (!(res = my_xmalloc(1)))
    return (NULL);
  res[0] = 0;
  tmp = spot;
  while (tmp && tmp->color)
    {
      if (!(ret = get_spot_clust(tmp)))
        return (NULL);
      if (!(res = realloc(res, strlen(res) + strlen(ret) + 1)))
        return (NULL);
      strcat(res, ret);
      free(ret);
      tmp = tmp->next;
    }
  return (res);
}
