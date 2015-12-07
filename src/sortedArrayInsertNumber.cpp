/*
OVERVIEW: Given a sorted array, insert a given number into the array at appropriate position.
			E.g.: Arr = [2, 4, 6], num = 5 final Arr = [2, 4, 5, 6]. 5 is inserted at 2nd index.

INPUTS: Integer	Array pointer, length of the array, number to be inserted.

OUTPUT: Array pointer after inserting number.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Use realloc to allocate memory.
*/

#include <stdio.h>
#include <malloc.h>
int binary(int*, int, int);
void increase(int**);
int * sortedArrayInsertNumber(int *Arr, int len, int num) {
	if (Arr == NULL || len <= 0)
		return NULL;
	int index = binary(Arr, len, num);
	increase(&Arr);
	for (int i = index; i <= len; i++) {
		num = num + Arr[i];
		Arr[i] = num - Arr[i];
		num = num - Arr[i];
	}
	return Arr;
}
void increase(int** Arr) {
	*Arr = (int*)realloc(*Arr, 6 * sizeof(int));
}
int binary(int *Arr, int len, int num) {
	int first = 0;
	int last = len - 1;
	int mid = (first + last) / 2;
	while (first <= last) {
		if (Arr[mid] < num)
			first = mid + 1;
		else if (Arr[mid] == num)
			return mid;
		else
			last = mid - 1;
		mid = (first + last) / 2;
	}
	if (mid == 0)
		return mid;
	else
		return mid + 1;
}