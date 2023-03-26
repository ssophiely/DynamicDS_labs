#include "Hlist.h"
#include <ctime>

// ����������� ��� ����������
SetL::SetL() {
}

// ����������� �����������
SetL::SetL(const SetL& set) {
	m_set = (set.m_set);
}

// ����������� � �����������
SetL::SetL(int n, int min, int max, int f) {
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
bool SetL::is_empty() {
	return m_set.empty();
}

// �������� �������������� ���������
bool SetL::in_set(int x) {
	if (std::find(m_set.begin(), m_set.end(), x) == m_set.end()) {
		return false;
	}
	return true;
}

// ���������� �������� � ���������
void SetL::add(int x) {
	if (!in_set(x))
		m_set.push_back(x);
}

// �������� ���������
void SetL::clear() {
	m_set.clear();
}

// �������� ���������
int SetL::size() {
	return m_set.size();
}

// ����� ���������
std::string SetL::print(std::string ch) {
	if (is_empty()) {
		return "";
	}
	std::string s = std::to_string(*m_set.begin());
	for (list<int>::iterator it = ++m_set.begin(); it != m_set.end(); it++) {
		s += ch + std::to_string(*it);
	}
	return s;
}

// � - ������������ �
bool SetL::is_subset(SetL setB) {
	for (list<int>::iterator it = m_set.begin(); it != m_set.end(); it++) {
		if (!setB.in_set(*it)) {
			return false;
		}
	}
	return true;
}

// ��������� ���� ��������
bool SetL::is_equal(SetL setB) {
	return (is_subset(setB) && setB.is_subset(*this));
}

// ����������� ���� ��������
SetL SetL::set_union(SetL setB) {
	if (is_empty() && setB.is_empty()) {
		return SetL();
	}
	SetL newset = SetL();
	for (list<int>::iterator it = m_set.begin(); it != m_set.end(); it++) {
		newset.add(*it);
	}
	for (list<int>::iterator it = setB.m_set.begin(); it != setB.m_set.end(); it++) {
		newset.add(*it);
	}
	return newset;
}

// ����������� ���� ��������
SetL  SetL::set_intersection(SetL setB) {
	if (is_empty() || setB.is_empty()) {
		return SetL();
	}
	SetL newset = SetL();
	for (list<int>::iterator it = m_set.begin(); it != m_set.end(); it++) {
		if (setB.in_set(*it)) {
			newset.add(*it);
		}
	}
	return newset;
}

// �������� ���� ��������
SetL SetL::set_difference(SetL setB) {
	if (is_empty()) {
		return SetL();
	}
	SetL newset = SetL();
	for (list<int>::iterator it = m_set.begin(); it != m_set.end(); it++) {
		if (!setB.in_set(*it)) {
			newset.add(*it);
		}
	}
	return newset;
}

// ������������ �������� ��������
SetL SetL::set_symmetric_difference(SetL setB) {
	return set_union(setB).set_difference(set_intersection(setB));
}

SetL::~SetL() {
	clear();
}
