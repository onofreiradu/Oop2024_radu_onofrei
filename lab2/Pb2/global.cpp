#include "global.h"

int name_comp(Student* s1, Student* s2)
{
	float aux;
	aux = strcmp(s1->get_name(), s2->get_name());
	if (aux < 0) return -1;
	if (aux > 0) return 1;
	return 0;
}

int math_comp(Student *s1, Student* s2)
{
	if (s1->get_math_grd() < s2->get_math_grd()) return -1;
	if (s1->get_math_grd() > s2->get_math_grd()) return 1;
	return 0;
}

int history_comp(Student *s1, Student *s2)
{
	if (s1->get_history_grd() < s2->get_history_grd()) return -1;
	if (s1->get_history_grd() > s2->get_history_grd()) return 1;
	return 0;
}

int english_comp(Student* s1, Student *s2)
{
	if (s1->get_english_grd() < s2->get_english_grd()) return -1;
	if (s1->get_english_grd() > s2->get_english_grd()) return 1;
	return 0;
}

int average_comp(Student* s1, Student* s2)
{
	if (s1->average_grd() < s2->average_grd()) return -1;
	if (s1->average_grd() > s2->average_grd()) return 1;
	return 0;
}
