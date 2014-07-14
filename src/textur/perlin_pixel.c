/*
** perlin_pixel.c for rt in /home/tran_0/Dropbox/raytracer/tran_0/perlin_noise/final_perlin
**
** Made by david tran
** Login   <tran_0@epitech.net>
**
** Started on  Sat May 31 08:21:21 2014 david tran
** Last update Sun Jun  8 23:25:50 2014 chambon emmanuel
*/

#include "rt.h"

int		get_color_alias(double red, double green, double blue)
{
  int		color;

  color = ((((int)(red * 255)) << 16) +
	   (((int)(green * 255)) << 8) + (int)(blue * 255));
  return (color);
}

int		get_pixel_marbr(t_rt *mlx, t_ray *ray)
{
  double	valeur;

  valeur = 1 - sqrt(fabs(sin(2 * 3.141592 *
			     bruit_coherent2D(ray->x, ray->y, &mlx->N2D))));
  return (get_color_alias((1 - valeur) + 0.7 * valeur, (1 - valeur)
			  + 0.7 * valeur, (1 - valeur) + 0.7 * valeur));
}

int		get_pixel_wood(t_rt *mlx, t_ray *ray)
{
  double	valeur;
  double	f;
  double	seuil;
  double	red;
  double	blue;
  double	green;

  red = (double)ray->color->rgba[0] / 256.;
  green = (double)ray->color->rgba[1] / 256.;
  blue = (double)ray->color->rgba[2] / 256.;
  seuil = 0.2;
  valeur = fmod(bruit_coherent2D(ray->x, ray->y, &mlx->N2D), seuil);
  if (valeur > seuil / 2)
    valeur = seuil - valeur;
  f = (1 - cos(PI * valeur / (seuil / 2))) / 2;
  return (get_color_alias(red * (1 - f) + 0.1 * f, green * (1 - f) + 0.1 * f,
			  blue * (1 - f)));
}

int		get_pixel(t_rt *mlx, t_ray *ray)
{
  double	valeur;
  double	red;
  double	blue;
  double	green;
  double	f;

  red = (double)ray->color->rgba[0] / 256.;
  green = (double)ray->color->rgba[1] / 256.;
  blue = (double)ray->color->rgba[2] / 256.;
  valeur = bruit_coherent2D(ray->x, ray->y, &mlx->N2D);
  f = (1 - cos(PI * valeur / (0.2 / 2))) / 2;
  return (get_color_alias((valeur + red) / 2 * (1 - f), (valeur + green)
		    / 2 * (1 - f), (valeur + blue) / 2 * (1 - f)));
}

int		get_pixel_sky(t_rt *mlx, t_ray *ray)
{
  double	valeur;

  valeur = bruit_coherent2D(ray->x, ray->y, &mlx->N2D);
  return (get_color_alias(valeur, valeur, 1));
}
