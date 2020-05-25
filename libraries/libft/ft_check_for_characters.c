//
//  ft_check_for_characters.c
//  Wolfenstein
//
//  Created by Rodrigo  on 15/05/2020.
//  Copyright © 2020 Rodrigo . All rights reserved.
//

#include "libft.h"

int		ft_check_string_for_characters(char *str, char *characters)
{
	int i;
	int j;
	
	j = 0;
	i = 0;
	while (characters[i])
	{
		j = 0;
		while (str[j])
			if (str[j++] == characters[i])
				return (1);
		i++;
	}
	
	return (0);
}
