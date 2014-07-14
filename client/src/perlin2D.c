/*
** perlin2D.c for rt in /home/tran_0/Dropbox/raytracer/tran_0/perlin_noise/final_perlin
**
** Made by david tran
** Login   <tran_0@epitech.net>
**
** Started on  Sat May 31 08:09:31 2014 david tran
** Last update Sun Jun  8 22:30:31 2014 david tran
*/

#include "client_rt.h"

int	initBruit2D(t_n2D *N2D)
{
  int	i;

  N2D->vals = memset(N2D->vals, 0, N2D->len_max * N2D->high_max);
  srand(time(NULL));
  i = 0;
  while (i < N2D->len_max * N2D->high_max)
    {
      N2D->vals[i] = ((double) rand()) / RAND_MAX;
      i++;
    }
  return (0);
}

double		bruit2D(int i, int j, t_n2D *N2D)
{
  return (N2D->vals[i * N2D->len_max + j]);
}

double		fonction_bruit2D(double x, double y, t_n2D *N2D)
{
  t_dble	stdb;
  int		i;
  int		j;

  i = (int)(x / PAS);
  j = (int)(y / PAS);
  stdb.a = bruit2D(i, j, N2D);
  stdb.b = bruit2D(i + 1, j, N2D);
  stdb.c = bruit2D(i, j + 1, N2D);
  stdb.d = bruit2D(i + 1, j + 1, N2D);
  x = fmod(x / PAS, 1);
  y = fmod(y / PAS, 1);
  return (interpolation_cos2D(&stdb, x, y));
}

double		bruit_coherent2D(double x, double y, t_n2D *N2D)
{
  double	somme;
  double	p;
  int		f;
  int		i;

  somme = 0;
  p = 1;
  f = 1;
  i = 0;
  while (i < OCTAVES)
    {
      somme += p * fonction_bruit2D(x * f, y * f, N2D);
      p *= PERSISTANCE;
      f *= 2;
      i++;
    }
  return (somme * (1 - PERSISTANCE) / (1 - p));
}
