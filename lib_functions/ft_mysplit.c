/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mysplit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhnguyen <anhnguyen@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 14:08:09 by anhnguyen         #+#    #+#             */
/*   Updated: 2015/03/16 14:09:14 by anhnguyen        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int		ft_strlen(char *s)
{
	int i;

	i = 0;
	while (*s)
	{
		i++;
		s++;
	}
	return (i);
}

char **ft_tabtrim(char **segs)
{
	char **segs_trim;
	int i;
	int j;

	i = 0;
	j = 0;
	segs_trim = (char **)malloc(sizeof(char *) * 100);
	while (segs[i])
	{
		if (ft_strlen(segs[i]) > 0)
			segs_trim[j++] = segs[i];
		i++;
	}
	return (segs_trim);
}

char **ft_mysplit(char *s, char c)
{
	char **segs;
	int i;
	int j;

	i = 0;
	j = 0;
	segs = (char **)malloc(sizeof(char*) * 100);
	segs[i] = (char *)malloc(sizeof(char) * 1000);
	while (*s)
	{
		if (*s == c)
		{
			segs[i][j] = '\0';
			j = 0;
			i++;
			segs[i] = (char *)malloc(sizeof(char) * 1000);
		}
		else
		{
			segs[i][j] = *s;
			j++;
		}
		s++;
	}
	segs[++i] = NULL;
	segs = ft_tabtrim(segs);
	return (segs);
}

int main(void)
{
	char **segs;

	segs = ft_mysplit("   aa bb cc    dd    ", ' ');
	
	assert(strcmp(segs[0], "aa") == 0);
	assert(strcmp(segs[1], "bb") == 0);
	printf("%s\n", "all tests passed!");
	return (0);	
}

