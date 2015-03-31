#include <unistd.h>
#include <stdlib.h>

int ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void ft_putstr(char *s)
{
	write(1, s, ft_strlen(s));
}

void ft_strcpy(char *s1, char *s2)
{
	while (*s2)
	{
		*s1 = *s2;
		s1++;
		s2++;
	}
	*s1 = 0;
}

char *ft_strdup(char *s)
{
	char *snew;

	snew = malloc(sizeof(char) * (ft_strlen(s) + 1));
	ft_strcpy(snew, s);
	return (snew);
}

int ft_strnequ(char *s1, char *s2, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

char *ft_strstr(char *h, char *n)
{
	while (*h)
	{
		if (ft_strnequ(h, n, ft_strlen(n)))
			return (h);
		h++;
	}
	return (NULL);
}

char *local_max;

void match_right(char *s1, char *s2)
{
	char *c1;

	c1 = ft_strdup(s1);
	while (*c1)
	{
		if (ft_strstr(s2, c1))
		{
			if (ft_strlen(c1) > ft_strlen(local_max))
				local_max = ft_strdup(c1);
		}
		c1[ft_strlen(c1) - 1] = 0;
	}
}

void match_left(char *s1, char *s2)
{
	while (*s1)
	{
		match_right(s1, s2);
		s1++;
	}
}

void maxlenoc(char **segs)
{
	char *gle_max;

	gle_max = *segs;
	segs++;
	while (*segs)
	{
		local_max = "";
		match_left(gle_max, *segs);
		if (ft_strlen(local_max) < ft_strlen(gle_max))
			gle_max = local_max;
		segs++;
	}
	ft_putstr(gle_max);
}

int main(int ac, char **av)
{
	if (ac == 2)
		ft_putstr(av[1]);
	if (ac > 2)
		maxlenoc(++av);
	ft_putstr("\n");
	return (0);
}
