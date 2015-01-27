/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/05 12:11:08 by juschaef          #+#    #+#             */
/*   Updated: 2014/12/05 12:20:54 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

char	rot_char(char c)
{
	if (c >= 'a' && c < 'z')
		return (c + 1);
	else if (c == 'z' || c == 'Z')
		return (c - 25);
	else if (c >= 'A' && c < 'Z')
		return (c + 1);
	return (c);
}

void	rotone(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		str[i] = rot_char(str[i]);
		i++;
	}
	ft_putstr(str);
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		rotone(argv[1]);
	write(1, "\n", 1);
	return (0);
}