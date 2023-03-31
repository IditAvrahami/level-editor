#include "Polynomial.h"
#include <iostream>
#include <iomanip>
#include <sstream>

Polynomial::Polynomial(const int degree, const std::vector<double>& coefficient) 
	: m_degree(degree), m_polynom(coefficient)
{
	if (allZero())
		m_polynom.push_back(0);
}

bool Polynomial::allZero()
{
	for (size_t i = 0; i < m_polynom.size(); i++)
	{
		if (m_polynom[i] != 0)
			return false;
	}
	return true;
}

double Polynomial::calculateAnswer(const double x)
{
	double result = m_polynom[0];
	double expResult = x;
	for (size_t i = 1; i < m_degree; i++)
	{
		result += (m_polynom[i] * expResult);
		expResult *= expResult;
	}
	return result;
}

void Polynomial::print()
{
	std::cout << this->getExpresion();
}

std::string Polynomial::getExpresion()
{
	std::ostringstream my_str;
	if (m_degree < 1 || allZero())
	{
		my_str << m_polynom[0];
		std::string exp = my_str.str();
		return exp;
	}
	int size = m_degree - 1;
	for (int i = size; i >= 0; i--)
	{
		if (m_polynom[i] != 0)
		{
			my_str << m_polynom[i] << "*";
			my_str << "x ^ " << i;
			if ( i != 0)
				my_str << " + ";
		}
	}
	std::string exp = my_str.str();
	return std::string(exp);

}
