/*****************************************************************
* * Author: Yong Lee
* * Date Created: 2-27-14
* * Lab Number: CS165
* * Filename: w8p2.cpp
* *
* * Overview: Merge the numbers from two files into a third
* *	file in a long list from smallest value to largest
* *
* * Input: The numbers from two files in sorted order from
* *	smallest to largest
* *
* * Output: Thirst file containing a long list of numbers
* *	from two files from smallest to largest
* * 
* * 
* *  
* *****************************************************************/

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

//merge two files into a third file 
void merge(std::ifstream &f1, std::ifstream &f2, std::ofstream &f3);


int main()
{
	std::cout << "Let's merge two files and put it into a third file shall we?" << std::endl;

	std::ifstream file1;
	std::ifstream file2;
	std::ofstream file3;

	file1.open("w8p2a.txt");
	if (file1.fail())
	{
		std::cout << "Input file 1 opening failed." << std::endl;
		exit(1);
	}

	file2.open("w8p2b.txt");
	if (file2.fail())
	{
		std::cout << "Input file 2 opening failed." << std::endl;
		exit(1);
	}

	file3.open("w8p2out.txt");
	if (file3.fail())
	{
		std::cout << "Output file opening failed." << std::endl;
		exit(1);
	}

	merge(file1, file2, file3);

	file1.close();
	file2.close();
	file3.close();

	return 0;
}


void merge(std::ifstream &f1, std::ifstream &f2, std::ofstream &f3)
{
	std::vector <int> vec;
 
	int a=0, n1=0, n2=0;

	while (f1 >> a)
	{
		n1++; //count how many numbers in file 1
		vec.push_back(a); //fill list
	}
	
	while (f2 >> a)
	{
		n2++; //count how many numbers in file 2
		vec.push_back(a); //fill list
	}

	std::cout << "Numbers from two files are : ";
	for (int o=0; o < n1+n2; o++)
	{
		std::cout << vec[o] << "\t" << std::endl;
	}

	std::cout << "There are " << n1 << " numbers in file 1 and " << n2 << " numbers in file 2" << std::endl;

	std::sort(vec.begin(), vec.end()); //sort numbers, c++ website	

	f3 << "The numbers from two files are:" << std::endl;	
	for (int o=0; o < n1+n2; o++)
	{
		f3 << vec[o] << std::endl;
	}
}

