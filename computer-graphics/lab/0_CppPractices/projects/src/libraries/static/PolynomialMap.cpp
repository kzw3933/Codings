#include <iostream>
#include <fstream>
#include <cassert>
#include <cmath>

#include "PolynomialMap.h"

#define EPSILON 1.0e-10	// zero double

using namespace std;

PolynomialMap::PolynomialMap(const PolynomialMap& other) {
    m_Polynomial = other.m_Polynomial;
}

PolynomialMap::PolynomialMap(const string& file) {
    ReadFromFile(file);
}

PolynomialMap::PolynomialMap(const double* cof, const int* deg, int n) {
	for(int i = 0; i < n; i++) {
		m_Polynomial[deg[i]] = cof[i];
	}
}

PolynomialMap::PolynomialMap(const vector<int>& deg, const vector<double>& cof) {
	assert(deg.size() == cof.size());
	for(int i = 0; i < deg.size(); i++) {
		m_Polynomial[deg[i]] = cof[i];
	}
}

double PolynomialMap::coff(int i) const {
	auto target = m_Polynomial.find(i);
	if(target == m_Polynomial.end())
		return 0.;
	return target->second;
}

double& PolynomialMap::coff(int i) {
	return m_Polynomial[i];
}

void PolynomialMap::compress() {
	auto iter=m_Polynomial.begin();
	while(iter!= m_Polynomial.end()) {
		if(iter->second < EPSILON) {
			iter = m_Polynomial.erase(iter);
		} else {
			iter++;
		}
	}
}

PolynomialMap PolynomialMap::operator+(const PolynomialMap& right) const {
	PolynomialMap poly(right);
	for(auto term: m_Polynomial) {
		poly.coff(term.first) += term.second;
	}
	poly.compress();
	return poly;
}

PolynomialMap PolynomialMap::operator-(const PolynomialMap& right) const {
	PolynomialMap poly(right);
	for(auto term: m_Polynomial) {
		poly.coff(term.first) -= term.second;
	}
	poly.compress();
	return poly;
}

PolynomialMap PolynomialMap::operator*(const PolynomialMap& right) const {
	PolynomialMap poly;
	for(auto term1: m_Polynomial) {
		for(auto term2: m_Polynomial) {
			poly.coff(term1.first+term2.first) += term1.second*term2.second;
		}
	}
	return poly;
}

PolynomialMap& PolynomialMap::operator=(const PolynomialMap& right) {
	m_Polynomial = right.m_Polynomial;
	return *this;
}

void PolynomialMap::Print() {
	compress();

	std::cout << "f(x) = ";

	if(m_Polynomial.empty()) {
		std::cout << 0 << std::endl;
		return ;
	}

    bool first = true;
    for (auto term : m_Polynomial) {
        if(term.second > 0) {
            if(!first)
                std::cout << "+";
            std::cout << term.second;

        } else if(term.second < 0) {
            std::cout  << term.second;
        } else {
            continue;
        }
        
        if (term.first > 0) {
            if(term.first == 1) 
                std::cout << "x";
            else
                std::cout << "x^" << term.first;
        } else if (term.first < 0) {
            std::cout << "x^(" << term.first << ")";
        }

        if(first)
            first = false;
    }
    std::cout << std::endl;
}

bool PolynomialMap::ReadFromFile(const string& file) {
    m_Polynomial.clear();

	ifstream fin;
    fin.open(file.c_str());
    if(!fin.is_open()) {
        std::cout << "Failed to open file " << file << "!" << std::endl;
        std::abort();
    }

    char ch;
    int num;
    int deg, cof;
    fin >> ch >> num;
    while (fin >> deg >> cof) {
        m_Polynomial[deg] = cof;
    }
    fin.close();
    return true;
}
