#include <iostream>
#include "Header.h"

int main()
{
	setlocale(0, "");
	Element* s1 = create_set(10, 10, 50);
	if (s1 != nullptr) {
		std::cout << "Множество s1 создано\n";
	}
	else {
		std::cout << "Множество s1 с данными параметрами не может быть создано\n";
	}
	std::cout << "Вывод множества s1:  " << print(s1, ", ") << std::endl;
	std::cout << "Мощность s1:  " << capacity_of(s1) << "\n";

	s1 = clear(s1);
	std::cout << "Удаление s1\n";
	std::cout << "Вывод множества s1:  " << print(s1, ", ") << std::endl;
	std::cout << "Мощность s1:  " << capacity_of(s1) << "\n\n";

	Element* s2 = create_set(5, 25, 27);
	if (s2 != nullptr) {
		std::cout << "Множество s2 создано\n";
	}
	else {
		std::cout << "Множество s2 с данными параметрами не может быть создано\n";
	}
	std::cout << "Вывод множества s2:  " << print(s2, ", ") << std::endl;
	std::cout << "Мощность s2:  " << capacity_of(s2) << "\n\n";

	system("pause");
	return 0;
}

