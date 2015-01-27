## Difficulte
e.g. count island, maxlenoc, gdiam

building blocks

- read file
```
char	*parsing(char *s)
{
	char *map;
	char *tmp;
	char buff[1025];
	int ret;
	int fd;

	map = (char *)malloc(1000000);
	ret = 1;
	fd = open(s, O_RDONLY);
	while ((ret = read(fd, buff, 1024)))
	{
		buff[ret] = 0;
		ft_strcat(map, buff);
	}
	tmp = strdup(map);
	free(map)
	return (tmp);
}
```