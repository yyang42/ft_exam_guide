
int ft_strlen(char *s)
{
    int i;

    i = 0;
    while (s[i])
    	i++;
    return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar(n + '0');
}

void	ft_strcpy(char *d, char *s)
{
	while ((*d++ = *s++))
		;
}

char	*ft_strdup(char *s)
{
	char *d;

	d = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	ft_strcpy(d, s);
	return (d);
}


int		ft_atoi(char *s)
{
	int i;

	i = 0;
	while (*s)
	{
		i = i * 10 + *s++ - '0';
	}
	return (i);
}
