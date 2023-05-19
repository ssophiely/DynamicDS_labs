#include "Htree.h"
#include <ctime>
#include <iostream>

Tree::Tree() {
	m_root = nullptr;
	m_size = 0;
}

Tree::Tree(int n, int min, int max) {
	m_size = 0;
	if ((max - min + 1) < n) {
		m_root = nullptr;
		return;
	}
	srand(time(NULL));
	while (m_size != n) {
		int val = min + rand() % (max - min + 1);
		add(val);
	}
}

bool Tree::empty() {
	return m_size == 0;
}

void Tree::add(int x) {
	if (m_root == nullptr) {
		tnode* node = new tnode;
		node->m_value = x;
		node->m_left = nullptr;
		node->m_right = nullptr;
		m_root = node;
		++m_size;
		std::cout << "Добавлено  " << x << "\n";
		return;
	}
	tnode* current = m_root;
	while (current->m_value != x)
	{
		if (current->m_value > x && current->m_left == NULL)
		{
			tnode* node = new tnode;
			node->m_value = x;
			node->m_left = nullptr;
			node->m_right = nullptr;
			current->m_left = node;
			++m_size;
			std::cout << "Добавлено  " << x << "\n";
			return;
		}
		if (current->m_value < x && current->m_right == NULL)
		{
			tnode* node = new tnode;
			node->m_value = x;
			node->m_left = nullptr;
			node->m_right = nullptr;
			current->m_right = node;
			++m_size;
			std::cout << "Добавлено  " << x << "\n";
			return;
		}
		if (current->m_value > x)
			current = current->m_left;
		else
			current = current->m_right;
	}
}

string Tree::print(string type) {
	string s = "";
	if (type == "HD") {
		traversalHD(m_root, s);
		return s;
	}
	else if (type == "LR") {
		traversalLR(m_root, s);
		return s;
	}
	else if (type == "DH") {
		traversalDH(m_root, s);
		return s;
	}
	else
		return "Обход " + type + " не извеcтен. Введите HD, LR или DH";

}

void Tree::traversalHD(tnode* curr, string& s)
{
	if (curr)
	{
		s += std::to_string(curr->m_value) + " ";
		traversalHD(curr->m_left, s);
		traversalHD(curr->m_right, s);
	}
}

void Tree::traversalLR(tnode* curr, string& s) {
	if (curr) {
		traversalLR(curr->m_left, s);
		s += std::to_string(curr->m_value) + " ";
		traversalLR(curr->m_right, s);
	}

}

void Tree::traversalDH(tnode* curr, string& s) {
	if (curr) {
		traversalDH(curr->m_left, s);
		traversalDH(curr->m_right, s);
		s += std::to_string(curr->m_value) + " ";
	}
}

void Tree::clear(tnode* curr) {
	if (curr) {
		clear(curr->m_left);
		clear(curr->m_right);
		delete curr;
		m_size--;
	}
}

Tree::~Tree() {
	clear(m_root);
}