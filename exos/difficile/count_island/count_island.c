#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

void	ft_putstr(char *s)
{
	while (*s)
	{
		write(1, s, 1);
		s++;
	}
}

int ft_strlen(char *s)
{
	int len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char *read_map(char *path)
{
	int fd;
	int ret;
	char c;
	int char_pos;
	char *mapstr;

	ret = -1;
	mapstr = malloc(sizeof(char) * (1000 * 1000 * 10));
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	char_pos = 0;
	if (!fd)
		return (NULL);
	while ((ret = read(fd, &c, 1)) > 0)
	{
		if (c != '\n' && c != 'X' && c != '.')
			return (NULL);
		mapstr[char_pos] = c;
		char_pos++;
	}
	if (ret == -1)
		return (NULL);
	mapstr[char_pos] = 0;
	if (mapstr[char_pos - 1] != '\n')
		return (NULL);
	return (mapstr);
}

char **build_map(char *s)
{
	char **map;
	int y;
	int x;
	int line_len;

	line_len = -1;
	map = malloc(sizeof(char *) * (2000));
	y = 0;
	x = 0;
	map[0] = malloc(sizeof(char) * (2000));
	while (*s)
	{
		if (*s == '\n')
		{
			map[y][x] = 0;
			if (line_len == -1)
				line_len = ft_strlen(map[y]);
			else if (line_len != ft_strlen(map[y]))
				return (NULL);
			y++;
			map[y] = malloc(sizeof(char) * (2000));
			x = 0;
		}
		else
		{
			map[y][x] = *s;
			x++;
		}
		s++;
	}
	map[y] = NULL;
	return (map);
}

void print_map(char **map)
{
	while (*map)
	{
		ft_putstr(*map);
		ft_putstr("\n");
		map++;	
	}
}


#include <stdio.h>

void infect(char **map, int y, int x, char count)
{
	if (y >= 0 && x >= 0
		&& map[y]
		&& map[y][x]
		&& map[y][x] == 'X')
	{
		map[y][x] = count;
		infect(map, y + 1, x, count);
		infect(map, y - 1, x, count);
		infect(map, y, x + 1, count);
		infect(map, y, x - 1, count);
	}
}

void travel(char **map)
{
	int x = 0;
	int y = 0;
	char count = '0';

	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'X')
			{
				infect(map, y, x, count);
				count++;
			}
			// write(1, &(map[y][x]), 1);
			x++;
		}
		// write(1, "\n", 1);
		y++;
	}
}

int main(int ac, char **av)
{
	char *map_str;
	char **map;

	if (ac == 2)
	{
		if ((map_str = read_map(av[1])))
		{
			// ft_putstr("====\n");
			// ft_putstr(map_str);
			// ft_putstr("====\n");
			map = build_map(map_str);
			if (map)
			{
				travel(map);
				// ft_putstr("====\n");
				print_map(map);
			}
			else
			ft_putstr("\n");
		}
		else
		{
			ft_putstr("\n");
		}
	}
	(void)av;
	return (0);
}
