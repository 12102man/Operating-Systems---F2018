#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<sys/types.h> 
#include<string.h> 
#include<sys/wait.h> 



int main() {
	int channel[2];
	pipe(channel);
	write(channel[1], "Hello!", 7);
	close(channel[1]);

	char concat_str[7]; 
	read(channel[0], concat_str, 7);
	printf("%s\n",concat_str);
	close(channel[0]);
}св