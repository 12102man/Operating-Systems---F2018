#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char *argv[] ) {
	int add = 0;
	FILE *output;
	int buffer;

	if (strcmp(argv[1], "tee") != 0) {
		printf("Sorry, not a tee\n");
		return 0;
	}

	if (strcmp(argv[2], "-a") == 0) {
		add = 1;
	}

	if (add == 0) {
		output = fopen(argv[3], "w");
	} else {
		output = fopen(argv[3], "a");
	}

	while (read(0, &buffer, 1) > 0) {
        fprintf(output, "%c", buffer);
        printf("%c", buffer);
    }
    fclose(output);

}
