#pragma once
#include "Headers.hpp"
#include "BinaryTree.hpp"


template <typename T> 
bool biggerZero(T first) {
	if (first > 0) return true;
	else return false;
}

template <typename T>
T fooSquare(T item) {
	return item * item;
}

template <typename T>
T fooAdd(T first, T second) {
	return first + second;
}

template <class T>
void test() {
	system("cls");

	cout << "/--------------------------NEW TEST--------------------------\\" << endl;
	cout << endl;
	BinaryTree<T>* Tree = new BinaryTree<T>();
	for (int i = 0; i < 15; i++) {
		Tree->toInsert((T)(rand() % 100 - 50));
	}
	Tree->printTree();
	cout << endl;

	cout << "\\------------------------------------------------------------/" << endl;
	cout << "==============================================================" << endl;
	cout << "/--------------------------BALANCED--------------------------\\" << endl;
	cout << endl;
	
	Tree->DSW();
	Tree->printTree();

	cout << endl;
	cout << "\\------------------------------------------------------------/" << endl;
	cout << "==============================================================" << endl;
	cout << "/-------------------------toCheckTest------------------------\\" << endl;
	cout << endl;

	cout << Tree->toCheck((T)(rand() % 100 - 50)) << endl;
	if (Tree->toCheck(Tree->getRoot()->Get())) {
		cout << "Success";
	}
	else {
		throw std::exception("Error:failed");
	}
	cout << endl;

	cout << endl;
	cout << "\\------------------------------------------------------------/" << endl;
	cout << "==============================================================" << endl;
	cout << "/------------------------toStringTest------------------------\\" << endl;
	cout << endl;

	cout << "LNR: " << Tree->toString("LNR") << endl;
	cout << "RNL: " << Tree->toString("RNL") << endl;
	cout << "LRN: " << Tree->toString("LRN") << endl;
	cout << "RLN: " << Tree->toString("RLN") << endl;
	cout << "NLR: " << Tree->toString("NLR") << endl;
	cout << "NRL: " << Tree->toString("NRL") << endl;
	
	cout << endl;
	cout << "\\------------------------------------------------------------/" << endl;
	cout << "==============================================================" << endl;
	cout << "/--------------------------WhereTest-------------------------\\" << endl;
	cout << endl;

	for (int i = 0; i < Tree->Where(biggerZero, "LNR")->GetSize() - 1; i++) {
		cout << Tree->Where(biggerZero, "LNR")->Get(i)->Get() << " -> ";
	}
	cout << Tree->Where(biggerZero, "LNR")->Get(Tree->Where(biggerZero, "LNR")->GetSize() - 1)->Get() << endl;

	cout << endl;
	cout << "\\------------------------------------------------------------/" << endl;
	cout << "==============================================================" << endl;
	cout << "/---------------------------MapTest--------------------------\\" << endl;
	cout << endl;
	
	Tree->map(fooSquare);
	Tree->printTree();

	cout << endl;
	cout << "\\------------------------------------------------------------/" << endl;
	cout << "==============================================================" << endl;
	cout << "/--------------------------reduceTest------------------------\\" << endl;
	cout << endl;

	cout << "reduce(fooAdd()) for the Tree: " << Tree->reduce(fooAdd, 0, "LNR") << endl;
	
	cout << endl;
	cout << "\\------------------------------------------------------------/" << endl;
	cout << "==============================================================" << endl;
	cout << "/--------------------------DeleteTest------------------------\\" << endl;
	cout << endl;

	Tree->removeNode(Tree->getRoot()->Get());
	Tree->printTree();

	cout << endl;
	cout << "\\------------------------------------------------------------/" << endl;
	cout << endl;
}