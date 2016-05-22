/******************************************************************
* * Author: Yong Lee
* * Date Created: 2-27-14
* * Lab Number: CS165
* * Filename: w8p1.cpp
* *
* * Overview: First part, find the median of a set of numbers
* *	in a file. Second part, fin three quartiles.
* *
* * Input: A text file containing a set of numbers.(unknown number)
* *
* * Output: The median and three quartiles
* *
* *  
* *****************************************************************/

#include <fstream>
#include <iostream>
#include <cstdlib>

// find the location of the median
int count(double &howMany, double &a, int &b, int &c);

// find the median
int findMed(double &a, int &b, int &c);

// find the quartile
int quartile(int &m, int &m1, int &m2, int &m3);


int main()
{
	std::cout << "Let's figure out median and quartile." <<std::endl;

	double countEm, med1;
	int med2, med;

	count (countEm, med1, med2, med);

	std::cout << "There are " << countEm << " numbers in the file" << std::endl;

	std::cout << "Median is "<< findMed(med1, med2, med) << std::endl;

	int q1, q2, q3;

	quartile(med, q1, q2, q3);

	std::cout << "Quartiles are " << q1 << " " << q2 << " " << q3 << std::endl;

	return 0;
}	

int count(double &howMany, double &a, int &b, int &c)
{
	std::ifstream numIn;

	numIn.open("w8p1.txt");
	if (numIn.fail())
	{
		std::cout << "Input file opening failed." << std::endl;
		exit(1);
	}

	howMany=0;
	int i;

	while (numIn >> i)
	{
		howMany++; //count how many numbers in the file
	}
	

	numIn.close();

	a = howMany/2;
	b = howMany/2;
	c = 0;

	if (a > b)
	{
		c = b + 1;
		std::cout << "There are odd number of numbers in the file." << std::endl;
	}
	else
	{
		c = b;
		std::cout << "There are even number of numbers in the file." << std::endl;
	}

	numIn.close();
}	


int findMed(double &a, int &b, int &c)
{
	std::ifstream find;

	find.open("w8p1.txt");
	if (find.fail())
	{
		std::cout << "Input file opening failed." << std::endl;
		exit(1);
	}

	double med;
	int m1, m2;

	if (a > b) //odd number of numbers in the file
	{
		for(int o=0; o < c; o++)
		{
			find >> med;
		}
	}
	if (a == b) //even number of numbers in the file
	{
		for(int f=0; f < c; f++)
		{
			find >> m1;
		}
		find >> m2;
		med = (m1 + m2)/2;
	
		std::cout << "In the middle, there are two numbers: " << m1 << " and "<< m2 << std::endl;
	}
	
	find.close();	

	return med;	
}


int quartile(int &m, int &m1, int &m2, int &m3)
{
	std::ifstream quar;

	quar.open("w8p1.txt");
	if (quar.fail())
	{
		std::cout << "Input file opening failed." << std::endl;
		exit(1);
	}

	int c = m/2;

	for(int f=0; f < c; f++)
	{
		quar >> m1;
	}
	for(int f=0; f < c; f++)
	{
		quar >> m2;
	}
	for(int g=0; g < c; g++)
	{
		quar >> m3;
	}
	
	quar.close();	

}
