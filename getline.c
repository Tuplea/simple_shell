#include "main.h"

/**
 *_getline - reads an entire line from stream
 *void: void
 *
 *Return: pointer to the line or NULL if failed
 */
char *_getline(void)
{
	static char buffer[BUFFER_SIZE];
	static int pos;
	static int size;
	char *line = NULL;
	ssize_t read_size = 0;

	while (1)
	{
		if (pos >= size)
	{
		pos = 0;
		size = read(STDIN_FILENO, buffer, BUFFER_SIZE);
		if (size <= 0)
			break;
	}
		while (pos < size)
		{
			if (buffer[pos] == '\n')
			{
				pos++;
				line = realloc(line, read_size + 1);
				if (!line)
					return (NULL);
				line[read_size] = '\0';
				return (line);
			}
			line = realloc(line, read_size + 1);
			if (!line)
				return (NULL);
			line[read_size] = buffer[pos];
			read_size++;
			pos++;
		}
	}
	if (line)
		line[read_size] = '\0';
	return (line);
}
