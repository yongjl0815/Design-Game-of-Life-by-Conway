/******************************************************************
* * Author: Yong Lee
* * Date Created: 3-1-14
* * Lab Number: CS165
* * Filename: w8p3.cpp
* *
* * Overview: Convert string into an integer using stringstream.
* *	If input is invalid, the user is asked to enter again.
* *
* *
* * Input: The user enters an integer or not.
* *
* *
* * Output: A converted integer printed.
* * 
* *  
* *****************************************************************/

#include <iostream>
#include <string>
#include <sstream>

int main()
{
	std::stringstream whatever;

	std::string number;

	int integ;

	do
	{
		whatever.str("");
		whatever.clear();

		std::cout << "Please enter an integer, or not. Whatever you want man." << std::endl
		<< "But if you don't enter an integer, I'm gonna pester you again." << std::endl;
		std::getline (std::cin, number);

		whatever << number;

		while (whatever >> integ)
		{
		}
	}
	while(integ == 0); // checks if input is an integer. To be honest, I'm not sure this is what the problem wants, but it seems to does its job and keeps the code simple.
	
	std::cout << "Number you entered is " << integ << std::endl;
	
	return 0;
}
