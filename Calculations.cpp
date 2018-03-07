#include "stdafx.h"
#include <iostream>
#include <string>
#include <conio.h>

int NumCheck()	
{
	bool err = false;
	int num = 0;
	do {
		err = false;
		std::cin >> num;
		if (!std::cin.good()) {
			err = true;
			std::cout << "That is not a number!";
			std::cin.clear();
			std::cin.ignore(100, '\n');
		}
	} while (err);
	return num;
}

int Addition(int &first_num, int &second_num)
{
	return first_num + second_num;
}

int Subtraction(int &first_num, int &second_num)
{
	return first_num - second_num;
}

int Multipication(int &first_num, int &second_num)
{
	return first_num * second_num;
}

int Division(int &first_num, int &second_num)
{
	if (second_num == 0) {
		std::string error = "Division by zero!\n";
		throw error;
	}
	return first_num / second_num;
}

int Factorial(int &first_num)
{
	int fact = 1;
	for (int i = 1; i <= first_num; ++i)
	{
		fact *= i;
	}
	first_num = fact;
	return first_num;
}

int Modulo(int &first_num, int &second_num)
{
	if (second_num == 0) {
		std::string error = "Division by zero!\n";
		throw error;
	}
	return first_num % second_num;
}

int CalcOptions() {
	int first_num = 0, second_num = 0;
	char operation = '0';
	char again = '0';
	bool exit = false;
	std::cout << "Press ESC to exit." << std::endl;
	while(exit==false)
	{
	
		first_num = NumCheck();
		std::cin >> operation;

		switch (operation)
		{
		case '+':
			second_num = NumCheck();
			std::cout << "= " << Addition(first_num, second_num) << std::endl;
			break;
		case '-':
			second_num = NumCheck();
			std::cout << "= " << Subtraction(first_num, second_num) << std::endl;
			break;
		case '*':
			second_num = NumCheck();
			std::cout << "= " << Multipication(first_num, second_num) << std::endl;
			break;
		case '/':
			second_num = NumCheck();
			try
			{
				std::cout << "= " << Division(first_num, second_num) << std::endl;
			}
			catch(std::string error)
			{
				std::cout << "Exception! " << error;
			}
			std::cin.get();
			break;
		case '!':
			std::cout << Factorial(first_num) << std::endl;
			break;
		case '%':
			second_num = NumCheck();
			try
			{
				std::cout << "= " << Modulo(first_num, second_num) << std::endl;
			}
			catch (std::string error)
			{
				std::cout << "Exception! " << error;
			}
			std::cin.get();
			break;
		}

		again = _getch();
		if (again == 27)
			exit = true;
	} 
	return 0;
}

