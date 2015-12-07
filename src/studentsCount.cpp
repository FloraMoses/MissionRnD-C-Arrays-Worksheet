
/*
OVERVIEW:  Write a function that takes ascending sorted student's score array and tells how many 
number of students got more marks and how many students got less marks than the given student.
E.g.: Input array: [10, 20, 30, 40, 50], score: 30, lessCount value is 2 (10, 20 are less than 30),
moreCount value is 2 (40, 50 are greater than 30).

INPUTS: Ascending sorted student marks array, length of the array, one student score, lessCount and
moreCount are to be used to store final results.

OUTPUT: Update lessCount and moreCount with number of students less than and more than given score.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <stdio.h>
int sameElements(int*, int);
void * studentsCount(int *Arr, int len, int score, int *lessCount, int *moreCount) {
	if (Arr == NULL || len < 0) {
		return NULL;
	}
	if (len == 1) {
		if (Arr[0] > score) {
			*lessCount = 0;
			*moreCount = 1;
		}
		else if (Arr[0] < score) {
			*lessCount = 1;
			*moreCount = 0;
		}
		else {
			*lessCount = 0;
			*moreCount = 0;
		}
	}
	else if (sameElements(Arr, len)) {
		if (Arr[0] == score) {
			*lessCount = 0;
			*moreCount = 0;
		}
		else if (Arr[0] < score) {
			*lessCount = len;
			*moreCount = 0;
		}
		else {
			*lessCount = 0;
			*moreCount = len;
		}
	}
	else {
		int index;
		for (int i = 0; i < len; i++) {
			if (Arr[i] >= score) {
				index = i;
				break;
			}
		}
		*lessCount = index;
		if (Arr[index] == score)
			*moreCount = len - index - 1;
		else
			*moreCount = len - index;
	}
	return NULL;
}
int sameElements(int *Arr, int len) {
	int count = 0;
	for (int j = 0; j < len - 1; j++) {
		if (Arr[j] == Arr[j + 1])
			count++;
	}
	if (count == len - 1)
		return 1;
	else return 0;
}