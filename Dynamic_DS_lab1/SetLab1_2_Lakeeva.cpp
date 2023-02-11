#include "Header.h"

// �������� ������� ���������
Element* create_empty_set() {
	Element* head = nullptr;
	return head;
}

// �������� �� ������ ���������
bool is_empty(Element* head) {
	if (head == nullptr) {
		return true;
	}
	return false;
}

// �������� �������������� ���������
bool in_set(Element* head, int x) {
	if (is_empty(head)) {
		return false;
	}
	while (head != nullptr) {
		if ((head)->value == x) {
			return true;
		}
		head = head->next;
	}
	return false;
}

// ���������� �������� � ���������
Element* add(Element* head, int x) {
	if (!in_set(head, x)) {
		Element* elem = new Element;
		elem->value = x;
		elem->next = head;
		head = elem;
	}
	return head;
}

// �������� ���������
Element* create_set(int n, int min, int max) {
	if (max - min + 1 < n) {
		create_empty_set();
	}
	Element* head = nullptr;
	int size = 0;
	while (size != n) {
		Element* pr_head = head;
		head = add(head, min + rand() % (max - min + 1));
		if (pr_head != head) {
			size++;
		}
	}
	return head;
}

// �������� ���������
Element* clear(Element* head) {
	while (head != nullptr) {
		Element* ptr = head;
		head = ptr->next;
		delete ptr;
	}
	return head;
}

// �������� ���������
int capacity_of(Element* head) {
	if (is_empty(head)) {
		return 0;
	}
	int size = 0;
	while (head != nullptr) {
		size++;
		head = head->next;
	}
	return size;
}

// ����� ���������
std::string print(Element* head, std::string ch) {
	if (is_empty(head)) {
		return "";
	}
	std::string s = std::to_string(head->value);
	head = head->next;
	while (head != nullptr) {
		s += ch + std::to_string(head->value);
		head = head->next;
	}
	return s;
}