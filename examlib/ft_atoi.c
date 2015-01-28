#include "libft.h"

int ft_atoi(char *s)
{
	int i;

	i = 0;
	while (*s)
	{
		i = i * 10 + *s - '0';
		s++;
	}
	return (i);
}

#ifdef FT_ATOI
int main(void)
{
	assert(ft_atoi("12345") == 12345);
	assert(ft_atoi("0") == 0);
	assert(ft_atoi("") == 0);
	assert(ft_atoi("9999") == 9999);
	printf("%s", "passed");
	return (0);
}
#endif
