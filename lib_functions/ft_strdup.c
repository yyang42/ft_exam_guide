#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

#include "libft.h"

char *ft_strdup(char *s)
{
	char *dup;

	dup = malloc(sizeof(char) * (ft_strlen(s) + 1));
	ft_strcpy(dup, s);
	return (dup);	
}

#ifdef FT_STRDUP
int main(void)
{
	assert(strcmp(ft_strdup("aaa"), "aaa") == 0);
	assert(strcmp(ft_strdup(""), "") == 0);
	printf("%s\n", "all tests passed!");
	return (0);	
}
#endif
