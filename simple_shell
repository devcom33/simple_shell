#include "main.h"
void asgn_lptr(char **lptr, size_t *n, char *buffer, size_t b);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
void *_realloc(void *ptr, unsigned int prev_size, unsigned int new_size);

/**
 * asgn_lptr - reassigns a lptr var for _getline.
 * @lptr: the buff to store an input string.
 * @n: sizeee off the lineptr.
 * @buffer: string to assign too lineptr.
 * @b: size of buffer.
 */
void asgn_lptr(char **lptr, size_t *n, char *buffer, size_t b)
{
	if (*lptr == NULL)
	{
		if (b > 120)
			*n = b;
		else
			*n = 120;
		*lptr = buffer;
	}
	else if (*n < b)
	{
		if (b > 120)
			*n = b;
		else
			*n = 120;
		*lptr = buffer;
	}
	else
	{
		_strcpy(*lptr, buffer);
		free(buffer);
	}
}

/**
 * _realloc - it realaloc a memory using malloc and free.
 * @ptr:the pointer to the memory prev..
 * @prev_size: size in bytes of the alloc space for ptr.
 * @new_size: size in bytes for the new k.
 * Return: ptr..
 */
void *_realloc(void *ptr, unsigned int prev_size, unsigned int new_size)
{
	void *memo;
	char *ptr_copy, *fill;
	unsigned int index;

	if (new_size == prev_size)
		return (ptr);

	if (ptr == NULL)
	{
		memo = malloc(new_size);
		if (memo == NULL)
			return (NULL);

		return (memo);
	}

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	ptr_copy = ptr;
	memo = malloc(sizeof(*ptr_copy) * new_size);
	if (memo == NULL)
	{
		free(ptr);
		return (NULL);
	}

	fill = memo;

	for (index = 0; index < prev_size && index < new_size; index++)
		fill[index] = *ptr_copy++;

	free(ptr);
	return (memo);
}

/**
 * _getline - func that read input from some stream.
 * @lptr: bufferrr to store some input.
 * @n: size offf lineptr.
 * @stream: a stream to be raed from.
 * Return: always number of bytes read.
 */
ssize_t _getline(char **lptr, size_t *n, FILE *stream)
{
	static ssize_t input;
	ssize_t ret;
	char c = 'x', *buffer;
	int r;

	if (input == 0)
		fflush(stream);
	else
		return (-1);
	input = 0;

	buffer = malloc(sizeof(char) * 120);
	if (!buffer)
		return (-1);

	while (c != '\n')
	{
		r = read(STDIN_FILENO, &c, 1);
		if (r == -1 || (r == 0 && input == 0))
		{
			free(buffer);
			return (-1);
		}
		if (r == 0 && input != 0)
		{
			input++;
			break;
		}
		if (input >= 120)
			buffer = _realloc(buffer, input, input + 1);

		buffer[input] = c;
		input++;
	}
	buffer[input] = '\0';

	asgn_lptr(lptr, n, buffer, input);

	ret = input;
	if (r != 0)
		input = 0;
	return (ret);
}
