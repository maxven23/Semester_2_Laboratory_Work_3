#pragma once
#include "Headers.hpp"
#include "BinaryTree.hpp"

void MenuText() {
	system("cls");
	cout << "---------------------MENU---------------------" << endl;
	cout << endl;
	cout << "1. Show the Tree" << endl;
	cout << "2. Add element to the Tree" << endl;
	cout << "3. Delete element from the Tree" << endl;
	cout << "4. Map" << endl;
	cout << "5. Reduce" << endl;
	cout << "6. Where" << endl;
	cout << "7. Balance the Tree" << endl;
	cout << "8. Make a String from the Tree" << endl;
	cout << "9. Exit" << endl;
	cout << endl;
	cout << "----------------------------------------------" << endl;
	cout << endl;
}

void pressAnyButton() {
	cout << "Press any button to continue . . ." << endl;
	system("pause>>VOID");
}

template <typename T>
void makeDes(BinaryTree<T>* Tree, int choose) {
	switch (choose) {

		// PrintTree
	case 1: 
	{
		system("cls");

		if (Tree->getRoot() == nullptr) {
			cout << "FAILED: Tree is EMPTY" << endl;
		}
		else {
			Tree->printTree(Tree->getRoot(), Tree->getHeight());
		}
		cout << endl;
		pressAnyButton();
	}
			break;

		// Add element
	case 2: 
	{
		system("cls");

		T newelem;
		cout << "Enter an element you want to Add: " << endl;
		cout << endl;
		cin >> newelem;

		if (Tree->toCheck(newelem)) {
			system("cls");
			cout << "Element already in the Tree" << endl;
		}
		else {
			system("cls");
			Tree->toInsert(newelem);
			cout << "Element '" << newelem << "' was added" << endl;
		}
		cout << endl;

		pressAnyButton();
	}
	break;
		// Delete element
	case 3:
	{
		system("cls");

		T elem;
		cout << "Enter an element you want to Delete: " << endl;
		cout << endl;
		cin >> elem;

		if (Tree->toCheck(elem)) {
			system("cls");
			Tree->removeNode(elem);
			cout << "Element '" << elem << "' was deleted" << endl;
			cout << "No such element in the Tree" << endl;
		}
		else {
			system("cls");
			cout << "No such element in the Tree" << endl;
		}
		cout << endl;

		pressAnyButton();
	}
	break;

		// map()
	case 4:
	{
		system("cls");

		pressAnyButton();
	}
	break;

		// reduce()
	case 5:
	{
		system("cls");

		pressAnyButton();
	}
	break;

		// where()
	case 6:
	{
		system("cls");

		pressAnyButton();
	}
	break;

		// Balance Tree
	case 7:
	{
		system("cls");

		Tree->DSW();
		cout << "Tree was balanced" << endl;
		cout << endl;

		pressAnyButton();
	}
	break;
		// ToString
	case 8: 
	{
		system("cls");

		cout << "--------------INFO--------------" << endl;
		cout << endl;
		cout << "Enter a 3-letters string, which" << endl;
		cout << "contains 'N' (root), 'L' (left)," << endl;
		cout << "'R' (right) in order you want to" << endl;
		cout << "go through the Tree." << endl;
		cout << endl;
		cout << "--------------------------------" << endl;
		cout << endl;

		string order;

		cin >> order;

		system("cls");
		cout << "Your Tree in ORDER '" << order << "': " << endl;
		cout << Tree->toString(order) << endl;
		cout << endl;

		pressAnyButton();
	}
	break;

	// Exit
	case 9: 
	{
		system("cls");

		cout << "Closing . . ." << endl;
		cout << endl;

		exit(1);
	}
	break;
	}
}

template <typename T>
void Menu() {
	BinaryTree<T>* Tree = new BinaryTree<T>();

	while (true) {
		int choose = -1;
		MenuText();

		cin >> choose;

		makeDes(Tree, choose);
	}
}