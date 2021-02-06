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

void	check_wall_textures_are_ok(char * line, t_map_parser orientation)
{
	int i;

	i = ft_strlen(line) - 1;
	if (line[i] != 'm' && line[i - 1] != 'p' && line[i - 2] != 'x')
	{
		if (orientation == NORTH)
			print_error("North texture ending doesn't have valid characters xpm");
		else if (orientation == SOUTH)
			print_error("South texture ending doesn't have valid characters xpm");
		else if (orientation == WEST)
			print_error("West texture ending doesn't have valid characters xpm");
		else if (orientation == EAST)
			print_error("East texture ending doesn't have valid characters xpm");
		else if (orientation == SPRITE)
			print_error("Sprite texture ending doesn't have valid characters xpm");
		else
			print_error("Unknown error on textures .xpm extension characters");
	}
}
