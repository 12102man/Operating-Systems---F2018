#include <stdio.h>
#include <stdlib.h>


int main(void) {
 	while(1) {
 		char command[100];
 		printf(">");
 		scanf("%s", command);
 		system(command);
 	}
}