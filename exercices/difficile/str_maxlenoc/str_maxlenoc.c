#include <unistd.h>
#include <stdlib.h>





#include <stdio.h>






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

char	*ft_strdup(char *s)
{
	char *d;

	d = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	ft_strcpy(d, s);
	return (d);
}

char 	*match_from_end(char *s, char *m)
{
	char *cpy;

	cpy = ft_strdup(m);
	while (*cpy)
	{
		printf("cpy: %s\n", cpy);
		if (ft_strstr(s, cpy))
			return (cpy);
		cpy[ft_strlen(cpy) - 1] = 0;
	}
	return (cpy);
}

char	*match(char *match, char *s)
{
	char *max;
	char *cur_match;

	max = ft_strdup("");
	while (*match)
	{
		cur_match = match_from_end(s, match);
		if (ft_strlen(cur_match) > ft_strlen(max))
			max = cur_match;
		match++;
	}
	return (max);
}

void	maxlenoc(char **ss)
{
	char *cur_match;

	cur_match = ss[0];
	ss++;
	while (*ss)
	{
		cur_match = match(cur_match, *ss);
		ss++;
	}
	write(1, cur_match, ft_strlen(cur_match));
}

int		main(int ac, char **av)
{
	if (ac > 1)
		maxlenoc(++av);
	write(1, "\n", 1);
	return (0);
}
