#include "main.h"

int main(void)
{
	size_t n;
	char *buf = malloc(sizeof(char) * n);
	printf("USER/DESKTOP/$:");
	getline(&buf, &n, stdin);
	printf("USER/DESKTOP/$: you typed :%s\n the size is %ld\n", buf, n);
	return (0);
}
