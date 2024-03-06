#include "FirstClass.h"
#include <stdio.h>


int main() {
	FirstClass c1;
	printf("Valoarea lui x este %d\n", c1.getX());
	c1.setX(10);
	printf("Valoarea lui x este %d", c1.getX());
	c1.y = 5;
	return 0;
}