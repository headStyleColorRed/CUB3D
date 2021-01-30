
#include "../library.h"

/*
	parse_texture() ->
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
	if ((open(splitted_texture[1], O_RDONLY)) < 0)
		print_error("North texture file doesn't exist");
	map->map_textures.NO_texture = splitted_texture[1];
}

void	parse_south_texture(char *raw_map, t_map *map)
{
	char *texture;
	char **splitted_texture;

	texture = parse_character(raw_map, map_textures(SOUTH));
	if (!texture)
		print_error("south texture field not found.");

	splitted_texture = ft_split(texture, ' ');
	if ((open(splitted_texture[1], O_RDONLY)) < 0)
		print_error("South texture file doesn't exist");
	map->map_textures.SO_texture = splitted_texture[1];
}

void	parse_east_texture(char *raw_map, t_map *map)
{
	char *texture;
	char **splitted_texture;

	texture = parse_character(raw_map, map_textures(EAST));
	if (!texture)
		print_error("east texture field not found.");

	splitted_texture = ft_split(texture, ' ');
	if ((open(splitted_texture[1], O_RDONLY)) < 0)
		print_error("East texture file doesn't exist");
	map->map_textures.EA_texture = splitted_texture[1];
}

void	parse_west_texture(char *raw_map, t_map *map)
{
	char *texture;
	char **splitted_texture;

	texture = parse_character(raw_map, map_textures(WEST));
	if (!texture)
		print_error("west texture field not found.");

	splitted_texture = ft_split(texture, ' ');
	if ((open(splitted_texture[1], O_RDONLY)) < 0)
		print_error("West texture file doesn't exist");
	map->map_textures.WE_texture = splitted_texture[1];
}

void	parse_sprite_texture(char *raw_map, t_map *map)
{
	char *texture;
	char **splitted_texture;

	texture = parse_character(raw_map, map_textures(SPRITE));
	if (!texture)
		print_error("sprite texture field not found.");

	splitted_texture = ft_split(texture, ' ');
	if ((open(splitted_texture[1], O_RDONLY)) < 0)
		print_error("Sprite texture file doesn't exist");
	map->map_textures.SP_texture = splitted_texture[1];
}
