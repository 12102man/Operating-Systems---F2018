#include <stdio.h>

int main() {
	int n;
	scanf("%d",&n);
	int *array = malloc(sizeof(int));
	for (int i=1; i<=n;i++) {
		realloc(array, (i)*sizeof(int));
		array[i-1] = i;
		printf("%d  ", array[i-1]);
	}
	free(array);
}