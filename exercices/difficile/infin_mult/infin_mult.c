#include <stdlib.h>
#include <unistd.h>
#define END_OF_STRING -1

static void ft_putchar(char c)
{
	write(1, &c, 1);
}

static int  ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	i++;
	return (i);
}

static void ft_bzero(char *str, int size)
{
	int		i;

	i = 0;
	while (i < size)
		str[i++] = 0;
}

static void print(char *res)
{
	while (*res == 0)
		res++;
	while (*res != END_OF_STRING)
	{
		ft_putchar(*res + '0');
		res++;
	}
}

static void add(char *res, int i1, int i2, char *nb1, char *nb2)
{
	int		unit_i;
	int		dec_i;

	unit_i = i1+i2+1;
	dec_i = i1+i2;

	res[unit_i] += (nb1[i1] - '0') * (nb2[i2] - '0');
	res[dec_i] += res[unit_i] / 10;
	res[unit_i] %= 10;
}

static char *mult(char *nb1, char *nb2)
{
	char	*res;
	int		res_size;
	int		i2_sav;
	int		i1;
	int		i2;

	res_size = ft_strlen(nb1) + ft_strlen(nb2);
	res = malloc(sizeof(char) * (res_size + 1));
	ft_bzero(res, res_size + 1);
	res[res_size] = END_OF_STRING;
	i1 = ft_strlen(nb1) - 1;
	i2 = ft_strlen(nb2) - 1;
	i2_sav = i2;
	while (i1 >= 0)
	{
		i2 = i2_sav;
		while (i2 >= 0)
		{
			add(res, i1, i2, nb1, nb2);
			i2--;
		}
		i1--;
	}
	return (res);
}

static void mult_wrapper(char *nb1, char *nb2)
{
	int       neg;

	if (nb1[0] == '0' || nb1[0] == 0 || nb2[0] == '0' || nb2[0] == 0)
	{
		write(1, "0", 1);
		return;
	}
	neg = 0;
	if (nb1[0] == '-')
	{
		neg = !neg;
		nb1++;
	}
	if (nb2[0] == '-')
	{
		neg = !neg;
		nb2++;
	}
	if (neg)
		write(1, "-", 1);
	print(mult(nb1, nb2));
}

int     main(int ac, char **av)
{
	if (ac == 3)
		mult_wrapper(av[1], av[2]);
	write(1, "\n", 1);
	return (0);
}
