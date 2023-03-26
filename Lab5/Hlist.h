#pragma once
#include <list>
#include <string>
using namespace std;

class SetL {
private:
	list <int> m_set;
public:

	// ����������� ��� ����������
	SetL();

	// ����������� �����������
	SetL(const SetL&);

	// ����������� � �����������
	SetL(int, int, int, int);

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
	bool is_subset(SetL);

	// ��������� ���� ��������
	bool is_equal(SetL);

	// ����������� ���� ��������
	SetL set_union(SetL);

	// ����������� ���� ��������
	SetL set_intersection(SetL);

	// �������� ���� ��������
	SetL set_difference(SetL);

	// ������������ �������� ��������
	SetL set_symmetric_difference(SetL);

	// ����������
	~SetL();
};

