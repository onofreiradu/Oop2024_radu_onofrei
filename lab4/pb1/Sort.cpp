#include "Sort.h"
#include "time.h"
#include <stdlib.h>
#include <stdarg.h>
#include <iostream>
Sort::Sort(int numar_elemente, int min_element, int max_element)
{
	vector = new int[numar_elemente];
	this->nr_elemente = numar_elemente;
	time_t t;
	srand((unsigned)time(&t));
	for (int i = 0; i < numar_elemente; i++) {
		this->vector[i] = min_element + rand() % (min_element - max_element + 1);
	}
}

Sort::Sort(int* v, int numar_elemente)
{
	this->nr_elemente = numar_elemente;
	for (int i = 0; i < numar_elemente; i++) {
		this->vector[i] = v[i];
	}

}

Sort::Sort() : vector(new int[6] {1, 2, 3, 4, 5, 6}) {
	this->nr_elemente = 6;
}

Sort::Sort(int count, ...)
{
	this->nr_elemente = count;
	this->vector = new int[count];
	va_list vl;
	va_start(vl, count);
	for (int i = 0; i < count; i++)
	{
		this->vector[i] = va_arg(vl, int);
	}
	va_end(vl);
}

Sort::Sort(char* c)
{
	int indice = 0;
	int count_nr = 1;
	int nr;
	while (c[indice] != '\0') {
		if (c[indice] == ',') count_nr++;
		indice++;
	}
	this->vector = new int[count_nr];
	this->nr_elemente = count_nr;
	indice = 0;
	int indice_cuv = 0;
	while (c[indice] != '\0') {
		nr = 0;
		while (c[indice] >= '0' && c[indice] <= '9') {
			nr = nr * 10 + c[indice] - '0';
			indice++;
		}
		this->vector[indice_cuv++] = nr;
		indice++;
	}
}

void Sort::InsertSort(bool ascendent)
{
	int aux;
	
	for (int i = 1; i < this->nr_elemente; i++) {
		for (int j = i; j > 0; j--) {
			if (ascendent && this->vector[j-1] > this->vector[j] || !ascendent && this->vector[j-1] < this->vector[j]) {
				aux = this->vector[j-1];
				this->vector[j-1] = this->vector[j];
				this->vector[j] = aux;
			}
		}
	}
	
	
	

}


void Sort::QuickSort(bool ascendent)
{
	quicksort(0, this->nr_elemente-1, ascendent);
}

void Sort::BubbleSort(bool ascendent)
{
	int aux;
	for (int i = 0; i < this->nr_elemente-1; i++) {
		for (int j = i + 1; j < this->nr_elemente; j++) {
			if (ascendent && this->vector[j] > this->vector[i] || !ascendent && this->vector[j] < this->vector[i]) {
				aux = this->vector[i];
				this->vector[i] = this->vector[j];
				this->vector[j] = aux;
			}
		}
	}
}

void Sort::Print()
{
	for (int i = 0; i < this->nr_elemente; i++) {
		std::cout << this->vector[i]<<' ';
	}
}

int Sort::GetElementsCount()
{
	return this->nr_elemente;
}

int Sort::GetElementFromIndex(int index)
{
	return this->vector[index];
}

void Sort::quicksort(int st, int dr, bool ascendent)
{
	int poz;
	if (st < dr) {
		poz = partitie(st, dr, ascendent);
		quicksort(st, poz - 1, ascendent);
		quicksort(poz + 1, dr, ascendent);
	}
}

int Sort::partitie(int st, int dr, bool ascendent)
{
	int aux;
	int pivot = this->vector[dr];
	
	int i = (st - 1);

	for (int j = st; j <= dr; j++)
	{
		if (this->vector[j] < pivot && ascendent || this->vector[j] > pivot && !ascendent)
		{
			i++;
			aux = this->vector[i];
			this->vector[i] = this->vector[j];
			this->vector[j] = aux;
		}
	}
	aux = this->vector[i + 1];
	this->vector[i + 1] = this->vector[dr];
	this->vector[dr] = aux;
	return (i + 1);
}

