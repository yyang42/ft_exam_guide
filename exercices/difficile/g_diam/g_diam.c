#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct		s_node
{
	int				value;
	struct s_node	**links;
	int				visited;
}					t_node;

#define M10 10 * 1000 * 1000

t_node *arr[M10];
int gmax = 0;

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putstr(char *s)
{
	while (*s)
		write(1, s++, 1);
}

void ft_putnbr(int i)
{
	if (i < 10)
	{
		ft_putchar(i + '0');
	}
	else
	{
		ft_putnbr(i / 10);
		ft_putnbr(i % 10);
	}
}

int ft_strlen(char *s)
{
	int l;

	l = 0;
	while (s[l])
		l++;
	return (l);
}

int ft_atoi(char *s)
{
	int i;

	i = 0;
	while (*s)
	{
		i = i * 10 + *s - '0';
		s++;
	}
	return (i);
}

char **ft_strsplit(char *s, char c)
{
	char **segs;
	int y;
	int x;	
	segs = malloc(sizeof(char *) * (ft_strlen(s) + 1));
	y = 0;
	x = 0;
	segs[y] = malloc(sizeof(char) * (ft_strlen(s) + 1));
	while (*s)
	{
		if (*s == c)
		{
			segs[y][x] = 0;
			y++;
			segs[y] = malloc(sizeof(char) * (ft_strlen(s) + 1));
			x = 0;
		}
		else
		{
			segs[y][x] = *s;
			x++;
		}
		s++;
	}
	segs[++y] = NULL;
	return (segs);
}

void printsegs(char **segs)
{
	while (*segs)
	{
		ft_putstr(*segs);
		ft_putstr("\n");
		segs++;
	}
}


t_node *node_new(int val)
{
	t_node *node;

	node = malloc(sizeof(t_node));
	node->value = val;
	node->visited = 0;
	node->links = malloc(sizeof(t_node) * 10 * 1000);
	node->links[0] = NULL;
	return (node);
}

t_node *node_get(int val)
{
	if (!arr[val])
		arr[val] = node_new(val);
	return (arr[val]);
}

void node_link(t_node *node, t_node *link)
{
	t_node **links;
	int i;

	i = 0;
	links = node->links;
	while (links[i])
	{
		if (links[i] == link)
			return ;
		i++;
	}
	links[i] = link;
	links[i+1] = NULL;
}

void build_nodes(char **segs)
{
	int n1;
	int n2;

	while (*segs)
	{
		n1 = ft_atoi(ft_strsplit(*segs, '-')[0]);
		n2 = ft_atoi(ft_strsplit(*segs, '-')[1]);
		node_link(node_get(n1), node_get(n2));
		node_link(node_get(n2), node_get(n1));
		segs++;
	}
}

void check_links(t_node **links)
{
	printf("link: ");
	while (*links)
	{
		printf("%d ", (*links)->value);
		links++;
	}
	printf("\n");
}

void check_nodes(void)
{
	int i;
	t_node *n;

	i = 0;
	while (i < M10)
	{
		if (arr[i] != NULL)
		{
			n = arr[i];
			printf("val: %d\n", n->value);
			check_links(n->links);
		}
		i++;
	}
}

void reset_graph(void)
{
	int i;
	t_node *n;

	i = 0;
	while (i < M10)
	{
		if (arr[i] != NULL)
		{
			n = arr[i];
			n->visited = 0;
		}
		i++;
	}
}

void max_rec(t_node *n, int cur_max)
{
	t_node **links;
	t_node *l_node;

	n->visited = 1;
	links = n->links;
	cur_max++;
	if (cur_max > gmax)
		gmax = cur_max;
	while (*links)
	{
		l_node = *links;
		if (!l_node->visited)
		{
			max_rec(l_node, cur_max);
			l_node->visited = 0;
		}
		links++;
	}
}

void node_build_max(void)
{
	int i;
	t_node *n;

	i = 0;
	while (i < M10)
	{
		if (arr[i] != NULL)
		{
			n = arr[i];
			max_rec(n, 0);
			reset_graph();
		}
		i++;
	}
}

int main(int ac, char **av)
{
	char **segs;

	if (ac == 2)
	{
		//ft_putstr(av[1]);	
		//ft_putstr("\n=== atoi\n");
		//printf("%d\n", ft_atoi("123456"));
		//ft_putstr("\n=== av\n");
		//ft_putstr(av[1]);
		segs = ft_strsplit(av[1], ' ');
		//ft_putstr("\n=== segs\n");
		//printsegs(segs);
		//ft_putstr("\n=== nodes\n");
		build_nodes(segs);
		//ft_putstr("\n=== check nodes\n");
		//check_nodes();
		node_build_max();
		//ft_putstr("\n=== max\n");
		ft_putnbr(gmax);
	}
	ft_putstr("\n");	
	return (0);
}

