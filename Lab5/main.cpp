#include <iostream>
#include "Hclass_list.h"
#include "Hstruct_list.h"
#include "Hlist.h"
#include "Hset.h"
#include <chrono>
#include <iomanip>
using namespace std::chrono;
using namespace std;

int main()
{
	setlocale(0, "");
	int N;
	cout << "Введите мощность множеств    ";
	cin >> N;

	// Структура
	auto struct1 = chrono::steady_clock::now();
	Element* A = create_set(N, 0, 10 * N, 5);
	auto struct11 = chrono::steady_clock::now();
	Element* B = create_set(N, 0, 10 * N, 10);

	auto struct2 = chrono::steady_clock::now();
	int s = capacity_of(A);
	auto struct22 = chrono::steady_clock::now();

	auto struct3 = chrono::steady_clock::now();
	bool f1 = is_subset(A, A);
	auto struct33 = chrono::steady_clock::now();

	auto struct4 = chrono::steady_clock::now();
	f1 = is_subset(B, A);
	auto struct44 = chrono::steady_clock::now();

	auto struct5 = chrono::steady_clock::now();
	f1 = is_equal(A, A);
	auto struct55 = chrono::steady_clock::now();

	auto struct6 = chrono::steady_clock::now();
	f1 = is_equal(B, A);
	auto struct66 = chrono::steady_clock::now();

	auto struct7 = chrono::steady_clock::now();
	Element* C = set_union(A, B);
	auto struct77 = chrono::steady_clock::now();

	auto struct8 = chrono::steady_clock::now();
	C = set_intersection(A, B);
	auto struct88 = chrono::steady_clock::now();

	auto struct9 = chrono::steady_clock::now();
	C = set_difference(A, B);
	auto struct99 = chrono::steady_clock::now();

	auto struct10 = chrono::steady_clock::now();
	C = set_difference(B, A);
	auto struct100 = chrono::steady_clock::now();

	auto struct20 = chrono::steady_clock::now();
	C = set_symmetric_difference(A, B);
	auto struct200 = chrono::steady_clock::now();


	// Класс множество
	auto class1 = chrono::steady_clock::now();
	Set A1 = Set(N, 0, 10 * N, 5);
	auto class11 = chrono::steady_clock::now();
	Set B1 = Set(N, 0, 10 * N, 10);

	auto class2 = chrono::steady_clock::now();
	s = A1.size();
	auto class22 = chrono::steady_clock::now();

	auto class3 = chrono::steady_clock::now();
	f1 = A1.is_subset(B1);
	auto class33 = chrono::steady_clock::now();

	auto class4 = chrono::steady_clock::now();
	f1 = B1.is_subset(A1);
	auto class44 = chrono::steady_clock::now();

	auto class5 = chrono::steady_clock::now();
	f1 = A1.is_equal(A1);
	auto class55 = chrono::steady_clock::now();

	auto class6 = chrono::steady_clock::now();
	f1 = A1.is_equal(B1);
	auto class66 = chrono::steady_clock::now();

	auto class7 = chrono::steady_clock::now();
	Set D = A1.set_union(B1);
	auto class77 = chrono::steady_clock::now();

	auto class8 = chrono::steady_clock::now();
	D = A1.set_intersection(B1);
	auto class88 = chrono::steady_clock::now();

	auto class9 = chrono::steady_clock::now();
	D = A1.set_difference(B1);
	auto class99 = chrono::steady_clock::now();

	auto class10 = chrono::steady_clock::now();
	D = B1.set_difference(A1);
	auto class100 = chrono::steady_clock::now();

	auto class20 = chrono::steady_clock::now();
	D = A1.set_symmetric_difference(B1);
	auto class200 = chrono::steady_clock::now();

	//// List
	auto list1 = chrono::steady_clock::now();
	SetL A2 = SetL(N, 0, 10 * N, 5);
	auto list11 = chrono::steady_clock::now();
	SetL B2 = SetL(N, 0, 10 * N, 10);

	auto list2 = chrono::steady_clock::now();
	s = A2.size();
	auto list22 = chrono::steady_clock::now();

	auto list3 = chrono::steady_clock::now();
	f1 = A2.is_subset(B2);
	auto list33 = chrono::steady_clock::now();

	auto list4 = chrono::steady_clock::now();
	f1 = B2.is_subset(A2);
	auto list44 = chrono::steady_clock::now();

	auto list5 = chrono::steady_clock::now();
	f1 = A2.is_equal(A2);
	auto list55 = chrono::steady_clock::now();

	auto list6 = chrono::steady_clock::now();
	f1 = A2.is_equal(B2);
	auto list66 = chrono::steady_clock::now();

	auto list7 = chrono::steady_clock::now();
	SetL E = A2.set_union(B2);
	auto list77 = chrono::steady_clock::now();

	auto list8 = chrono::steady_clock::now();
	E = A2.set_intersection(B2);
	auto list88 = chrono::steady_clock::now();

	auto list9 = chrono::steady_clock::now();
	E = A2.set_difference(B2);
	auto list99 = chrono::steady_clock::now();

	auto list10 = chrono::steady_clock::now();
	E = B2.set_difference(A2);
	auto list100 = chrono::steady_clock::now();

	auto list20 = chrono::steady_clock::now();
	E = A2.set_symmetric_difference(B2);
	auto list200 = chrono::steady_clock::now();

	// Set
	auto set1 = chrono::steady_clock::now();
	SetS A3 = SetS(N, 0, 10 * N, 5);
	auto set11 = chrono::steady_clock::now();
	SetS B3 = SetS(N, 0, 10 * N, 10);

	auto set2 = chrono::steady_clock::now();
	s = A3.size();
	auto set22 = chrono::steady_clock::now();

	auto set3 = chrono::steady_clock::now();
	f1 = A3.is_subset(B3);
	auto set33 = chrono::steady_clock::now();

	auto set4 = chrono::steady_clock::now();
	f1 = B3.is_subset(A3);
	auto set44 = chrono::steady_clock::now();

	auto set5 = chrono::steady_clock::now();
	f1 = A3.is_equal(A3);
	auto set55 = chrono::steady_clock::now();

	auto set6 = chrono::steady_clock::now();
	f1 = A3.is_equal(B3);
	auto set66 = chrono::steady_clock::now();

	auto set7 = chrono::steady_clock::now();
	SetS F = A3.set_union(B3);
	auto set77 = chrono::steady_clock::now();

	auto set8 = chrono::steady_clock::now();
	F = A3.set_intersection(B3);
	auto set88 = chrono::steady_clock::now();

	auto set9 = chrono::steady_clock::now();
	F = A3.set_difference(B3);
	auto set99 = chrono::steady_clock::now();

	auto set10 = chrono::steady_clock::now();
	F = B3.set_difference(A3);
	auto set100 = chrono::steady_clock::now();

	auto set20 = chrono::steady_clock::now();
	F = A3.set_symmetric_difference(B3);
	auto set200 = chrono::steady_clock::now();

	std::cout << "   ----------------------------------------------------------------------------------------------------------------\n";
	std::cout << std::setw(4) << "|"
		<< std::setw(30) << left << ""
		<< std::setw(3) << "|"
		<< std::setw(28) << "Список на основе структуры"
		<< std::setw(3) << "|"
		<< std::setw(25) << "Список на основе класса"
		<< std::setw(3) << "|"
		<< std::setw(5) << right << "List"
		<< std::setw(4) << "|"
		<< std::setw(6) << "Set"
		<< std::setw(4) << "|"
		<< std::endl;
	std::cout << "   ----------------------------------------------------------------------------------------------------------------\n";

	std::cout << std::setw(4) << "|"
		<< std::setw(30) << left << " Создание множества"
		<< std::setw(3) << "|"
		<< std::setw(28) << chrono::duration_cast<chrono::microseconds>(struct11 - struct1).count()
		<< std::setw(3) << "|"
		<< std::setw(25) << chrono::duration_cast<chrono::microseconds>(class11 - class1).count()
		<< std::setw(3) << "|"
		<< std::setw(5) << chrono::duration_cast<chrono::microseconds>(list11 - list1).count()
		<< std::setw(4) << right << "|"
		<< std::setw(2) << ""
		<< std::setw(5) << left << chrono::duration_cast<chrono::microseconds>(set11 - set1).count()
		<< std::setw(3) << right << "|"
		<< std::endl;
	std::cout << std::setw(4) << "|"
		<< std::setw(30) << left << " Мощность"
		<< std::setw(3) << "|"
		<< std::setw(28) << chrono::duration_cast<chrono::microseconds>(struct22 - struct2).count()
		<< std::setw(3) << "|"
		<< std::setw(25) << chrono::duration_cast<chrono::microseconds>(class22 - class2).count()
		<< std::setw(3) << "|"
		<< std::setw(5) << chrono::duration_cast<chrono::microseconds>(list22 - list2).count()
		<< std::setw(4) << right << "|"
		<< std::setw(2) << ""
		<< std::setw(5) << left << chrono::duration_cast<chrono::microseconds>(set22 - set2).count()
		<< std::setw(3) << right << "|"
		<< std::endl;
	std::cout << std::setw(4) << "|"
		<< std::setw(30) << left << " Подмножество A-A"
		<< std::setw(3) << "|"
		<< std::setw(28) << chrono::duration_cast<chrono::microseconds>(struct33 - struct3).count()
		<< std::setw(3) << "|"
		<< std::setw(25) << chrono::duration_cast<chrono::microseconds>(class33 - class3).count()
		<< std::setw(3) << "|"
		<< std::setw(5) << duration_cast<chrono::microseconds>(list33 - list3).count()
		<< std::setw(4) << right << "|"
		<< std::setw(2) << ""
		<< std::setw(5) << left << chrono::duration_cast<chrono::microseconds>(set33 - set3).count()
		<< std::setw(3) << right << "|"
		<< std::endl;
	std::cout << std::setw(4) << "|"
		<< std::setw(30) << left << " Подмножество B-A"
		<< std::setw(3) << "|"
		<< std::setw(28) << chrono::duration_cast<chrono::microseconds>(struct44 - struct4).count()
		<< std::setw(3) << "|"
		<< std::setw(25) << chrono::duration_cast<chrono::microseconds>(class44 - class4).count()
		<< std::setw(3) << "|"
		<< std::setw(5) << duration_cast<chrono::microseconds>(list44 - list4).count()
		<< std::setw(4) << right << "|"
		<< std::setw(2) << ""
		<< std::setw(5) << left << chrono::duration_cast<chrono::microseconds>(set44 - set4).count()
		<< std::setw(3) << right << "|"
		<< std::endl;
	std::cout << std::setw(4) << "|"
		<< std::setw(30) << left << " Равенство А=A"
		<< std::setw(3) << "|"
		<< std::setw(28) << chrono::duration_cast<chrono::microseconds>(struct55 - struct5).count()
		<< std::setw(3) << "|"
		<< std::setw(25) << chrono::duration_cast<chrono::microseconds>(class55 - class5).count()
		<< std::setw(3) << "|"
		<< std::setw(5) << chrono::duration_cast<chrono::microseconds>(list55 - list5).count()
		<< std::setw(4) << right << "|"
		<< std::setw(2) << ""
		<< std::setw(5) << left << chrono::duration_cast<chrono::microseconds>(set55 - set5).count()
		<< std::setw(3) << right << "|"
		<< std::endl;
	std::cout << std::setw(4) << "|"
		<< std::setw(30) << left << " Равенство A=B"
		<< std::setw(3) << "|"
		<< std::setw(28) << chrono::duration_cast<chrono::microseconds>(struct66 - struct6).count()
		<< std::setw(3) << "|"
		<< std::setw(25) << chrono::duration_cast<chrono::microseconds>(class66 - class6).count()
		<< std::setw(3) << "|"
		<< std::setw(5) << chrono::duration_cast<chrono::microseconds>(list66 - list6).count()
		<< std::setw(4) << right << "|"
		<< std::setw(2) << ""
		<< std::setw(5) << left << chrono::duration_cast<chrono::microseconds>(set66 - set6).count()
		<< std::setw(3) << right << "|"
		<< std::endl;
	std::cout << std::setw(4) << "|"
		<< std::setw(30) << left << " Объединение А и B"
		<< std::setw(3) << "|"
		<< std::setw(28) << chrono::duration_cast<chrono::microseconds>(struct77 - struct7).count()
		<< std::setw(3) << "|"
		<< std::setw(25) << chrono::duration_cast<chrono::microseconds>(class77 - class7).count()
		<< std::setw(3) << "|"
		<< std::setw(5) << chrono::duration_cast<chrono::microseconds>(list77 - list7).count()
		<< std::setw(4) << right << "|"
		<< std::setw(2) << ""
		<< std::setw(5) << left << chrono::duration_cast<chrono::microseconds>(set77 - set7).count()
		<< std::setw(3) << right << "|"
		<< std::endl;
	std::cout << std::setw(4) << "|"
		<< std::setw(30) << left << " Пересечение А и B"
		<< std::setw(3) << "|"
		<< std::setw(28) << chrono::duration_cast<chrono::microseconds>(struct88 - struct8).count()
		<< std::setw(3) << "|"
		<< std::setw(25) << chrono::duration_cast<chrono::microseconds>(class88 - class8).count()
		<< std::setw(3) << "|"
		<< std::setw(5) << chrono::duration_cast<chrono::microseconds>(list88 - list8).count()
		<< std::setw(4) << right << "|"
		<< std::setw(2) << ""
		<< std::setw(5) << left << chrono::duration_cast<chrono::microseconds>(set88 - set8).count()
		<< std::setw(3) << right << "|"
		<< std::endl;
	std::cout << std::setw(4) << "|"
		<< std::setw(30) << left << " Разность А-B"
		<< std::setw(3) << "|"
		<< std::setw(28) << chrono::duration_cast<chrono::microseconds>(struct99 - struct9).count()
		<< std::setw(3) << "|"
		<< std::setw(25) << chrono::duration_cast<chrono::microseconds>(class99 - class9).count()
		<< std::setw(3) << "|"
		<< std::setw(5) << chrono::duration_cast<chrono::microseconds>(list99 - list9).count()
		<< std::setw(4) << right << "|"
		<< std::setw(2) << ""
		<< std::setw(5) << left << chrono::duration_cast<chrono::microseconds>(set99 - set9).count()
		<< std::setw(3) << right << "|"
		<< std::endl;
	std::cout << std::setw(4) << "|"
		<< std::setw(30) << left << " Разность B-A"
		<< std::setw(3) << "|"
		<< std::setw(28) << chrono::duration_cast<chrono::microseconds>(struct100 - struct10).count()
		<< std::setw(3) << "|"
		<< std::setw(25) << chrono::duration_cast<chrono::microseconds>(class100 - class10).count()
		<< std::setw(3) << "|"
		<< std::setw(5) << chrono::duration_cast<chrono::microseconds>(list100 - list10).count()
		<< std::setw(4) << right << "|"
		<< std::setw(2) << ""
		<< std::setw(5) << left << chrono::duration_cast<chrono::microseconds>(set100 - set10).count()
		<< std::setw(3) << right << "|"
		<< std::endl;
	std::cout << std::setw(4) << "|"
		<< std::setw(30) << left << " Симметричная разность А и B"
		<< std::setw(3) << "|"
		<< std::setw(28) << chrono::duration_cast<chrono::microseconds>(struct200 - struct20).count()
		<< std::setw(3) << "|"
		<< std::setw(25) << chrono::duration_cast<chrono::microseconds>(class200 - class20).count()
		<< std::setw(3) << "|"
		<< std::setw(5) << chrono::duration_cast<chrono::microseconds>(list200 - list20).count()
		<< std::setw(4) << right << "|"
		<< std::setw(2) << ""
		<< std::setw(5) << left << chrono::duration_cast<chrono::microseconds>(set200 - set20).count()
		<< std::setw(3) << right << "|"
		<< "\n";
	std::cout << "   ----------------------------------------------------------------------------------------------------------------\n\n";


	system("pause");
	return 0;

}
