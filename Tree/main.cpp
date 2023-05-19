#include <iostream>
#include "Htree.h"
using namespace std;

int main()
{
	setlocale(0, "");
	Tree tree1;
	tree1.add(10);
	tree1.add(4);
	tree1.add(7);
	tree1.add(9);
	tree1.add(3);
	tree1.add(5);
	tree1.add(14);
	tree1.add(2);
	tree1.add(1);
	tree1.add(0);

	cout << "\nДерево пустое\t" << std::boolalpha<< tree1.empty() << endl;
	cout << "\nОбход дерева сверху вниз\t" << tree1.print("HD") << endl;
	cout << "\nОбход дерева снизу вверх\t" << tree1.print("DH") << endl;
	cout << "\nОбход дерева слева направо\t" << tree1.print("LR") << "\n\n";


	system("pause");
	return 0;

}

