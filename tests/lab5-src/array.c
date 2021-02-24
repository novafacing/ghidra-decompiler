
#include <stdio.h>

#include "array.h"

// Return sum of the array
double sumArray(int n, double * array) {
  double sum = 0;
  
  double * p = array;
  double * pend = p+n;

  while (p < pend) {
    sum += *p;
    p++;
  }

  return sum;
}

// Return maximum element of array
double maxArray(int n, double * array) {
	double max = *array;;
	double * aend = array + n;
	while (array < aend) {
		if (*array > max) max = *array;
		array++;
	}
	return max;
}

// Return minimum element of array
double minArray(int n, double * array) {
	double min = *array;
	double * aend = array + n;
	while (array < aend) {
		if (*array < min) min = *array;
		array++;
	}
	return min;
}

// Find the position int he array of the first element x 
// such that min<=x<=max or -1 if no element was found
int findArray(int n, double * array, double min, double max) {
	int position = 0;
	double * abeg = array;
	double * aend = array + n;
	while (array < aend) {
		if (*array <= max && *array >= min) {
			return array - abeg;
		}
		array++;
	}
	return -1;
}

// Sort array without using [] operator. Use pointers 
// Hint: Use a pointer to the current and another to the next element
int sortArray(int n, double * array) {
	double * abeg = array;
	double * aend = array + n;
	while (array < aend) {
		double * curr = array + 1;
		while (curr < aend) {
			if (*curr < *array) {
				double temp = *array;
				*array = *curr;
				*curr = temp;
			}
			curr++;
		}
		array++;
	}
	array = abeg;
}

// Print array
void printArray(int n, double * array) {
	double * abeg = array;
	double * aend = array + n;
	while (array < aend) {
		printf("%d:%.6f\n", array - abeg, *array);
		array++;
	}
}

