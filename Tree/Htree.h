#pragma once
#include <string>
using namespace std;

class Tree {
private:
	struct tnode {
		int m_value;
		struct tnode* m_left;
		struct tnode* m_right;
	};
	tnode* m_root;
	int m_size;
	void traversalHD(tnode*, string&);
	void traversalLR(tnode*, string&);
	void traversalDH(tnode*, string&);

public:
	Tree();
	Tree(int, int, int);
	bool empty();
	void add(int);
	string print(string);
	void clear(tnode*);
	~Tree();
};