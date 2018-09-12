#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define console_RL_BUFSIZE 1024
#define console_TOK_BUFSIZE 64
#define console_TOK_DELIM " \t\r\n\a"


int console_cd(char **args);
int console_help(char **args);
int console_exit(char **args);

char *builtin_str[] = {
  "cd",
  "help",
  "exit"
};

int (*builtin_func[]) (char **) = {
  &console_cd,
  &console_help,
  &console_exit
};

int console_num_builtins() {
  return sizeof(builtin_str) / sizeof(char *);
}

int console_cd(char **args)
{
  if (args[1] == NULL) {
    fprintf(stderr, "console: expected argument to \"cd\"\n");
  } else {
    if (chdir(args[1]) != 0) {
      perror("console");
    }
  }
  return 1;
}

int console_help(char **args)
{
  int i;
  printf("The following are built in:\n");

  for (i = 0; i < console_num_builtins(); i++) {
    printf("  %s\n", builtin_str[i]);
  }

  printf("Use the man command for information on other programs.\n");
  return 1;
}

int console_exit(char **args)
{
  return 0;
}

int console_launch(char **args)
{
  pid_t pid, wpid;
  int status;

  pid = fork();
  if (pid == 0) {
    // Child process
    if (execvp(args[0], args) == -1) {
      perror("console");
    }
    exit(EXIT_FAILURE);
  } else if (pid < 0) {
    // Error forking
    perror("console");
  } else {
    // Parent process
    do {
      wpid = waitpid(pid, &status, WUNTRACED);
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
  }

  return 1;
}

int console_execute(char **args)
{
  int i;

  if (args[0] == NULL) {
    // An empty command was entered.
    return 1;
  }

  for (i = 0; i < console_num_builtins(); i++) {
    if (strcmp(args[0], builtin_str[i]) == 0) {
      return (*builtin_func[i])(args);
    }
  }

  return console_launch(args);
}


char **console_split_line(char *line)
{
  int bufsize = console_TOK_BUFSIZE, position = 0;
  char **tokens = malloc(bufsize * sizeof(char*));
  char *token;

  if (!tokens) {
    fprintf(stderr, "console: allocation error\n");
    exit(EXIT_FAILURE);
  }

  token = strtok(line, console_TOK_DELIM);
  while (token != NULL) {
    tokens[position] = token;
    position++;

    if (position >= bufsize) {
      bufsize += console_TOK_BUFSIZE;
      tokens = realloc(tokens, bufsize * sizeof(char*));
      if (!tokens) {
        fprintf(stderr, "console: allocation error\n");
        exit(EXIT_FAILURE);
      }
    }

    token = strtok(NULL, console_TOK_DELIM);
  }
  tokens[position] = NULL;
  return tokens;
}

char *console_read_line(void)
{
  int bufsize = console_RL_BUFSIZE;
  int position = 0;
  char *buffer = malloc(sizeof(char) * bufsize);
  int c;

  if (!buffer) {
    fprintf(stderr, "console: allocation error\n");
    exit(EXIT_FAILURE);
  }

  while (1) {
    c = getchar();

    if (c == EOF || c == '\n') {
      buffer[position] = '\0';
      return buffer;
    } else {
      buffer[position] = c;
    }
    position++;

    if (position >= bufsize) {
      bufsize += console_RL_BUFSIZE;
      buffer = realloc(buffer, bufsize);
      if (!buffer) {
        fprintf(stderr, "console: allocation error\n");
        exit(EXIT_FAILURE);
      }
    }
  }
}


void console_loop(void) {
	char *line;
	char **args;
	int status;

	do {
		printf("> ");
		line = console_read_line();
		args = console_split_line(line);
		status = console_execute(args);

		free(line);
		free(args);
	} while (status);
}


int main(int argc, char const *argv[])
{
	console_loop();
	return 0;
}