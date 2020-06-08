#pragma once

template <class T>

class DynamicArray
{
private:
	T* items;
	int size;

public:
	// ������������
	DynamicArray(T* items, const int size) {
		if (size < 0)
			throw std::exception("INVALID INPUT: size < 0");
		this->size = size;
		this->items = new T[size];
		for (int i = 0; i < size; i++) {
			this->items[i] = *(items + i);
		}
	}

	DynamicArray(const DynamicArray<T> &array) {
		this->size = array.GetSize();
		this->items = new T[this->size];
		for (int i = 0; i < this->size; i++) {
			this->Set(i, array.Get(i));
		}

	}

	DynamicArray(const int size) {
		if (size < 0)
			throw std::exception("INVALID INPUT: size < 0");
		this->items = new T[size];
		this->size = size;
	}

	// ��������� ������� �������
	int GetSize() {
		return this->size;
	}

	// ��������� �������� ������� �� �������
	T Get(int index) {
		if (index < 0 || index >= this->size)
			throw std::exception("INDEX ERROR: Index out of range");
		return this->items[index];
	}

	// ��������� ������� � ���������� �������� ������� (������)
	T GetFirst() {
		return Get(0);
	}

	T GetLast() {
		return this->Get(this->GetSize() - 1);
	}

	// ��������� / ������� ����� ��������� ������� �� �������
	void Set(int index, const T value) {
		if (index < 0 || index >= this->size)
			throw std::exception("IDNEX ERROR: Index out of range");
		this->items[index] = value;
	}
	
	// ����������
	~DynamicArray() {
		delete[] items;
	};
};