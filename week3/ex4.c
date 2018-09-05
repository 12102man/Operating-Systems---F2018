#include <stdio.h>
#define ARR_SIZE(a) (sizeof(a) / sizeof(*a))

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void print_array(int arr[], int size) {
	for (int i=0; i<size; i++) {
		printf("%d", arr[i]);
		printf(" ");
	}
	printf("\n");
}

int partition (int arr[], int start, int end) 
{ 
    int pivot = arr[end];
    int i = (start - 1);  
  
    for (int j = start; j <= end- 1; j++) { 
        if (arr[j] <= pivot) { 
            i++; 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[end]); 
    return (i + 1); 
} 

void quick_sort(int arr[], int start, int end)
{
    if (start < end) {
        int pivot = partition(arr, start, end);
        quick_sort(arr, start, pivot- 1); 
        quick_sort(arr, pivot+ 1, end); 
    }
}



int main() {
	int arr[] = {5,4,3,2,1}; 
    quick_sort(arr, 0, ARR_SIZE(arr)-1); 
    print_array(arr, ARR_SIZE(arr)); 
    return 0; 
}