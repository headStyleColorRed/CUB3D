//
//  map_manager.h
//  Wolfenstein
//
//  Created by Rodrigo  on 09/05/2020.
//  Copyright © 2020 Rodrigo . All rights reserved.
//

#ifndef map_manager_h
#define map_manager_h

# define MIN_SCREEN_HEIGHT 100
# define MAX_SCREEN_HEIGHT 1440
# define MIN_SCREEN_WIDTH 100
# define MAX_SCREEN_WIDTH 2560

typedef enum e_map_parser
{
	NORTH,
	SOUTH,
	WEST,
	EAST,
	RESOLUTION,
	SPRITE,
	FLOOR,
	CEILING,
	MAP
}			t_map_parser;

typedef enum e_bool
{
	ft_false,
	ft_true
}			t_bool;

typedef enum e_arguments
{
	MAP_PATH = 1,
	SAVE_FILE
}			t_arguments;

/*  M A P   R E A D E R */
char 	*read_map(t_map *raw_map);
void	process_file(char *map_file, t_map *map);
void	file_processor(int argc, char **argv, t_game *game);

/*  M A P   P A R S E R  */
char	*parse_character(char *raw_map, char *chosen_field);
void	parse_cube_map(char *raw_map, t_map *map);

/*  M A P   T E X T U R E	P A R S E R */
void	parse_north_texture(char *raw_map, t_map *map);
void	parse_south_texture(char *raw_map, t_map *map);
void	parse_east_texture(char *raw_map, t_map *map);
void	parse_west_texture(char *raw_map, t_map *map);
void	parse_sprite_texture(char *raw_map, t_map *map);

/*  M A P   R E S T 	P A R S E R */
void	parse_resolution(char *raw_map, t_map *map);
void	parse_floor_color(char *raw_map, t_map *map);
void	parse_ceiling_color(char *raw_map, t_map *map);


/*  M A P   R G B   C O N F O R M A N C E */
void	does_rgb_color_contain_alpha(char **splitted_fields);
void	is_rgb_color_number_offlimits(char **splitted_fields);
void	check_all_fields_are_present(t_map *map);

/*  M A P   M A T R I X */
void	parse_map(t_map *map);
int		is_map_beggining(char *line);

/*  M A P   S P A C E D   M A T R I X */
void	parse_spaced_map(t_map *map);


/*  M A P   B A C K	  S P A C I N G */
void	check_if_resolution_is_ok(char *line);
void	check_if_floor_ceiling_is_ok(char *line);
void	check_wall_textures_are_ok(char * line, t_map_parser orientation);

/*  M A P   C O N F O R M I N G */
void	check_file_conformity(t_map *map);

/*  M A P   C O N F O R M I N G	   M A P */
void	check_map_right_left_conformity(t_map *map);
void	check_map_top_bottom_conformity(t_map *map);
// void	check_map_top_conformity(t_map *map);
// void	check_map_bottom_conformity(t_map *map);

/*  M A P   C O N V E R T I N G */
void	transform_file_to_matrix(t_map *map);

/*  M A P   T E X T U R E S */
char	*map_textures(t_map_parser chosenMap);
#endif
