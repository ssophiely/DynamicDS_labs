#pragma once
#include <set>
#include <string>
using namespace std;

class SetS {
private:
	set <int> m_set;
public:

	// ����������� ��� ����������
	SetS();

	// ����������� �����������
	SetS(const SetS&);

	// ����������� � �����������
	SetS(int, int, int, int);

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
	bool is_subset(SetS);

	// ��������� ���� ��������
	bool is_equal(SetS);

	// ����������� ���� ��������
	SetS set_union(SetS);

	// ����������� ���� ��������
	SetS set_intersection(SetS);

	// �������� ���� ��������
	SetS set_difference(SetS);

	// ������������ �������� ��������
	SetS set_symmetric_difference(SetS);

	// ����������
	~SetS();
};

