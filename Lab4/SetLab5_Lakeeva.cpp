#include "Header.h"
#include <ctime>

// ����������� ��� ����������
Set::Set() {
}

// ����������� �����������
Set::Set(const Set& set) {
	m_set = (set.m_set);
}

// ����������� � �����������
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

// �������� �� ������ ���������
bool Set::is_empty() {
	return m_set.empty();
}

// �������� �������������� ���������
bool Set::in_set(int x) {
	if (m_set.find(x) == m_set.end()) {
		return false;
	}
	return true;
}

// ���������� �������� � ���������
void Set::add(int x) {
	m_set.insert(x);
}

// �������� ���������
void Set::clear() {
	m_set.clear();
}

// �������� ���������
int Set::size() {
	return m_set.size();
}

// ����� ���������
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

// � - ������������ �
bool Set::is_subset(Set setB) {
	for (set<int>::iterator it = m_set.begin(); it != m_set.end(); it++) {
		if (!setB.in_set(*it)) {
			return false;
		}
	}
	return true;
}

// ��������� ���� ��������
bool Set::is_equal(Set setB) {
	return (is_subset(setB) && setB.is_subset(*this));
}

// ����������� ���� ��������
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

// ����������� ���� ��������
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

// �������� ���� ��������
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

// ������������ �������� ��������
Set Set::set_symmetric_difference(Set setB) {
	return set_union(setB).set_difference(set_intersection(setB));
}

Set::~Set() {
	clear();
}
