#include "Add.h"
#include <iostream>

Add::Add(const std::shared_ptr<Function>& func1,const std::shared_ptr<Function>& func2)
{
	m_function1 = func1;
	m_function2 = func2;
	m_expretion = "( " + func1->getExpresion() + " ) + ( " + func2->getExpresion() + " )";
}

double Add::calculateAnswer(const double x)
{
	return (m_function1->calculateAnswer(x) + m_function2->calculateAnswer(x) );
}

std::shared_ptr<Function> Add::getFirst()
{
	return m_function1;
}

std::shared_ptr<Function> Add::getSecond()
{
	return m_function2;
}

void Add::setFirst(const std::shared_ptr<Function>& first)
{
	m_function1 = first;
}

void Add::setSecond(const std::shared_ptr<Function>& second)
{
	m_function2 = second;
}

bool Add::checkIfValidValue(const double x)
{
	return true;
}

void Add::print()
{
	std::cout << m_expretion;
}

std::string Add::getExpresion()
{
	return m_expretion;
}
