#include "Sort.h"

int main() {
	char sir[] = "10,20,50,5\0";
	Sort st(sir);
	st.QuickSort(true);
	st.Print();
	return 0;
}