#include "main.h"
/**
 * s_cmp - it compares two strings.
 * @s1 : the first string.
 * @s2 : the second string.
 * Return: 0 if true.
 */
int s_cmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	if (*s1 != *s2)
		return (*s1 - *s2);

	return (0);
}

