/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/05 14:42:00 by juschaef          #+#    #+#             */
/*   Updated: 2014/12/05 15:00:31 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ord_alphnum.h"

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int		ft_isspace(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

char	ft_tolower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

char	**ft_split(char *str)
{
	char	**grid;
	int		i;
	int		j;
	int		k;

	grid = (char **)malloc(10000);
	i = 0;
	j = 0;
	k = 0;
	while (ft_isspace(str[i]))
		i++;
	grid[j] = (char *)malloc(1000);
	while (str[i] != '\0')
	{
		if (!(ft_isspace(str[i])))
		{
			grid[j][k] = str[i];
			i++;
			k++;
		}
		if (ft_isspace(str[i]))
		{
			grid[j][k] = '\0';
			j++;
			grid[j] = (char *)malloc(1000);
			k = 0;
		}
		while (ft_isspace(str[i]))
			i++;
	}
	grid[++j] = NULL;
	return (grid);
}

void	ft_strswap(char **s1, char **s2)
{
	char *temp;

	temp = ft_strdup(*s1);
	*s1 = ft_strdup(*s2);
	*s2 = ft_strdup(temp);
	free(temp);
}
