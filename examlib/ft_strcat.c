#include <stdio.h>
#include <assert.h>
#include <string.h>

void ft_strcat(char *d, char *s)
{
	while (*d)
		d++;
	while ((*d++ = *s++))
		;
}

#ifdef FT_STRCAT
int main(void)
{
	char s[1000];

	*s = 0;
	ft_strcat(s, "aaa");
	ft_strcat(s, "bbb");
	assert(strcmp(s, "aaabbb") == 0);
	printf("%s\n", "all tests passed!");
	return (0);	
}
#endif
