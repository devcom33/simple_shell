#include "main.h"
/**
 * main - main function
 * @arc: len argument
 * @arv: arv argument by user
 * @envp: envp argument env
 * Return: 0
 */
int main(int arc, char **arv, char **envp)
{
	if (arc == 1)
	{
		prompt(arv, envp);
	}
	return (0);
}
