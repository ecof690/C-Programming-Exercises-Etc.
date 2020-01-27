/*
--		Insertion sort is a simple sorting algorithm that builds			--
--		the final sorted array (or list) one item at a time.				--


--		This example prepared for integer arrays.							--
--		Still, it can be easily transform to other types like double.       --
*/

#pragma warning(disable:4996)//To close scanf warning on VS-17. Unless you use Visual Studio 2017, it's not necessary.

//Headers..
#include <stdio.h>

//Prototypes,
void print(int*, int);
void insertionSort(int*, int);


int main() {
	int i, n;

	printf("////---  Welcome to Insertion Sorting Algorithm Example !  ---\\\\\\\\ \n\n\n\n");

	printf("Input size of array : ");
	scanf("%d", &n); //n will be use for create int-array.

	int *arr = (int*)malloc(n * sizeof(int));//This line creating dynamically allocated memory.
	printf("Input the elements of the array :");
	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	printf("Original array : ");
	print(arr, n);

	insertionSort(arr, n);

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


void insertionSort(int *arr, int size) {
	int i, j, temp;

	for (i = 1; i < size; i++) {
		temp = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > temp) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = temp;
	}
}//End of insertionSort-func.
