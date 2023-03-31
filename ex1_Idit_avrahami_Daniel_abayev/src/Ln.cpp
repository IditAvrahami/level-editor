#include "Ln.h"
#include <cmath>
#include <iostream>
#include <sstream>

Ln::Ln() : m_base(2.7182)
{
	m_expresion = "ln( x )";
}

Ln::Ln(const std::string& inside) : m_base(2.7182)
{
	m_expresion = "ln( " + inside + " )";
}

Ln::Ln(const double base, const std::shared_ptr<Function>& func) : m_base(base), m_func(func)
{
	std::ostringstream my_str;
	my_str << "log_" << m_base << " ( " << func->getExpresion() << " )";
	m_expresion = my_str.str();
}


double Ln::calculateAnswer(const double x)
{
	if (m_base == 2.7182)
	return std::log(x) ;
	return (std::log(m_func->calculateAnswer(x)) / std::log(m_base));
}

void Ln::print()
{
	std::cout << m_expresion;
}

std::string Ln::getExpresion()
{
	return m_expresion;
}
