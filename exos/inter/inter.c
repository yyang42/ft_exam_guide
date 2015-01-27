/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/19 21:34:15 by juschaef          #+#    #+#             */
/*   Updated: 2014/12/19 21:40:02 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *s)
{
	return (*s ? ft_strlen(++s) + 1 : 0);
}

void	ft_strcat(char *s, char c)
{
	while (*s)
		s++;
	*s = c;
	s++;
	*s = 0;
}

char	*ft_strchr(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}
	return (0);
}

void	inter(char *s1, char *s2)
{
	char match[10000];

	match[0] = 0;
	while (*s1)
	{
		if (ft_strchr(s2, *s1))
			if (!(ft_strchr(match, *s1)))
				ft_strcat(match, *s1);
		s1++;
	}
	write(1, match, ft_strlen(match));
}

int		main(int ac, char **av)
{
	if (ac == 3)
		inter(av[1], av[2]);
	write(1, "\n", 1);
	return (0);
}