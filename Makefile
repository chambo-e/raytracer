##
## Makefile for raytracer in /home/paasch_j/Dropbox/raytracer/paasch_j/raytracer
## 
## Made by johan paasche
## Login   <paasch_j@epitech.net>
## 
## Started on  Thu May 22 15:03:31 2014 johan paasche
## Last update Sun Jul 13 22:30:24 2014 chambon emmanuel
##

NAME		= raytracer

CC		= gcc -fopenmp -g

RM		= rm -f

LIBDST		= libmlx

MLX		= -L$(LIBDST)/ -lmlx -L/usr/lib64/ -lXext -lpthread -lX11

MATH		= -lm

LIB		= $(MLX)	\
		  $(MATH)	\

CFLAGS		=  -W -Wall -Wextra -ansi -pedantic -std=c99 -D_POSIX_SOURCE -I$(INCLUDES)

BINDST		= bin

OBJDST		= obj

INCLUDES	= include

DATABANK	= databank

SRCDST		= src

COLOR		= "\033[35m"

GREEN		= "\033[32m"

COLOR_OFF	= "\033[0m"

ECHO		= echo -e

CAT		= cat

LINK		= ln -fs

INIT_DST	= init

BASE_DST	= base

OBJECTS_DST	= objects

LIGHT_DST	= light

SCENE_DST	= scene

IMAGE_DST	= image

CLUSTER_DST	= cluster

DEBUG_DST	= debug

TEXTUR_DST	= textur

APP_DST		= app

INIT_SRCS	      =	main.c				\
			init_struct.c			\
			print_usage.c			\
			free_rt.c			\
			open_get_file.c			\
			lines_c.c			\
			obj_c.c				\
			spot_c.c			\
			set_eye.c			\
			set_window.c			\
			set_opt.c			\
			set_obj.c			\
			set_spot.c			\
			set_misc.c			\
			set_client.c			\
			init_mlx.c			\
			handle_key.c			\
			break_loop.c			\
			equation_array.c		\
			handle_redraw.c			\

BASE_SRCS	      =	strlen_tab.c			\
			print_error.c			\
			my_str_to_wordtab.c		\
			free_tab.c			\
			my_putchar.c			\
			epur_str.c			\
			my_putstr.c			\
			get_next_line.c			\
			my_xmalloc.c			\

OBJECTS_SRCS   	      =	plane.c				\
			sphere.c			\
			cylinder.c			\
			cone.c				\
			k_calcul.c			\
			tore.c				\
			cube_troue.c			\
			calc_cubic.c			\
			calc_quartic.c			\

LIGHT_SRCS	      =	lighting.c			\
			shadows.c			\

SCENE_SRCS	      =	scene.c				\
			rotation.c			\
			filtre.c			\
		 	rainbow.c			\
			draw_image.c			\
			aliasing.c			\

IMAGE_SRCS	      =	output_ppm.c			\
			output_bmp.c			\
			handle_texture.c		\

CLUSTER_SRCS	      =	check_calculated.c		\
			client_c.c			\
			cluster.c			\
			divide_calc.c			\
			ipv4_support.c			\
			send_info.c			\
			send_objs.c			\
			send_opt.c			\
			send_spots.c			\

TEXTUR_SRCS	      = perlin2D.c			\
			perlin_init.c			\
			perlin_inter.c			\
			perlin_pixel.c			\

APP_SRCS	      = connect_app.c			\
			parse_received.c		\
			gyroscope.c			\
			parse_obj.c			\
			parse_spot.c			\
			init_app.c			\
			handle_list.c			\

SRC_FILES	      = $(INIT)				\
			$(BASE)				\
			$(OBJECTS)			\
			$(LIGHT)			\
			$(SCENE)			\
			$(IMAGE)			\
			$(CLUSTER)			\
			$(TEXTUR)			\
			$(APP)				\

INIT		= 	$(addprefix $(INIT_DST)/, $(INIT_SRCS))

BASE		= 	$(addprefix $(BASE_DST)/, $(BASE_SRCS))

OBJECTS		= 	$(addprefix $(OBJECTS_DST)/, $(OBJECTS_SRCS))

LIGHT		= 	$(addprefix $(LIGHT_DST)/, $(LIGHT_SRCS))

IMAGE		= 	$(addprefix $(IMAGE_DST)/, $(IMAGE_SRCS))

SCENE		= 	$(addprefix $(SCENE_DST)/, $(SCENE_SRCS))

CLUSTER		= 	$(addprefix $(CLUSTER_DST)/, $(CLUSTER_SRCS))

TEXTUR		=	$(addprefix $(TEXTUR_DST)/, $(TEXTUR_SRCS))

APP		=	$(addprefix $(APP_DST)/, $(APP_SRCS))

SRCS		= 	$(addprefix $(SRCDST)/, $(SRC_FILES))

PRO		= 	$(addprefix $(BINDST)/, $(NAME))

OBJS		= 	$(addsuffix .o, $(basename $(subst $(SRCDST), $(OBJDST), $(SRCS))))

FIRST		:= 	$(shell test -d $(BINDST)		 || mkdir $(BINDST))			\
			$(shell test -d $(OBJDST)                || mkdir $(OBJDST))			\
		 	$(shell test -d $(OBJDST)/$(INIT_DST)    || mkdir $(OBJDST)/$(INIT_DST))	\
		 	$(shell test -d $(OBJDST)/$(BASE_DST)    || mkdir $(OBJDST)/$(BASE_DST))	\
		 	$(shell test -d $(OBJDST)/$(LIGHT_DST)   || mkdir $(OBJDST)/$(LIGHT_DST))	\
		 	$(shell test -d $(OBJDST)/$(SCENE_DST)   || mkdir $(OBJDST)/$(SCENE_DST))	\
		 	$(shell test -d $(OBJDST)/$(IMAGE_DST)   || mkdir $(OBJDST)/$(IMAGE_DST))	\
		 	$(shell test -d $(OBJDST)/$(DEBUG_DST)   || mkdir $(OBJDST)/$(DEBUG_DST))	\
		 	$(shell test -d $(OBJDST)/$(CLUSTER_DST) || mkdir $(OBJDST)/$(CLUSTER_DST))	\
		 	$(shell test -d $(OBJDST)/$(TEXTUR_DST)  || mkdir $(OBJDST)/$(TEXTUR_DST))	\
		 	$(shell test -d $(OBJDST)/$(OBJECTS_DST) || mkdir $(OBJDST)/$(OBJECTS_DST))	\
		 	$(shell test -d $(OBJDST)/$(APP_DST)	 || mkdir $(OBJDST)/$(APP_DST))		\

$(NAME)		:	$(PRO)
		 	@$(LINK) $(PRO) $(NAME)
		 	@$(ECHO) -n $(GREEN) 
		 	@$(ECHO) -n $(COLOR_OFF)

$(OBJDST)/%.o	:	$(SRCDST)/%.c
		  	@$(ECHO) -n $(COLOR)
		 	$(CC) $(CFLAGS) $(LIB) -c $< -o $@
		  	@$(ECHO) -n $(COLOR_OFF)

$(PRO)		: 	$(OBJS)
		  	@$(ECHO) $(GREEN)
		  	$(CC) $(CFLAGS) $(OBJS) -o $(PRO) $(LIB)
		  	@$(ECHO) $(COLOR_OFF)

all		: 	$(NAME)

clean		:
		  	@$(RM)   $(OBJS)
		  	@$(ECHO) "\nDeleting Objs"

fclean		: 	clean
		  	@$(RM)   $(PRO)
		  	@$(RM)   $(NAME)
		  	@$(ECHO) "Deleting binary"

re		: 	fclean all

.PHONY		: 	all clean fclean re
