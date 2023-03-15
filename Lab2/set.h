#pragma once
#include <string>

struct Element {
	int value;
	Element* next;
};

class Set {
private:
	Element* head;
public:

	// Конструктор без параметров
	Set();

	// Конструктор копирования
	Set(const Set& set);

	// Конструктор с параметрами
	Set(int, int, int, bool);

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
	std::string print(std::string);

	// А - подмножество В
	bool is_subset(Set);

	// Равенство двух множеств
	bool is_equal(Set);

	// Объединение двух множеств
	Set set_union(Set);

	// Пересечение двух множеств
	Set set_intersection(Set);

	// Разность двух множеств
	Set set_difference(Set);

	// Симметричная разность множеств
	Set set_symmetric_difference(Set);

	// Деструктор
	~Set();
};

