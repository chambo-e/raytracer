/*
** calc_quartic.c for calc_quartic in /home/wallet_v/rendu/MUL_2013_rtv1
**
** Made by valentin wallet
** Login   <wallet_v@epitech.net>
**
** Started on  Fri Jun  6 17:36:00 2014 valentin wallet
** Last update Wed Jun 18 01:04:24 2014 johan paasche
*/

#include "client_rt.h"

void		calc_quartic_coeff(t_poly *poly, t_tor *tor)
{
  poly->coeff_0 = tor->four;
  if (poly->coeff_0 != 1.0)
    {
      poly->coeff_1 = tor->three / poly->coeff_0;
      poly->coeff_2 = tor->two / poly->coeff_0;
      poly->coeff_3 = tor->one / poly->coeff_0;
      poly->coeff_4 = tor->zero / poly->coeff_0;
    }
  else
    {
      poly->coeff_1 = tor->three;
      poly->coeff_2 = tor->two;
      poly->coeff_3 = tor->one;
      poly->coeff_4 = tor->zero;
    }
  poly->coeff_1_2 = poly->coeff_1 * poly->coeff_1;
  poly->p = -0.375 * poly->coeff_1_2 + poly->coeff_2;
  poly->q = 0.125 * poly->coeff_1_2 * poly->coeff_1 - 0.5 * poly->coeff_1 *
    poly->coeff_2 + poly->coeff_3;
  poly->r = -0.01171875 * poly->coeff_1_2 * poly->coeff_1_2 + 0.0625 *
    poly->coeff_1_2 * poly->coeff_2 - 0.25 * poly->coeff_1 *
    poly->coeff_3 + poly->coeff_4;
}

void		fill_struct_for_cubic(t_poly *poly, t_tor *tor2)
{
  tor2->three = 1.0;
  tor2->two = -0.5 * poly->p;
  tor2->one = -poly->r;
  tor2->zero = 0.5 * poly->r * poly->p - 0.125 * poly->q * poly->q;
  tor2->n = 3;
}

int		delta_quartic(t_poly *poly)
{
  poly->delta_1 = 2.0 * poly->z - poly->p;
  if (poly->delta_1 < 0.0)
    {
      if (poly->delta_1 > -1.0e-10)
	poly->delta_1 = 0.0;
      else
	return (EXIT_FAILURE);
    }
  if (poly->delta_1 < 1.0e-10)
    {
      poly->delta_2 = poly->z * poly->z - poly->r;
      if (poly->delta_2 < 0.0)
	return (EXIT_FAILURE);
      poly->delta_2 = sqrt(poly->delta_2);
    }
  else
    {
      poly->delta_1 = sqrt(poly->delta_1);
      poly->delta_2 = 0.5 * poly->q / poly->delta_1;
    }
  poly->q_1 = poly->delta_1 * poly->delta_1;
  poly->q_2 = -0.25 * poly->coeff_1;
  return (EXIT_SUCCESS);
}

void		fill_root_quartic(t_poly *poly, double *result, int *i)
{
  poly->p = poly->q_1 - 4.0 * (poly->z - poly->delta_2);
  if (poly->p == 0)
    result[(*i)++] = -0.5 * poly->delta_1 - poly->q_2;
  else if (poly->p > 0)
    {
      poly->p = sqrt(poly->p);
      result[(*i)++] = -0.5 * (poly->delta_1 + poly->p) + poly->q_2;
      result[(*i)++] = -0.5 * (poly->delta_1 - poly->p) + poly->q_2;
    }
  poly->p = poly->q_1 - 4.0 * (poly->z + poly->delta_2);
  if (poly->p == 0)
    result[(*i)++] = 0.5 * poly->delta_1 - poly->q_2;
  else if (poly->p > 0)
    {
      poly->p = sqrt(poly->p);
      result[(*i)++] = 0.5 * (poly->delta_1 + poly->p) + poly->q_2;
      result[(*i)++] = 0.5 * (poly->delta_1 - poly->p) + poly->q_2;
    }
}

int		solve_quartic(double *result, t_tor *tor)
{
  int		i;
  t_tor		tor2;
  t_poly	poly;
  double	roots[3];

  calc_quartic_coeff(&poly, tor);
  fill_struct_for_cubic(&poly, &tor2);
  i = solve_cubic(roots, &tor2);
  if (i > 0)
    poly.z = roots[0];
  else
    return (0);
  if ((delta_quartic(&poly)) == 1)
    return (0);
  i = 0;
  fill_root_quartic(&poly, result, &i);
  return (i);
}
