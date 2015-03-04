#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void	ft_strcat(char *s1, char *s2)
{
	while (*s1)
		s1++;
	while ((*s1++ = *s2++))
		;
}

char *read_map(char *map)
{
	int fd;
	int ret;
	char *map_str;
	char buff[10001];

	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (NULL);
	map_str = malloc(1000000);
	while ((ret = read(fd, buff, 10000)) > 0)
	{
		buff[ret] = 0;
		if (buff[ret - 1] != '\n')
			return (NULL);
		ft_strcat(map_str, buff);
	}
	close(fd);
	if (ret == -1)
		return (NULL);
	return (map_str);
}

int	line_len(char *s)
{
	int i;
	
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

char **create_map(char *s)
{
	int len;
	char **map;
	int x;
	int y;

	len = line_len(s);
	map = malloc(sizeof(char *) * 10000);
	y = 0;
	x = 0;
	map[y] = malloc(10000);
	while (*s)
	{
		map[y][x] = *s;
		x++;
		if (*s == '\n')
		{
			if (x != len + 1)
				return (NULL);
			map[y][x] = 0;
			x = 0;
			y++;
			map[y] = malloc(100000);
		}
		s++;
	}
	map[y] = NULL;
	return (map);
}

void	mark_map(char **map, int y, int x, char m)
{
	if (!map[y])
		return ;
	if (map[y][x] != 'X')
		return ;
	map[y][x] = m;
	mark_map(map, y - 1, x, m);
	mark_map(map, y + 1, x, m);
	mark_map(map, y, x - 1, m);
	mark_map(map, y, x + 1, m);
}

void	travel_map(char **map)
{
	int x;
	int y;
	char mark;

	y = 0;
	mark = '0';
	while (map[y])
	{
		 x = 0;
		 while (map[y][x])
		 {
		 	if(map[y][x] == 'X')
			{
				mark_map(map, y, x, mark);
				mark++;
			}
			x++;
		 }
		 y++;
	}
}

void	ft_putstr(char *s)
{
	while (*s)
		write(1, s++, 1);
}

void	print_map(char **map)
{
	while (*map)
		ft_putstr(*map++);
}

int	main(int ac, char **av)
{
	char *map_str;
	char **map;

	if (ac == 2)
	{
		map_str = read_map(av[1]);
		if (map_str)
		{
			map = create_map(map_str);
			if (map)
			{
				travel_map(map);
				print_map(map);
			}
			else
				write(1, "\n", 1);	
		}
		else
			write(1, "\n", 1);	
	}
	else
		write(1, "\n", 1);
	return (0);
}
