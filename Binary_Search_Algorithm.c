/*
--		Binary Search(or binary chop) is a search algorithm that                 --
--		finds the position of a target value within a sorted array.              --


--		This example prepared for integer arrays.
--		Still, it can be easily transform to other types like double.            --
*/

#pragma warning(disable:4996)//To close scanf warning on VS-17. Unless you use Visual Studio 2017, it's not necessary.

//Headers..
#include <stdio.h>

//Prototypes,
int binarySearch(int *, int, int, int);//BinarySearch Algorithm with recursive method.

int main() {

	int arr[] = { 2,4,6,8,10,12,14 };
	int n = 6;//Array's last element index.

	int result = binarySearch(arr, 0, n, 12);//12 is searched element.

	if (result == -1)
		printf("Number is not present in array. \n\n");
	else
		printf("Number is present at index %d . \n\n", result);

	return 0;
}//End of main-func.

int binarySearch(int *arr, int start, int end, int num) {
	if (end >= start) {
		int mid = start + (end - start) / 2;

		if (arr[mid] == num) {
			return mid;
		}
		else if (arr[mid] > num) {
			return binarySearch(arr, start, mid - 1, num);
		}
		else if (arr[mid] < num) {
			return binarySearch(arr, mid + 1, end, num);
		}
	}//End of outside if-statement.

	return -1;
}//End of binarySearch func.
