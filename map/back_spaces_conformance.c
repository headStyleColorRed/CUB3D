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
