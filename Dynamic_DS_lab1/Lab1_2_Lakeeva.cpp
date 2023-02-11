#include <iostream>
#include "Header.h"

int main()
{
	setlocale(0, "");
	Element* s1 = create_set(10, 10, 50);
	std::cout << "Множество s1:  " << print(s1, ", ") << std::endl;
	std::cout << "Мощность s1:  " << capacity_of(s1);
	return 0;
}

