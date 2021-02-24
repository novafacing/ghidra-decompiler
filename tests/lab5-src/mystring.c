#include <stdlib.h>
#include "mystring.h"

int mystrlen(char * s) {
    int r = 0;
	while (*s != '\0') s++, r++;
	return r;
}

char * mystrcpy(char * dest, char * src) {
	char * r = dest;
	int l = mystrlen(src);
	int i = 0;
	while (i < l) {
		*dest = *src;
		dest++, src++, i++;
	}
	*dest = '\0';
	return r;
}

char * mystrcat(char * dest, char * src) {
    char* r = dest;
    while (*dest != '\0') {
	dest++;
    }
    mystrcpy(dest, src);
    return r;
}


int mystrcmp(char * s1, char * s2) {
    while (*s1 == *s2 && *s1 != '\0' && *s2 != 0) s1++, s2++;
    if (*s1 == '\0' && *s2 == '\0') return 0;
    if ((*s1 - *s2) < 0) return -1;
    if ((*s1 - *s2) > 0) return 1;
    return -1;
}

char * mystrstr(char * hay, char * needle) {
    while (*hay != '\0') {
	if (*hay == *needle && *hay != '\0' && *needle != '\0') {
	    char* r = hay;
	    char* a = needle;
	    while(*hay == *needle && *hay != '\0' && *needle != '\0') hay++, needle++;
	    if (*needle == '\0') return r;
	    hay = r;
	    needle = a;
	}
	hay++;
    }
    return NULL;
}

char * mystrdup(char * s) {
    char* r = (char*)malloc(mystrlen(s) * sizeof(char));
    mystrcpy(r, s);
    return r;
}

char * mymemcpy(char * dest, char * src, int n)
{
	for (int i = 0; i < n; i++) {
		*dest = *src;
		dest++, src++;
	}
}

