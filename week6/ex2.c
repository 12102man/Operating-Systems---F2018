#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<sys/types.h> 
#include<string.h> 
#include<sys/wait.h> 



int main() {
	int channel[2];
	pipe(channel);
	pid_t p;
	p = fork();

	// If parent
	if (p>0) {
		close(channel[0]);
		write(channel[1], "Hello!", 7);
		close(channel[1]);
	}


	// If child
	if (p == 0) {
		char concat_str[7]; 
		close(channel[1]);
        read(channel[0], concat_str, 7); 
        printf("%s\n", concat_str);
        close(channel[0]);
        exit(0);
	}

}