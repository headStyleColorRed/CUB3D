
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

CC				= gcc
RM				= rm -f 
CFLAGS			= -Wall -Wextra -Werror

NAME			= cub3D

all:			$(NAME)

$(NAME):		$(OBJS)
				@echo "\033[0;31m[Remove last version...]"
				@rm -rf Cub3D
				@echo "\033[0;36m[Libft compilation...]"
				$(MAKE) -C libraries/libft
				@echo "\033[0;33m[cub3D compilation...]"
				gcc  ./libraries/libft/libft.a  ${CFLAGS} -o ${NAME} ${OBJS} 
				@echo "\033[0;31m[Deleting Objects...]"
				$(RM) *.o map/*.o
				@echo "\033[1;32m[* * * * * * * * * * * * * * * * * * * * * * *]"
				@echo "\033[1;32m[ C O M P I L E D  	S U C C E S F U L L Y]"
				@echo "\033[1;32m[* * * * * * * * * * * * * * * * * * * * * * *]"


fclean:			clean
				$(RM) *.o map/*.o

re:				fclean $(NAME)