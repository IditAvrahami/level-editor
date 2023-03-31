#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include "Function.h"
#include <string>
class Menu
{
public:
	 Menu(); // build the array func sin and ln() 
	 ~Menu() = default;
	void start(); // loop of all get input from the user
	void deleteFunc(const int row);
	void helpFunc();
	void printFuncList();
	bool isValid(int func);
	
private:
	std::vector<std::shared_ptr<Function>> m_functions; // point of funcs
};
