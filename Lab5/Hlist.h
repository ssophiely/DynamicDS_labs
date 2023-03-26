#pragma once
#include <list>
#include <string>
using namespace std;

class SetL {
private:
	list <int> m_set;
public:

	// Конструктор без параметров
	SetL();

	// Конструктор копирования
	SetL(const SetL&);

	// Конструктор с параметрами
	SetL(int, int, int, int);

	// Проверка на пустое мнржество
	bool is_empty();

	// Проверка принадлежности множеству 
	bool in_set(int);

	// Добавление элемента в множество  
	void add(int);

	// Мощность множества
	int size();

	// Очистка множества
	void clear();

	// Вывод множества 
	string print(string);

	// А - подмножество В
	bool is_subset(SetL);

	// Равенство двух множеств
	bool is_equal(SetL);

	// Объединение двух множеств
	SetL set_union(SetL);

	// Пересечение двух множеств
	SetL set_intersection(SetL);

	// Разность двух множеств
	SetL set_difference(SetL);

	// Симметричная разность множеств
	SetL set_symmetric_difference(SetL);

	// Деструктор
	~SetL();
};

