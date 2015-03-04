#include "g_diam.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.c"

t_node *arr[1000000];

t_node *node_new(int node_val)
{
	t_node *node;

	node = malloc(sizeof(t_node));
	node->visited = 0;
	node->value = node_val;
	node->links = malloc(sizeof(t_node) * 10000);
	node->max = 0;
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

void link_nodes(t_node **arr, char **segs)
{
	int node_val;
	int link_val;

	while (*segs)
	{
		node_val = ft_atoi(split_input(*segs, '-')[0]);
		link_val = ft_atoi(split_input(*segs, '-')[1]);
		add_relation(get_node(arr, node_val), get_node(arr, link_val));
		add_relation(get_node(arr, link_val), get_node(arr, node_val));
		segs++;
	}
}

void build_graph(t_node **arr, char *str)
{
	char **segs;

	segs = split_input(str, ' ');
	link_nodes(arr, segs);
}

void get_max_path_rec(t_node *node, int cur)
{
	t_node **links;
	t_node *link_node;

	node->visited = 1;
	links = node->links;
	// printf("cur %d\n", cur);
	// printf("enter node: %d\n", node->value);
	cur++;
	node->max = (cur < node->max ) ? node->max : cur;
	while (*links)
	{
		link_node = *links;
		if (!link_node->visited)
		{
			get_max_path_rec(link_node, cur);
			link_node->visited = 0;
		}
		links++;
	}
}

void print_links(t_node *node)
{
	t_node **links;

	links = node->links;
	while (*links)
	{
		// printf("node: %d\n", (*links)->value);
		links++;
	}
}

int get_max_path_info(t_node **arr)
{
	int global_max;
	int i;

	global_max = 0;
	i = 0;
	while (i < 100000)
	{
		if (arr[i])
		{
			// printf("== start node %d ==\n", arr[i]->value);
			print_links(arr[i]);
		}
		i++;
	}
	// printf("====================\n");
	return (global_max);
}

void reset_graph(t_node **arr)
{
	int i;

	i = 0;
	while (i < 100000)
	{
		if (arr[i])
		{
			arr[i]->visited = 0;	
		}
		i++;
	}
}

int get_max_path(t_node **arr)
{
	int global_max;
	int i;

	global_max = 0;
	i = 0;
	while (i < 100000)
	{
		if (arr[i])
		{
			// printf("== start node %d ==\n", arr[i]->value);
			get_max_path_rec(arr[i], 1);
			arr[i]->max--;
			global_max = (global_max < arr[i]->max) ? arr[i]->max : global_max;
			reset_graph(arr);
		}
		i++;
	}
	return (global_max);
}

void	g_diam(char *str)
{
	build_graph(arr, str);
	// get_max_path_info(arr);
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
