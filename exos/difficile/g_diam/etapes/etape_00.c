#include <stdio.h>
#include <unistd.h>

int main(int ac, char **av)
{
	if (ac == 2)
	{
		write(1, "abc", 3);
	}
	write(1, "\n", 1);
	(void)av;
	return (0);
}
