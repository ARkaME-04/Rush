#include <stdlib.h>
#include <unistd.h>
#include "dictionary.h"

#define BUFFER_SIZE 4096

char	*read_dict_file(char *filename)
{
	int	fd;
	int	bytes;
	char    *buffer;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		dict_error();
		free(buffer);
		return (NULL);
	}
	bytes = read(fd, buffer, BUFFER_SIZE);
	if (bytes < 0)
	{
		dict_error();
		free(buffer);
		close(fd);
		return (NULL);
	}
	buffer[bytes] = '\0';
	close(fd);
	return (buffer);
}
