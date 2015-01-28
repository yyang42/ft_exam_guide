#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

#include "libft.h"

int ft_memcmp(void *s1_, void *s2_, int n)
{
	unsigned char *s1 = s1_;
	unsigned char *s2 = s2_;

	while (n--)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (0);
}

#ifdef FT_MEMCMP
int main(void)
{
	assert(ft_memcmp("abc", "abc", 3) == 0);
	assert(ft_memcmp("aa", "bb", 2) < 0);
	assert(ft_memcmp("bb", "aa", 2) > 0);
	assert(ft_memcmp("aab", "aac", 2) == 0);
	printf("%s\n", "all tests passed!");
	return (0);	
}
#endif

