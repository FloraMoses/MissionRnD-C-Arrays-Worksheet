/*
OVERVIEW: In a given ascending sorted array, two numbers are changed their position, please fix those two numbers.
E.g.: In [10, 40, 30, 20, 50] 20 and 40 are swapped, so final output will be [10, 20, 30, 40, 50]

INPUTS: Ascending sorted array with two positions swapped, length of the array.

OUTPUT: Update sorted array by fixing swapped numbers.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>

void * sortedArrayPositionsChange(int *Arr, int len)
{
	if (Arr == NULL || len <= 0) {
		return NULL;
	}
	int index = -1, index1 = -1;
	for (int i = 0; i < len - 1; i++) {
		if (Arr[i] > Arr[i + 1]) {
			index = i;
			break;
		}
	}
	if (index != -1) {
		for (int i = len - 1; i > index; i--) {
			if (Arr[i] < Arr[i - 1]) {
				index1 = i;
				break;
			}
		}
		int temp = Arr[index];
		Arr[index] = Arr[index1];
		Arr[index1] = temp;
	}
	return NULL;
}