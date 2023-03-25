#include "Hstruct_list.h"
#include <ctime>

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
Element* create_set(int n, int min, int max, bool f) {
	// ��������� �
	if (f) {
		if ((int)((max - min + 1) / 5) + 1 < n) {
			return create_empty_set();
		}
		srand(time(NULL));
		Element* head = nullptr;
		int size = 0;
		while (size != n) {
			Element* pr_head = head;
			int el = min + rand() % (max - min + 1);
			if (el % 5 == 0) {
				head = add(head, el);
				if (pr_head != head) {
					size++;
				}
			}
		}
		return head;
	}
	// ��������� B
	else
	{
		if ((int)((max - min + 1) / 10) + 1 < n) {
			return create_empty_set();
		}
		srand(time(NULL));
		Element* head = nullptr;
		int size = 0;
		while (size != n) {
			Element* pr_head = head;
			int el = min + rand() % (max - min + 1);
			if (el % 10 == 0) {
				head = add(head, el);
				if (pr_head != head) {
					size++;
				}
			}
		}
		return head;
	}
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

// � - ������������ �
bool is_subset(Element* headA, Element* headB) {
	if (is_empty(headA)) {
		return true;
	}
	if (capacity_of(headB) < capacity_of(headA)) {
		return false;
	}
	while (headA != nullptr) {
		if (!in_set(headB, headA->value)) {
			return false;
		}
		headA = headA->next;
	}
	return true;
}

// ��������� ���� ��������
bool is_equal(Element* headA, Element* headB) {
	return (is_subset(headA, headB) && is_subset(headB, headA));
}

// ����������� ���� ��������
Element* set_union(Element* headA, Element* headB) {
	if (is_empty(headA) && is_empty(headB)) {
		return nullptr;
	}
	Element* head = nullptr;
	while (headA != nullptr) {
		head = add(head, headA->value);
		headA = headA->next;
	}
	while (headB != nullptr) {
		head = add(head, headB->value);
		headB = headB->next;
	}
	return head;
}

// ����������� ���� ��������
Element* set_intersection(Element* headA, Element* headB) {
	if (is_empty(headA) || is_empty(headB)) {
		return nullptr;
	}
	Element* head = nullptr;
	while (headA != nullptr) {
		if (in_set(headB, headA->value)) {
			head = add(head, headA->value);
		}
		headA = headA->next;
	}
	return head;
}

// �������� ���� ��������
Element* set_difference(Element* headA, Element* headB) {
	if (is_empty(headA)) {
		return nullptr;
	}
	Element* head = nullptr;
	while (headA != nullptr) {
		if (!in_set(headB, headA->value)) {
			head = add(head, headA->value);
		}
		headA = headA->next;
	}
	return head;
}

// ������������ �������� ��������
Element* set_symmetric_difference(Element* headA, Element* headB) {
	return set_difference(set_union(headA, headB), set_intersection(headA, headB));
}