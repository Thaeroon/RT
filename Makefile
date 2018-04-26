# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/07 16:48:28 by nmuller           #+#    #+#              #
#    Updated: 2018/04/26 23:32:54 by pbeller          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


##############
# PARAMETERS #
##############

# directories
LIB_PATH = libs
SRC_PATH = srcs
OBJ_PATH = obj


# compiler flags
CC = clang
CFLAGS = -Werror -Wall -Wextra -Iinc
LFLAGS = -I $(LIB_PATH)/libtowel/includes -I $(LIB_PATH)/minilibx_macos -I includes

# linker flags
LKFLAGS =  -L$(LIB_PATH)/minilibx_macos -lmlx -framework OpenGL -framework AppKit \
			-L$(LIB_PATH)/libtowel -ltowel -lm -lpthread

# libs
LIB = $(LIB_PATH)/libtowel/libtowel.a $(LIB_PATH)/minilibx_macos/libmlx.a

# files
SRC_FILES =	camera/build_camera_from_dict.c\
			camera/camera_del.c\
			camera/camera_new.c\
			camera/camera_print.c\
			camera/init_camera.c\
			env/env_del.c\
			env/env_fill.c\
			env/env_fill2.c\
			env/env_new.c\
			env/env_print.c\
			light/add_light_to_list_from_dict.c\
			light/build_light_from_dict.c\
			light/light_del.c\
			light/light_new.c\
			light/light_print.c\
			light/lights_del.c\
			light/lights_print.c\
			main.c\
			object/add_object_to_list_from_dict.c\
			object/build_object_from_dict.c\
			object/object_del.c\
			object/object_new.c\
			object/object_print.c\
			object/objects_del.c\
			object/objects_print.c\
			render/image.c\
			render/recursion.c\
			render/render.c\
			render/rotate_cam.c\
			render/save.c\
			render/texture.c\
			render/thread.c\
			render/translate_cam.c\
			scatter/scatter.c\
			scatter/scatter_dielectric.c\
			scatter/scatter_lamberian.c\
			scatter/scatter_metal.c\
			shape/cone.c\
			shape/cone_coup.c\
			shape/cone_neg.c\
			shape/cube.c\
			shape/cube_neg.c\
			shape/cylindre.c\
			shape/cylindre_neg.c\
			shape/object_hit.c\
			shape/plan.c\
			shape/rectangle.c\
			shape/sphere.c\
			shape/sphere_coup.c\
			shape/sphere_neg.c\
			shape/tube.c\
			transformation/cut.c\
			transformation/cut2.c\
			transformation/rotation.c\
			transformation/translation.c\
			utils/dict_get_with_default.c\
			utils/read_raw_input.c\
			vector/vector_operations.c\
			vector/vector_transfo.c\
			xopt/xopt_check_valid_opts.c\
			xopt/xopt_del.c\
			xopt/xopt_init.c\
			xopt/xopt_new.c\
			xopt/xopt_singleton.c


# executable name
NAME = RT

##############
# PROCESSING #
##############

# variables
OBJ_FILES = $(SRC_FILES:.c=.o)
SRC = $(addprefix $(SRC_PATH)/,$(SRC_FILES))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_FILES))

# rules
.PHONY: clean fclean re norme lib fcleanall
all: lib $(NAME)

$(NAME): $(OBJ) $(LIB)
	$(CC) $(OBJ) -o $(NAME) $(LKFLAGS)

lib:
	@make -C $(LIB_PATH)/libtowel
	@make -C $(LIB_PATH)/minilibx_macos

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(dir $@) 2> /dev/null || true
	$(CC) $(CFLAGS) $(LFLAGS) -o $@ -c $<

clean:
	@rm -fv $(OBJ)
	@rmdir -v $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	@rm -fv $(NAME)

fcleanall: fclean
	@make fclean -C $(LIB_PATH)/libtowel
	@make clean -C $(LIB_PATH)/minilibx_macos

re: fclean all

norme:
	norminette $(SRC)
	norminette $(INC_PATH)*.h
