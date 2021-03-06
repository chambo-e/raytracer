/*
** struct.h for RT in /home/chambo-e/Dropbox/epitech/raytracer/chambo_e/conf_file
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Wed May 14 22:01:56 2014 chambon emmanuel
** Last update Sat Jul  5 21:14:22 2014 chambon emmanuel
*/

#ifndef STRUCT_H_
# define STRUCT_H_

/*
**			STRUCTURES | TYPEDEF
*/

typedef unsigned int	colour;

typedef union		u_color
{
  unsigned int		color;
  unsigned char	       	rgba[4];
}			t_color;

typedef struct		s_opt
{
  double		eye_pos[3];
  double		eye_rot[3];
  char			texture;
  char			aa;
  char			filter;
}			t_opt;

typedef struct		s_spot
{
  char			type;
  double		pos[3];
  t_color		*color;
  struct s_spot		*next;
  struct s_spot		*previous;
}			t_spot;

typedef struct          s_ray
{
  double                eye[3];
  double                p1[3];
  double                v[3];
  double                k;
  t_color		*color;
  double		x;
  double  		y;
}			t_ray;

typedef struct		s_obj
{
  char			type;
  double		obj_pos[3];
  double		obj_rot[3];
  double                (*k)(t_ray *, struct s_obj *);
  double                (*cos)(t_ray *, struct s_obj *, t_spot *);
  double		special;
  double		rayon;
  double		angle;
  t_color		*color;
  double		brill;
  char			texture;
  struct s_obj		*next;
  struct s_obj		*previous;
}			t_obj;

typedef	struct		s_parse
{
  char			*line;
  struct s_parse	*next;
}			t_parse;

typedef struct		s_img
{
  void			*mlx;
  void			*img;
  void			*win;
  char			*data;
  int			size;
  int			bpp;
  int			end;
}			t_img;

typedef struct		s_client
{
  struct addrinfo	*servinfo;
  char			*service;
  char			*hostname;
  int			beg;
  int			end;
  struct s_client	*next;
}			t_client;

typedef struct		s_n2D
{
  int			len_max;
  int			high_max;
  double		*vals;
}			t_n2D;

typedef struct		s_dble
{
  double		a;
  double		b;
  double		c;
  double		d;
}			t_dble;

typedef struct	        s_rt
{
  int			winsize_x;
  int			winsize_y;
  int			beg;
  int			end;
  char			*save;
  int			cluster;
  t_opt			*eye;
  t_obj			*objs;
  t_spot		*spot;
  t_img			*img;
  t_n2D			N2D;
  t_client		*client;
}			t_rt;

int			get_pixel_wood(t_rt *mlx, t_ray *ray);
int			get_pixel_marbr(t_rt *mlx, t_ray *ray);
int			get_pixel(t_rt *mlx, t_ray *ray);
int			get_pixel_sky(t_rt *mlx, t_ray *ray);

typedef struct		s_perlin
{
  int			(*pixel)(t_rt *rt, t_ray *ray);
}			t_perlin;

extern t_perlin		pertext[];

typedef struct		s_arg_thread
{
  t_rt			*rt;
  t_client		*client;
}			t_arg_thread;

typedef struct		s_send
{
  char			*limit;
  char			*eye;
  char			*spot;
  char			*obj;
}			t_send;

# endif /* STRUCT_H_ */
