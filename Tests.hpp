#pragma once
#include "Headers.hpp"
#include "BinaryTree.hpp"

void test() {
	BinaryTree<int>* Tree = new BinaryTree<int>();
	for (int i = 0; i < 5; i++) {
		Tree->toInsert(rand() % 100);
	}
	Tree->printTree(Tree->getRoot(), Tree->getHeight());




}