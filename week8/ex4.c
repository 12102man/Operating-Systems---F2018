#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
	char* memory;
	struct rusage usage;
	
	for(int i=0; i<10;i++) {
		memory = calloc(10485760, 1);
		getrusage(RUSAGE_SELF, &usage);

		printf("\n");
		printf("Iteration %d:\n", i);
		printf("Maximum resident share size: %ld\n", usage.ru_maxrss);
		printf("Integral shared memory size: %ld\n", usage.ru_ixrss);
		printf("Integral unshared data size: %ld\n", usage.ru_idrss);
		printf("Integral unshared stack size: %ld\n", usage.ru_isrss);
		printf("Soft page faults: %ld\n", usage.ru_minflt);
		printf("Hard page faults: %ld\n", usage.ru_majflt);
		printf("Swaps: %ld\n", usage.ru_nswap);

		sleep(1);
	}
}