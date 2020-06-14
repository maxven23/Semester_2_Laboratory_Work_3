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

void funcMenu() {
	system("cls");
	cout << "-------------------funcMENU-------------------" << endl;
	cout << endl;
	cout << "1. funcName#1" << endl;
	cout << "2. funcName#2" << endl;
	cout << "3. funcName#3" << endl;
	cout << endl;
	cout << "0. Exit" << endl;
	cout << endl;
	cout << "----------------------------------------------" << endl;
	cout << endl;
}

void pressAnyButton() {
	cout << "Press any button to continue . . ." << endl;
	system("pause>>VOID");
}

void Example() {
	system("cls");
	cout << "THIS IS AN EXAMPLE OF FUNC" << endl;
	cout << endl;
	pressAnyButton();
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
			Tree->printTree();
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

		if (Tree->removeNode(elem)) {
			system("cls");
			cout << "Element '" << elem << "' was deleted successfully" << endl;
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
		int choice;
		while (true) {
			funcMenu();

			cin >> choice;
			if (choice == 1) {
				Example();
			}
			if (choice == 2) {
				Example();
			}
			if (choice == 3) {
				Example();
			}
			else if (choice == 0) {
				break;
			}
		}
	}
	break;

		// reduce()
	case 5:
	{
		system("cls");
		int choice;
		while (true) {
			funcMenu();

			cin >> choice;
			if (choice == 1) {
				Example();
			}
			if (choice == 2) {
				Example();
			}
			if (choice == 3) {
				Example();
			}
			else if (choice == 0) {
				break;
			}
		}
	}
	break;

		// where()
	case 6:
	{
		system("cls");
		int choice;
		while (true) {
			funcMenu();

			cin >> choice;
			if (choice == 1) {
				Example();
			}
			if (choice == 2) {
				Example();
			}
			if (choice == 3) {
				Example();
			}
			else if (choice == 0) {
				break;
			}
		}
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