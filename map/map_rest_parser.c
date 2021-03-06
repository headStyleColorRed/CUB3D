
#include "../library.h"

/*
	parse_north_texture() ->
			1. Gets the raw string with the values we need
			2. Splits the line in three and assignes the 1º field to the texture
			3. It saves the texture in the map struct
 */

int		ft_number_of_occurrences(const char *string, const char character)
{
	int repetitions;
	int i;

	i = 0;
	repetitions = 0;
	while (string[i])
		if(string[i++] == character)
			repetitions++;
	return repetitions;
}

void	check_splitted_fields(char **splitted_fields, int number_of_fields)
{
	if (number_of_fields != 2 && number_of_fields != 3)
		print_error("Wrong number of fields on resolution or ceiling");
	if (number_of_fields == 2)
		if(!splitted_fields[1] || !splitted_fields[2])
			print_error("Resolution fields missing");
	if (number_of_fields == 3)
	{
		if(!splitted_fields[0] || !splitted_fields[1] || !splitted_fields[2])
			print_error("Ceiling/Floor colors fields missing");
		does_rgb_color_contain_alpha(splitted_fields);
		is_rgb_color_number_offlimits(splitted_fields);
	}
}

void	parse_resolution(char *raw_map, t_map *map)
{
	char *resolutions;
	char **splitted_resolutions;

	resolutions = parse_character(raw_map, map_textures(RESOLUTION));
	if (!resolutions)
		print_error("Resolutions field not found.");
	check_if_resolution_is_ok(resolutions);
	splitted_resolutions = ft_split(resolutions, ' ');
	check_splitted_fields(splitted_resolutions, 2);
	map->resolution.height = ft_atoi(splitted_resolutions[1]);
	map->resolution.width = ft_atoi(splitted_resolutions[2]);
}

void	parse_floor_color(char *raw_map, t_map *map)
{
	char *floor_line;
	char **splitted_floor_line;
	char **splitted_floor_colors;

	floor_line = parse_character(raw_map, map_textures(FLOOR));
	if (!floor_line)
		print_error("floor color field not found.");
	if (ft_number_of_occurrences(floor_line, ',') > 2)
		print_error("Two many commas in Floor field");
	check_if_floor_ceiling_is_ok(floor_line);
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
	if (ft_number_of_occurrences(ceiling_line, ',') > 2)
		print_error("Two many commas in Ceiling field");
	check_if_floor_ceiling_is_ok(ceiling_line);
	splitted_ceiling_line = ft_split(ceiling_line, ' ');
	splitted_ceiling_colors = ft_split(splitted_ceiling_line[1], ',');
	check_splitted_fields(splitted_ceiling_colors, 3);
	map->ceiling_color.r_color = ft_atoi(splitted_ceiling_colors[0]);
	map->ceiling_color.g_color = ft_atoi(splitted_ceiling_colors[1]);
	map->ceiling_color.b_color = ft_atoi(splitted_ceiling_colors[2]);
}

void	check_map_is_last_field(t_map *map)
{
	int		i;

	i = ft_strlen(map->map) - 1;


		if (map->map[i] != '1')
			print_error("Map ending is not correct");
}
