#pragma once
#include <set>
#include <string>
using namespace std;

class SetS {
private:
	set <int> m_set;
public:

	// Конструктор без параметров
	SetS();

	// Конструктор копирования
	SetS(const SetS&);

	// Конструктор с параметрами
	SetS(int, int, int, int);

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
	bool is_subset(SetS);

	// Равенство двух множеств
	bool is_equal(SetS);

	// Объединение двух множеств
	SetS set_union(SetS);

	// Пересечение двух множеств
	SetS set_intersection(SetS);

	// Разность двух множеств
	SetS set_difference(SetS);

	// Симметричная разность множеств
	SetS set_symmetric_difference(SetS);

	// Деструктор
	~SetS();
};

