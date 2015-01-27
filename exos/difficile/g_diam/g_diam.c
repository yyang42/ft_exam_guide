#include "g_diam.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.c"

t_node *node_new(int node_val)
{
	t_node *node;

	node = malloc(sizeof(t_node));
	node->visited = 0;
	node->value = node_val;
	node->links = malloc(100000);
	*(node->links) = NULL;
	return (node);
}


t_node *get_node(t_node **arr, int val)
{
	if (arr[val])
		return (arr[val]);
	arr[val] = node_new(val);
	return (arr[val]);
}

char **split_input(char *str, char c)
{
	char **segs;
	int i;

	segs = malloc(100000);
	i = 0;
	while (*str)
	{
		segs[i] = str;
		while (*str != c && *str)
			str++;
		*str = 0;
		str++;
		i++;
	}
	segs[i] = NULL;
	return (segs);
}

void	add_relation(t_node *node1, t_node *node2)
{
	t_node **links;
	int i;

	// printf("node1 %d\n", node1->value);
	links = node1->links;
	i = 0;
	while (links[i])
	{
		if (links[i] == node2)
			return ;
		i++;
	}
	links[i] = node2;
	links++;
	links[i] = NULL;
}

t_node *link_nodes(t_node **arr, char **segs)
{
	int node_val;
	int link_val;

	while (*segs)
	{
		node_val = ft_atoi(split_input(*segs, '-')[0]);
		link_val = ft_atoi(split_input(*segs, '-')[1]);
		add_relation(get_node(arr, node_val), get_node(arr, link_val));
		segs++;
	}
	return (NULL);
}

t_node *build_graph(t_node **arr, char *str)
{
	char **segs;
	t_node *head;

	segs = split_input(str, ' ');
	head = link_nodes(arr, segs);
	return (head);
}

int get_max_path_rec(t_node *node, int *max_path)
{
	t_node **links;

	links = node->links;
	node->visited = 1;
	while (*links)
	{
		(*max_path)++;
		printf("node: %d : link %d\n", node->value, (*links)->value);
		if (!(*links)->visited)
			get_max_path_rec(*links, max_path);
		links++;
	}
	return (1);
}

int get_max_path(t_node **arr)
{
	int cur_max;
	int prev_max;
	int i;

	prev_max = cur_max = 0;
	i = 0;
	while (i < 100000)
	{
		if (arr[i])
		{
			get_max_path_rec(arr[i], &cur_max);
			if (prev_max < cur_max)
				prev_max = cur_max;
			cur_max = 0;
		}
		i++;
	}
	// printf("%d\n", max_path);
	// printf("arr %d\n", arr[1]->value);
	// printf("arr %d\n", arr[1]->links[0]->links[0]->value);
	return (prev_max);
}

void	g_diam(char *str)
{
	t_node **arr;

	arr = malloc(1000000);
	build_graph(arr, str);
	ft_putnbr(get_max_path(arr));
}

int main(int ac, char **av)
{
	if (ac == 2)
		g_diam(ft_strdup(av[1]));
	write(1, "\n", 1);
	(void)av;
	return (0);
}
