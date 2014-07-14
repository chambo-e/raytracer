/*
** rt.h for RT in /home/chambo-e/Dropbox/epitech/raytracer/chambo_e/conf_file
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Wed May 14 21:59:15 2014 chambon emmanuel
** Last update Fri Jul  4 23:32:31 2014 chambon emmanuel
*/

#ifndef RT_H_
# define RT_H_

# include <stdio.h>
# include <unistd.h>
# include <stddef.h>
# include <fcntl.h>
# include <stdlib.h>
# include <omp.h>
# include <string.h>
# include <strings.h>
# include <stdint.h>
# include <netdb.h>
# include <sys/types.h>
# include <netinet/in.h>
# include <sys/socket.h>
# include <arpa/inet.h>
# include <pthread.h>
# include <errno.h>
# include <limits.h>
# include <math.h>
# include <sys/stat.h>

# include "conf.h"
# include "struct.h"
# include "output.h"
# include "base.h"
# include "server.h"
# include "equation.h"
# include "mlx.h"
# include "goodies.h"
# include "perlin.h"
# include "app.h"

# define        X               0
# define        Y               1
# define        Z               2
# define        PI              3.141592653589793238
# define        TWO_PI          6.283185207179586476925286766560
# define        TWO_PI_3        2.0943951023931954923084
# define        TWO_PI_43       4.1887902047863909846168
# define	ESCAPE_KEY	65307
# define	WINX		rt->winsize_x
# define	WINY		rt->winsize_y

# define	UNUSED		__attribute__((unused))

int		handle_key(int, t_rt *);
int		init_mlx(t_rt *);
int		mlx_node(t_rt *);
int		check_calculated(char *, t_rt *);
void		init_ray(t_rt *, t_ray *, int, int);
void		assign_ray(t_rt *, t_ray *, t_obj *);
t_obj		*cast_ray(t_ray *, t_obj *, t_obj *);
int		cast_a_ray_alias(t_rt *, int, int);
void		divide_calc(t_rt *, int, int);
void		break_loop(t_rt *);
colour          new_color(t_color *, double);
colour          shining(t_color *, t_color *, double, double);
colour          get_the_scene(t_rt *, int , int);
colour          shadows(t_rt *, t_ray *, t_obj *);
void            put_pxl(t_img *, t_color);
int		draw_image(t_rt *);
void            x_rotation(t_ray *, t_obj *);
void            y_rotation(t_ray *, t_obj *);
void            z_rotation(t_ray *, t_obj *);
void		filter(t_rt *);

#endif	/* !RT_H_ */
