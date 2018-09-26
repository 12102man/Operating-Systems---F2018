#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<sys/types.h> 
#include<string.h> 
#include<sys/wait.h> 
#include <signal.h>


int main() {
	pid_t p;
	p = fork();

	if (p > 0) {
		printf("I AM PARENT\n");
		sleep(10);
		kill(p, SIGTERM);
		
	} else {
		while(1) {
			printf("Child is alive\n");
			sleep(1);
		}
	}
}