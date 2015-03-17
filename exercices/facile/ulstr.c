/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulstr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/19 18:01:48 by juschaef          #+#    #+#             */
/*   Updated: 2014/12/19 20:26:50 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *s)
{
	return (*s ? ft_strlen(++s) + 1 : 0);
}

char	ulchar(char c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	else if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

void	ulstr(char *s)
{
	char *ss;
	
	ss = s;
	while (*s)
	{
		*s = ulchar(*s);
		s++;
	}
	write(1, ss, ft_strlen(ss));
}

int		main(int ac, char **av)
{
	if (ac == 2)
		ulstr(av[1]);
	write(1, "\n", 1);
	return (0);
}
