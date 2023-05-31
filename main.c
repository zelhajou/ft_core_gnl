#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
int main()
{
	char buffer[10];
	int fd = open("test.txt", O_RDONLY);

	// int bytes = read(fd, buffer, 10);
	// printf("%s\n", buffer);
	// bytes = read(fd, buffer, 10);
	// printf("%s", buffer);

	if (fd == -1)
	{
		perror("Failed to open file");
		return 1;
	}

	char *line;
	// while (1)
	// {
	line = get_next_line(fd);
	// if (line == NULL)
	// 	break;
	printf("%s\n", line);
	// }

	close(fd);

	return 0;
}