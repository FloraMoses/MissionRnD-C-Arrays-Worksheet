/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that 
returns the names and scores of top K students.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20,
30 , 40) and K value is 2.
return top 2 students [ { "stud2", 30 }, { "stud3", 40 } ]

INPUTS: array of structures of type student, length of the array, integer K.

OUTPUT: Return top K students from array. Output need not be in decreasing order of scores.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include <malloc.h>
struct student* sort1(struct student*, int);
struct student {
	char *name;
	int score;
};
struct student ** topKStudents(struct student *students, int len, int K) {
	if (K <= 0)
		return NULL;
	if (K > len)
		K = len;
	students = sort1(students, len);
	struct student **result = (struct student**)malloc(sizeof(struct student) * K);
	for (int i = len - K, j = 0; i < len; i++, j++) {
		result[j] = &students[i];
	}
	return result;
}
struct student* sort1(struct student *students, int len) {
	struct student temp;
	for (int i = 0; i < len - 1; ++i) {
		for (int j = 0; j < len - i - 1; ++j) {
			if (students[j].score > students[j + 1].score) {
				temp = students[j + 1];
				students[j + 1] = students[j];
				students[j] = temp;
			}
		}
	}
	return students;
}