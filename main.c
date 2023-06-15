#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
int main(int ac, char **av)
{
	char	buffer[10];
	int		fd = open(av[1], O_RDONLY);


	if (fd == -1)
	{
		perror("Failed to open file");
		return 1;
	}

	char *line;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		printf("%s", line);
			// printf("%lu\n", strlen(line));
			free(line);
	}

	close(fd);
	return 0;
}