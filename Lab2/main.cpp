#include <iostream>
#include "set.h"

int main()
{
	setlocale(0, "");
	srand(time(NULL));

	Set A = Set(6 + rand() % 4, 20, 90, 1);
	Set B = Set(6 + rand() % 4, 10, 90, 0);

	std::cout << "Мощность A:  " << A.size() << "\n\n";
	std::cout << "Мощность B:  " << B.size() << "\n\n";

	std::cout << "Множество A:\n" << A.print("  ") << "\n\n";
	std::cout << "Множество B:\n" << B.print("  ") << "\n\n";

	if (A.is_subset(B)) {
		std::cout << "A - подмножество B" << "\n\n";
	}
	else {
		std::cout << "A не подмножество B" << "\n\n";
	}

	if (A.is_equal(B)) {
		std::cout << "A равно B" << "\n\n";
	}
	else {
		std::cout << "A не равно B" << "\n\n";
	}

	if (A.is_subset(A)) {
		std::cout << "A - подмножество A" << "\n\n";
	}
	else {
		std::cout << "A не подмножество A" << "\n\n";
	}

	if (A.is_equal(A)) {
		std::cout << "A равно A" << "\n\n";
	}
	else {
		std::cout << "A не равно A" << "\n\n";
	}

	std::cout << "A + B:  " << A.set_union(B).print(", ");

	std::cout << "\n\n";
	std::cout << "A * B:  " << A.set_intersection(B).print(", ");

	std::cout << "\n\n";
	std::cout << "A - B:  " << A.set_difference(B).print(", ");

	std::cout << "\n\n";
	std::cout << "B - A:  " << B.set_difference(A).print(", ");

	std::cout << "\n\n";
	std::cout << "Симметричная разность A и B:  " << A.set_symmetric_difference(B).print(", ") << "\n\n";

	system("pause");
	return 0;
}
