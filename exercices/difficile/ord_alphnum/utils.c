/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/05 14:41:12 by juschaef          #+#    #+#             */
/*   Updated: 2014/12/05 14:41:43 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ord_alphnum.h"

int		size_array(char **array)
{
	int count;

	count = 0;
	while (array[count] != NULL)
		count++;
	return (count);
}

int		ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

char	*ft_strdup(char *str)
{
	char	*dup;
	int		i;

	i = 0;
	dup = (char *)malloc(ft_strlen(str) + 100);
	while (str[i])
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

int		ft_strcmp(char *s1, char *s2)
{
	while (ft_tolower(*s1) == ft_tolower(*s2))
	{
		if (*s2 == '\0')
			return (0);
		s1++;
		s2++;
	}
	return ((unsigned char)ft_tolower(*s2) < (unsigned char)ft_tolower(*s1));
}
