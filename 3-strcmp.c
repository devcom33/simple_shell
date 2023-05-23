#include "main.h"
/**
 * _strcmp - unction that compares two strings
 * @s1: first function
 * @s2: second function
 * Return: val
 */
int _strcmp(char *s1, char *s2)
{
	int cmp = 0;

	while (*s1 == *s2 && *s1 != '\0')
	{
		s1++;
		s2++;
	}
	if (s1 != s2)
		cmp = *s1 - *s2;

	return (cmp);
}
