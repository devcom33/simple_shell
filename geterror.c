#include "main.h"
/**
 */
int intlen(int n)
{
	unsigned int num;
	int len = 1;

	if (n < 0)
	{
		len++;
		num = n * -1;
	}
	else
	{
		num = n;
	}
	while (num > 9)
	{
		len++;
		num = num / 10;
	}

	return (len);
}
/**
 */
char *_itoa(int num)
{
	char *buff;
	size_t  n;
	int len = intlen(num);

	buff = malloc(len + 1);
	if (!buff)
		return (NULL);
	buff[len] = '\0';
	if (num < 0)
	{
		n = num * -1;
		*buff = '-';
	}
	else
		n = num;
	len--;
	do
	{
		*(buff + len) = (n % 10) + '0';
		n /= 10;
		len--;
	}
	while (n > 0);
	return (buff);
}
/**
 * runcmd - a function that run command
 * @rgv: rgv argument
 * @arv: arv argument
 * @envp: envp argument
 */
void geterror(denum *n, char **arv, char *cmd)
{
	int len;
	char *errmsg, *cnt_str;

	cnt_str = _itoa(n->cnt);
	len = _strlen(arv[0]) + _strlen(cmd) + _strlen(cnt_str) + 17;
	errmsg = malloc(len);
	if (!errmsg)
	{
		free(errmsg);
		free(cnt_str);
		return;
	}
	_strcpy(errmsg, arv[0]);
	_strcat(errmsg, ": ");
	_strcat(errmsg, cnt_str);
	_strcat(errmsg, ": ");
	_strcat(errmsg, cmd);
	_strcat(errmsg, ": not found\n");
	_strcat(errmsg, "\0");
	write(STDOUT_FILENO, errmsg, len);
	free(errmsg);
}
