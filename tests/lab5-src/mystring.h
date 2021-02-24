
#if !defined MYSTRING_H
#define MYSTRING_H

int mystrlen(char * s);
char * mystrcpy(char * dest, char * src);
char * mystrcat(char * dest, char * src);
int mystrcmp(char * s1, char * s2);
char * mystrstr(char * hay, char * needle);
char * mystrdup(char * s);
char * mymemcpy(char * dest, char * src, int n);

#endif



