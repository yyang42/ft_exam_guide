/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/05 14:40:34 by juschaef          #+#    #+#             */
/*   Updated: 2014/12/05 14:55:42 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ord_alphnum.h"

char	**sort_alpha(char **grid)
{
	int		i;
	int		j;
	int		size;

	size = size_array(grid);
	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (ft_strlen(grid[j]) == ft_strlen(grid[j + 1]))
				if (ft_strcmp(grid[j], grid[j + 1]) > 0)
					ft_strswap(&(grid[j]), &(grid[j + 1]));
			j++;
		}
		i++;
	}
	grid[size] = NULL;
	return (grid);
}

char	**sort_by_length(char **grid)
{
	int		i;
	int		j;
	int		size;

	size = size_array(grid);
	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (ft_strlen(grid[j]) > ft_strlen(grid[j + 1]))
				ft_strswap(&(grid[j]), &(grid[j + 1]));
			j++;
		}
		i++;
	}
	grid[size] = NULL;
	return (grid);
}
