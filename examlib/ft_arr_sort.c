#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

#include "libft.h"

int sort_strcmp(void *s1_, void *s2_)
{
	char *s1 = s1_;
	char *s2 = s2_;
	return (ft_strcmp(s1, s2) > 0);
}

void ft_arr_sort(void *arr_, int (*cmp_fn)(void *a, void *b))
{
	void **arr = arr_;
	int i;
	int j;
	int len = ft_arr_len(arr);

	i = 0;
	while (i < len - 1)
	{
		j = 0;
		while ( j < len - i - 1)
		{
			if (cmp_fn(arr[j], arr[j + 1]))
				ft_arr_swap(arr, j, j + 1); 
			j++;
		}
		i++;
	}
}
#ifdef FT_ARR_SORT
int main(void)
{
	char *arr[10];
	
	arr[0] = "abb";
	arr[1] = "aaa";
	arr[2] = "ccc";
	arr[3] = "bbb";
	arr[4] = NULL;

	ft_arr_sort(arr, sort_strcmp);
	assert(strcmp(arr[0], "aaa") == 0);
	assert(strcmp(arr[1], "abb") == 0);
	assert(strcmp(arr[2], "bbb") == 0);
	assert(strcmp(arr[3], "ccc") == 0);
	printf("%s\n", "all tests passed!");
	return (0);	
}
#endif

