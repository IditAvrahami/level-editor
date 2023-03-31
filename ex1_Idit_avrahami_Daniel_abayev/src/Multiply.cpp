#include "Multiply.h"
#include <iostream>

Multiply::Multiply(const std::shared_ptr<Function>& func1, const std::shared_ptr<Function>& func2)
{
	m_function1 = func1;
	m_function2 = func2;
	m_expretion = "( " + func1->getExpresion() + " ) * ( " + func2->getExpresion() + " )";
}

double Multiply::calculateAnswer(const double x)
{
	return (m_function1->calculateAnswer(x) * m_function2->calculateAnswer(x));
}

std::shared_ptr<Function> Multiply::getFirst()
{
	return m_function1;
}

std::shared_ptr<Function> Multiply::getSecond()
{
	return m_function2;
}

void Multiply::setFirst(const std::shared_ptr<Function>& first)
{
	m_function1 = first;
}

void Multiply::setSecond(const std::shared_ptr<Function>& second)
{
	m_function2 = second;
}

bool Multiply::checkIfValidValue(const double x)
{
	return true;
}

void Multiply::print()
{
	std::cout << m_expretion;
}

std::string Multiply::getExpresion()
{
	return m_expretion;
}
