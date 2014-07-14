/*
** k_calcul.c for raytracer in /home/paasch_j/Dropbox/raytracer/paasch_j/raytracer
**
** Made by johan paasche
** Login   <paasch_j@epitech.net>
**
** Started on  Thu May 22 23:29:06 2014 johan paasche
** Last update Fri Jun  6 20:54:07 2014 johan paasche
*/

#include "rt.h"

double		find_k(double delta, double a, double b)
{
  double	k1;
  double	k2;
  double	k;

  if (delta < LOW)
    return (-1);
  k = -1;
  k1 = (-b - sqrt(delta)) / (2 * a);
  k2 = (-b + sqrt(delta)) / (2 * a);
  if (k1 < LOW && k2 < LOW)
    return (-1);
  if (k1 > LOW)
    k = k1;
  if (k2 > LOW && k2 < k1)
    k = k2;
  return (k);
}

void		init_tab(double array[], double value, int size)
{
  int		i;

  i = 0;
  while (i < size)
    array[i++] = value;
}
