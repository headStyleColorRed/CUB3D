#include "../library.h"

void	does_rgb_color_contain_alpha(char **splitted_fields)
{
	int	i;

	i = 0;
	while (splitted_fields[0][i])
		if (ft_isalnum(splitted_fields[0][i++]) != 1)
			print_error("First Ceiling/Floor RGB parameter is wrong");
	i = 0;
	while (splitted_fields[1][i])
		if (ft_isalnum(splitted_fields[1][i++]) != 1)
			print_error("Second Ceiling/Floor RGB parameter is wrong");
	i = 0;
	while (splitted_fields[2][i])
		if (ft_isalnum(splitted_fields[2][i++]) != 1)
			print_error("Third Ceiling/Floor RGB parameter is wrong");
}

void	is_rgb_color_number_offlimits(char **splitted_fields)
{
	int numbered_rgb;

	numbered_rgb = ft_atoi(splitted_fields[0]);
	if(numbered_rgb > 255 || numbered_rgb < 0)
		print_error("First Ceiling/Floor RGB parameter is offlimits");
	numbered_rgb = ft_atoi(splitted_fields[1]);
	if(numbered_rgb > 255 || numbered_rgb < 0)
		print_error("Second Ceiling/Floor RGB parameter is offlimits");
	numbered_rgb = ft_atoi(splitted_fields[2]);
	if(numbered_rgb > 255 || numbered_rgb < 0)
		print_error("Third Ceiling/Floor RGB parameter is offlimits");
}

void is_valid_parameter(char *param)
{
	t_bool isValid;

	if (ft_strlen(param) > 2)
		print_error("Parameter is longer than 2 characters");

	if (ft_strlen(param) == 1)
	{
		if (ft_strncmp(param, "R", 1))
			isValid = ft_true;
	}

}

void	check_if_first_parameter_is_allowed(char *line)
{
	int		i;
	char	croppedField[5];

	i = 0;
	while (ft_isalpha(line[i]) && i < 5)
	{
		croppedField[i] = line[i];
		i++;
	}
	croppedField[i] = '\0';
	is_valid_parameter(croppedField);
}

void	check_all_fields_are_present(t_map *map)
{
	int		fd;
	int		i;
	int		j;
	char	*line;

	fd = open(map->map_file, O_RDONLY);
	i = 0;
	j = 0;
	while (get_next_line(fd, &line) == 1)
	{
		// printf("%s", line);
		check_if_first_parameter_is_allowed(line);

		free(line);
	}
	close(fd);
}
