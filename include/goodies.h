/*
** goodies.h for goodies in /home/wallet_v/Dropbox/raytracer/wallet_v
**
** Made by valentin wallet
** Login   <wallet_v@epitech.net>
**
** Started on  Fri Jun  6 23:49:38 2014 valentin wallet
** Last update Sun Jun  8 05:27:45 2014 johan paasche
*/

#ifndef GOODIES_H_
#define GOODIES_H_

typedef struct          s_poly
{
  double                p;
  double                q;
  double                r;
  double                d;
  double                z;
  double                delta_1;
  double                delta_2;
  double                q_1;
  double                q_2;
  double                coeff_0;
  double                coeff_1;
  double                coeff_2;
  double                coeff_3;
  double                coeff_4;
  double                coeff_1_2;
}                       t_poly;

typedef struct          s_cubic
{
  double                Q;
  double                R;
  double                Q_3;
  double                R_2;
  double                sq;
  double                d;
  double                a_d_3;
  double                theta;
  double                coeff_0;
  double                coeff_1;
  double                coeff_2;
  double                coeff_3;
  double                coeff_1_2;
}                       t_cubic;

typedef	struct		s_tor
{
  double		zero;
  double		one;
  double		two;
  double		three;
  double		four;
  double	       	n;
}			t_tor;

int                     solve_quartic(double *, t_tor *);
double                  solve_cubic(double *, t_tor *);
double			normal_tore(t_ray *, t_obj *, t_spot *);
double			inter_tor(t_ray *, t_obj *);
double			normal_cube(t_ray *, t_obj *, t_spot *);
double			mini_k(double *, int);
double			cube_equation(t_ray *, t_obj *);
void			fill_tor_struct_normal(t_tor *tor, double *);
void			fill_tor_struct_one(t_tor *);

#endif /* GOODIES_H_ */
