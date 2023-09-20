#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>

#define DELIM " \t\n"
extern char **environ;


/**int main(int ac, char **argv);*/
char *_strdup(const char *str);
char *read_line(void);
char **_tokenizer(char *line);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
int _execute(char **command, char **argv, int idx);
void freeString(char **arr);
char *_getenv(char *variable);
char *_getpath(char *command);
char *_strcpy(char *dest, char *src);
void print_error(char *name, char *cmd, int idx);
char *_itoa(int n);
void reverse_string(char *str, int len);




#endif
