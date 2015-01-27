/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/05 12:27:17 by juschaef          #+#    #+#             */
/*   Updated: 2014/12/05 14:39:55 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

char	*ft_strcat(char *str, char c)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	str[i++] = c;
	str[i] = '\0';
	return (str);
}
		
int		ft_strchr(char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

void	ft_union(char *s1, char *s2)
{
	char	match[500];

	while (*s1)
	{
		if (!(ft_strchr(match, *s1)))
			ft_strcat(match, *s1);
		s1++;
	}
	while (*s2)
	{
		if(!(ft_strchr(match, *s2)))
			ft_strcat(match, *s2);
		s2++;
	}
	ft_putstr(match);
}

int		main(int argc, char **argv)
{
	if (argc == 3)
		ft_union(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}