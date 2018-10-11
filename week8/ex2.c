#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
	char* memory;
	for(int i=0; i<10;i++) {
		printf("Allocating... i=%d\n", i);
		memory = calloc(10485760, 1);
		sleep(1);
	}
}