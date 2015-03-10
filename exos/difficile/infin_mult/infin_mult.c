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

static void add(char *res, int l1, int l2, char *nb1, char *nb2)
{
	int		unit_i;
	int		dec_i;

	unit_i = l1+l2+1;
	dec_i = l1+l2;

	res[unit_i] += (nb1[l1] - '0') * (nb2[l2] - '0');
	res[dec_i] += res[unit_i] / 10;
	res[unit_i] %= 10;
}

static char *mult(char *nb1, char *nb2)
{
	char	*res;
	int		l1 = ft_strlen(nb1);
	int		l2 = ft_strlen(nb2);
	int		l2_sav;

	res = malloc(sizeof(*res) * (l1 + l2 + 1));
	ft_bzero(res, (l1 + l2 + 1));
	res[(l1 + l2)] = END_OF_STRING;

	l1--; // index
	l2--; // index
	l2_sav = l2;
	while (l1 >= 0)
	{
		l2 = l2_sav;
		while (l2 >= 0)
		{
			add(res, l1, l2, nb1, nb2);
			l2--;
		}
		l1--;
	}
	return (res);
}

static void mult_wrapper(char *nb1, char *nb2)
{
	int       neg;

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
	if (nb1[0] == '0' || nb1[0] == 0 || nb2[0] == '0' || nb2[0] == 0)
	{
		write(1, "0", 1);
		return;
	}
	print(mult(nb1, nb2));
}

int     main(int ac, char **av)
{
	if (ac == 3)
		mult_wrapper(av[1], av[2]);
	write(1, "\n", 1);
}
