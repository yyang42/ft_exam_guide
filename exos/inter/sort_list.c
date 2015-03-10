/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 09:56:36 by exam              #+#    #+#             */
/*   Updated: 2015/03/05 11:09:06 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

static int	lst_len(t_list *lst)
{
	int i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next; 
	}
	return (i);
}

static void convert_to_arr(t_list **arr, t_list *lst)
{
	int i;

	i = 0;
	while (lst)
	{
		arr[i] = lst;
		lst = lst->next;
		i++;
	}
	arr[i] = 0;
}

static void arr_sort(t_list **arr, int len, int (*cmp)(int, int))
{
	int i;
	int j;
	t_list *tmp;

	j = 0;
	while (j < len - 1)
	{
		i = 0;
		while (i < len - j - 1)
		{
			if (cmp(arr[i]->data, arr[i + 1]->data) > 0)
			{
				tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
			}
			i++;
		}
		j++;
	}
}

static t_list *lst_push(t_list *lst, t_list *elem)
{
	t_list *save;

	save = lst;
	elem->next = lst;
	save = elem;
	return (save);
}

static t_list *convert_to_lst(t_list **arr)
{
	t_list *save;
	int i;
	
	save = 0;
	i = 0;
	while (arr[i])
	{
		save = lst_push(save, arr[i]);
		arr++;
	}
	return (save);
}

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	int len;
	t_list *arr[100000];
	t_list *new_lst;

	len = lst_len(lst);
	convert_to_arr(arr, lst);
	arr_sort(arr, len, cmp);
	new_lst = convert_to_lst(arr);
	return (new_lst);
}

