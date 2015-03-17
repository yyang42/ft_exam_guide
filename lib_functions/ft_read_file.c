#include "libft.h"
#include <fcntl.h>

#define BUFF_SIZE 1024

char	*ft_read_file(char *s)
{
	char buff[BUFF_SIZE + 1];
	char *output;
	int ret;
	int fd;

	output = (char *)malloc(1000000);
	*output = '\0';
	fd = open(s, O_RDONLY);
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		buff[ret] = 0;
		ft_strcat(output, buff);
	}
	return (output);
}
