
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void mymemdump(FILE * fd, char * p , int len);
void orgmemdump(FILE * fd, char * p , int len);

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

int g;

void
printUsage() {
    printf("Usage: testmemdump <1|2|3|4|5>\n");
    exit(1);
}

char * memdump_str( int useMine, char * p , int len) {

	// Send output to buffer.

	// Create buffer
	int maxBufferSize = 10 * 1024;
	char * buffer = (char *) malloc(maxBufferSize);
	if (buffer == NULL) {
		perror("malloc:");
		exit(1);
	}

	// Create a FILE stream that will store into the buffera
	FILE *fd = fmemopen(buffer, maxBufferSize, "w");
	if (fd == NULL) {
		perror("fmemopen:");
		exit(1);
	}

	if (useMine) {
		mymemdump(fd, p, len);
	}
	else {
		orgmemdump(fd, p, len);
	}

	// Close file or it will not be written in string
	fclose(fd);

	return buffer;
}

int
main(int argc, char ** argv) {
  char str[20];
  int a = 5;
  int b = -5;
  double y = 12;
  struct X x;
  struct List * head;

  if ( argc < 2) {
    printUsage();
    exit(1);
  }

  // Get test number
  int testNum = -1;
  sscanf(argv[1], "%d", &testNum);

  if ( testNum < 1 || testNum > 6) {
	printf("Invalid test number\n");
	printUsage();
	exit(1);
  }

  // Initialize some variables in memory
  g = 34;
  x.a = 'A';
  x.i = 9;
  x.b = '0';
  x.p = &x.i;
  strcpy(str, "Hello world\n");

  // Build a list in the heap
  head = (struct List *) malloc(sizeof(struct List));
  head->str=strdup("Welcome ");
  head->next = (struct List *) malloc(sizeof(struct List));
  head->next->str = strdup("to ");
  head->next->next = (struct List *) malloc(sizeof(struct List));
  head->next->next->str = strdup("cs250");
  head->next->next->next = NULL;


  printf("&a=0x%lX\n", (long unsigned int) a);
  printf("&y=0x%lX\n", (long unsigned int) &y);
  printf("&x=0x%lX\n", (long unsigned int) &x.a);
  printf("head=0x%lx\n", (long unsigned int) head);

  char * myoutput;
  char * expectedoutput;

  printf("--------------- Test %d -------------------\n", testNum);

  if ( testNum == 1) {
  	myoutput =   memdump_str(1, (char *) &g, 8);
  	expectedoutput =   memdump_str(0, (char *) &g, 8);
  }
  else if ( testNum == 2) {
  	myoutput =   memdump_str(1, (char *) main, 20);
  	expectedoutput =   memdump_str(0, (char *) main, 20);
  }
  else if ( testNum == 3) {
  	myoutput =   memdump_str(1, (char *) str, 32);
  	expectedoutput =   memdump_str(0, (char *) str, 32);
  }
  else if ( testNum == 4) {
  	myoutput =   memdump_str(1, (char *) &y, 8);
  	expectedoutput =   memdump_str(0, (char *) &y, 8);
  }
  else	if ( testNum == 5) {
  	myoutput =   memdump_str(1, (char *) head, 128);
  	expectedoutput =   memdump_str(0, (char *) head, 128);
  }
  else {
	printf("Invalid test\n");
	exit(1);
  }

  // Print the outputs
  printf("--------- My Output -------\n");
  printf("%s", myoutput);
  printf("--------- Expected Output -------\n");
  printf("%s", expectedoutput);

  // Print the result of the comparison
  printf("---------------------------------\n");
  if (strcmp(myoutput, expectedoutput)==0) {
    printf("Output is the same...\n");
    printf(">>>> Test %d Passed\n", testNum);
    exit(0);
  }
  else {
    printf("Output is different...\n");
    printf("***** Test %d Failed\n", testNum);
    exit(1);
  }

}
