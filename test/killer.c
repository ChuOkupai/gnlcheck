/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   killer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 17:40:03 by asoursou          #+#    #+#             */
/*   Updated: 2019/09/29 17:45:21 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <get_next_line.h>
#include <stdlib.h>
#include <unistd.h>

void	kill(char *s)
{
	int f;

	f = open(s, O_RDONLY);
	if (get_next_line(f, &s) > 0)
	{
		ft_putendl(s);
		free(s);
	}
	close(f);
	ft_putstr("killer: ");
	ft_putnbr(get_next_line(f, &s));
	ft_putstr("\nbuffer: ");
	ft_putnbr(s != NULL);
	ft_putchar('\n');
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		kill(argv[1]);
	return (0);
}
