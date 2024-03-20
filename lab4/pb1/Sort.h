#pragma once
class Sort
{
	int* vector;
	int nr_elemente;
public:
	Sort(int numar_elemente, int min_element, int max_element);
	Sort(int* vector, int numar_elemente);
	Sort();
	Sort(int count, ...);
	Sort(char* c);
    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
private:
	void quicksort(int st, int dr, bool ascendent = false);
	int partitie(int st, int dr, bool ascendent = false);
};
