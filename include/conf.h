/*
** conf.h for RT in /home/chambo_e/Dropbox/raytracer/chambo_e
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Fri Apr 18 17:11:05 2014 chambon emmanuel
** Last update Sun Jul 13 22:39:51 2014 chambon emmanuel
*/

#ifndef CONF_H_
# define CONF_H_

/*
**			INCLUDES
*/
# include "error.h"
# include "struct.h"
/*
**			DEFINES
*/
# define BUFF_SIZE	4096
# define COMMENT_CHAR	'#'
# define DEFINE_CHAR	':'
# define PARAM_CHAR	','
# define NORMAL_LIGHT	0
# define AMB_LIGHT	1
# define SPECUL_LIGHT	2
# define MAX_LIGHT	2
# define FILTER_NONE	0
# define FILTER_SEPIA	1
# define FILTER_BW	2
# define FILTER_NEG	3
# define FILTER_MAX	3
# define TEXTURE_MAX	4
# define PL		"PLAN"
# define SPH		"SPHERE"
# define CO		"CONE"
# define CYL		"CYLINDRE"
# define CT		"CUBE TROUE"
# define TO		"TORE"
# define PLAN_TYPE	1
# define SPHERE_TYPE	2
# define CONE_TYPE	3
# define CYLINDRE_TYPE	4
# define TORE_TYPE	5
# define CUBE_TYPE	6
/*
**			CONF PROTOTYPES
*/
int			init_struct(t_rt *, char *);
int			print_usage(char *);
t_parse			*parse_file(char *);
int			get_window(t_parse *, t_rt *);
int			get_eye(t_parse *, t_rt *);
int			get_opt(t_parse *, t_rt *);
int			add_line(t_parse *, char *);
void			init_lines(t_parse *);
int			get_spot(t_parse *, t_rt *);
int			check_define(int *, char *);
int			add_spot(char *, t_spot *);
int			get_obj(t_parse *, t_rt *);
int			set_color(t_color *, char **);
int			add_obj(t_parse *, t_obj *);
char			get_type(char *);
int			get_pos(char *, t_obj *);
int			get_rot(char *, t_obj *);
t_color			*get_color(char *);
int			get_misc(char *, t_obj *);
int			get_misc_bis(char *, t_obj *);
int			get_client(t_parse *, t_rt *);
int			get_rayon_angle(char *, t_obj *);
int			add_info_client(char *, t_client *, t_client *);
int			get_texture(t_parse *, t_rt *, int);
int			get_image(t_parse *, t_rt *, int);
int			check_texture_img(t_rt *);
double			(**init_fonction_array(int))();
double			(**set_equation_array())();
double			(**set_normale_array())();
int			set_fct_ptr(t_obj *, int);
int			redraw_callback(t_rt *);
void			render_image(t_rt *);
void			free_objs(t_obj *);
void			free_spot(t_spot *);

# endif /* CONF_H_ */
