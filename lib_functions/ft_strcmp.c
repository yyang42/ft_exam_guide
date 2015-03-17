#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

int ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2)
	{
		if (!*s1)
			return (0);
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

#ifdef FT_STRCMP
int main(void)
{
	assert(ft_strcmp("abc", "abc") == 0);
	assert(ft_strcmp("aa", "bb") < 0);
	assert(ft_strcmp("bb", "aa") > 0);
	assert(ft_strcmp("aab", "aac") < 0);
	printf("%s\n", "all tests passed!");
	return (0);	
}
#endif

