#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

#include "libft.h"

void ft_arr_swap(void *arr_, int i, int j)
{
	void **arr = arr_;
	void *tmp;

	tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

#ifdef FT_ARR_SWAP
int main(void)
{
	char *arr[10];

	arr[0] = "aaa";
	arr[1] = "bbb";

	ft_arr_swap(arr, 0, 1);
	assert(strcmp(arr[0], "bbb") == 0);
	assert(strcmp(arr[1], "aaa") == 0);
	printf("%s\n", "all tests passed!");
	return (0);	
}
#endif

