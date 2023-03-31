#include "Menu.h"
#include <vector>
#include "Sin.h"
#include "Ln.h"
#include "Constant.h"
#include "Add.h"
#include "Multiply.h"
#include "Composite.h"
#include "Polynomial.h"
#include <stdio.h>
#include <string.h>
#include <iomanip>

Menu::Menu() 
{
	m_functions.resize(0);
	auto sinPtr = std::make_shared<Sin>();
	auto lnPtr = std::make_shared<Ln>();
	m_functions.push_back(sinPtr);
	m_functions.push_back(lnPtr);
}

void Menu::start()
{
	std::cout << std::setprecision(2) << std::fixed;
	printFuncList();
	std::cout << " func :";

	std::string choice;
	std::cin >> choice;
	int num1, num2;
	double x;
	while (choice.compare("exit") != 0) // if want to exit
	{
		if (choice.compare(EVALUATE) == 0)
		{
			std::cout << "numbers of funcs and x value  :";
			std::cin >> num1 >> x; // get the func number
			if (isValid(num1))
				std::cout << std::setprecision(3) << m_functions[num1]->calculateAnswer(x) << std::endl;
		}
		else if (choice.compare(POLYNOM) == 0)
		{
			std::cout << "enter degree of polynom :";
			std::cin >> num1;
			std::vector<double> coefficient;
			for (size_t i = 0; i < num1; i++)
			{
				std::cin >> x;
				coefficient.push_back(x);
			}
			Polynomial func(num1, coefficient); // send the functions
			auto funcPtr = std::make_shared<Polynomial>(func);
			m_functions.push_back(funcPtr); // add func to list
		}
		else if (choice.compare(MULTIPLY) == 0)
		{
			std::cout << "numbers of funcs  :";
			std::cin >> num1 >> num2; // get the func number
			if (isValid(num1) && isValid(num2))
			{
				Multiply func(m_functions[num1], m_functions[num2]); // send the functions
				auto funcPtr = std::make_shared<Multiply>(func);
				m_functions.push_back(funcPtr); // add func to list
			}
		}
		else if (choice.compare(ADD) == 0)
		{
			std::cout << "numbers of funcs  :";
			std::cin >> num1 >> num2; // get the func number
			if (isValid(num1) && isValid(num2))
			{
				Add func(m_functions[num1], m_functions[num2]); // send the functions
				auto funcPtr = std::make_shared<Add>(func);
				m_functions.push_back(funcPtr); // add func to list
			}
		}
		else if (choice.compare(COMPOSITE) == 0)
		{
			std::cout << "numbers of funcs  :";
			std::cin >> num1 >> num2; // get the func number
			if (isValid(num1) && isValid(num2))
			{
				Composite func(m_functions[num1], m_functions[num2]); // send the functions
				auto funcPtr = std::make_shared<Composite>(func);
				m_functions.push_back(funcPtr); // add func to list
			}
		}
		else if (choice.compare(LOG) == 0)
		{
			std::cout << "numbers of base and func  :";
			std::cin >> x >> num2; // get the base and func number
			if (isValid(num2))
			{
				Ln func(x, m_functions[num2]); // send the functions
				auto funcPtr = std::make_shared<Ln>(func);
				m_functions.push_back(funcPtr); // add func to list
			}
		}
		else if (choice.compare(DELETE) == 0)
		{
			std::cin >> num1;
			if (isValid(num1))
				deleteFunc(num1);
		}
		else if (choice.compare(HELP) == 0)
		{
			helpFunc();
		}
		else
			std::cout << "invalid command" << std::endl;
		printFuncList();
		std::cin >> choice;
	}
	
	std::cout << "GoogBye" << std::endl;

}

void Menu::deleteFunc(const int row)
{	
	for (size_t i = row; i < m_functions.size() - 1; i++)
	{
		m_functions[i] = m_functions[i + 1];
	}
	if (row < m_functions.size())
		m_functions.pop_back();
}

void Menu::helpFunc()
{
	std::cout << "Following is the list of the calculator's available commands:" << std::endl;
	std::cout << "eval(uate) num x - Evaluates function #num on x" << std::endl;
	std::cout << "poly(nomial) N c0 c1 ... cN - 1 - Creates a polynomial with N coefficients" << std::endl;
	std::cout << "mul(tiply) num1 num2 - Creates a function that is the multiplication of" << std::endl;
	std::cout << "function #num1 and function #num2" << std::endl;
	std::cout << "add num1 num2 - Creates a function that is the sum of function #num1 and function #num2" << std::endl;
	std::cout << "comp(osite) num1 num2 - Creates a function that is the composition of" << std::endl;
	std::cout << "del(ete) num - Deletes function #num from function list" << std::endl;
	std::cout << "help - Prints this help screen" << std::endl;
	std::cout << "exit - Exits the program" << std::endl;
}

void Menu::printFuncList()
{
	std::cout << std::endl;
	for (size_t i = 0; i < m_functions.size(); i++)
	{
		std::cout << i << ". ";
		m_functions[i]->print();
		std::cout << std::endl;
	}
	std::cout << "enter command or help to help screen" << std::endl;
}

bool Menu::isValid(int func)
{
	if (func < m_functions.size())
		return true;
	return false;
}

