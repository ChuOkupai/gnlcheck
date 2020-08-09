/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 19:54:00 by asoursou          #+#    #+#             */
/*   Updated: 2020/08/09 13:17:20 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line_bonus.h"

int	main(int ac, char **av)
{
	char	*l;
	int		f;
	int		n;
	int		r;

	if (ac == 2 && (f = open(av[1], O_RDONLY)))
	{
		n = 0;
		while ((r = get_next_line(f, &l)) == 1)
		{
			printf("%3d: |%s|\n", ++n, l);
			free(l);
		}
		if (r == -1)
			printf("error: %p\n", l);
		else if (!r)
		{
			printf("last: |%s|\n", l);
			free(l);
		}
		else
			printf("error: unknown return value\n");
		close(f);
	}
	return (0);
}
