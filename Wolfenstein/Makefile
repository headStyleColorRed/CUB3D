
SRCS			=	map/map_conforming.c \
					map/map_confoming_map.c \
					map/map_texture_parser.c \
					map/map_spaced_matrix.c \
					map/map_reader.c \
					map/map_matrix.c \
					map/map_rest_parser.c \
					map/map_parser.c \
					errors/errorManager.c \
					globals.c \
					main.c \
					libraries/get_next_line/get_next_line.c
OBJS			= $(SRCS:.c=.o)

NAME	= cub3D

GCC		= gcc

FLAGS	= -Wall -Wextra -Werror

INCLUDE	= -I minilibx

MLX_DIR		=	minilibx_opengl



all:	$(NAME)

.PHONY:	clean fclean re bonus bench bclean

$(NAME):	$(OBJS)
				@echo "\033[0;31m[Remove last version...]"
				@rm -rf Cub3D
				@echo "\033[0;35m[minilib compilation...]"
				$(MAKE) -C minilibx_opengl
				@echo "\033[0;36m[Libft compilation...]"
				$(MAKE) -C libraries/libft
				@echo "\033[0;33m[cub3D compilation...]"
				gcc ./libraries/libft/libft.a $(FLAGS) -o $(NAME) $(OBJS)  -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
				@echo "\033[0;31m[Deleting Objects...]"
				$(RM) *.o map/*.o
				@echo "\033[1;32m[* * * * * * * * * * * * * * * * * * * * * * *]"
				@echo "\033[1;32m[ C O M P I L E D  	S U C C E S F U L L Y]"
				@echo "\033[1;32m[* * * * * * * * * * * * * * * * * * * * * * *]"
				@./cub3D
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

%.o: %.c
	$(GCC) $(INCLUDE) -c $<  -o $(<:.c=.o)

run: all
	@./cub3d.out
