#include <iostream>
#include "Header.h"

int main()
{
	setlocale(0, "");
	srand(time(NULL));

	Element* A = create_set(6 + rand() % 4, 20, 90, 1);
	Element* B = create_set(6 + rand() % 4, 10, 90, 0);

	std::cout << "Мощность A:  " << capacity_of(A) << "\n\n";
	std::cout << "Мощность B:  " << capacity_of(B) << "\n\n";

	std::cout << "Множество A:\n" << print(A, "  ") << "\n\n";
	std::cout << "Множество B:\n" << print(B, "  ") << "\n\n";

	if (is_subset(A, B)) {
		std::cout << "A - подмножество B" << "\n\n";
	}
	else {
		std::cout << "A не подмножество B" << "\n\n";
	}

	if (is_equal(A, B)) {
		std::cout << "A равно B" << "\n\n";
	}
	else {
		std::cout << "A не равно B" << "\n\n";
	}

	if (is_subset(A, A)) {
		std::cout << "A - подмножество A" << "\n\n";
	}
	else {
		std::cout << "A не подмножество A" << "\n\n";
	}

	if (is_equal(A, A)) {
		std::cout << "A равно A" << "\n\n";
	}
	else {
		std::cout << "A не равно A" << "\n\n";
	}

	std::cout << "A + B:  " << print(set_union(A, B), ", ");

	std::cout << "\n\n";
	std::cout << "A * B:  " << print(set_intersection(A, B), ", ");

	std::cout << "\n\n";
	std::cout << "A - B:  " << print(set_difference(A, B), ", ");

	std::cout << "\n\n";
	std::cout << "B - A:  " << print(set_difference(B, A), ", ");

	std::cout << "\n\n";
	std::cout << "Симметричная разность A и B:  " << print(set_symmetric_difference(A, B), ", ") << "\n\n";

	system("pause");
	return 0;
}