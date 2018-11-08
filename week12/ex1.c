#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
	FILE *f;
    f = fopen("ex1.txt", "w");

	int randomData = open("/dev/random", O_RDONLY);
	char myRandomData[50];
    size_t randomDataLen = 0;
    while (randomDataLen < sizeof myRandomData)
    {
        ssize_t result = read(randomData, myRandomData + randomDataLen, (sizeof myRandomData) - randomDataLen);
        randomDataLen += result;
    }
    close(randomData);
    fprintf(f, "%s", myRandomData);
    fclose(f);
}