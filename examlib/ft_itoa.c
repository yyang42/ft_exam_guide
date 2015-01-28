#include "libft.h"

char *ft_itoa(int n)
{
	char *s;

	s = malloc(100);
	s += 100;
	*s = 0;
	while (1)
	{
		s--;
		*s = n % 10 + '0';
		n = n / 10;
		if (!n)
			break;
	}
	return (s);
}

#ifdef FT_ITOA
int main(void)
{
	assert(strcmp(ft_itoa(1234), "1234") == 0);
	assert(strcmp(ft_itoa(0), "0") == 0);
	printf("%s", "passed");
	return (0);
}
#endif

