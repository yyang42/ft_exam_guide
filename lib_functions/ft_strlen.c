#include <stdio.h>
#include <assert.h>

int ft_strlen(char *s)
{
	int len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

#ifdef FT_STRLEN
int main(void)
{
	assert(ft_strlen("") == 0);
	assert(ft_strlen("12345") == 5);
	printf("%s\n", "all tests passed!");
	return (0);	
}
#endif
