#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

#include "libft.h"
char *ft_strstr(char *s, char *needle)
{
	while (*s)
	{
		if (ft_memcmp(s, needle, ft_strlen(needle)) == 0)
			return (s);
		s++;
	}
	return (NULL);
}

#ifdef FT_STRSTR
int main(void)
{
	assert(strcmp(ft_strstr("abcd", "bc"), "bcd") == 0);
	assert(strcmp(ft_strstr("abcd", "cd"), "cd") == 0);
	assert(strcmp(ft_strstr("abcd", "ab"), "abcd") == 0);
	printf("%s\n", "all tests passed!");
	return (0);	
}
#endif

