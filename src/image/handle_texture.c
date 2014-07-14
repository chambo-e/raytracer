/*
** handle_texture.c for rt in /home/chambo-e/Dropbox/epitech/raytracer/chambo_e/work_folder
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Fri Jun  6 11:47:27 2014 chambon emmanuel
** Last update Sat Jul  5 21:17:43 2014 chambon emmanuel
*/

#include "rt.h"

int		get_texture(t_parse *lines, t_rt *rt, int i)
{
  t_parse	*tmp;

  tmp = lines;
  while (tmp)
    {
      if ((!(strncmp(tmp->line, "TEXTURE", 7))) &&
          (((rt->eye->texture) != -1)))
        return (print_error(MULTIDEF_TEXTURE));
      else if (!(strncmp(tmp->line, "TEXTURE", 7)))
        {
          while (tmp->line[i] != DEFINE_CHAR && tmp->line[i])
            if (check_define(&i, tmp->line) == -1)
              return (-1);
          rt->eye->texture = atoi(&tmp->line[i + 1]);
          if (rt->eye->texture > TEXTURE_MAX || rt->eye->texture < 0)
            return (print_error(WR_TEXTURE));
        }
      tmp = tmp->next;
    }
  if (rt->eye->texture == -1)
    rt->eye->texture = 0;
  return (0);
}

int		check_texture_img(t_rt *rt)
{
  if (rt->eye->texture)
    return (print_error(IMG_TEXTURE));
  return (0);
}
