#pragma once
#include <string>

struct Element {
	int value;
	Element* next;
};

// Создание пустого множества
Element* create_empty_set();

// Проверка на пустое мнржество
bool is_empty(Element*);

// Проверка принадлежности множеству
bool in_set(Element*, int);

// Добавление элемента в множество
Element* add(Element*, int);

// Создание множества
Element* create_set(int, int, int, bool);

// Мощность множества
int capacity_of(Element*);

// Вывод множества
std::string print(Element*, std::string);

// Удаление множества
Element* clear(Element*);

// А - подмножество В
bool is_subset(Element*, Element*);

// Равенство двух множеств
bool is_equal(Element*, Element*);

// Объединение двух множеств
Element* set_union(Element*, Element*);

// Пересечение двух множеств
Element* set_intersection(Element*, Element*);

// Разность двух множеств
Element* set_difference(Element*, Element*);

// Симметричная разность множеств
Element* set_symmetric_difference(Element*, Element*);