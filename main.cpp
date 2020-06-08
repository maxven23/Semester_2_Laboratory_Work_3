#include <iostream>
#include "BinaryTree.hpp"

using namespace std;

int main(void) {
	string string;

	BinaryTree<int>* tree;
	tree = new BinaryTree<int>();
	for (size_t i = 24; i > 0; i--)
	{
		tree->toInsert(rand() % 100);
	}
	tree->printTree(tree->getRoot(), tree->getHeight());

	return 0;
}