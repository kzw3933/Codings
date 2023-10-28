// implementation of class DArray
#include <iostream>

#include "DArray.h"

#define ALIGN8(x) ((x+7)/8)*8

// default constructor
DArray::DArray() {
	Init();
}

// set an array with default values
DArray::DArray(int nSize, double dValue)
	: m_pData(new double[ALIGN8(nSize)]), m_nSize(nSize), m_nMax(ALIGN8(nSize)) {
	for (int i = 0; i < nSize; i++) {
		m_pData[i] = dValue;
	}
}

DArray::DArray(const DArray& arr) 
	: m_pData(new double[arr.m_nMax]), m_nSize(arr.m_nSize), m_nMax(arr.m_nMax) {
	for (int i = 0; i < arr.m_nSize; i++) {
		m_pData[i] = arr.m_pData[i];
	}
}

// deconstructor
DArray::~DArray() {
	Free();
}

// display the elements of the array
void DArray::Print() const {
	std::cout << "DArray[" << m_nSize << "]: ";
	for (int i = 0; i < m_nSize; i++) {
		std::cout << m_pData[i] << " ";
	}
	std::cout << std::endl;
}

// initilize the array
void DArray::Init() {
	m_pData = nullptr;
	m_nSize = 0;
	m_nMax = 0;
}

// free the array
void DArray::Free() {
	if (m_pData != nullptr) {
		delete[] m_pData;
		m_pData = nullptr;

		m_nSize = 0;
		m_nMax = 0;
	}
}

// get the size of the array
int DArray::GetSize() const {
	return m_nSize;
}

// set the size of the array
void DArray::SetSize(int nSize) {
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
const double& DArray::GetAt(int nIndex) const {
	if (nIndex < m_nSize && nIndex >= 0)
		return m_pData[nIndex];

	std::cout << "Error! The Index is invalid." << std::endl;
	std::abort();
}

// set the value of an element 
void DArray::SetAt(int nIndex, double dValue) {
	if (nIndex < m_nSize && nIndex >= 0) {
		m_pData[nIndex] = dValue;
		return;
	}

	std::cout << "Error! The Index is invalid." << std::endl;
	std::abort();
}

// overload operator '[]'
double& DArray::operator[](int nIndex) {
	if (nIndex < m_nSize && nIndex >= 0)
		return m_pData[nIndex];

	std::cout << "Error! The Index is invalid." << std::endl;
	std::abort();
}

// overload operator '[]'
const double& DArray::operator[](int nIndex) const {
	if (nIndex < m_nSize && nIndex >= 0)
		return m_pData[nIndex];

	std::cout << "Error! The Index is invalid." << std::endl;
	std::abort();
}

// add a new element at the end of the array
void DArray::PushBack(double dValue) {
	Reserve(m_nSize + 1);
	m_pData[m_nSize] = dValue;
	m_nSize += 1;
}

// delete an element at some index
void DArray::DeleteAt(int nIndex) {
	if (nIndex < m_nSize && nIndex >= 0) {
		for (int i = nIndex; i < m_nSize-1; i++) {
			m_pData[i] = m_pData[i + 1];
		}
		m_nSize -= 1;
		return;
	}

	std::cout << "Error! The Index is invalid." << std::endl;
	std::abort();
}

// insert a new element at some index
void DArray::InsertAt(int nIndex, double dValue) {
	if (nIndex < m_nSize && nIndex >= 0 || m_nSize == 0 && nIndex == 0) {
		Reserve(m_nSize + 1);
		for (int i = m_nSize; i > nIndex; i--) {
			m_pData[i] = m_pData[i - 1];
		}
		m_pData[nIndex] = dValue;
		m_nSize += 1;
		return;
	}
	
	std::cout << "Error! The Index is invalid." << std::endl;
	std::abort();
}

// overload operator '='
DArray& DArray::operator = (const DArray& arr) {
	Reserve(arr.m_nSize);
	for (int i = 0; i < arr.m_nSize; i++) {
		m_pData[i] = arr.m_pData[i];
	}
	m_nSize = arr.m_nSize;
	return *this;
}

// allocate enough memory
void DArray::Reserve(int nSize) {
	if (nSize > m_nMax) {
		int new_size = m_nMax > 0? m_nMax: 8;
		while (new_size < nSize) {
			new_size *= 2;
		}
		auto new_pData = new double[new_size];
		for (int i = 0; i < m_nSize; i++) {
			new_pData[i] = m_pData[i];
		}
		if (m_pData != nullptr)
			delete[] m_pData;
		m_pData = new_pData;
		m_nMax = new_size;
	}
}
