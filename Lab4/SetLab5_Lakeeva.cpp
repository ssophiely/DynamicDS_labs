#include "Header.h"
#include <ctime>

// Конструктор без параметров
Set::Set() {
}

// Конструктор копирования
Set::Set(const Set& set) {
	m_set = (set.m_set);
}

// Конструктор с параметрами
Set::Set(int n, int min, int max, int f) {
	if ((int)((max - min + 1) / f) + 1 < n) {
		return;
	}
	srand(time(NULL));
	while (m_set.size() != n) {
		int el = min + rand() % (max - min + 1);
		if (el % f == 0) {
			add(el);
		}
	}
}

// Проверка на пустое множество
bool Set::is_empty() {
	return m_set.empty();
}

// Проверка принадлежности множеству
bool Set::in_set(int x) {
	if (m_set.find(x) == m_set.end()) {
		return false;
	}
	return true;
}

// Добавление элемента в множество
void Set::add(int x) {
	m_set.insert(x);
}

// Удаление множества
void Set::clear() {
	m_set.clear();
}

// Мощность множества
int Set::size() {
	return m_set.size();
}

// Вывод множества
std::string Set::print(std::string ch) {
	if (is_empty()) {
		return "";
	}
	std::string s = std::to_string(*m_set.begin());
	for (set<int>::iterator it = ++m_set.begin(); it != m_set.end(); it++) {
		s += ch + std::to_string(*it);
	}
	return s;
}

// А - подмножество В
bool Set::is_subset(Set setB) {
	for (set<int>::iterator it = m_set.begin(); it != m_set.end(); it++) {
		if (!setB.in_set(*it)) {
			return false;
		}
	}
	return true;
}

// Равенство двух множеств
bool Set::is_equal(Set setB) {
	return (is_subset(setB) && setB.is_subset(*this));
}

// Объединение двух множеств
Set Set::set_union(Set setB) {
	if (is_empty() && setB.is_empty()) {
		return Set();
	}
	Set newset = Set();
	for (set<int>::iterator it = m_set.begin(); it != m_set.end(); it++) {
		newset.add(*it);
	}
	for (set<int>::iterator it = setB.m_set.begin(); it != setB.m_set.end(); it++) {
		newset.add(*it);
	}
	return newset;
}

// Пересечение двух множеств
Set  Set::set_intersection(Set setB) {
	if (is_empty() || setB.is_empty()) {
		return Set();
	}
	Set newset = Set();
	for (set<int>::iterator it = m_set.begin(); it != m_set.end(); it++) {
		if (setB.in_set(*it)) {
			newset.add(*it);
		}
	}
	return newset;
}

// Разность двух множеств
Set Set::set_difference(Set setB) {
	if (is_empty()) {
		return Set();
	}
	Set newset = Set();
	for (set<int>::iterator it = m_set.begin(); it != m_set.end(); it++) {
		if (!setB.in_set(*it)) {
			newset.add(*it);
		}
	}
	return newset;
}

// Симметричная разность множеств
Set Set::set_symmetric_difference(Set setB) {
	return set_union(setB).set_difference(set_intersection(setB));
}

Set::~Set() {
	clear();
}
