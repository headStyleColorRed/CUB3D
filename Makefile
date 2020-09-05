SRCS			=	map/map_conforming.c \
					map/map_confoming_map.c \
					map/map_texture_parser.c \
					map/map_spaced_matrix.c \
					map/map_reader.c \
					map/map_matrix.c \
					map/map_rest_parser.c \
					map/map_parser.c \
					map/map_converting_map.c \
					engine/engine_movement.c \
					engine/engine_game.c \
					engine/engine_raycast.c \
					errors/errorManager.c \
					game/game.c \
					globals.c \
					main.c \
					libraries/get_next_line/get_next_line.c
OBJS			= $(SRCS:.c=.o)

NAME	= 	cub3D

FLAGS	= -Wall -Werror -Wextra -g

GCC = gcc

INCLUDE	= -I minilibx

MLX_DIR		=	libraries/minilibx_opengl

all:	$(NAME)

$(NAME):	$(OBJS)
				@echo "\033[0;31m[Remove last version...]"
			@rm -rf Cub3D
				@echo "\033[0;35m[minilib compilation...]"
			$(MAKE) -C libraries/minilibx_opengl
				@echo "\033[0;36m[Libft compilation...]"
			$(MAKE) -C libraries/libft
				@echo "\033[0;33m[cub3D compilation...]"
			$(GCC) ./libraries/libft/libft.a  $(OBJS) -o $(NAME) -L $(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
				@echo "\033[1;32m[* * * * * * * * * * * * * * * * * * * * * * *]"
				@echo "\033[1;32m[ C O M P I L E D  	S U C C E S F U L L Y]"
				@echo "\033[1;32m[* * * * * * * * * * * * * * * * * * * * * * *]"

%.o: %.c
	$(GCC) $(FLAGS) $(INCLUDE) -c $<  -o $(<:.c=.o)

fclean: clean
	rm -f $(NAME)

clean : 
		@echo "\033[0;31m[Deleting Objects...]"
	$(RM) $(OBJS) map/*.o engine/*.o game/*.o

re:				fclean $(NAME)