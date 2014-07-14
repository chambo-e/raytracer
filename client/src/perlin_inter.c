/*
** perlin_inter.c for rt in /home/tran_0/Dropbox/raytracer/tran_0/perlin_noise/final_perlin
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Sat May 31 08:22:06 2014 david tran
** Last update Sun Jun  8 21:59:10 2014 david tran
*/

#include "client_rt.h"

double		interpolation_cos1D(double a, double b, double x)
{
  double	k;

  k = (1 - cos(x * PI)) / 2;
  return (a * (1 - k) + b * k);
}

double		interpolation_cos2D(t_dble *stdb, double x, double y)
{
  double	y1;
  double	y2;

  y1 = interpolation_cos1D(stdb->a, stdb->b, x);
  y2 = interpolation_cos1D(stdb->c, stdb->d, x);
  return (interpolation_cos1D(y1, y2, y));
}
