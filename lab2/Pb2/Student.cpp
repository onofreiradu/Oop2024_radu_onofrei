#include "Student.h"

void Student::set_name(const char* inputName)
{
	this->name = inputName;
}

const char* Student::get_name()
{
	return name;
}

void Student::set_math_grd(float input_grade)
{
	if (1.0f <= input_grade && input_grade < 10.0f) {
		this->math_grd = input_grade;
	}
}

void Student::set_history_grd(float input_grade)
{
	if (1.0f <= input_grade && input_grade < 10.0f) {
		this->history_grd = input_grade;
	}
}

void Student::set_english_grd(float input_grade)
{
	if (1.0f <= input_grade && input_grade < 10.0f) {
		this->english_grd = input_grade;
	}
}

float Student::get_history_grd()
{
	return history_grd;
}

float Student::get_english_grd()
{
	return this->english_grd;
}

float Student::get_math_grd()
{
	return this->math_grd;
}

float Student::average_grd()
{
	return ((this->english_grd + this->math_grd + this->history_grd) / 3.0f);
}
