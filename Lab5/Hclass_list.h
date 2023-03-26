#pragma once
#include <string>
#include "Hstruct_list.h"


class Set {
private:
	Element* head;
public:

	// ����������� ��� ����������
	Set();

	// ����������� �����������
	Set(const Set& set);

	// ����������� � �����������
	Set(int, int, int, int);

	// �������� �� ������ ���������
	bool is_empty();

	// �������� �������������� ���������
	bool in_set(int);

	// ���������� �������� � ���������
	void add(int);

	// �������� ���������
	int size();

	// ������� ���������
	void clear();

	// ����� ���������
	std::string print(std::string);

	// � - ������������ �
	bool is_subset(Set);

	// ��������� ���� ��������
	bool is_equal(Set);

	// ����������� ���� ��������
	Set set_union(Set);

	// ����������� ���� ��������
	Set set_intersection(Set);

	// �������� ���� ��������
	Set set_difference(Set);

	// ������������ �������� ��������
	Set set_symmetric_difference(Set);

	// ����������
	~Set();
};


