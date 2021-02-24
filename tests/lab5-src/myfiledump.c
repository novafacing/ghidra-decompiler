
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void filedump(char * p , int len) {
	char * orig_pointer = p;
	printf("0x%016lX: ", (unsigned long) p - (unsigned long) orig_pointer);
	for (int i = 1; i < len; i++) {
		int c = p[i - 1] & 0xFF;
		printf("%02X ", c); /* print the current byte */
		
		/* prints the last byte once the array is at the last byte. */
		if (i == len - 1) {
			i++;
			c = p[i - 1] & 0xFF;
			printf("%02X ", c);
		}

		if (i % 16 == 0) {
			printf(" ");
			
			for (int j = i - 16; j < i; j++) {
				int c = p[j] & 0xFF;
				printf("%c", (c > 31 && c < 127) ? c : '.');
			}
			
			printf("\n");
			
			if (i != len) {
				printf("0x%016lX: ", (unsigned long) p + i - (unsigned long)orig_pointer);
			}
		}

		if ((len % 16) != 0 && i == len) {
			if (len < 16) {
				for (int j = i; j < 16; j++) {
					printf("   ");
				}
				printf(" ");
				for (int j = 0; j < len; j++) {
					int c = p[j]&0xFF;
					printf("%c", (c >= 32 && c < 127) ? c : '.');
				}
				printf("\n");
			} else {
				for (int j = i; j % 16 != 0; j++) {
					printf("   ");
				}
				int base = i;
				while (base % 16 != 0) base--;
				printf(" ");
				for (int j = base; j < i; j++) {
					int c = p[j]&0xFF;
					printf("%c", (c >= 32 && c < 127) ? c : '.');
				}
				printf("\n");
			}
		}
	}	
}

int main(int argc, char **argv) {
	FILE *fp = fopen(argv[1], "r");
	if (fp == NULL){
		printf("Error opening file \"%s\"\n", argv[1]);
		exit(0);
	}
	fseek(fp, 0L, SEEK_END);
	int fsize = ftell(fp);
	fseek(fp, 0L, SEEK_SET);
	char * file_contents = (char*)malloc(fsize * sizeof(char));	
	if (argc == 3 && fsize < atoi(argv[2])) {
		fread(file_contents, sizeof(char), fsize, fp);
		filedump(file_contents, fsize);
	} else if (argc < 3) {
		fread(file_contents, sizeof(char), fsize, fp);
		filedump(file_contents, fsize);
	} else {
		fread(file_contents, sizeof(char), atoi(argv[2]), fp);
		filedump(file_contents, atoi(argv[2]));
	}	
}
