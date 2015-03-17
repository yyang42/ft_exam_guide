/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ord_alpha.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/05 13:22:32 by juschaef          #+#    #+#             */
/*   Updated: 2014/12/05 14:55:45 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ord_alphnum.h"

void	print_grid(char **grid)
{
	int i;

	i = 1;
	ft_putstr(grid[0]);
	while (grid[i] != NULL)
	{
		if (ft_strlen(grid[i]) == ft_strlen(grid[i - 1]))
			write(1, " ", 1);
		else
			write(1, "\n", 1);
		ft_putstr(grid[i]);
		i++;
	}
}

void	function(char *str)
{
	char **grid;

	grid = (char **)malloc(100000);
	grid = ft_split(str);
	grid = sort_by_length(grid);
	grid = sort_alpha(grid);
	print_grid(grid);
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		function(argv[1]);
	write(1, "\n", 1);
	return (0);
}
