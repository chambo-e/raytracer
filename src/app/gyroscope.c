/*
** gyroscope.c for raytracer in /home/paasch_j/Dropbox/raytracer/MUL_2013_rtracer
**
** Made by johan paasche
** Login   <paasch_j@epitech.net>
**
** Started on  Sun Jun 15 19:14:05 2014 johan paasche
** Last update Thu Jun 19 14:17:32 2014 chambon emmanuel
*/

#include "rt.h"

/*
** Dans les calculs du rt : X => profondeur
**			    Y => de gauche a droite
**			    Z => de haut en bas
*/

/*
** Dans l'appli : il faudrait ne bouger que de haut en bas et de droite a gauche,
** reserver le x pour une fonction zoom
** donc dans l'appli on evite les modifications de l'axe X.
*/

void		x_gyro(t_opt *eye, double angle)
{
  double	copy[2];

  if (abs(angle) > 0)
    {
      copy[0] = eye->eye_rot[Y];
      copy[1] = eye->eye_rot[Z];
      eye->eye_rot[Z] = cos(angle) * copy[1] + sin(angle) * copy[0];
    }
}

void		y_gyro(t_opt *eye, double angle)
{
  double	copy[2];

  if (abs(angle) > 0)
    {
      copy[0] = eye->eye_rot[X];
      copy[1] = eye->eye_rot[Z];
    }
  (void)copy;
}

void		z_gyro(t_opt *eye, double angle)
{
  double	copy[2];

  if (abs(angle) > 0)
    {
      copy[0] = eye->eye_rot[X];
      copy[1] = eye->eye_rot[Y];
    }
  (void)copy;
}

void		gyroscope(t_opt *eye, double x_rot, double y_rot, double z_rot)
{
  double	round_angles[3];
  void		(*gyro_fct[3])(t_opt *, double);
  int		i;

  init_tab(round_angles, 0, 3);
  round_angles[0] = x_rot;
  round_angles[1] = round(y_rot);
  round_angles[2] = round(z_rot);
  gyro_fct[0] = &x_gyro;
  gyro_fct[1] = &y_gyro;
  gyro_fct[2] = &z_gyro;
  i = 0;
  while (i < 3)
    {
      if (abs(round_angles[i]) > 0)
	gyro_fct[i](eye, round_angles[i]);
      ++i;
    }
}
