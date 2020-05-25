
#include "../library.h"

/*
	parse_north_texture() ->
			1. Gets the raw string with the values we need
			2. Splits the line in three and assignes the 1º field to the texture
			3. It saves the texture in the map struct
 */

void	check_splitted_fields(char **splitted_fields, int number_of_fields)
{
	if (number_of_fields == 2)
		if(!splitted_fields[1] || !splitted_fields[2])
			print_error("Resolution fields missing");
	
	if (number_of_fields == 3)
		if(!splitted_fields[0] || !splitted_fields[1] || !splitted_fields[2])
			print_error("Ceiling/Floor colors fields missing");
}

void	parse_resolution(char *raw_map, t_map *map)
{
	char *resolutions;
	char **splitted_resolutions;
	
	resolutions = parse_character(raw_map, map_textures(RESOLUTION));
	if (!resolutions)
		print_error("Resolutions field not found.");
	
	splitted_resolutions = ft_split(resolutions, ' ');
	check_splitted_fields(splitted_resolutions, 2);
	map->resolution.width = ft_atoi(splitted_resolutions[1]);
	map->resolution.length = ft_atoi(splitted_resolutions[2]);
	
}

void	parse_floor_color(char *raw_map, t_map *map)
{
	char *floor_line;
	char **splitted_floor_line;
	char **splitted_floor_colors;
	
	floor_line = parse_character(raw_map, map_textures(FLOOR));
	if (!floor_line)
		print_error("floor color field not found.");
	
	splitted_floor_line = ft_split(floor_line, ' ');
	splitted_floor_colors = ft_split(splitted_floor_line[1], ',');
	check_splitted_fields(splitted_floor_colors, 3);
	map->floor_color.r_color = ft_atoi(splitted_floor_colors[0]);
	map->floor_color.g_color = ft_atoi(splitted_floor_colors[1]);
	map->floor_color.b_color = ft_atoi(splitted_floor_colors[2]);
}

void	parse_ceiling_color(char *raw_map, t_map *map)
{
	char *ceiling_line;
	char **splitted_ceiling_line;
	char **splitted_ceiling_colors;
	
	ceiling_line = parse_character(raw_map, map_textures(CEILING));
	if (!ceiling_line)
		print_error("ceiling color field not found.");
	
	splitted_ceiling_line = ft_split(ceiling_line, ' ');
	splitted_ceiling_colors = ft_split(splitted_ceiling_line[1], ',');
	check_splitted_fields(splitted_ceiling_colors, 3);
	map->ceiling_color.r_color = ft_atoi(splitted_ceiling_colors[0]);
	map->ceiling_color.g_color = ft_atoi(splitted_ceiling_colors[1]);
	map->ceiling_color.b_color = ft_atoi(splitted_ceiling_colors[2]);
}



