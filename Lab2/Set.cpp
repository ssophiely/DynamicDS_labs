#include "set.h"
#include <ctime>

// ����������� ��� ����������
Set::Set() {
	head = nullptr;
}

// ����������� �����������
Set::Set(const Set& set) {
	head = nullptr;
	Element* ptr = set.head;
	while (ptr != nullptr) {
		add(ptr->value);
		ptr = ptr->next;
	}
}

// ����������� � �����������
Set::Set(int n, int min, int max, bool f) {
	// ��������� �
	if (f) {
		if ((int)((max - min + 1) / 5) + 1 < n) {
			head = nullptr;
			return;
		}
		srand(time(NULL));
		head = nullptr;
		int size = 0;
		while (size != n) {
			Element* pr_head = head;
			int el = min + rand() % (max - min + 1);
			if (el % 5 == 0) {
				add(el);
				if (pr_head != head) {
					size++;
				}
			}
		}
	}
	// ��������� B
	else
	{
		if ((int)((max - min + 1) / 10) + 1 < n) {
			head = nullptr;
			return;
		}
		srand(time(NULL));
		head = nullptr;
		int size = 0;
		while (size != n) {
			Element* pr_head = head;
			int el = min + rand() % (max - min + 1);
			if (el % 10 == 0) {
				add(el);
				if (pr_head != head) {
					size++;
				}
			}
		}
	}
}

// �������� �� ������ ���������
bool Set::is_empty() {
	if (head == nullptr) {
		return true;
	}
	return false;
}

// �������� �������������� ���������
bool Set::in_set(int x) {
	if (is_empty()) {
		return false;
	}
	Element* ptr = head;
	while (ptr != nullptr) {
		if ((ptr)->value == x) {
			return true;
		}
		ptr = ptr->next;
	}
	return false;
}

// ���������� �������� � ���������
void Set::add(int x) {
	if (!in_set(x)) {
		Element* elem = new Element;
		elem->value = x;
		elem->next = head;
		head = elem;
	}
}

// �������� ���������
void Set::clear() {
	while (head != nullptr) {
		Element* ptr = head;
		head = ptr->next;
		delete ptr;
	}
}

// �������� ���������
int Set::size() {
	if (is_empty()) {
		return 0;
	}
	int size = 0;
	Element* ptr = head;
	while (ptr != nullptr) {
		size++;
		ptr = ptr->next;
	}
	return size;
}

// ����� ���������
std::string Set::print(std::string ch) {
	if (is_empty()) {
		return "";
	}
	Element* ptr = head;
	std::string s = std::to_string(ptr->value);
	ptr = ptr->next;
	while (ptr != nullptr) {
		s += ch + std::to_string(ptr->value);
		ptr = ptr->next;
	}
	return s;
}

// � - ������������ �
bool Set::is_subset(Set setB) {
	if (is_empty()) {
		return true;
	}
	if (setB.size() < size()) {
		return false;
	}
	Element* ptr = head;
	while (ptr != nullptr) {
		if (!setB.in_set(ptr->value)) {
			return false;
		}
		ptr = ptr->next;
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
	Element* ptr = head;
	Set newset = Set();
	while (ptr != nullptr) {
		newset.add(ptr->value);
		ptr = ptr->next;
	}
	Element* ptr2 = setB.head;
	while (ptr2 != nullptr) {
		newset.add(ptr2->value);
		ptr2 = ptr2->next;
	}
	return newset;
}

// ����������� ���� ��������
Set  Set::set_intersection(Set setB) {
	if (is_empty() || setB.is_empty()) {
		return Set();
	}
	Element* ptr = head;
	Set newset = Set();
	while (ptr != nullptr) {
		if (setB.in_set(ptr->value)) {
			newset.add(ptr->value);
		}
		ptr = ptr->next;
	}
	return newset;
}

// �������� ���� ��������
Set Set::set_difference(Set setB) {
	if (is_empty()) {
		return Set();
	}
	Element* ptr = head;
	Set newset = Set();
	while (ptr != nullptr) {
		if (!setB.in_set(ptr->value)) {
			newset.add(ptr->value);
		}
		ptr = ptr->next;
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
