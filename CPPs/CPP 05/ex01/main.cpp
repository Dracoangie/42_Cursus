#include "Form.hpp"
#include <iostream>

int main()
{
	std::cout << "\n===== TEST 1: valid form =====\n" << std::endl;

	try
	{
		Form contract("Contract", 50, 25);
		std::cout << contract << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}


	std::cout << "\n===== TEST 2: invalid grades =====\n" << std::endl;

	try
	{
		Form invalid1("TooHigh", 0, 25);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Form invalid2("TooLow", 151, 25);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}


	std::cout << "\n===== TEST 3: successful signing =====\n" << std::endl;

	try
	{
		Bureaucrat boss("Boss", 1);
		Form taxForm("Taxes", 50, 20);

		std::cout << boss << std::endl;
		std::cout << taxForm << std::endl;

		boss.signForm(taxForm);

		std::cout << taxForm << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}


	std::cout << "\n===== TEST 4: failed signing =====\n" << std::endl;

	try
	{
		Bureaucrat intern("Intern", 150);
		Form secret("Secret files", 50, 10);

		std::cout << intern << std::endl;
		std::cout << secret << std::endl;

		intern.signForm(secret);

		std::cout << secret << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}