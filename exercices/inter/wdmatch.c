/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/19 20:28:41 by juschaef          #+#    #+#             */
/*   Updated: 2014/12/19 20:31:00 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *s)
{
	return (*s ? ft_strlen(++s) + 1 : 0);
}

void	wdmatch(char *s1, char *s2)
{
	char *s;

	s = s1;
	while (*s2)
	{
		if (*s2 == *s1)
			s1++;
		s2++;
	}
	if (!(*s1))
		write(1, s, ft_strlen(s));
}

int		main(int ac, char **av)
{
	if (ac == 3)
		wdmatch(av[1], av[2]);
	write(1, "\n", 1);
	return (0);
}