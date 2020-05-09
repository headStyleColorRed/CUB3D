//
//  errorManager.c
//  Wolfenstein
//
//  Created by Rodrigo  on 09/05/2020.
//  Copyright © 2020 Rodrigo . All rights reserved.
//

#include "../library.h"

void	write_error(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	print_error(char *str)
{
	write_error("Error");
	write_error(str);
	exit(0);
}
