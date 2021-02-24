
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "array.h"

double a[] = {4, 7, 2, 6, 1, 8, 9, 2, 11, -1, 3, 12};
int n = sizeof(a)/sizeof(double);

void test1() {
  double s = sumArray(n, a);
  printf("sumArray=%lf\n", s);
}

void test2() {
  double s = maxArray(n, a);
  printf("maxArray=%lf\n", s);
}

void test3() {
  double s = minArray(n, a);
  printf("minArray=%lf\n", s);
}

void test4() {
  int i = findArray(n, a, 8.5, 10);
  printf("findArray=%d\n", i);
}

void test5() {
  printArray(n, a);
}

void test6() {
  printArray(n, a);
  printf("-----------\n");
  sortArray(n,a);
  printArray(n, a);
}

int main(int argc, char ** argv) {

  char * test;
  
  if (argc <2) {
    printf("Usage: test_array test1|test2|test3|test4|test5|test6\n");
    exit(1);
  }
  
  test = argv[1];
  printf("Running %s\n", test);
  if (strcmp(test, "test1")==0) {
    test1();
  }
  else if (strcmp(test, "test2")==0) {
    test2();
  }
  else if (strcmp(test, "test3")==0) {
    test3();
  }
  else if (strcmp(test, "test4")==0) {
    test4();
  }
  else if (strcmp(test, "test5")==0) {
    test5();
  }
  else if (strcmp(test, "test6")==0) {
    test6();
  }
  else {
    printf("Test not found!!n");
    exit(1);
  }
  
  return 0;
}

