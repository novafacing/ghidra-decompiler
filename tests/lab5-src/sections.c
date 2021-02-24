#include <stdio.h>
#include <stdlib.h>

int a=5;
int buffer[1000000];

int foo() {
  int d;
  static int e = 5;
  printf("&d=%p &le=%p\n", &d, &e);
}

int main() {
  int b;
  static int c;
  int * p = (int *) malloc(sizeof(int));
  char * str = "Hello World\n";

  printf("&a=%p\n", &a);
  printf("&b=%p &c=%p\n", &b, &c);
  printf("&p=%p p=%p\n", &p, p);
  printf("&str=%p str=%p\n", &str, str);
  foo();
  printf("main=%p &foo=%p\n", main, &foo);
}
