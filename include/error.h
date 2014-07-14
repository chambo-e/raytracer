/*
** error.h for RT in /home/chambo_e/Dropbox/raytracer/chambo_e
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Fri Apr 18 22:35:02 2014 chambon emmanuel
** Last update Wed Jun 11 17:42:27 2014 chambon emmanuel
*/

#ifndef ERROR_H_
# define ERROR_H_

# define WRONG_EXTENSION		"A \"*.conf\" is expected.\n"
# define NO_FILE			" : No such file.\n"
# define WR_ARG_WINDOW			"Wrong arguments for WINDOW\
					variable.\n"
# define WR_WINX			"Invalid parameter for\
					 WINDOW.winsize_x.\n"
# define WR_WINY			"Invalid parameter for\
					WINDOW.winsize_y.\n"
# define MULTIDEF_WINDOW		"WINDOW is defined more than once.\n"
# define NO_WINDOW			"No WINDOW has been defined.\n"
# define MULTIDEF_EYE			"EYE_POS is defined more than once.\n"
# define WR_ARG_EYE_POS			"Wrong Argument for EYE_POS\
					variable.\n"
# define NO_EYE_POS	      		"No EYE_POS has been defined. EYE_POS\
					is mandatory.\n"
# define MULTIDEF_EYE_ROT		"EYE_ROT is defined more than once.\n"
# define WR_ARG_EYE_ROT			"Wrong Argument for EYE_ROT\
					variable.\n"
# define NO_EYE_ROT	      		"No EYE_ROT has been defined. EYE_ROT\
					is mandatory.\n"
# define MULTIDEF_AA			"AA (AntiAliasing) is defined\
					 more than once.\n"
# define WRONG_AA			"AntiAliasing (AA) must be 0 or 1\n"
# define MULTIDEF_TEXTURE		"TEXTURE is defined more than once.\n"
# define MULTIDEF_IMG			"IMAGE is defined more than once.\n"
# define WRONG_3D			"3D must be 0 or 1\n"
# define MULTIDEF_FILTER		"FILTER is defined more than once.\n"
# define WRONG_FILTER			"FILTER must be <= 3\n"
# define WR_ARG_SPOT			"Wrong arguments for SPOT variable.\n"
# define MISSING_SEP			"\":\" is missing\n"
# define COL_VALUE_MAX			"Color value must be <= 255 and >= 0\n"
# define WR_TYPE			"Object type is unknow\n"
# define WR_POS				"Wrong argument for object position\n"
# define WR_ROT				"Wrong argument for object rotation\n"
# define WR_COL				"Wrong argument for object color\n"
# define WR_MISC			"Wrong argument for object misc\n"
# define WR_AR				"Wrong argument for object rayon\
					 or angle\n"
# define NO_MLX				"Can't initiate mlx. Please check\
					 your env\n"
# define WRONG_FILE			"Format unrecognized, supported\
					formats are \".ppm\" an \".bmp\"\n"
# define CLIENT_MISSING			"Client hostname or IP is missing\n"
# define UNKNOW_HOST			"Client hostname or IP is unknow\n"
# define INVALID_ADRESS			"Can't reach client. Please check\
					it adress\n"
# define MALLOC_ERROR			"Can't perform malloc\n"
# define THREAD_ERROR			"Unable to create thread for %s.\
					Connection is skipped\n"
# define THREAD_APP			"Unable to create thread for application. It will not be available\n"
# define LIGHT_MAX			"Lights must be < %d\n"
# define WR_TRANSP			"Transparency must be > 0 and < 1\n"
# define WR_BRILL			"Brilliance must be > 0 and < 1\n"
# define WR_REFLEX			"Reflexion must be 0 or 1\n"
# define WR_SPECIAL			"Effect must be > -2147483647\
					and < 2147483646\n"
# define NO_TEXTURE			"Texture file not found. It will\
					 not be applied\n"
# define WRONG_PPM			"PPM file texture is not valid.\
					 It will not be applied\n"
# define SOCK_ERROR			"socket : %s on test n°%d on %s\n"
# define CONNECT_ERROR			"connect : %s on test n°%d on %s\n"
# define UNREACH			"%s unreachable -> skipped\n"
# define WR_TEXTURE			"TEXTURE type must be > 0 and < 3\n"
# define IMG_TEXTURE			"TEXTURE and IMAGE cannot be both\
					 applied.\n"

#endif /* ERROR_H_ */
