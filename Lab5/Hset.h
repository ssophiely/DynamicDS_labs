#pragma once
#include <set>
#include <string>
using namespace std;

class Set {
private:
	set <int> m_set;
public:

	// ����������� ��� ����������
	Set();

	// ����������� �����������
	Set(const Set&);

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
	string print(string);

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

