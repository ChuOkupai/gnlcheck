/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 23:56:43 by asoursou          #+#    #+#             */
/*   Updated: 2020/08/09 13:10:06 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line_bonus.h"

void	close_all(int *f, int size)
{
	while (size--)
		close(f[size]);
}

int		open_all(int *f, int size, char **argv)
{
	int i;

	i = -1;
	while (++i < size)
		if ((f[i] = open(argv[i], O_RDONLY)) < 0)
		{
			close_all(f, i);
			return (-1);
		}
	return (0);
}

int		read_all(int *f, int size)
{
	char	*l;
	int		i;
	int		n;

	i = -1;
	n = 0;
	while (++i < size)
		if (f[i])
		{
			if (get_next_line(f[i], &l) > 0)
			{
				printf("|%s|\n", l);
				free(l);
				++n;
			}
			else
			{
				if (l)
					free(l);
				close(f[i]);
				f[i] = 0;
			}
		}
	return (n);
}

int		main(int argc, char **argv)
{
	if (argc > 1)
	{
		int f[--argc];

		if (!open_all(f, argc, argv + 1))
			while (read_all(f, argc));
		else
			printf("error: Could not open files\n");
	}
	return (0);
}
