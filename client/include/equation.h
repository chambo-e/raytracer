/*
** equation.h<2> for rt in /home/tran_0/Dropbox/raytracer/chambo_e/link_folder/client
**
** Made by david tran
** Login   <tran_0@epitech.net>
**
** Started on  Sat Jun  7 23:25:46 2014 david tran
** Last update Wed Jun 18 01:05:00 2014 johan paasche
*/

#ifndef EQUATION_H_
# define EQUATION_H_

double		find_k(double, double, double);

void		init_tab(double[], double, int);

double		(**set_equation_array())();
double		(**set_normale_array())();

int		set_fct_ptr(t_obj *, int);

double		plane_equation(t_ray *, t_obj *);
double		sphere_equation(t_ray *, t_obj *);
double		cylinder_equation(t_ray *, t_obj *);
double		cone_equation(t_ray *, t_obj *);
double		tore_equation(t_ray *, t_obj *);
double		cube_equation(t_ray *, t_obj *);

double		plane_normale(t_ray *, t_obj *, t_spot *);
double		sphere_normale(t_ray *, t_obj *, t_spot *);
double		cylinder_normale(t_ray *, t_obj *, t_spot *);
double		cone_normale(t_ray *, t_obj *, t_spot *);
double		tore_normale(t_ray *, t_obj *, t_spot *);
double		cube_normale(t_ray *, t_obj *, t_spot *);

void		lighting(t_ray *, t_obj *, t_spot *);

#endif /* !EQUATION_H_ */
