/*
** equation.h for raytracer in /home/paasch_j/Dropbox/raytracer/paasch_j/raytracer
**
** Made by johan paasche
** Login   <paasch_j@epitech.net>
**
** Started on  Thu May 22 23:27:29 2014 johan paasche
** Last update Sun Jun  8 06:32:27 2014 johan paasche
*/

#ifndef		EQUATION_H_
# define	EQUATION_H_

# include	"struct.h"
# include	"goodies.h"

# define	LOW	0.000001

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

# endif		/*!EQUATION_H_*/
