#pragma once
#include <cstring>
class Student
{
	char name[30];
	float math_grd, history_grd, english_grd;
public:
	void set_name(char* inputName);
	char * get_name();
	void set_math_grd(float input_grade);
	void set_history_grd(float input_grade);
	void set_english_grd(float input_grade);
	float get_history_grd();
	float get_english_grd();
	float get_math_grd();
	float average_grd();


};

