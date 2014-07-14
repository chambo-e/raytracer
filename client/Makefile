##
## Makefile for RT in /home/chambo_e/Dropbox/raytracer/chambo_e
## 
## Made by chambon emmanuel
## Login   <chambo_e@epitech.net>
## 
## Started on  Fri Apr 18 17:01:12 2014 chambon emmanuel
## Last update Wed Jun 18 01:06:05 2014 johan paasche
##

CC		=	gcc -fopenmp -g

RM		=	rm -f

INCLUDE		=	include/

CFLAGS		=	-W -Wall -Wextra -ansi -pedantic -I$(INCLUDE) -D_POSIX_C_SOURCE

SRC_F		=	src/

BASE_F		=	base/

SRC		=	$(SRC_F)main.c					\
			$(SRC_F)init_client.c				\
			$(SRC_F)plane.c					\
			$(SRC_F)scene.c					\
			$(SRC_F)shadows.c				\
			$(SRC_F)sphere.c				\
			$(SRC_F)print_usage.c				\
			$(SRC_F)k_calcul.c				\
			$(SRC_F)check_calculated.c			\
			$(SRC_F)cone.c					\
			$(SRC_F)tore.c					\
			$(SRC_F)calc_quartic.c				\
			$(SRC_F)calc_cubic.c				\
			$(SRC_F)cube_troue.c				\
			$(SRC_F)equation_array.c			\
			$(SRC_F)lighting.c				\
			$(SRC_F)aliasing.c				\
			$(SRC_F)pxl.c					\
			$(SRC_F)perlin2D.c				\
			$(SRC_F)perlin_init.c				\
			$(SRC_F)perlin_inter.c				\
			$(SRC_F)perlin_pixel.c				\
			$(SRC_F)obj_c.c					\
			$(SRC_F)cylinder.c				\
			$(SRC_F)rotation.c				\
			$(SRC_F)decrypt.c				\
			$(SRC_F)rainbow.c				\
			$(SRC_F)set_eye.c				\
			$(SRC_F)set_spot.c				\
			$(SRC_F)set_objs.c				\
			$(SRC_F)free_rt_client.c			\
			$(SRC_F)send_response.c				\
			$(SRC_F)$(BASE_F)my_str_to_wordtab.c		\
			$(SRC_F)$(BASE_F)my_xmalloc.c			\

OBJ		=	$(SRC:.c=.o)

NAME		=	raytracer_client


$(NAME)		:	$(OBJ)
			@$(CC) $(OBJ) -o $(NAME) -lm
			@echo ""
			@echo "Client compiled"


all		:	$(NAME)

clean		:
			@$(RM) $(OBJ)

fclean		:	clean
			@$(RM) $(NAME)

re		:	fclean all
