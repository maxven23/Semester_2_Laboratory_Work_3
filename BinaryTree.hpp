#pragma once
#include "Headers.hpp"
#include <stdio.h>
#include <Windows.h>

template <class T> 
class BinaryTree {
public:
	template <class T>
	class Node {
	public:
		T item;
		Node* left;
		Node* right;

		Node(T item) {
			this->item = item;
			this->left = nullptr;
			this->right = nullptr;
		}

		T Get() {
			return this->item;
		}
	};

private:
	Node<T>* root;

public:
	//----------Конструкторы----------//
	BinaryTree(T item) {
		this->root = new Node<T>(item);
	};

	BinaryTree(Node* root) {
		this->root = root;
	};

	BinaryTree() {
		this->root = nullptr;
	};

	//-------------Методы--------------//

	Node<T>* getRoot() {
		return this->root;
	};

	// Проверка на наличие элемента в дереве
	bool toCheck(T item) {
		Node<T>* temp;
		temp = this->root;

		while (temp != nullptr) {
			if (temp->Get() > item) {
				temp = temp->right;
			}
			else if (temp->Get() < item) {
				temp = temp->left;
			}
			else {
				return true;
			}
		}
		
		if (temp == nullptr) {
			return false;
		}
	};

	// Поиск узла по значению с заданного узла
	Node<T>* findNode(Node<T>* Node, T item) {
		if (this->root == nullptr) {
			throw std::exception("ERROR: Tree is EMPTY");
		}

		if (Node->item == item) {
			return Node;
		}
		else {
			if (Node->item < item) {
				return findNode(Node->right, item);
			}
			else {
				return findNode(Node->left, item);
			}
		}
	};

	// Поиск узла с заданным значением во всём дереве
	Node<T>* findNode(T item) {
		return findNode(this->root, item);
	};

	// map для поддерева, начиная с заданного узла
	void map(Node<T>* Node, T (*foo)(T)) {
		Node->item = foo(Node->item);

		if (Node->right != nullptr) {
			map(Node->right, foo);
		}
		if (Node->left != nullptr) {
			map(Node->left, foo);
		}
	};

	// map для всего деева
	void map(T(*foo)(T)) {
		if (this->root == nullptr) {
			std::cout << "Tree is EMPTY" << std::endl;;
		}
		else {
			map(this->root, foo);
		}
	};

	// "Высота" поддерева, длина самой длинной ветви начиная с заданного узла
	static int getHeight(Node<T>* Node) 
	{
		int L = 0;
		int R = 0;
		if (Node->left == nullptr && Node->right == nullptr) {
			return 0;
		}
		else {
			if (Node->right != nullptr) {
				R = getHeight(Node->right) + 1;
			}
			else {
				R = 0;
			}

			if (Node->left != nullptr) {
				L = getHeight(Node->left) + 1;
			}
			else {
				L = 0;
			}
		}

		if (L > R) {
			return L;
		}
		else {
			return R;
		}
	};

	// "Высота" всего дерева
	int getHeight() {
		if (this->root == nullptr) {
			throw std::exception("ERROR: Tree is EMPTY");
		}

		return (getHeight(this->root));
	};

	// Получение поддерева по элементу
	BinaryTree<T>* getSubTree(T item) {
		Node<T>* temp = this->findNode(item);
		BinaryTree<T>* subTree = new BinaryTree<T>(temp);

		return subTree;
	};

	// Проверка деревьев на равенство
	bool isEqual(BinaryTree<T>* Tree) {
		if ((this->getRoot() == nullptr && Tree->getRoot() != nullptr) || 
			(this->getRoot() != nullptr && Tree->getRoot() == nullptr)) {
			return false;
		}

		if (this->getRoot() == nullptr && Tree->getRoot()) {
			return true;
		}

		Node<T>* Right = this->root->right;
		Node<T>* Left = this->root->left;
		Node<T>* treeRight = Tree->getRoot()->right;
		Node<T>* treeLeft = Tree->getRoot()->left;
		bool out = true;

		if (Left != nullptr && treeLeft != nullptr) {
			out = out && this->getSubTree(Left->item)->isEqual(Tree->getSubTree(treeLeft->item));
		}

		if (Left == nullptr && treeLeft == nullptr) {
			out = true;
		}
		else {
			out = false;
		}

		if (Right != nullptr && treeRight != nullptr) {
			out = out && this->getSubTree(Right->item)->isEqual(Tree->getSubTree(treeRight->item));
		}

		if (Right == nullptr && treeRight == nullptr) {
			out = true;
		}
		else {
			out = false;
		}
		return out;
	};

	// Проверка на вхождение поддерева в исходной дерево
	bool toCheckSubtree(BinaryTree<T>* subTree) {
		if (subTree->getRoot() == nullptr && this->getRoot() != nullptr) {
			return false;
		}
		if (subTree->getRoot() == this->getRoot()) {
			return true;
		}
		if (this->toCheck(subTree->getRoot()->item))	{
			return this->getSubTree(subTree->getRoot()->item)->isEqual(subTree);
		}
		else {
			return false;
		}
	};

	// Прошивка с заданного узла
	static Sequence<Node<T>*>* Chain(Node<T>* node, std::string order)	{
		Sequence<Node<T>*>* list = nullptr;
		Node<T>** array;
		for (size_t i = 0; i < order.length(); i++)	{
			switch (order[i]) {

			case 'N':
				if (list == nullptr) {
					list = new ListSequence<Node<T>*>();
					list->Prepend(node);
				}
				else {
					Sequence<Node<T>*>* list1 = nullptr;
					list1 = new ListSequence<Node<T>*>();
					list1->Prepend(node);

					list = list->Concat(list1);
				}
				break;

			case 'R':
				if (node->right != nullptr) {
					if (list == nullptr) {
						list = Chain(Node->right, order);
					}
					else {
						list = list->Concat(Chain(node->right, order));
					}
				}
				break;

			case 'L':
				if (node->left != nullptr)  {
					if (list == nullptr) {
						list = Chain(node->left, order);
					}
					else {
						list = list->Concat(Chain(node->left, order));
					}
				}
				break;
			}
		}
		return list;
	};

	// Прошивка всего дерева
	Sequence<Node<T>*>* Chain(std::string order) {
		return this->Chain(this->root, order);
	};

	// Вставка элемента
	void toInsert(T item) {
		if (this->toCheck(item)) {
			return;
		}

		Node<T>* toInsert = new Node<T>(item);
		Node<T>* p = this->root;
		Node<T>* p1 = nullptr;

		while (p != nullptr) {
			p1 = p;
			if (item < p->Get()) {
				p = p->left;
			}
			else {
				p = p->right;
			}
		}

		if (p1 == nullptr) {
			this->root = toInsert;
		}
		else {
			if (item < p1->Get()) {
				p1->left = toInsert;
			}
			else {
				p1->right = toInsert;
			}
		}
	};

	// Удаление элемента
	bool removeNode(Node<T>* node, T item) {
		if (node == nullptr) {
			return false;
		}

		bool where;
		Node<T>* temp = node;
		Node<T>* temp1 = nullptr;

		if (temp->left == nullptr && temp->right == nullptr) {
			if (temp->item == item) {
				delete temp;
				return true;
			}
			else {
				return false;
			}
		}
		while (temp != nullptr && temp->item != item) {
			if (item < temp->item) {
				where = false;
				temp1 = temp;
				temp = temp->left;
			}
			else {
				if (item > temp->item) {
					where = true;
					temp1 = temp;
					temp = temp->right;
				}
			}
		}
		if (temp == nullptr) {
			std::cout << "ERROR: Tree is EMPTY" << std::endl;
			return false;
		}
		else {
			if (temp->right == nullptr && temp->left == nullptr) {
				if (!where) {
					temp1->left = nullptr;
				}
				else {
					temp1->right = nullptr;
				}
				delete temp;
				return true;
			}
			else {
				if (temp->right != nullptr && temp->left == nullptr) {
					if (temp1->left == temp) {
						temp1->left = temp->right;
					}
					else {
						temp1->right = temp->right;
					}
					delete temp;
					return true;
				}
				else {
					if (temp->left != nullptr && temp->right == nullptr) {
						if (temp1->left == temp) {
							temp1->left = temp->left;
						}
						else {
							temp1->right = temp->left;
						}
						delete temp;
						return true;
					}
					else {
						if (temp->left != nullptr && temp->right != nullptr) {
							Node<T>* temp2 = nullptr;
							temp1 = temp;
							temp2 = temp;
							where = true;
							temp = temp->right;
							while (temp->left != nullptr) {
								temp2 = temp;
								where = false;
								temp = temp->left;
							}
							temp1->item = temp->item;

							if (temp->right != nullptr) {
								if (where) {
									temp2->right = temp->right;
								}
								else {
									temp2->left = temp->right;
								}

								delete temp;
								return true;
							}
							else {
								if (where) {
									temp2->right = nullptr;
								}
								else {
									temp2->left = nullptr;
								}

								delete temp;
								return true;
							}
						}
					}
				}
			}
		}
	};

	// Удаление узла по элементу
	bool removeNode(T item) {
		return removeNode(this->root, item);
	};

	// Сохранение дерева по обходу в строку
	std::string toString(std::string order) {
		std::string res;
		Sequence<Node<T>*>* chainTree = this->Chain(order);
		if (this->root == nullptr) {
			throw std::exception("ERROR: Tree is EMPTY");
		}

		for (int i = 0; i < chainTree->GetSize(); i++) {
			if (i == 0) {
				res += std::to_string(chainTree->Get(i)->item) + " ";
			}
			else {
				res += "-> " + std::to_string(chainTree->Get(i)->item) + " ";
			}
		}
		return res;
	};

	// reduce
	T reduce(T(*foo)(T, T), T startItem, std::string order) {
		if (this->root == nullptr) {
			throw std::exception("ERROR: Tree is EMPTY");
		}
		T out = { 0 };
		Sequence<Node<T>*>* ChainTree = this->Chain(order);

		for (int i = 0; i < ChainTree->GetSize(); i++) {
			if (i == 0) {
				out = foo(ChainTree->Get(i)->Get(), startItem);
			}
			else {
				out = foo(ChainTree->Get(i)->Get(), out);
			}
		}
		return out;
	};

	// Вывод дерева
	void printTree(Node<T>* node, int level)
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		if (node)
		{
			printTree(node->left, level + 1);
			for (int i = 0; i < level - this->getHeight(); i++) cout << "          ";
			SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 2));
			std::cout << "lvl" << level - this->getHeight() << ": ";
			SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
			std::cout << node->Get() << std::endl;
			printTree(node->right, level + 1);
		}
	};
};