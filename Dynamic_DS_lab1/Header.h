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
Element* create_set(int, int, int);

// Мощность множества
int capacity_of(Element*);

// Вывод множества
std::string print(Element*, std::string);

// Удаление множества
Element* clear(Element*);