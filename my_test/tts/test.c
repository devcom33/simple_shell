#include "main.h"
int main(void)
{
	pid_t pid;

	printf("before fork\n");
	pid = fork();

	if (pid == -1)
	{
		perror("unsuccessful\n");
		return 1;
	}
	
	if (pid == 0)
	{	
		printf("child process\n");
	}
	
	else 
	{
		wait(NULL);
		sleep(10);
		printf("parent process\n");
	}
	
	return (0);

}
