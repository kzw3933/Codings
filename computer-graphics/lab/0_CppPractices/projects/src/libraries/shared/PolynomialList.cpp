#include <iostream>
#include <fstream>
#include <cmath>

#include "PolynomialList.h"

#define EPSILON 1.0e-10	// zero double

using namespace std;

PolynomialList::PolynomialList(const PolynomialList& other) {
    m_Polynomial = other.m_Polynomial;
}

PolynomialList::PolynomialList(const string& file) {
    ReadFromFile(file);
}

PolynomialList::PolynomialList(const double* cof, const int* deg, int n) {
    for (int i = 0; i < n; i++) {
        AddOneTerm(Term(deg[i], cof[i]));
    }
}

PolynomialList::PolynomialList(const vector<int>& deg, const vector<double>& cof) {
    for (int i = 0; i < deg.size(); i++) {
        AddOneTerm(Term(deg[i], cof[i]));
    }
}

double PolynomialList::coff(int i) const {
    for (auto term : m_Polynomial) {
        if (term.deg == i)
            return term.cof;
    }
    return 0.; 
}

double& PolynomialList::coff(int i) {
    return AddOneTerm(Term(i, 0)).cof;
}

void PolynomialList::compress() {
    auto iter = m_Polynomial.begin();
    while (iter != m_Polynomial.end()) {
        if (fabs((*iter).cof) < EPSILON)
            iter = m_Polynomial.erase(iter);
        else
            iter++;
    }
}

PolynomialList PolynomialList::operator+(const PolynomialList& right) const {
    PolynomialList poly(*this);
    for (auto term : right.m_Polynomial) {
        poly.AddOneTerm(term);
    }
    return poly;
}

PolynomialList PolynomialList::operator-(const PolynomialList& right) const {
    PolynomialList poly(*this);
    for (auto term : right.m_Polynomial) {
        poly.AddOneTerm(Term(term.deg, -term.cof));
    }
    return poly;
}

PolynomialList PolynomialList::operator*(const PolynomialList& right) const {
    PolynomialList poly;
    for (auto term1 : m_Polynomial) {
        for (auto term2 : right.m_Polynomial) {
            poly.AddOneTerm(Term(term1.deg + term2.deg, term1.cof * term2.cof));
        }
    }
    return poly;
}

PolynomialList& PolynomialList::operator=(const PolynomialList& right) {
    m_Polynomial = right.m_Polynomial;
    return *this;
}

void PolynomialList::Print() {
    compress();
    std::cout << "f(x) = ";

    if(m_Polynomial.empty()) {
		std::cout << 0 << std::endl;
		return ;
	}

    bool first = true;
    for (auto term : m_Polynomial) {
        if(term.cof > 0) {
            if(!first)
                std::cout << "+";
            std::cout << term.cof;

        } else if(term.cof < 0) {
            std::cout  << term.cof;
        } else {
            continue;
        }
        
        if (term.deg > 0) {
            if(term.deg == 1) 
                std::cout << "x";
            else
                std::cout << "x^" << term.deg;
        } else if (term.deg < 0) {
            std::cout << "x^(" << term.deg << ")";
        }

        if(first)
            first = false;
    }
    std::cout << std::endl;

}

bool PolynomialList::ReadFromFile(const string& file) {
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
        AddOneTerm(Term(deg, cof));
    }
    fin.close();
    return true;
}

PolynomialList::Term& PolynomialList::AddOneTerm(const Term& term) {
    auto iter = m_Polynomial.begin();
    for (; iter != m_Polynomial.end(); iter++) {
        if (iter->deg < term.deg)
            break;
        if (iter->deg == term.deg) {
            iter->cof += term.cof;
            return *iter;
        }
    }
    return *m_Polynomial.insert(iter, term);
}
