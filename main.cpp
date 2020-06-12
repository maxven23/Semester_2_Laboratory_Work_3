#include <iostream>
#include "BinaryTree.hpp"

using namespace std;

int main(void) {
	string string;

	BinaryTree<int>* tree;
	tree = new BinaryTree<int>();
	for (size_t i = 4; i > 0; i--)
	{
		tree->toInsert(rand() % 100);
	}


	tree->toInsert(100);
	tree->toInsert(150);
	tree->toInsert(250);
	tree->toInsert(125);
	tree->toInsert(112);
	tree->toInsert(80);
	tree->printTree(tree->getRoot(), tree->getHeight());

	//tree->DSW();
	//cout << endl << endl;
	//tree->printTree(tree->getRoot(), tree->getHeight());

	//cout << endl << endl << "toString(\"LNR\"): " << tree->toString("LNR");
	return 0;
}