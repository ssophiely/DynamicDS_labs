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
Element* create_set(int, int, int, bool);

// �������� ���������
int capacity_of(Element*);

// ����� ���������
std::string print(Element*, std::string);

// �������� ���������
Element* clear(Element*);

// � - ������������ �
bool is_subset(Element*, Element*);

// ��������� ���� ��������
bool is_equal(Element*, Element*);

// ����������� ���� ��������
Element* set_union(Element*, Element*);

// ����������� ���� ��������
Element* set_intersection(Element*, Element*);

// �������� ���� ��������
Element* set_difference(Element*, Element*);

// ������������ �������� ��������
Element* set_symmetric_difference(Element*, Element*);