#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

#include "libft.h"
char **ft_strsplit(char *s, char c)
{
	char **segs;
	int i;

	i = 0;
	segs = malloc(100 * 1000);
	while (*s)
	{
		if (*s == c)
		{
			*s = 0;
			s++;
		}
		segs[i] = s;
		s++;
	}
	return (segs);
}

#ifdef FT_STRSPLIT
int main(void)
{
	char **segs;

	segs = ft_strsplit("aa bb cc dd", 'c');
	
	assert(strcmp(segs[0], "aa") == 0);
	assert(strcmp(segs[1], "bb") == 0);
	printf("%s\n", "all tests passed!");
	return (0);	
}
#endif

