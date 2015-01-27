#include <assert.h>
#include <string.h>

int ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void ft_strcat(char *d, char *s)
{
	while (*d) d++;
	while ((*d++ = *s++));
}

int main(void)
{
	char s[1000];

	assert(ft_strlen("") == 0);
	assert(ft_strlen("coucou") == 6);

	bzero(s, 1000);
	ft_strcat(s, "abc");
	ft_strcat(s, "123");
	assert(strcmp(s, "abc123") == 0);
	return (0);
}
