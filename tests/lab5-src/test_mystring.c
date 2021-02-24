
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#include "mystring.h"

void test1() {
	int l = mystrlen("Hello world");
	printf("mystrlen(\"Hello world\")=%d\n", l);

	l = mystrlen("CS240 Programming in C");
	printf("mystrlen(\"CS240 Programming in C\")=%d\n", l);

	l = mystrlen("");
	printf("mystrlen(\"\")=%d\n", l);
	
}

void test2() {
	char a[200];
	char * b;
	b = mystrcpy(a, "Hello world");
	printf("\"%s\"\n", a);
	printf("\"%s\"\n", b);

	b = mystrcpy(a, "");
	printf("\"%s\"\n", a);
	printf("\"%s\"\n", b);
}

void test3() {
	char a[200];
	char * b;
	mystrcpy(a, "Hello world");
	b = mystrcat(a, ", CS240 C Programming");
	b = mystrcat(a, ", This is a great course");
	printf("\"%s\"\n", a);
	printf("\"%s\"\n", b);

	mystrcpy(a, "");
	b = mystrcat(a, "");
	b = mystrcat(b, "Hello");
	
	printf("\"%s\"\n", a);
	printf("\"%s\"\n", b);
}

void test4() {
	int result;
	char *s1, *s2;

	s1 = "banana";
	s2 = "apple";
	result = mystrcmp(s1,s2);
	printf("mystrcmp(\"%s\", \"%s\")=%d\n",s1, s2, result);

	s1 = "apple";
	s2 = "banana";
	result = mystrcmp(s1,s2);
	printf("mystrcmp(\"%s\", \"%s\")=%d\n",s1, s2, result);

	s1 = "appleapple";
	s2 = "applebanana";
	result = mystrcmp(s1,s2);
	printf("mystrcmp(\"%s\", \"%s\")=%d\n",s1, s2, result);

	s1 = "applebanana";
	s2 = "appleapple";
	result = mystrcmp(s1,s2);
	printf("mystrcmp(\"%s\", \"%s\")=%d\n",s1, s2, result);

	s1 = "apple";
	s2 = "apple";
	result = mystrcmp(s1,s2);
	printf("mystrcmp(\"%s\", \"%s\")=%d\n",s1, s2, result);

	s1 = "appleapple";
	s2 = "apple";
	result = mystrcmp(s1,s2);
	printf("mystrcmp(\"%s\", \"%s\")=%d\n",s1, s2, result);

	s1 = "apple";
	s2 = "applebanana";
	result = mystrcmp(s1,s2);
	printf("mystrcmp(\"%s\", \"%s\")=%d\n",s1, s2, result);

	s1 = "applebanana";
	s2 = "apple";
	result = mystrcmp(s1,s2);
	printf("mystrcmp(\"%s\", \"%s\")=%d\n",s1, s2, result);
}

void test5()
{
	char * hay;
	char * needle;
	char * result;
	
	hay = "Hello world. CS240";
	needle = "ld";
	result = mystrstr(hay, needle);
	printf("mystrstr(\"%s\",\"%s\")=\"%s\"\n", hay, needle, result?result:"NULL");
	
	hay = "Hello world. CS240";
	needle = "llo";
	result = mystrstr(hay, needle);
	printf("mystrstr(\"%s\",\"%s\")=\"%s\"\n", hay, needle, result?result:"NULL");
	
	hay = "Hello world. CS240";
	needle = "CS251";
	result = mystrstr(hay, needle);
	printf("mystrstr(\"%s\",\"%s\")=\"%s\"\n", hay, needle, result?result:"NULL");
	
	needle = "Hello world. CS240";
	hay = "CS240";
	result = mystrstr(hay, needle);
	printf("mystrstr(\"%s\",\"%s\")=\"%s\"\n", hay, needle, result?result:"NULL");
	
}

void test6() {

	char * p = "Hello";
	char * q = mystrdup(p);
	int i;

	printf("q=\"%s\"\n", q);

	for (i=0; i<10; i++) {
		q = mystrdup(p);
		printf("(q==p) = %d\n", (q==p)?1:0);
		printf("q=\"%s\"\n", q);
		p = q;
	}
}

void test7()
{
	char * p = "Hello world";
	char q[40];

	mymemcpy(q,p,20);
	printf("q=\"%s\"\n", q);
}

int main(int argc, char ** argv) {

	char * test;
	
	if (argc <2) {
		printf("Usage: test_resizable_table test1|test2|...test7\n");
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
	else if (strcmp(test, "test7")==0) {
		test7();
	}
	else {
		printf("Test not found!!n");
		exit(1);
	}

	return 0;

}
