#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

#include "libft.h"
int ft_arr_len(void *arr_)
{
	int i;
	void **arr = arr_;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

#ifdef FT_ARR_LEN
int main(void)
{
	char *arr[10];
	
	arr[0] = "aaa";
	arr[1] = "bbb";
	arr[2] = "ccc";
	arr[3] = NULL;

	assert(ft_arr_len((void *)arr) == 3);
	arr[2] = NULL;
	assert(ft_arr_len((void *)arr) == 2);
	printf("%s\n", "all tests passed!");
	return (0);	
}
#endif

