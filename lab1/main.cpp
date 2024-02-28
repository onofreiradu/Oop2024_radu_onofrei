#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	FILE* f;
	char c = 0;
	f = fopen("in.txt", "r");
	int nr=0, suma=0;
	c = fgetc(f);
	while (c != EOF) {
		
		if (c == '\n') {
			suma += nr;
			nr = 0;
		} else
		if (c >= '0' && c <= '9') {
			nr *= 10;
			nr += c - '0';
		}
		c = fgetc(f);
	} 
	suma = nr;
	printf("%d", suma);
	return 0;
}