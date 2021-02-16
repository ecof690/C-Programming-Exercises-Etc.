/*
--		The merge sort algorithm divides the input array into two halves,                      --
--		calls itself for the two halves, and then merges the two sorted halves.                --
--		At the end of process, you have a sorted array.                                        --


--		This example prepared for integer arrays.
--		Still, it can be easily transform to other types like double.                          --
*/

#pragma warning(disable:4996)//To close scanf warning on VS-17. Unless you use Visual Studio 2017, it's not necessary.

//Headers..
#include <stdio.h>

//Prototypes,
void print(int*, int);
void mergeSort(int*, int, int);


int main() {
	int i, n;

	printf("////---  Welcome to Merge Sorting Algorithm Example !  ---\\\\\\\\ \n\n\n\n");

	printf("Input size of array : ");
	scanf("%d", &n); // n will be use for create int-array.

	int* arr = (int*)malloc(n * sizeof(int));//This line creating dynamically allocated memory.
	printf("Input the elements of the array :");
	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	printf("Original array : ");
	print(arr, n);

	mergeSort(arr, 0, n - 1);

	printf("Sorted array : ");
	print(arr, n);

	return 0;
}//End of main-func.


void print(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}//End of print-func.


void merge(int* arr, int l, int m, int r) {
	int i, j, k;
	int s_sub1 = m - l + 1;
	int s_sub2 = r - m;

	int* temp_arr_L = (int*)malloc(s_sub1 * sizeof(int));//This line creating dynamically allocated memory.
	int* temp_arr_R = (int*)malloc(s_sub2 * sizeof(int));//This line creating dynamically allocated memory.

	for (i = 0; i < s_sub1; i++)
		temp_arr_L[i] = arr[l + i];

	for (j = 0; j < s_sub2; j++)
		temp_arr_R[j] = arr[m + 1 + j];


	i = 0;
	j = 0;
	k = l;


	while (i < s_sub1 && j < s_sub2) {
		if (temp_arr_L[i] <= temp_arr_R[j]) {
			arr[k] = temp_arr_L[i];
			i++;
		}
		else {
			arr[k] = temp_arr_R[j];
			j++;
		}
		k++;
	}


	while (i < s_sub1) {
		arr[k] = temp_arr_L[i];
		i++;
		k++;
	}


	while (j < s_sub2) {
		arr[k] = temp_arr_R[j];
		j++;
		k++;
	}

}//End of merge-func.


// (l: left index, r: right index) of sub-array of the main array to be sorted.
void mergeSort(int* arr, int l, int r) {

	if (l < r) {
		int m = l + (r - l) / 2;//Kind of (l+r)/2

		mergeSort(arr, l, m);//First half for sort.
		mergeSort(arr, m + 1, r);//Second half for sort.

		merge(arr, l, m, r);
	}
}//End of mergeSort-func.