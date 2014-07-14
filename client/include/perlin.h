/*
** perlin.h for rt in /home/tran_0/Dropbox/raytracer/paasch_j/MUL_2013_rtracer/client
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Sun Jun  8 21:46:56 2014 david tran
** Last update Sun Jun  8 21:57:06 2014 david tran
*/

#ifndef PERLIN_H_
# define PERLIN_H_

# define TAILLE 1000
# define OCTAVES 8
# define PAS 128
# define PERSISTANCE 0.5

double		bruit2D(int i, int j, t_n2D *N2D);
double		fonction_bruit2D(double x, double y, t_n2D *N2D);
double		bruit_coherent2D(double x, double y, t_n2D *N2D);
int		initBruit2D(t_n2D *N2D);
int		get_color_alias(double red, double green, double blue);
double		interpolation_cos1D(double a, double b, double x);
double		interpolation_cos2D(t_dble *stdb, double x, double y);
int		perlin_noise(t_rt_client *mlx);
int		perlin_color(t_rt_client *, t_ray *, t_obj *);
int		init_func_perlin(t_rt_client *rt);

#endif /* !PERLIN_H_ */
