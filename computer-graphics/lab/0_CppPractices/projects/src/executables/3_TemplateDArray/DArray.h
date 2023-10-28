#pragma once

#include <iostream>

#define ALIGN8(x) ((x+7)/8)*8

// interfaces of Dynamic Array class DArray
template <typename T>
class DArray {
public:
	DArray(); // default constructor
	DArray(int nSize, T tValue = 0); // set an array with default values
	DArray(const DArray& arr); // copy constructor
	~DArray(); // deconstructor

	void Print() const; // print the elements of the array

	int GetSize() const; // get the size of the array
	void SetSize(int nSize); // set the size of the array

	const T& GetAt(int nIndex) const; // get an element at an index
	void SetAt(int nIndex, T tValue); // set the value of an element

	T& operator[](int nIndex); // overload operator '[]'
	const T& operator[](int nIndex) const; // overload operator '[]'

	void PushBack(T tValue); // add a new element at the end of the array
	void DeleteAt(int nIndex); // delete an element at some index
	void InsertAt(int nIndex, T tValue); // insert a new element at some index

	DArray& operator = (const DArray& arr); //overload operator '='

private:
	T* m_pData; // the pointer to the array memory
	int m_nSize; // the size of the array
	int m_nMax;

private:
	void Init(); // initilize the array
	void Free(); // free the array
	void Reserve(int nSize); // allocate enough memory
};



// implementation of class DArray

// default constructor
template<typename T>
DArray<T>::DArray() {
	Init();
}

// set an array with default values
template<typename T>
DArray<T>::DArray(int nSize, T tValue)
	: m_pData(new T[ALIGN8(nSize)]), m_nSize(nSize), m_nMax(ALIGN8(nSize)) {
	for (int i = 0; i < nSize; i++) {
		m_pData[i] = tValue;
	}
}

template<typename T>
DArray<T>::DArray(const DArray& arr)
	: m_pData(new T[arr.m_nMax]), m_nSize(arr.m_nSize), m_nMax(arr.m_nMax) {
	for (int i = 0; i < arr.m_nSize; i++) {
		m_pData[i] = arr.m_pData[i];
	}
}

// deconstructor
template<typename T>
DArray<T>::~DArray() {
	Free();
}

// display the elements of the array
template<typename T>
void DArray<T>::Print() const {
	std::cout << "DArray[" << m_nSize << "]: ";
	for (int i = 0; i < m_nSize; i++) {
		std::cout << m_pData[i] << " ";
	}
	std::cout << std::endl;
}

// initilize the array
template<typename T>
void DArray<T>::Init() {
	m_pData = nullptr;
	m_nSize = 0;
	m_nMax = 0;
}

// free the array
template<typename T>
void DArray<T>::Free() {
	if (m_pData != nullptr) {
		delete[] m_pData;
		m_pData = nullptr;

		m_nSize = 0;
		m_nMax = 0;
	}
}

// get the size of the array
template<typename T>
int DArray<T>::GetSize() const {
	return m_nSize;
}

// set the size of the array
template<typename T>
void DArray<T>::SetSize(int nSize) {
	Reserve(nSize);
	if (nSize > m_nSize) {
		for (int i = m_nSize; i < nSize; i++) {
			m_pData[i] = 0;
		}
	}
	else {
		m_nSize = nSize;
	}
}

// get an element at an index
template<typename T>
const T& DArray<T>::GetAt(int nIndex) const {
	if (nIndex < m_nSize && nIndex >= 0)
		return m_pData[nIndex];

	std::cout << "Error! The Index is invalid." << std::endl;
	std::abort();
}

// set the value of an element 
template<typename T>
void DArray<T>::SetAt(int nIndex, T tValue) {
	if (nIndex < m_nSize && nIndex >= 0) {
		m_pData[nIndex] = tValue;
		return;
	}

	std::cout << "Error! The Index is invalid." << std::endl;
	std::abort();
}

// overload operator '[]'
template<typename T>
T& DArray<T>::operator[](int nIndex) {
	if (nIndex < m_nSize && nIndex >= 0)
		return m_pData[nIndex];

	std::cout << "Error! The Index is invalid." << std::endl;
	std::abort();
}

// overload operator '[]'
template<typename T>
const T& DArray<T>::operator[](int nIndex) const {
	if (nIndex < m_nSize && nIndex >= 0)
		return m_pData[nIndex];

	std::cout << "Error! The Index is invalid." << std::endl;
	std::abort();
}

// add a new element at the end of the array
template<typename T>
void DArray<T>::PushBack(T tValue) {
	Reserve(m_nSize + 1);
	m_pData[m_nSize] = tValue;
	m_nSize += 1;
}

// delete an element at some index
template<typename T>
void DArray<T>::DeleteAt(int nIndex) {
	if (nIndex < m_nSize && nIndex >= 0) {
		for (int i = nIndex; i < m_nSize - 1; i++) {
			m_pData[i] = m_pData[i + 1];
		}
		m_nSize -= 1;
		return;
	}

	std::cout << "Error! The Index is invalid." << std::endl;
	std::abort();
}

// insert a new element at some index
template<typename T>
void DArray<T>::InsertAt(int nIndex, T tValue) {
	if (nIndex < m_nSize&& nIndex >= 0 || m_nSize == 0 && nIndex == 0) {
		Reserve(m_nSize + 1);
		for (int i = m_nSize; i > nIndex; i--) {
			m_pData[i] = m_pData[i - 1];
		}
		m_pData[nIndex] = tValue;
		m_nSize += 1;
		return;
	}

	std::cout << "Error! The Index is invalid." << std::endl;
	std::abort();
}

// overload operator '='
template<typename T>
DArray<T>& DArray<T>::operator = (const DArray& arr) {
	Reserve(arr.m_nSize);
	for (int i = 0; i < arr.m_nSize; i++) {
		m_pData[i] = arr.m_pData[i];
	}
	m_nSize = arr.m_nSize;
	return *this;
}

// allocate enough memory
template<typename T>
void DArray<T>::Reserve(int nSize) {
	if (nSize > m_nMax) {
		int new_size = m_nMax > 0 ? m_nMax : 8;
		while (new_size < nSize) {
			new_size *= 2;
		}
		auto new_pData = new T[new_size];
		for (int i = 0; i < m_nSize; i++) {
			new_pData[i] = m_pData[i];
		}
		if (m_pData != nullptr)
			delete[] m_pData;
		m_pData = new_pData;
		m_nMax = new_size;
	}
}
