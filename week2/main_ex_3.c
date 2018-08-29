#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define buffer_size 1024

void soviet_union(int j, int *n){
	int number_of_stars = 2*j-1;
	int center = (2*(*n)-2) / 2 - (j-1);
	
	for (int i = 0; i<center ; i++){
		printf(" ");
	} 
	for (int i = 0; i<number_of_stars; i++){
		printf("*");
	}
	printf("\n");
}

int main(int argv, char **argc) {
	int n = atoi(argc[1]);
	for (int j=1; j<=n; j++){
		soviet_union(j, &n);
	}
}


