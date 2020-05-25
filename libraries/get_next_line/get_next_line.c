/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabrado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 13:11:21 by rlabrado          #+#    #+#             */
/*   Updated: 2019/12/15 15:36:30 by rlabrado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strndup(const char *src, size_t n)
{
	size_t		i;
	char		*output;

	i = 0;
	while (src[i] != '\0' && i < n)
		i++;
	if ((output = (char*)malloc(sizeof(char) * (i + 1))) == NULL)
		return (NULL);
	i = 0;
	while (src[i] != '\0' && i < n)
	{
		output[i] = src[i];
		i++;
	}
	output[i] = '\0';
	return (output);
}

char	*ft_reader(const int fd, char *state_keeper)
{
	int		ft;
	char	buffer[BUFFER_SIZE + 1];
	char	*tmp;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, buffer, 0) < 0)
		return (0);
	if (state_keeper == 0)
		state_keeper = ft_strdup("");
	while (!(ft_strchr(state_keeper, '\n')))
	{
		if ((ft = read(fd, buffer, BUFFER_SIZE)) < 0)
			return (0);
		buffer[ft] = '\0';
		tmp = ft_strjoin(state_keeper, buffer);
		free(state_keeper);
		state_keeper = tmp;
		if (ft == 0 || state_keeper[0] == '\0')
			break ;
	}
	return (state_keeper);
}

int		get_next_line(int fd, char **line)
{
	int				i;
	char			*tmp;
	static char		*state_keep;

	if (fd < 0 || line == NULL || (state_keep = ft_reader(fd, state_keep)) == 0)
		return (-1);
	if ((tmp = ft_strchr(state_keep, '\n')))
	{
		i = tmp - state_keep;
		tmp = ft_strdup(state_keep + i + 1);
		if ((*line = ft_strndup(state_keep, i)) == 0)
			return (-1);
		free(state_keep);
		state_keep = ft_strdup(tmp);
		free(tmp);
		return (1);
	}
	else
	{
		if ((*line = ft_strdup(state_keep)) == 0)
			return (-1);
		free(state_keep);
		state_keep = NULL;
		return (0);
	}
}
