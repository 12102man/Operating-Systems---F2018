#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	int times = atoi(argv[1]);
	for (int i=0; i<3;i++){
		fork();
		sleep(5);
	}

	
	return 0;
}
