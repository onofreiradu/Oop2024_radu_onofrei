#include "NumberList.h"

void NumberList::Init()
{
	this->count = 0;
}

bool NumberList::Add(int x)
{
	if (this->count < 10) {
		this->numbers[this->count] = x;
		count++;
		return true;
	}
	else return false;
}

void NumberList::Sort()
{
	bool sortat = false;
	int aux;
	for (int i = this->count; i > 0 && !sortat; i--) {
		sortat = true;
		for (int j = 0; j < i-1; j++) {
			if (this->numbers[j] > this->numbers[j+1]) {
				aux = this->numbers[j+1];
				this->numbers[j+1] = this->numbers[j];
				this->numbers[j] = aux;
				sortat = false;
			}
		}
	}
}

void NumberList::Print()
{
	for (int i = 0; i < this->count; i++) {
		std::cout << this->numbers[i] << ' ';
	}
	std::cout << '\n';
}
