#include "main.h"
void handle_exit(char *cmd)
{
        if (s_cmp("exit", cmd) == 0)
        {
                free(cmd);
                exit(EXIT_SUCCESS);
        }
}
