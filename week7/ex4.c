#include <stdio.h>
#include <stdlib.h>

void *custom_realloc(void *ptr, size_t currentLength, size_t newLength)
{
	// If new length is 0, free()
   	if (newLength == 0) {
    	free(ptr);
    	return NULL;
	}
	
	// If there's no pointer given, create a new, using malloc
	else if (!ptr) {
    	return malloc(newLength);
	}

	// If new length is less or equal to current one, just keep it as it was
	else if (newLength <= currentLength) {
    	return ptr;
	}

	// Otherwise, create a bigger pointer and copy the old one in it
	else {
		int *newPointer = malloc(newLength);
    	memcpy(newPointer, ptr, currentLength);
    	free(ptr);		// Free old pointer
    	return newPointer;
	}
}

int main() {
	int *array1 = malloc(3*sizeof(int));
	array1[0] = 100;
	array1[1] = 200;
	array1[2] = 300;
	for (int i=0; i<3; i++) {
		printf("%d ",array1[i]);
	}
	printf("\n");
	int *array2 = custom_realloc(array1, sizeof(int)*3, sizeof(int)*10);
	for (int i=0; i<10; i++) {
		printf("%d ", array2[i]);
	}
}