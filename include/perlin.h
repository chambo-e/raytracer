/*
** perlin.h for rt in /home/tran_0/Dropbox/raytracer/paasch_j/MUL_2013_rtracer/src/textur
** 
** Made by david tran
** Login   <tran_0@epitech.net>
** 
** Started on  Sun Jun  8 16:00:55 2014 david tran
** Last update Sun Jun  8 21:47:59 2014 david tran
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
int		get_pixel_wood(t_rt *mlx, t_ray *ray);
int		get_pixel_marbr(t_rt *mlx, t_ray *ray);
int		get_pixel(t_rt *mlx, t_ray *ray);
int		get_pixel_sky(t_rt *mlx, t_ray *ray);
double		interpolation_cos1D(double a, double b, double x);
double		interpolation_cos2D(t_dble *stdb, double x, double y);
int		perlin_noise(t_rt *mlx);
int		perlin_color(t_rt *, t_ray *, t_obj *);
int		init_func_perlin(t_rt *rt);

#endif /* !PERLIN_H_ */
