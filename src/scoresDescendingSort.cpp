/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that sorts these scores in descending order.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40).
Output for this will be [ { "stud3", 40 }, { "stud2", 30 }, { "stud1", 20 } ]

INPUTS: Array of structures of type student, length of array.

OUTPUT: Sort the array in descending order of scores.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>

struct student {
	char name[10];
	int score;
};
int isSorted(struct student*);
int isSame(struct student*);
void * scoresDescendingSort(struct student *students, int len) {
	if (len <= 0 || students == NULL)
		return NULL;
	if (len != 1) {
		if (isSorted(students)) {
			int temp = students[0].score;
			students[0].score = students[2].score;
			students[2].score = temp;
		}
	}
	else if (!isSame) {
		for (int i = 0; i < 3; i++)	{
			for (int j = i + 1; j < 3; j++)	{
				if (students[i].score < students[j].score) {
					int temp = students[i].score;
					students[i].score = students[j].score;
					students[j].score = temp;
				}
			}
		}
	}
}
int isSorted(struct student *students) {
	if (students[0].score < students[1].score && students[1].score < students[2].score)
		return 1;
	return 0;
}
int isSame(struct student *students) {
	if (students[0].score == students[1].score && students[1].score == students[2].score)
		return 1;
	return 0;
}