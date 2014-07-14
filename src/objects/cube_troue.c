/*
** cube_troue.c for cube_troue in /home/wallet_v/Dropbox/raytracer/wallet_v
**
** Made by valentin wallet
** Login   <wallet_v@epitech.net>
**
** Started on  Fri Jun  6 22:54:39 2014 valentin wallet
** Last update Sun Jun  8 23:24:50 2014 chambon emmanuel
*/

#include "rt.h"

double          mini_k(double *result, int nbroots)
{
  double        tmp;
  int           i;

  if (nbroots == 0)
    return (-1);
  tmp = 0;
  i = 0;
  while (i < 4)
    {
      if (result[i] > 0)
        tmp = result[i];
      i++;
    }
  if (tmp == 0)
    return (-1);
  i = 0;
  while (i < 4)
    {
      if (result[i] > 0 && result[i] < tmp)
        tmp = result[i];
      i++;
    }
  return (tmp);
}

double		cube_normale(t_ray *ray, t_obj *obj, t_spot *light)
{
  double	xl;
  double	yl;
  double	zl;
  double	xn;
  double	yn;
  double	zn;
  double	L;
  double	N;
  double	x;
  double	y;
  double	z;

  xl = (ray->eye[0] + (ray->k * ray->v[0])) - light->pos[0];
  yl = (ray->eye[1] + (ray->k * ray->v[1])) - light->pos[1];
  zl = (ray->eye[2] + (ray->k * ray->v[2])) - light->pos[2];
  x = (ray->eye[0] / (obj->angle / PI * 180)) + (ray->k * ray->v[0]);
  y = (ray->eye[1] / (obj->angle / PI * 180)) + (ray->k * ray->v[1]);
  z = (ray->eye[2] / (obj->angle / PI * 180)) + (ray->k * ray->v[2]);
  xn = 4 * pow(x, 3) - 10 * x;
  yn = 4 * pow(y, 3) - 10 * y;
  zn = 4 * pow(z, 3) - 10 * z;
  L = sqrt(pow(xl, 2) + pow(yl, 2) + pow(zl, 2));
  N = sqrt(pow(xn, 2) + pow(yn, 2) + pow(zn, 2));
  return (((xn * xl) + (yn * yl) + (zn * zl)) / (L * N));
}

void		fill_values_cube(double *values, double *pos, t_ray *ray)
{
  values[0] = pow(ray->v[0], 4) + pow(ray->v[1], 4) + pow(ray->v[2], 4);
  values[1] = 4 * pow(ray->v[0], 3) * pos[0] + 4 * pow(ray->v[1], 3)
    * pos[1] + 4 * pow(ray->v[2], 3) * pos[2];
  values[2] += 6 * pow(ray->v[0], 2) * pow(pos[0], 2) - 5 * pow(ray->v[0], 2);
  values[3] += 4 * pow(pos[0], 3) * ray->v[0] - 10 * ray->v[0] * pos[0];
  values[4] += pow(pos[0], 4) - 5 * pow(pos[0], 2);
  values[2] += 6 * pow(ray->v[1], 2) * pow(pos[1], 2) - 5 * pow(ray->v[1], 2);
  values[3] += 4 * pow(pos[1], 3) * ray->v[1] - 10 * ray->v[1] * pos[1];
  values[4] += pow(pos[1], 4) - 5 * pow(pos[1], 2);
  values[2] += 6 * pow(ray->v[2], 2) * pow(pos[2], 2) - 5 * pow(ray->v[2], 2);
  values[3] += 4 * pow(pos[2], 3) * ray->v[2] - 10 * ray->v[2] * pos[2];
  values[4] += pow(pos[2], 4) - 5 * pow(pos[2], 2);
}

int		set_cube_equation(double result[], double n[], double p[],
				  t_obj *obj)
{
  if (obj->angle == 0)
    return (-1);
  init_tab(result, 0, 4);
  init_tab(n, 0, 4);
  init_tab(p, 0, 3);
  n[4] = obj->rayon;
  return (0);
}

double          cube_equation(t_ray *ray, t_obj *obj)
{
  double        result[4];
  int           nbroots;
  double        n[4];
  t_tor         tor;
  double	p[3];
  int		i;

  if ((i = set_cube_equation(result, n, p, obj)) == -1)
    return (0);
  while (i < 3)
    {
      p[i] = ray->eye[i] / (obj->angle / PI * 180);
      n[0] = pow(ray->v[0], 4) + pow(ray->v[1], 4) + pow(ray->v[2], 4);
      n[1] = 4 * pow(ray->v[0], 3) * p[X] + 4 * pow(ray->v[1], 3) * p[Y] + 4 *
      	pow(ray->v[2], 3) * p[Z];
      n[2] += 6 * pow(ray->v[i], 2) * pow(p[i], 2) - 5 * pow(ray->v[i], 2);
      n[3] += 4 * pow(p[i], 3) * ray->v[i] - 10 * ray->v[i] * p[i];
      n[4] += pow(p[i], 4) - 5 * pow(p[i], 2);
      ++i;
    }
  fill_tor_struct_normal(&tor, n);
  nbroots = solve_quartic(result, &tor);
  return (mini_k(result, nbroots));
}
