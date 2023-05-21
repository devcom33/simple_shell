#include "main.h"
#define MAX_C 10
void prompt(char **arv, char **envi)
{	
	pid_t mychild;
	size_t n;
	ssize_t num_c;
	/*char *cmd = malloc(sizeof(char) * n);*/
	char *cmd = NULL;
	char *rgv[MAX_C];
	int i = 0, x, stat/*,path*/;
	
	while (1)
	{
		if (isatty(STDIN_FILENO))
			/*printf("$ ");*/
			write(STDOUT_FILENO,"$ ", 2);
		num_c = getline(&cmd, &n, stdin);
		if (num_c == -1) /*handles the end file case*/
		{ 
			free(cmd);
			exit(EXIT_FAILURE);
		}
		while(cmd[i])
		{
			if (cmd[i] == '\n')
				cmd[i]= '\0';
			i++;
		}
		
		x = 0;

		rgv[x] = strtok(cmd, " \n");
		/*path = handle_p(rgv[0]);*/
		while (rgv[x])
		{	
			x++;
			rgv[x] = strtok(NULL, " \n");
		}
		mychild = fork();
		if (mychild == -1)
		{
			free(cmd);
			exit(EXIT_FAILURE);
		}
		if (mychild == 0)
		{
			if (execve(rgv[0], rgv, envi) == -1)
			{	/*write(4, arv[0], 4);*/
				/*perror(":No such a file or directory");*/
				printf("%s No such a file or directory\n", arv[0]);
			}
		}
		else
			wait(&stat);


	}
	free(cmd), exit(EXIT_SUCCESS);
}


int main(int arc, char **arv, char **envi)
{	if (arc == 1)
	{
		prompt(arv, envi);
	}	
	return (0);
}
