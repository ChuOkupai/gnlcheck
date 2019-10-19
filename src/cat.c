/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 19:54:00 by asoursou          #+#    #+#             */
/*   Updated: 2019/10/13 16:52:42 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line_bonus.h"

int	main(int argc, char **argv)
{
	char	*s;
	int		f;
	int		l;

	if (argc == 2 && (f = open(argv[1], O_RDONLY)))
	{
		l = 1;
		while (get_next_line(f, &s) > 0)
		{
			printf("%d\t: %s$\n", l++, s);
			free(s);
		}
		close(f);
	}
	return (0);
}
