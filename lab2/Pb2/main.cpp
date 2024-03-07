#include "Student.h"
#include "global.h"
#include <iostream>

int main() {
	char name1[] = "razvan", name2[] = "alex";
	Student s1;
	s1.set_english_grd(5);
	s1.set_history_grd(4);
	s1.set_math_grd(7);
	s1.set_name(name1);
	std::cout << s1.get_name() <<'\n';
	Student s2;
	s2.set_english_grd(3);
	s2.set_history_grd(9);
	s2.set_math_grd(10);
	s2.set_name(name2);
	std::cout << name_comp(&s1, &s2);
	std::cout << average_comp(&s1, &s2);
	return 0;
}