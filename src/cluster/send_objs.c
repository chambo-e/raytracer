/*
** send_objs.c for rt in /home/chambo-e/Dropbox/epitech/raytracer/chambo_e/work_folder
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Fri May 30 20:29:29 2014 chambon emmanuel
** Last update Fri Jul 11 16:03:38 2014 chambon emmanuel
*/

#include "rt.h"

char			*set_res_objs(char *res, char *ret, t_obj *obj)
{
  char			*pos;
  char			*rot;

  res[0] = 'O';
  res[1] = 'B';
  res[2] = ';';
  if (!(pos = get_double_som(3, NULL, obj, NULL))
      || !(rot = get_double_som(4, NULL, obj, NULL)))
    return (NULL);
  strcat(res, pos);
  strcat(res, rot);
  sprintf(ret, "%d;%lf;%lf;%lf;%d;%d;%d;%d;%lf;%d*", obj->type,
          obj->special, obj->rayon, obj->angle, obj->color->rgba[0],
          obj->color->rgba[1], obj->color->rgba[2], obj->color->rgba[3],
          obj->brill, obj->texture);
  strcat(res, ret);
  free(pos);
  free(rot);
  free(ret);
  return (res);
}

char			*get_obj_clust(t_obj *obj)
{
  char			*res;
  char			*ret;

  if (!(res = my_xmalloc((1024))) || !(ret = my_xmalloc(1024)))
    return (NULL);
  bzero(ret, 1024);
  bzero(res, 1024);
  if (!(res = set_res_objs(ret, res, obj)))
    return (NULL);
  return (res);
}

char			*concat_obj_struct(t_obj *obj)
{
  t_obj			*tmp;
  char			*res;
  char			*ret;

  if (!obj->next && !obj->color)
    return (strdup(""));
  if (!(res = my_xmalloc(1)))
    return (NULL);
  res[0] = 0;
  tmp = obj;
  while (tmp && tmp->color)
    {
      if (!(ret = get_obj_clust(tmp)))
        return (NULL);
      if (!(res = realloc(res, strlen(res) + strlen(ret) + 1)))
        return (NULL);
      strcat(res, ret);
      free(ret);
      tmp = tmp->next;
    }
  return (res);
}
