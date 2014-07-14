/*
** lighting.c for raytracer in /home/paasch_j/Dropbox/raytracer/paasch_j/raytracer
**
** Made by johan paasche
** Login   <paasch_j@epitech.net>
**
** Started on  Tue May 27 16:53:52 2014 johan paasche
** Last update Sat Jun  7 22:56:55 2014 david tran
*/

#include "client_rt.h"

void	stack_color(colour comp[], t_color *col)
{
  comp[0] += col->rgba[0];
  comp[1] += col->rgba[1];
  comp[2] += col->rgba[2];
}

void		lighting(t_ray *ray, t_obj *obj, t_spot *spots)
{
  t_spot	*light;
  double	cos;
  colour	total[3];
  t_color	col;
  int		i;

  light = spots;
  i = 0;
  init_tab((double *)total, 0, 3);
  while (light != NULL)
    {
      col.color = obj->color->color;
      cos = 0;
      cos = obj->cos(ray, obj, light);
      if (cos <= LOW)
	cos = 0.0;
      col.color = new_color(&col, cos);
      col.color = shining(&col, light->color, obj->brill, cos);
      stack_color(total, &col);
      light = light->next;
      ++i;
    }
  ray->color->rgba[0] = total[0] / i;
  ray->color->rgba[1] = total[1] / i;
  ray->color->rgba[2] = total[2] / i;
}
