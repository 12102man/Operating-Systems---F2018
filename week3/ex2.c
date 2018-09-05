#include <stdio.h>
 
#define ARR_SIZE(a) (sizeof(a) / sizeof(*a))

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubble_sort(int arr[], int size) {
	for (int i = 0; i<size-1; i++){
		for (int j = 0; j < size-i-1; j++) {
           if (arr[j] > arr[j+1]) {
              swap(&arr[j], &arr[j+1]);
           }
		}
	}
}

void print_array(int arr[], int size) {
	for (int i=0; i<size; i++) {
		printf("%d", arr[i]);
		printf(" ");
	}
	printf("\n");
}

int main() {
	int arr[] = {5,4,3,2,1};
	bubble_sort(arr, ARR_SIZE(arr));
	print_array(arr, ARR_SIZE(arr));

	return 0;
}