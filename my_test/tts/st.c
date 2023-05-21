#include "main.h"
int main(void)
{
	size_t n;
        char *buf = malloc(sizeof(char) * n);
	//char *argv[]= {stdin,"", NULL};
	pid_t pid;

     while(1)
      {	
	pid = fork();
	if (pid == -1)
		return -1;
	
	if (pid == 0)
	{	
		printf("USER/DESKTOP/i$:");
        	getline(&buf, &n, stdin);
        	printf("USER/DESKTOP/$: you typed :%s\n the size is %ld\n", buf, n);
		int val = execve(buf, buf, NULL);
		//int val = execve(argv[0], argv, NULL);
		
		if (val == -1)
			perror("Eirror");
	}
	else
	{	/*sleep(2);
		printf("just a moment...\n");
		sleep(3);*/
		wait(NULL);
		/*printf("done with execve :).\n");*/
	}
	free(buf);
       }
     return (0);
}
