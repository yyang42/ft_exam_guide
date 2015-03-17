#include "libft.h"

void ft_putnbr(int n)
{
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar(n + '0');
}

#ifdef FT_PUTNBR
int main(void)
{
	ft_putnbr(1234567890);
	return (0);
}
#endif
