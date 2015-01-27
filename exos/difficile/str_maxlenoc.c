/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maxlenoc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/19 21:42:22 by juschaef          #+#    #+#             */
/*   Updated: 2014/12/19 21:54:32 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *s)
{
	return (*s ? ft_strlen(++s) + 1 : 0);
}

int		ft_memcmp(void *s1, void *s2, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		if (((char *)s1)[i] != ((char *)s2)[i])
			return (((char *)s1)[i] - ((char *)s2)[i]);
		i++;
	}
	return (0);
}

char	*ft_strstr(char *s1, char *s2)
{
	while (*s1)
	{
		if (ft_memcmp(s1, s2, ft_strlen(s2)) == 0)
			return (s1);
		s1++;
	}
	return (0);
}

void	ft_strcpy(char *s1, char *s2)
{
	while ((*s1++ = *s2++))
		;
}

char	*match(char *m, char *s)
{
	int i;
	char cpy[10000];
	char mm[1000];

	mm[0] = 0;
	while (*m)
	{
		i = ft_strlen(m);
		ft_strcpy(cpy, m);
		while (i > 0)
		{
			cpy[i] = 0;
			if (ft_strstr(s, cpy) != 0)
			{
				if (ft_strlen(cpy) > ft_strlen(mm))
					ft_strcpy(mm, cpy);
			}
			i--;
		}
		m++;
	}
	ft_strcpy(m, mm);
	return (m);
}

void	maxlenoc(char **ss)
{
	char *m;

	m = ss[0];
	ss++;
	while (*ss)
	{
		m = match(m, *ss);
		ss++;
	}
	write(1, m, ft_strlen(m));
}

int		main(int ac, char **av)
{
	if (ac > 1)
		maxlenoc(++av);
	write(1, "\n", 1);
	return (0);
}
