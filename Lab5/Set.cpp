#include "Hset.h"
#include <ctime>

// ����������� ��� ����������
SetS::SetS() {
}

// ����������� �����������
SetS::SetS(const SetS& set) {
	m_set = (set.m_set);
}

// ����������� � �����������
SetS::SetS(int n, int min, int max, int f) {
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
bool SetS::is_empty() {
	return m_set.empty();
}

// �������� �������������� ���������
bool SetS::in_set(int x) {
	if (m_set.find(x) == m_set.end()) {
		return false;
	}
	return true;
}

// ���������� �������� � ���������
void SetS::add(int x) {
	m_set.insert(x);
}

// �������� ���������
void SetS::clear() {
	m_set.clear();
}

// �������� ���������
int SetS::size() {
	return m_set.size();
}

// ����� ���������
std::string SetS::print(std::string ch) {
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
bool SetS::is_subset(SetS setB) {
	for (set<int>::iterator it = m_set.begin(); it != m_set.end(); it++) {
		if (!setB.in_set(*it)) {
			return false;
		}
	}
	return true;
}

// ��������� ���� ��������
bool SetS::is_equal(SetS setB) {
	return (is_subset(setB) && setB.is_subset(*this));
}

// ����������� ���� ��������
SetS SetS::set_union(SetS setB) {
	if (is_empty() && setB.is_empty()) {
		return SetS();
	}
	SetS newset = SetS();
	for (set<int>::iterator it = m_set.begin(); it != m_set.end(); it++) {
		newset.add(*it);
	}
	for (set<int>::iterator it = setB.m_set.begin(); it != setB.m_set.end(); it++) {
		newset.add(*it);
	}
	return newset;
}

// ����������� ���� ��������
SetS  SetS::set_intersection(SetS setB) {
	if (is_empty() || setB.is_empty()) {
		return SetS();
	}
	SetS newset = SetS();
	for (set<int>::iterator it = m_set.begin(); it != m_set.end(); it++) {
		if (setB.in_set(*it)) {
			newset.add(*it);
		}
	}
	return newset;
}

// �������� ���� ��������
SetS SetS::set_difference(SetS setB) {
	if (is_empty()) {
		return SetS();
	}
	SetS newset = SetS();
	for (set<int>::iterator it = m_set.begin(); it != m_set.end(); it++) {
		if (!setB.in_set(*it)) {
			newset.add(*it);
		}
	}
	return newset;
}

// ������������ �������� ��������
SetS SetS::set_symmetric_difference(SetS setB) {
	return set_union(setB).set_difference(set_intersection(setB));
}

SetS::~SetS() {
	clear();
}
