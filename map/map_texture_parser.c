
#include "../library.h"

/*
	parse_north_texture() ->
			1. Gets the raw string with the values we need
			2. Splits the line in three and assignes the 1º field to the texture
			3. It saves the texture in the map struct
 */

void	parse_north_texture(char *raw_map, t_map *map)
{
	char *texture;
	char **splitted_texture;
	
	texture = parse_character(raw_map, map_textures(NORTH));
	if (!texture)
		print_error("North texture field not found.");
	
	splitted_texture = ft_split(texture, ' ');
	map->NO_texture = splitted_texture[1];
}

void	parse_south_texture(char *raw_map, t_map *map)
{
	char *texture;
	char **splitted_texture;
	
	texture = parse_character(raw_map, map_textures(SOUTH));
	if (!texture)
		print_error("south texture field not found.");
	
	splitted_texture = ft_split(texture, ' ');
	map->SO_texture = splitted_texture[1];
}

void	parse_east_texture(char *raw_map, t_map *map)
{
	char *texture;
	char **splitted_texture;
	
	texture = parse_character(raw_map, map_textures(EAST));
	if (!texture)
		print_error("east texture field not found.");
	
	splitted_texture = ft_split(texture, ' ');
	map->EA_texture = splitted_texture[1];
}

void	parse_west_texture(char *raw_map, t_map *map)
{
	char *texture;
	char **splitted_texture;
	
	texture = parse_character(raw_map, map_textures(WEST));
	if (!texture)
		print_error("west texture field not found.");
	
	splitted_texture = ft_split(texture, ' ');
	map->WE_texture = splitted_texture[1];
}

void	parse_sprite_texture(char *raw_map, t_map *map)
{
	char *texture;
	char **splitted_texture;
	
	texture = parse_character(raw_map, map_textures(SPRITE));
	if (!texture)
		print_error("sprite texture field not found.");
	
	splitted_texture = ft_split(texture, ' ');
	map->SP_texture = splitted_texture[1];
}
