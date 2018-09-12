#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
	int n = atoi(argv[1]);
	fork();
	if (fork() == 0) {
		printf("Hello from child [%d]\n", getpid()-n);
	} else {
		printf("Hello from parent [%d]\n", getpid()-n);
	}

	return 0;
}