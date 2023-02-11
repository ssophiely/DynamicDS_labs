#pragma once
#include <string>

struct Element {
	int value;
	Element* next;
};

// �������� ������� ���������
Element* create_empty_set();

// �������� �� ������ ���������
bool is_empty(Element*);

// �������� �������������� ���������
bool in_set(Element*, int);

// ���������� �������� � ���������
Element* add(Element*, int);

// �������� ���������
Element* create_set(int, int, int);

// �������� ���������
int capacity_of(Element*);

// ����� ���������
std::string print(Element*, std::string);

// �������� ���������
Element* clear(Element*);