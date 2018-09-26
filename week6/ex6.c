#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<sys/types.h> 
#include<string.h> 
#include<sys/wait.h> 
#include<signal.h>


int main() {
	pid_t fork_a, fork_b;

	int channel[2];
	pipe(channel);

	fork_a = fork();
	if (fork_a==0){
		// Child A code
		int status;		// code of B
		read(channel[0], &status, 10);
		printf("[A] Child created\n");
		printf("[A] Waiting for 3 secs\n");
		sleep(6);
		printf("[A] Killing child B (%d)\n", status);
		kill(status, SIGKILL);
		printf("[A] Child B killed\n");
		
	} 
	if (fork_a > 0) {
		//Forking B
		fork_b = fork();
		if (fork_b > 0) {
			int status_code;
			// Parent code
			printf("[P] I am parent of these two debils\n");
			write(channel[1], &fork_b, 10);
			close(channel[0]);
			close(channel[1]);
			printf("[P] Waiting for child B to be killed...\n");

			// waitpid
			waitpid(fork_b, &status_code, 0);
			printf("[P] Process B killed with status %d\n", status_code);
		
		}
		if (fork_b == 0) {
			// Child B code
			printf("[B] Child created. \n");
			sleep(10);
		}
	}
}