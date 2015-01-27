/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/05 12:21:10 by juschaef          #+#    #+#             */
/*   Updated: 2014/12/05 12:26:03 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	hidenp(char *s1, char *s2)
{
	while (*s2)
	{
		if (*s2 == *s1)
			s1++;
		if (*s1 == '\0')
		{
			write(1, "1", 1);
			return ;
		}
		s2++;
	}
	write(1, "0", 1);
}


int		main(int argc, char **argv)
{
	if (argc == 3)
		hidenp(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}