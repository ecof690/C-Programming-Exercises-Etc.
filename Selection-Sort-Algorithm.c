/*
--		The selection sort algorithm sorts an array by repeatedly finding the minimum element  --
--		from unsorted part and putting it at the beginning.                                    --


--		This example prepared for integer arrays.					       --
--		Still, it can be easily transform to other types like double.                          --
*/

#pragma warning(disable:4996)//To close scanf warning on VS-17. Unless you use Visual Studio 2017, it's not necessary.

//Headers..
#include <stdio.h>

//Prototypes,
void print(int*, int);
void selectionSort(int*, int);


int main() {
	int i, n;

	printf("////---  Welcome to Selection Sorting Algorithm Example !  ---\\\\\\\\ \n\n\n\n");

	printf("Input size of array : ");
	scanf("%d", &n); //n will be use for create int-array.

	int *arr = (int*)malloc(n * sizeof(int));//This line creating dynamically allocated memory.
	printf("Input the elements of the array :");
	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	printf("Original array : ");
	print(arr, n);

	selectionSort(arr, n);

	printf("Sorted array : ");
	print(arr, n);

	return 0;
}//End of main-func.


void print(int *arr, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}//End of print-func.


void swap(int *first, int *second) {
	int temp = *first;
	*first = *second;
	*second = temp;
}//End of swap-func.


void selectionSort(int *arr, int n) {
	int i, j, min_temp;

	for (i = 0; i < n - 1; i++) {
		min_temp = i;
		for (j = i + 1; j < n; j++) {
			if (arr[min_temp] > arr[j])
				min_temp = j;
		}
		swap(&arr[min_temp], &arr[i]);
	}
}//End of selectionSort-func.
