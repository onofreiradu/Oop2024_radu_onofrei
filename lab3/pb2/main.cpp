#include "Canvas.h"

int main() {
	Canvas cv(50, 50);
	cv.FillCircle(25, 25, 10, '*');
	cv.Print();
	cv.Clear();
	return 0;
}