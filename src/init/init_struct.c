/*
** init_struct.c for RT in /home/chambo_e/Dropbox/raytracer/chambo_e
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Fri Apr 18 18:04:56 2014 chambon emmanuel
** Last update Thu Jul 10 19:43:45 2014 chambon emmanuel
*/

#include "rt.h"

int		init_rt(t_rt *rt)
{
  rt->winsize_x = -1;
  rt->winsize_y = 0;
  rt->beg = 0;
  rt->end = 0;
  rt->img = NULL;
  rt->eye = NULL;
  rt->client = NULL;
  rt->objs = NULL;
  rt->spot = NULL;
  rt->N2D.vals = NULL;
  return (0);
}

int		init_img(t_rt *rt)
{
  if (!(rt->img = my_xmalloc(sizeof(t_img))) || init_func_perlin(rt) < 0)
    return (-1);
  rt->img->img = NULL;
  rt->img->win = NULL;
  rt->img->mlx = NULL;
  rt->img->data = NULL;
  rt->img->size = 0;
  rt->img->bpp = 0;
  rt->img->end = 0;
  return (0);
}

void		free_parse(t_parse *parse)
{
  t_parse	*tmp;

  while (parse)
    {
      tmp = parse;
      parse = parse->next;
      if (tmp->line)
        free(tmp->line);
      free(tmp);
    }
  free(parse);
}

int		get_nb_client(t_client *client)
{
  t_client	*tmp;
  int		i;

  i = 0;
  tmp = client;
  while (tmp && tmp->servinfo)
    {
      i++;
      tmp = tmp->next;
    }
  return (i);
}

int		init_struct(t_rt *rt, char *file)
{
  t_parse	*lines;

  if (!(lines = parse_file(file)))
    return (-1);
  if (init_rt(rt) == -1
      || get_window(lines, rt) == -1
      || get_client(lines, rt) == -1
      || get_eye(lines, rt) == -1
      || get_opt(lines, rt) == -1
      || get_spot(lines, rt) == -1
      || get_obj(lines, rt) == -1
      || init_img(rt) == -1)
    {
      free_rt(rt);
      free_parse(lines);
      return (-1);
    }
  divide_calc(rt, 0, 0);
  free_parse(lines);
  mlx_app(rt);
  return (0);
}
