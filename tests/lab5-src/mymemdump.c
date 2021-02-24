#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void mymemdump(FILE * fd, char * p , int len) {

	fprintf(fd, "0x%016lX: ", (unsigned long) p);
	for (int i=1; i < len; i++) {

		int c = p[i - 1]&0xFF;
		fprintf(fd, "%02X ", c); //print bytes

		if (i == len - 1) {
			i++;
			c = p[i -1]&0xFF;
			fprintf(fd, "%02X ", c); // print last byte
		}

		if (i % 16 == 0 ) { 

			fprintf(fd, " ");

			for (int j = i - 16; j < i; j++) {
				int c = p[j]&0xFF;
				fprintf(fd, "%c", (c >= 32 && c < 127) ? c : '.');
			}

			fprintf(fd,"\n");

			if (i != len) {
				fprintf(fd, "0x%016lX: ", (unsigned long) p + i);
			}
		}
		if ((len % 16) != 0 && i == len) {
			if (len < 16) {
				for (int j = i; j < 16; j++) {
					fprintf(fd, "   ");
				}
				fprintf(fd, " ");
				for (int j = 0; j < len; j++) {
					int c = p[j]&0xFF;
					fprintf(fd, "%c", (c >= 32 && c < 127) ? c : '.');
				}
				fprintf(fd, "\n");
			} else {
				for (int j = i; j % 16 != 0; j++) {
					fprintf(fd, "   ");
				}
				int base = i;
				while (base % 16 != 0) base--;
				fprintf(fd, " ");
				for (int j = base; j < i; j++) {
					int c = p[j]&0xFF;
					fprintf(fd, "%c", (c >= 32 && c < 127) ? c : '.');
				}
				fprintf(fd, "\n");
			}
		}
	}
}

