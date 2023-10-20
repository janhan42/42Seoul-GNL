#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
	FILE *a;
	int	fd;
	char *line;

	a = fopen("test.txt", "r");
	fd = fileno(a);

	printf("%d\n", fd);
	line = get_next_line(fd);
	printf("get_next_line :%s\n", line);
	line = get_next_line(fd);
	printf("get_next_line :%s\n", line);
	line = get_next_line(fd);
	printf("get_next_line :%s\n", line);
	line = get_next_line(fd);
	printf("get_next_line :%s\n", line);

	fclose(a);
}
