//
//  map_manager.h
//  Wolfenstein
//
//  Created by Rodrigo  on 09/05/2020.
//  Copyright © 2020 Rodrigo . All rights reserved.
//

#ifndef map_manager_h
#define map_manager_h

typedef struct	s_color
{
	int r_color;
	int g_color;
	int b_color;
}				t_color;

typedef struct s_resolution
{
	int width;
	int length;
}				t_resolution;

typedef struct	s_map
{
	char  			*NO_texture;
	char  			*SO_texture;
	char  			*WE_texture;
	char  			*EA_texture;
	char  			*SP_texture;
	t_resolution 	resolution;
	t_color			floor_color;
	t_color			ceiling_color;
	
}				t_map;


/*  M A P   R E A D E R */
char	*read_map(void);

/*  M A P   P A R S E R  */
void	parse_resolution(char *raw_map, t_map *map);

#endif
