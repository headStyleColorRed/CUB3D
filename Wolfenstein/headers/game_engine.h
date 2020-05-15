#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

typedef	struct	s_window
{
	void		*ptr;
	void		*win;
	double		ratio;
}				t_window;

/*  G A M E   E N G I N E */
void    start_game(t_map *map, t_window *window);

#endif 
