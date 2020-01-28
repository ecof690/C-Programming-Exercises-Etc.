/*
--		Bubble Sort is the simplest sorting algorithm that repeatedly steps through the list,  --
--		compares adjacent elements and swaps them if they are in the wrong order.              --


--		This example prepared for integer arrays.					       --
--		Still, it can be easily transform to other types like double.                          --
*/

#pragma warning(disable:4996)//To close scanf warning on VS-17. Unless you use Visual Studio 2017, it's not necessary.

//Headers..
#include <stdio.h>

//Function Prototypes,
void print(int*, int);//Displays the array.
void bubbleSort(int*, int);//BubbleSort Algorithm.

int main() {

	int i, n;

	printf("////---  Welcome to Bubble Sorting Algorithm Example !  ---\\\\\\\\ \n\n\n\n");

	printf("Input size of array : ");
	scanf("%d", &n); //n will be use for create int-array.

	int *arr = (int*)malloc(n * sizeof(int));//This line creating dynamically allocated memory.
	printf("Input the elements of the array :");
	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	printf("Original array : ");
	print(arr, n);

	bubbleSort(arr, n);

	printf("Sorted array : ");
	print(arr, n);

	return 0;
}//End of main-func.


void print(int *arr, int n) {
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}//End of print-func.


void swap(int *first, int *second) {
	int temp = *first;
	*first = *second;
	*second = temp;
}//End of swap-func.


void bubbleSort(int *arr, int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - 1 - i; j++) {
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
		}
	}
}//End of bubbleSort-func.
