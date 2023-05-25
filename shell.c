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
	bool interactive = (argc == 1 && isatty(STDIN_FILENO));
	prompt(argv, envp, interactive);
	return (0);
}
