#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define buffer_size 1024

void print_stars(int q){
	for (int i = 0; i<q; i++){
		printf("*");
	}
	printf("\n");
}

void half_yolochka(int *number_of_stars){
	for (int i = 1; i<=*number_of_stars; i++){
		print_stars(i);
	}
	printf("\n");
}

void soviet_union(int j, int *n){
	int number_of_stars = 2*j-1;
	int center = (2*(*n)-2) / 2 - (j-1);
	
	for (int i = 0; i<center ; i++){
		printf(" ");
	} 
	print_stars(number_of_stars);
}

void wall(int *number_of_stars){
	for (int i = 0; i<*number_of_stars; i++){
		print_stars(*number_of_stars);
	}
	printf("\n");
}

void best_triangle(int *number_of_stars){
	for (int i = 1; i<=*number_of_stars; i++){
		print_stars(i);
	}
	for (int i = *number_of_stars-1; i>0; i--){
		print_stars(i);
	}
	printf("\n");
}

int main() {
	int choice, stars;

	printf("Enter choice\n1 - for half_yolochka\n2 - for the best triangle\n3  - for wall\n4 - for Soviet Union (ex3): ");
	scanf("%d",&choice);

	if (choice == 4) {
		printf("Height?");
	} else {
		printf("How many stars?");
	}
	scanf("%d",&stars);

	if (choice == 1) {
		half_yolochka(&stars);
	} else if (choice == 2) {
		best_triangle(&stars);
	} else if (choice == 3) {
		wall(&stars);
	} else if (choice == 4) {
		for (int j=1; j<=stars; j++){
			soviet_union(j, &stars);
		}
	} else {
		printf("Not a command. Sorry, mate\n");
	}
	return 0;
}


