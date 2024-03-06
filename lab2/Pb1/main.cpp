#include "NumberList.h"


int main() {
	NumberList n1;
	n1.Init();
	n1.Add(21);
	n1.Add(10);
	n1.Add(3);
	n1.Add(11);
	n1.Sort();
	n1.Print();
	return 0;
}