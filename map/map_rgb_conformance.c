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

t_bool	is_valid_parameter(char *param)
{
	t_bool isValid;

	isValid = ft_false;
	if (ft_strlen(param) > 2)
		print_error("Parameter is longer than 2 characters");
	if (ft_strlen(param) == 1)
		if (ft_strncmp(param, "R", 1 )== 0 || ft_strncmp(param, "S", 1 )== 0 ||
			ft_strncmp(param, "C", 1 )== 0 || ft_strncmp(param, "F", 1 )== 0 )
			isValid = ft_true;
	if (ft_strlen(param) == 2)
	{
		if (ft_strncmp(param, "NO", 2) == 0 || ft_strncmp(param, "SO", 2) == 0 ||
		ft_strncmp(param, "EA", 2) == 0 || ft_strncmp(param, "WE", 2) == 0)
			isValid = ft_true;
	}

	return isValid;
}

t_bool	check_if_first_parameter_is_allowed(char *line)
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
	if (is_valid_parameter(croppedField))
		return ft_true;
	return ft_false;
}

void	check_all_fields_are_present(t_map *map)
{
	int		fd;
	int		i;
	int		j;
	char	*line;
	int		correct_fields;

	fd = open(map->map_file, O_RDONLY);
	i = 0;
	j = 0;
	correct_fields = 0;
	while (get_next_line(fd, &line) == 1)
	{
		if (check_if_first_parameter_is_allowed(line) == ft_true)
			correct_fields++;
		free(line);
	}
	close(fd);
	if (correct_fields != 8)
		print_error("A Field description was wrong");
}
