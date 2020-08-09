/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   killer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 17:40:03 by asoursou          #+#    #+#             */
/*   Updated: 2020/08/09 13:18:37 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line_bonus.h"

void	kill(const char *path)
{
	char	*l;
	int		f;

	if (!(f = open(path, O_RDONLY)))
		return ;
	l = NULL;
	if (get_next_line(f, &l) > 0)
	{
		printf("%s\n", l);
		free(l);
	}
	close(f);
	l = (char*)0xdeadbeef000000;
	printf("killer: %d (%p)\n", get_next_line(f, &l), l);
	if (l && l != (char*)0xdeadbeef000000)
	{
		printf("line: %s\n", l);
		free(l);
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
		kill(av[1]);
	return (0);
}
