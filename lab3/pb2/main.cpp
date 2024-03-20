#include "Canvas.h"

int main() {
	Canvas cv(50, 50);
	cv.DrawLine(10, 10, 30, 20, '*');
	cv.Print();
	cv.Clear();
	return 0;
}