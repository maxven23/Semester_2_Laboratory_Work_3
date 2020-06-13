#include <iostream>
#include "BinaryTree.hpp"
#include "Tests.hpp"
#include "Menu.hpp"

using namespace std;

int main(void) {
	bool start = false;
	int ISTART = 0;

	
	while (!start) {
		system("cls");
		cout << "------------------START-MENU------------------" << endl;
		cout << endl;
		cout << "1. Create a new Tree" << endl;
		cout << "2. Make Tests" << endl;
		cout << "3. Exit" << endl;
		cout << endl;
		cout << "----------------------------------------------" << endl;
		cout << endl;
		cin >> ISTART;

		if (ISTART == 1) {
			bool typed = false;
			int TYPE = 0;

			while (!typed) {
				system("cls");

				cout << "Choose TYPE of DATA:" << endl;
				cout << endl;
				cout << "1. Integer numbers" << endl;
				cout << "2. Real numbers" << endl;
				cout << endl;
				cout << "3. Cancel" << endl;
				cout << endl;
				
				cin >> TYPE;
				if (TYPE == 1) {
					Menu<int>();
				}
				else if (TYPE == 2) {
					Menu<double>();
				}
				else if (TYPE == 3) {
					typed = true;
				}
			}
		}
		else if (ISTART == 2) {
			test<int>();
			
			pressAnyButton();
		}
		else if (ISTART == 3) {
			exit(1);
		}
	}


	return 0;
}