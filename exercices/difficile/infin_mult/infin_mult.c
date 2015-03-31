#include <stdlib.h>
#include <unistd.h>




#include <stdio.h>





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

void add(char *res, int i1, int i2, char c1, char c2)
{
	int		unit_i;
	int		dec_i;

	unit_i = i1+i2+1;
	dec_i = i1+i2;
	res[unit_i] += (c1 - '0') * (c2 - '0');
	res[dec_i] += res[unit_i] / 10;
	res[unit_i] %= 10;
}

static char *mult(char *n1, char *n2)
{
	char	*res;
	int		res_size;
	int		i2_sav;
	int		i1;
	int		i2;

	res_size = ft_strlen(n1) + ft_strlen(n2);
	res = malloc(sizeof(char) * (res_size + 1));
	ft_bzero(res, res_size + 1);
	res[res_size] = END_OF_STRING;
	i1 = ft_strlen(n1) - 1;
	i2 = ft_strlen(n2) - 1;
	i2_sav = i2;
	while (i1 >= 0)
	{
		i2 = i2_sav;
		while (i2 >= 0)
		{
			printf("n1[%d]: %c n2[%d]: %c\n", i1, n1[i1], i2, n2[i2]);
			add(res, i1, i2, n1[i1], n2[i2]);
			print(res);
			printf("\n");
			i2--;
		}
		i1--;
	}
	return (res);
}

static void mult_wrapper(char *n1, char *n2)
{
	int       neg;

	if (n1[0] == '0' || n1[0] == 0 || n2[0] == '0' || n2[0] == 0)
	{
		write(1, "0", 1);
		return;
	}
	neg = 0;
	if (n1[0] == '-')
	{
		neg = !neg;
		n1++;
	}
	if (n2[0] == '-')
	{
		neg = !neg;
		n2++;
	}
	if (neg)
		write(1, "-", 1);
	print(mult(n1, n2));
}

int     main(int ac, char **av)
{
	if (ac == 3)
		mult_wrapper(av[1], av[2]);
	write(1, "\n", 1);
	return (0);
}
