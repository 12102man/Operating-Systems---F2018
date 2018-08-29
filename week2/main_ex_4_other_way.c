#include <stdio.h>
#include <stdlib.h>


void swap(int *x, int *y){
	int z = *x;
	*x=*y;
	*y=z;
}

int main() {
	int *a=malloc(sizeof(int)), *b=malloc(sizeof(int));
	printf("Enter int a: ");
	scanf("%d", a);
	printf("Enter int b: ");
	scanf("%d", b);

	swap(a, b);
	printf("\n\na=%d b=%d\n", *a,*b);

}