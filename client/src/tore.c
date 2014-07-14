/*
** tore.c for tore in /home/wallet_v/Dropbox/raytracer/wallet_v
**
** Made by valentin wallet
** Login   <wallet_v@epitech.net>
**
** Started on  Fri Jun  6 23:32:39 2014 valentin wallet
** Last update Wed Jun 18 01:04:25 2014 johan paasche
*/

#include "client_rt.h"

void            fill_tor_struct_one(t_tor *tor)
{
  tor->zero = tor->one;
  tor->one = tor->two;
  tor->two = tor->three;
  tor->three = tor->four;
}

void            fill_tor_struct_normal(t_tor *tor, double *values)
{
  tor->zero = values[4];
  tor->one = values[3];
  tor->two = values[2];
  tor->three = values[1];
  tor->four = values[0];
  tor->n = 4;
}

double            tore_normale(t_ray *ray, t_obj *obj, t_spot *light)
{
  double        xl;
  double        yl;
  double        zl;
  double        xn;
  double        yn;
  double        zn;
  double        L;
  double        N;
  double	inter[2];
  double        k2;

  xl = (ray->eye[0] + (ray->k * ray->v[0])) - light->pos[0];
  yl = (ray->eye[1] + (ray->k * ray->v[1])) - light->pos[1];
  zl = (ray->eye[2] + (ray->k * ray->v[2])) - light->pos[2];
  inter[0] = ray->eye[0] + (ray->k * ray->v[0]);
  inter[1] = ray->eye[1] + (ray->k * ray->v[1]);
  inter[2] = ray->eye[2] + (ray->k * ray->v[2]);
  k2 = 4 * (pow(inter[0], 2) + pow(inter[1], 2) + pow(inter[2], 2) +
	    pow(obj->rayon, 2) - pow(obj->angle / PI * 180, 2));
  xn = inter[0] * k2 - 8 * pow(obj->rayon, 2) * inter[0];
  yn = inter[1] * k2;
  zn = inter[2] * k2 - 8 * pow(obj->rayon, 2) * inter[2];
  L = sqrt(pow(xl, 2) + pow(yl, 2) + pow(zl, 2));
  N = sqrt(pow(xn, 2) + pow(yn, 2) + pow(zn, 2));
  return (((xn * xl) + (yn * yl) + (zn * zl)) / (L * N));
}

double          tore_equation(t_ray *ray, t_obj *obj)
{
  double        result[4];
  double        n[11];
  int           nbroots;
  t_tor         tor;

  nbroots = 0;
  init_tab(result, 0, 4);
  n[5]= ray->v[0] * ray->v[0] + ray->v[1] * ray->v[1] + ray->v[2] * ray->v[2];
  n[6] = 2.0 * (ray->v[0] * ray->eye[0] + ray->v[1]
		* ray->eye[1] + ray->v[2] * ray->eye[2]);
  n[7] = ray->eye[0] * ray->eye[0] + ray->eye[1] * ray->eye[1] + ray->eye[2] *
    ray->eye[2] + obj->rayon * obj->rayon - pow((obj->angle / PI * 180), 2);
  n[8] = 4.0 * obj->rayon * obj->rayon;
  n[9] = n[8] * (ray->v[0] * ray->v[0] + ray->v[2] * ray->v[2]);
  n[10] = n[8] * 2 * (ray->v[0] * ray->eye[0] + ray->v[2] * ray->eye[2]);
  n[11] = n[8] * (ray->eye[0] * ray->eye[0] + ray->eye[2] * ray->eye[2]);
  n[0] = n[5] * n[5];
  n[1] = 2.0 * n[5] * n[6];
  n[2] = 2.0 * n[5] * n[7] + n[6] * n[6] - n[9];
  n[3] = 2.0 * n[6] * n[7] - n[10];
  n[4] = n[7] * n[7] - n[11];
  fill_tor_struct_normal(&tor, n);
  nbroots = solve_quartic(result, &tor);
  return (mini_k(result, nbroots));
}
