#pragma once

template <class T>

class LinkedList 
{
private:
	// ����� ���� ������
	template <class T> 
	class Node {
	public:
		T item;
		Node* pnext;

		Node(T item = T(), Node* pnext = nullptr) {
			this->item = item;
			this->pnext = pnext;
		}
	};
	Node<T>* head;
	int size;
public:
	// ������������
	LinkedList() {
		this->size = 0;
		head = nullptr;
	};

	LinkedList(LinkedList<T>& list) {
		this->head = nullptr;
		this->size = list.Getsize();
		for (int i = 0; i < list.GetSize(); i++)
		{
			this->Prepend(list.Get(i));
		}
	};

	LinkedList(T* items, int size) {
		if (size < 0)
			throw std::exception("INVALID INPUT: Size < 0");
		this->head = nullptr;
		T* ptemp;
		this->size = size;
		for (int i = 0; i < size; i++)
		{
			ptemp = &items[i];
			if (head == nullptr)
			{
				head = new Node<T>(*ptemp);
			}
			else
			{
				Node<T>* temp = head;
				while (temp->pnext != nullptr)
				{
					temp = temp->pnext;
				}
				temp->pnext = new Node<T>(*ptemp);
			}
		}
	};
	
	// ��������� ����� ������
	int GetSize() {
		return this->size;
	}

	// ��������� �������� �� �������
	T Get(int index) {
		if (index < 0 || index >= this->size)
			throw std::exception("INDEX ERROR: Index out of range");
		int sch = 0;
		Node<T>* temp;
		temp = this->head;
		while (temp != nullptr) {
			if (sch == index)
				return temp->item;
			temp = temp->pnext;
			++sch;
		}
	};

	// ��������� ������� � ���������� �������� ������������� (� ������)
	T GetFirst() {
		return Get(0);
	};

	T GetLast() {
		return Get(this->size - 1);
	};

	// ���������� ���� � ������ ������
	void Append(T item) {
		this->head = new Node<T>(item, this->head);
		++this->size;
	};

	// ���������� ���� � ����� ������
	void Prepend(T item) {
		if (head == nullptr)
			this->head = new Node<T>(item);
		else {
			Node<T>* temp;
			temp = this->head;
			while (temp->pnext != nullptr) {
				temp = temp->pnext;
			}
			temp->pnext = new Node<T>(item);
		}
		++this->size;
	};

	// ������� ���� �� �������
	void InsertAt(T item, int index) {
		if (index < 0 || index >= this->size)
			throw std::exception("INDEX ERROR: Index out of range");
		if (index == 0)
			Append(item);
		else {
			Node<T>* temp;
			temp = this->head;
			for (int i = 0; i < index - 1; i++) {
				temp = temp->pnext;
			}
			Node<T>* newN = new Node<T>(item, temp->pnext);
			temp->pnext = newN;
		}
	};

	// �������� ����
	void fPop() {
		if (this->GetSize() == 0) {
			throw std::exception("INDEX ERROR: Empty list");
		}
		Node<T>* temp;
		temp = this->head;
		this->head = this->head->pnext;
		delete temp;
		--this->size;
	};

	// �������� ���� �� �������
	void RemoveAt(int index) {
		if (index < 0 || index >= this->size)
			throw std::exception("INDEX ERROR: Index out of range");
		if (index == 0) {
			fPop();
		}
		else {
			Node<T>* temp;
			Node<T>* del;
			temp = this->head;
			for (int i = 0; i < index; i++) {
				temp = temp->pnext;
			}
			del = temp->pnext;
			temp->pnext = del->pnext;
			delete del;
			--this->size;
		}
	};

	// ��������� "���������" �� ���������� � ��������� ��������
	LinkedList<T>* GetSubList(int start, int end) {
		if (start < 0 || start >= this->size || end < 0 || end >= this->size || end < start)
			throw std::exception("INDEX ERROR: Index out of range");
		T* temp = new T[end - start + 1];
		LinkedList<T>* tempList;
		tempList = new LinkedList<T>();
		for (int i = 0; i < end - start + 1; i++) {
			temp[i] = this->Get(i + start);
		}
		for (int i = 0; i < end - start + 1; i++) {
			tempList->Prepend(temp[i]);
		}
		delete[] temp;
		return tempList;
	};

	// ����������
	~LinkedList() {
		while (this->size != 0)
			fPop();
	};

	// ��������������� ���������� ������
	T& operator [] (const int index) {
		if (index < 0 || index >= this->size)
			throw std::exception("INDEX ERROR: Index out of range");
		Node<T>* temp;
		temp = this->head;
		int temp_i = 0;
		while (temp != nullptr) {
			if (temp_i == index) {
				return temp->item;
			}
			temp = temp->pnext;
			++temp_i;
		}
	};
};