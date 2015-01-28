#include <stdio.h>
#include <assert.h>
#include <string.h>

void ft_strcpy(char *d, char *s)
{
	while ((*d++ = *s++))
		;
}

#ifdef FT_STRCPY
int main(void)
{
	char s[1000];

	ft_strcpy(s, "aaa");
	assert(strcmp(s, "aaa") == 0);
	printf("%s\n", "all tests passed!");
	return (0);	
}
#endif
