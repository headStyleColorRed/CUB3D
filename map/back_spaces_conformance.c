#include "../library.h"

void	check_if_resolution_is_ok(char *line)
{
	int		i;
	int		spaces;

	i = 1;
	spaces = 0;
	if (line[i++] != ' ')
		print_error("Resolution field has no space after parameter");
	while (line[i] != '\0' && ft_isalnum(line[i]) == 1)
		i++;
	while (line[i] != '\0' && line[i] == ' ')
		i++;
	while (line[i] != '\0' && ft_isalnum(line[i]) == 1)
		i++;

	if(line[i] != '\0')
		print_error("Resolution map line has invalid characters at line's end");
}

void	check_if_floor_ceiling_is_ok(char *line)
{
	int		i;
	int		spaces;

	i = 1;
	spaces = 0;
	if (line[i++] != ' ')
		print_error("Floor/Ceiling field has no space after parameter");
	while (line[i] != '\0' && (ft_isalnum(line[i]) == 1 || line[i] == ','))
		i++;

	if(line[i] != '\0')
		print_error("Floor/Ceiling map line has invalid characters at line's end");
}

void wall_textures_checker_error(char *error, t_map_parser orientation)
{
	if (orientation == NORTH)
		print_error(ft_strjoin("North", error));
	else if (orientation == SOUTH)
		print_error(ft_strjoin("South", error));
	else if (orientation == WEST)
		print_error(ft_strjoin("West", error));
	else if (orientation == EAST)
		print_error(ft_strjoin("East", error));
	else if (orientation == SPRITE)
		print_error(ft_strjoin("Sprite", error));
	else
		print_error("Unknown error on textures .xpm extension characters");
}

void	check_wall_textures_are_ok(char * line, t_map_parser orientation)
{
	int i;

	i = 2;
	while (line[i++] != '\0')
		if (line[i] == ' ' && line[i - 1] != '\\')
			wall_textures_checker_error(" texture has forbidden spaces on it's string", orientation);

	i = ft_strlen(line) - 1;
	if (line[i] != 'm' && line[i - 1] != 'p' && line[i - 2] != 'x')
		wall_textures_checker_error("texture ending doesn't have valid characters xpm", orientation);
}
