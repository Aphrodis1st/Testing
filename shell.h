#ifndef _SHELL_H_
#define _SHELL_H_

#define MAX_CMND 12

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <stdlib.h>

void openPrompt(char **av, char **env);
int main(int ac, char **av, char **env);


#endif
