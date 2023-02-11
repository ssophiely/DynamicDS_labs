#include <iostream>
#include "Header.h"

int main()
{
	setlocale(0, "");
	Element* s1 = create_empty_set();
	std::cout << "Множество s1:   " << print(s1, ",") << std::endl;
	std::cout << "Мощность s1:   " << capacity_of(s1)<< std::endl;
	std::cout << "в множ   " << in_set(s1,56) << std::endl;
	s1=add(s1, 56);
	std::cout << "Множество s1:   " << print(s1, ",") << std::endl;
	std::cout << "Мощность s1:   " << capacity_of(s1) << std::endl;
	s1 = add(s1, 89);
	std::cout << "Множество s1:   " << print(s1, ",") << std::endl;
	return 0;
}

