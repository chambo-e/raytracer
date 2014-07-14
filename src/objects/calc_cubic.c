/*
** calc_cubic.c for calc_cubic in /home/wallet_v/rendu/MUL_2013_rtv1
**
** Made by valentin wallet
** Login   <wallet_v@epitech.net>
**
** Started on  Fri Jun  6 18:26:35 2014 valentin wallet
** Last update Sat Jun  7 06:01:04 2014 johan paasche
*/

#include "rt.h"

void		calc_coeff_cubic(t_cubic *cubic, t_tor *tor)
{
  cubic->coeff_0 = tor->three;
  if (cubic->coeff_0 != 1.0)
    {
      cubic->coeff_1 = tor->two / cubic->coeff_0;
      cubic->coeff_2 = tor->one / cubic->coeff_0;
      cubic->coeff_3 = tor->zero / cubic->coeff_0;
    }
  else
    {
      cubic->coeff_1 = tor->two;
      cubic->coeff_2 = tor->one;
      cubic->coeff_3 = tor->zero;
    }
}

void		calc_for_delta(t_cubic *cubic)
{
  cubic->coeff_1_2 = cubic->coeff_1 * cubic->coeff_1;
  cubic->Q = (cubic->coeff_1_2 - 3.0 * cubic->coeff_2) / 9.0;
  cubic->R = (cubic->coeff_1 * (cubic->coeff_1_2 - 4.5 * cubic->coeff_2) +
	      13.5 * cubic->coeff_3) / 27.0;
  cubic->Q_3 = cubic->Q * cubic->Q * cubic->Q;
  cubic->R_2 = cubic->R * cubic->R;
  cubic->d = cubic->Q_3 - cubic->R_2;
  cubic->a_d_3 = cubic->coeff_1 / 3.0;
}

double		solve_cubic(double *root, t_tor *tor)
{
  t_cubic	cubic;

  calc_coeff_cubic(&cubic, tor);
  calc_for_delta(&cubic);
  if (cubic.d >= 0.0)
    {
      cubic.d = cubic.R / sqrt(cubic.Q_3);
      cubic.theta = acos(cubic.d) / 3.0;
      cubic.sq = -2.0 * sqrt(cubic.Q);
      root[0] = cubic.sq * cos(cubic.theta) - cubic.a_d_3;
      root[1] = cubic.sq * cos(cubic.theta + TWO_PI_3) - cubic.a_d_3;
      root[2] = cubic.sq * cos(cubic.theta + TWO_PI_43) - cubic.a_d_3;
      return (3);
    }
  else
    {
      cubic.sq = pow(sqrt(cubic.R_2 - cubic.Q_3) + fabs(cubic.R), 1.0 / 3.0);
      if (cubic.R < 0)
	root[0] = (cubic.sq + cubic.Q / cubic.sq) - cubic.a_d_3;
      else
	root[0] = -(cubic.sq + cubic.Q / cubic.sq) - cubic.a_d_3;
      return (1);
    }
  return (0);
}
