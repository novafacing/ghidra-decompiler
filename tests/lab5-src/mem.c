
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void mymemdump(FILE *fd, char * p , int len);

struct X{
  char a;
  int i;
  char b;
  int *p;
};

struct List {
  char * str;
  struct List * next;
};

int
main() {
  char str[20];
  int a = 5;
  int b = -5;
  double y = 12;
  struct X x;
  struct List * head;

  x.a = 'A';
  x.i = 9;
  x.b = '0';
  x.p = &x.i;
  strcpy(str, "Hello world\n");
  printf("&str=0x%lX\n", (unsigned long)str);
  printf("&a=0x%lX\n", (unsigned long)&a);
  printf("&b=0x%lX\n", (unsigned long)&b);
  printf("&x.a=0x%lX\n", (unsigned long)&x.a);
  printf("&x.i=0x%lX\n", (unsigned long)&x.i);
  printf("&x.b=0x%lX\n", (unsigned long)&x.b);
  printf("&x.p=0x%lX\n", (unsigned long)&x.p);
  printf("&y=0x%lX\n", (unsigned long) &y);
  mymemdump(stdout, (char *) &x.a, 64);
  head = (struct List *) malloc(sizeof(struct List));
  head->str=strdup("Welcome ");
  head->next = (struct List *) malloc(sizeof(struct List));
  head->next->str = strdup("to ");
  head->next->next = (struct List *) malloc(sizeof(struct List));
  head->next->next->str = strdup("cs250");
  head->next->next->next = NULL;
  printf("head=0x%lx\n", (unsigned long) head);
  mymemdump(stdout, (char*) head, 256);
}

