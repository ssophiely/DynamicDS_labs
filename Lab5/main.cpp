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
	cout << "   Введите мощность множеств    ";
	cin >> N;

	std::cout << "   --------------------------------------------------------------------------------------\n";
	std::cout << std::setw(4) << "|"
		<< std::setw(30) << left << ""
		<< std::setw(5) << "|"
		<< std::setw(12) << "Структура"
		<< std::setw(5) << "|"
		<< std::setw(10) << "Класс"
		<< std::setw(4) << "|"
		<< std::setw(7) << "List"
		<< std::setw(4) << "|"
		<< std::setw(7) << "Set"
		<< std::setw(4) << "|"
		<< std::endl;
	std::cout << "   --------------------------------------------------------------------------------------\n";

	auto list1 = chrono::steady_clock::now();
	SetL A2 = SetL(N, 0, 10 * N, 5);
	auto list11 = chrono::steady_clock::now();
	SetL B2 = SetL(N, 0, 10 * N, 10);

	auto set1 = chrono::steady_clock::now();
	SetS A3 = SetS(N, 0, 10 * N, 5);
	auto set11 = chrono::steady_clock::now();
	SetS B3 = SetS(N, 0, 10 * N, 10);

	auto struct1 = chrono::steady_clock::now();
	Element* A = create_set(N, 0, 10 * N, 5);
	auto struct11 = chrono::steady_clock::now();
	Element* B = create_set(N, 0, 10 * N, 10);

	auto class1 = chrono::steady_clock::now();
	Set A1 = Set(N, 0, 10 * N, 5);
	auto class11 = chrono::steady_clock::now();
	Set B1 = Set(N, 0, 10 * N, 10);


	std::cout << std::setw(4) << right << "|"
		<< std::setw(30) << left << " Создание множества"
		<< std::setw(5) << "|"
		<< std::setw(12) << chrono::duration_cast<chrono::milliseconds>(struct11 - struct1).count()
		<< std::setw(5) << "|"
		<< std::setw(10) << chrono::duration_cast<chrono::milliseconds>(class11 - class1).count()
		<< std::setw(4) << "|"
		<< std::setw(7) << chrono::duration_cast<chrono::milliseconds>(list11 - list1).count()
		<< std::setw(4) << "|"
		<< std::setw(7) << chrono::duration_cast<chrono::milliseconds>(set11 - set1).count()
		<< std::setw(4) << "|"
		<< std::endl;

	auto struct2 = chrono::steady_clock::now();
	int s = capacity_of(A);
	auto struct22 = chrono::steady_clock::now();

	auto class2 = chrono::steady_clock::now();
	s = A1.size();
	auto class22 = chrono::steady_clock::now();

	auto list2 = chrono::steady_clock::now();
	s = A2.size();
	auto list22 = chrono::steady_clock::now();

	auto set2 = chrono::steady_clock::now();
	s = A3.size();
	auto set22 = chrono::steady_clock::now();

	std::cout << std::setw(4) << right << "|"
		<< std::setw(30) << left << " Мощность"
		<< std::setw(5) << "|"
		<< std::setw(12) << chrono::duration_cast<chrono::milliseconds>(struct22 - struct2).count()
		<< std::setw(5) << "|"
		<< std::setw(10) << chrono::duration_cast<chrono::milliseconds>(class22 - class2).count()
		<< std::setw(4) << "|"
		<< std::setw(7) << chrono::duration_cast<chrono::milliseconds>(list22 - list2).count()
		<< std::setw(4) << "|"
		<< std::setw(7) << chrono::duration_cast<chrono::milliseconds>(set22 - set2).count()
		<< std::setw(4) << "|"
		<< std::endl;

	auto struct3 = chrono::steady_clock::now();
	bool f1 = is_subset(A, A);
	auto struct33 = chrono::steady_clock::now();

	auto class3 = chrono::steady_clock::now();
	f1 = A1.is_subset(A1);
	auto class33 = chrono::steady_clock::now();

	auto list3 = chrono::steady_clock::now();
	f1 = A2.is_subset(A2);
	auto list33 = chrono::steady_clock::now();

	auto set3 = chrono::steady_clock::now();
	f1 = A3.is_subset(A3);
	auto set33 = chrono::steady_clock::now();

	std::cout << std::setw(4) << right << "|"
		<< std::setw(30) << left << " Подмножество A-A"
		<< std::setw(5) << "|"
		<< std::setw(12) << chrono::duration_cast<chrono::milliseconds>(struct33 - struct3).count()
		<< std::setw(5) << "|"
		<< std::setw(10) << chrono::duration_cast<chrono::milliseconds>(class33 - class3).count()
		<< std::setw(4) << "|"
		<< std::setw(7) << chrono::duration_cast<chrono::milliseconds>(list33 - list3).count()
		<< std::setw(4) << "|"
		<< std::setw(7) << chrono::duration_cast<chrono::milliseconds>(set33 - set3).count()
		<< std::setw(4) << "|"
		<< std::endl;

	auto struct4 = chrono::steady_clock::now();
	f1 = is_subset(B, A);
	auto struct44 = chrono::steady_clock::now();

	auto class4 = chrono::steady_clock::now();
	f1 = B1.is_subset(A1);
	auto class44 = chrono::steady_clock::now();

	auto list4 = chrono::steady_clock::now();
	f1 = B2.is_subset(A2);
	auto list44 = chrono::steady_clock::now();

	auto set4 = chrono::steady_clock::now();
	f1 = B3.is_subset(A3);
	auto set44 = chrono::steady_clock::now();

	std::cout << std::setw(4) << right << "|"
		<< std::setw(30) << left << " Подмножество В-A"
		<< std::setw(5) << "|"
		<< std::setw(12) << chrono::duration_cast<chrono::milliseconds>(struct44 - struct4).count()
		<< std::setw(5) << "|"
		<< std::setw(10) << chrono::duration_cast<chrono::milliseconds>(class44 - class4).count()
		<< std::setw(4) << "|"
		<< std::setw(7) << chrono::duration_cast<chrono::milliseconds>(list44 - list4).count()
		<< std::setw(4) << "|"
		<< std::setw(7) << chrono::duration_cast<chrono::milliseconds>(set44 - set4).count()
		<< std::setw(4) << "|"
		<< std::endl;

	auto struct5 = chrono::steady_clock::now();
	f1 = is_equal(A, A);
	auto struct55 = chrono::steady_clock::now();

	auto class5 = chrono::steady_clock::now();
	f1 = A1.is_equal(A1);
	auto class55 = chrono::steady_clock::now();

	auto list5 = chrono::steady_clock::now();
	f1 = A2.is_equal(A2);
	auto list55 = chrono::steady_clock::now();

	auto set5 = chrono::steady_clock::now();
	f1 = A3.is_equal(A3);
	auto set55 = chrono::steady_clock::now();

	std::cout << std::setw(4) << right << "|"
		<< std::setw(30) << left << " Равенство A=A"
		<< std::setw(5) << "|"
		<< std::setw(12) << chrono::duration_cast<chrono::milliseconds>(struct55 - struct5).count()
		<< std::setw(5) << "|"
		<< std::setw(10) << chrono::duration_cast<chrono::milliseconds>(class55 - class5).count()
		<< std::setw(4) << "|"
		<< std::setw(7) << chrono::duration_cast<chrono::milliseconds>(list55 - list5).count()
		<< std::setw(4) << "|"
		<< std::setw(7) << chrono::duration_cast<chrono::milliseconds>(set55 - set5).count()
		<< std::setw(4) << "|"
		<< std::endl;

	auto struct6 = chrono::steady_clock::now();
	f1 = is_equal(A, B);
	auto struct66 = chrono::steady_clock::now();

	auto class6 = chrono::steady_clock::now();
	f1 = A1.is_equal(B1);
	auto class66 = chrono::steady_clock::now();

	auto list6 = chrono::steady_clock::now();
	f1 = A2.is_equal(B2);
	auto list66 = chrono::steady_clock::now();

	auto set6 = chrono::steady_clock::now();
	f1 = A3.is_equal(B3);
	auto set66 = chrono::steady_clock::now();

	std::cout << std::setw(4) << right << "|"
		<< std::setw(30) << left << " Равенство A=B"
		<< std::setw(5) << "|"
		<< std::setw(12) << chrono::duration_cast<chrono::milliseconds>(struct66 - struct6).count()
		<< std::setw(5) << "|"
		<< std::setw(10) << chrono::duration_cast<chrono::milliseconds>(class66 - class6).count()
		<< std::setw(4) << "|"
		<< std::setw(7) << chrono::duration_cast<chrono::milliseconds>(list66 - list6).count()
		<< std::setw(4) << "|"
		<< std::setw(7) << chrono::duration_cast<chrono::milliseconds>(set66 - set6).count()
		<< std::setw(4) << "|"
		<< std::endl;

	auto struct7 = chrono::steady_clock::now();
	set_union(A, B);
	auto struct77 = chrono::steady_clock::now();

	auto class7 = chrono::steady_clock::now();
	A1.set_union(B1);
	auto class77 = chrono::steady_clock::now();

	auto list7 = chrono::steady_clock::now();
	A2.set_union(B2);
	auto list77 = chrono::steady_clock::now();

	auto set7 = chrono::steady_clock::now();
	A3.set_union(B3);
	auto set77 = chrono::steady_clock::now();

	std::cout << std::setw(4) << right << "|"
		<< std::setw(30) << left << " Объединение А и B"
		<< std::setw(5) << "|"
		<< std::setw(12) << chrono::duration_cast<chrono::milliseconds>(struct77 - struct7).count()
		<< std::setw(5) << "|"
		<< std::setw(10) << chrono::duration_cast<chrono::milliseconds>(class77 - class7).count()
		<< std::setw(4) << "|"
		<< std::setw(7) << chrono::duration_cast<chrono::milliseconds>(list77 - list7).count()
		<< std::setw(4) << "|"
		<< std::setw(7) << chrono::duration_cast<chrono::milliseconds>(set77 - set7).count()
		<< std::setw(4) << "|"
		<< std::endl;

	auto struct8 = chrono::steady_clock::now();
	set_intersection(A, B);
	auto struct88 = chrono::steady_clock::now();

	auto class8 = chrono::steady_clock::now();
	A1.set_intersection(B1);
	auto class88 = chrono::steady_clock::now();

	auto list8 = chrono::steady_clock::now();
	A2.set_intersection(B2);
	auto list88 = chrono::steady_clock::now();

	auto set8 = chrono::steady_clock::now();
	A3.set_intersection(B3);
	auto set88 = chrono::steady_clock::now();

	std::cout << std::setw(4) << right << "|"
		<< std::setw(30) << left << " Пересечение А и B"
		<< std::setw(5) << "|"
		<< std::setw(12) << chrono::duration_cast<chrono::milliseconds>(struct88 - struct8).count()
		<< std::setw(5) << "|"
		<< std::setw(10) << chrono::duration_cast<chrono::milliseconds>(class88 - class8).count()
		<< std::setw(4) << "|"
		<< std::setw(7) << chrono::duration_cast<chrono::milliseconds>(list88 - list8).count()
		<< std::setw(4) << "|"
		<< std::setw(7) << chrono::duration_cast<chrono::milliseconds>(set88 - set8).count()
		<< std::setw(4) << "|"
		<< std::endl;

	auto struct9 = chrono::steady_clock::now();
	set_difference(A, B);
	auto struct99 = chrono::steady_clock::now();

	auto class9 = chrono::steady_clock::now();
	A1.set_difference(B1);
	auto class99 = chrono::steady_clock::now();

	auto list9 = chrono::steady_clock::now();
	A2.set_difference(B2);
	auto list99 = chrono::steady_clock::now();

	auto set9 = chrono::steady_clock::now();
	A3.set_difference(B3);
	auto set99 = chrono::steady_clock::now();

	std::cout << std::setw(4) << right << "|"
		<< std::setw(30) << left << " Разность А и B"
		<< std::setw(5) << "|"
		<< std::setw(12) << chrono::duration_cast<chrono::milliseconds>(struct99 - struct9).count()
		<< std::setw(5) << "|"
		<< std::setw(10) << chrono::duration_cast<chrono::milliseconds>(class99 - class9).count()
		<< std::setw(4) << "|"
		<< std::setw(7) << chrono::duration_cast<chrono::milliseconds>(list99 - list9).count()
		<< std::setw(4) << "|"
		<< std::setw(7) << chrono::duration_cast<chrono::milliseconds>(set99 - set9).count()
		<< std::setw(4) << "|"
		<< std::endl;

	auto struct10 = chrono::steady_clock::now();
	set_difference(B, A);
	auto struct100 = chrono::steady_clock::now();

	auto class10 = chrono::steady_clock::now();
	B1.set_difference(A1);
	auto class100 = chrono::steady_clock::now();

	auto list10 = chrono::steady_clock::now();
	B2.set_difference(A2);
	auto list100 = chrono::steady_clock::now();

	auto set10 = chrono::steady_clock::now();
	B3.set_difference(A3);
	auto set100 = chrono::steady_clock::now();

	std::cout << std::setw(4) << right << "|"
		<< std::setw(30) << left << " Разность B и A"
		<< std::setw(5) << "|"
		<< std::setw(12) << chrono::duration_cast<chrono::milliseconds>(struct100 - struct10).count()
		<< std::setw(5) << "|"
		<< std::setw(10) << chrono::duration_cast<chrono::milliseconds>(class100 - class10).count()
		<< std::setw(4) << "|"
		<< std::setw(7) << chrono::duration_cast<chrono::milliseconds>(list100 - list10).count()
		<< std::setw(4) << "|"
		<< std::setw(7) << chrono::duration_cast<chrono::milliseconds>(set100 - set10).count()
		<< std::setw(4) << "|"
		<< std::endl;

	auto struct20 = chrono::steady_clock::now();
	set_symmetric_difference(A, B);
	auto struct200 = chrono::steady_clock::now();

	auto class20 = chrono::steady_clock::now();
	A1.set_symmetric_difference(B1);
	auto class200 = chrono::steady_clock::now();

	auto list20 = chrono::steady_clock::now();
	A2.set_symmetric_difference(B2);
	auto list200 = chrono::steady_clock::now();

	auto set20 = chrono::steady_clock::now();
	A3.set_symmetric_difference(B3);
	auto set200 = chrono::steady_clock::now();

	std::cout << std::setw(4) << right << "|"
		<< std::setw(30) << left << " Симметричная разность А и В"
		<< std::setw(5) << "|"
		<< std::setw(12) << chrono::duration_cast<chrono::milliseconds>(struct200 - struct20).count()
		<< std::setw(5) << "|"
		<< std::setw(10) << chrono::duration_cast<chrono::milliseconds>(class200 - class20).count()
		<< std::setw(4) << "|"
		<< std::setw(7) << chrono::duration_cast<chrono::milliseconds>(list200 - list20).count()
		<< std::setw(4) << "|"
		<< std::setw(7) << chrono::duration_cast<chrono::milliseconds>(set200 - set20).count()
		<< std::setw(4) << "|"
		<< std::endl;

	std::cout << "   --------------------------------------------------------------------------------------\n\n";

	system("pause");
	return 0;
}
