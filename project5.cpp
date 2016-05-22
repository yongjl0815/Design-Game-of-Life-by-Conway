/*******************************************************************
* * Author: Yong Lee
* * Overview: Design Game of Life by Conway.
* *
* *
* * Input: The user will be able to decide which cell will be alive.
* *
* *
* * Output: Generations of live and dead cells.
* *
* *  
* *****************************************************************/

#include <iostream>
#include <vector>
#include <cstdlib>

class Conway
{
public:
	Conway()
	{
		row = 22;
		column = 80;
	}

	std::vector< std::vector<char> > world; // first copy of 2d vector
	std::vector<char> wor;

	std::vector< std::vector<char> > copy; // second copy of 3d vector
	std::vector<char> cop;

	void grid(); // set grid 80x22 
	void reset(); // reset grid;
	void start(); // set life cells

	void generation(); // set next generation

	void middle(); // deal with middle cells

	void edgeUpper(); // deal with upper edge cells
	void edgeLower(); // deal with lower edge cells
	void edgeLeft(); // deal with left edge cells
	void edgeRight(); // deal with right edge cells

	void cornerUL(); // deal with upper left corner cells
	void cornerUR(); // deal with upper right corner cells
	void cornerLL(); // deal with lower left corner cells
	void cornerLR(); // deal with lower right corner cells

	void duplicate(); // make 2 vectors same after function generation
	void display(); // display world

private:
	int row;
	int column;
};


int main()
{
	Conway world;

	world.grid();

	char yn;

	do
	{
		std::cout << "Welcome to Conway's Game of Life." << std::endl
		<< "Press Enter key to got to next generation." << std::endl
		<< "Press any other key to stop." << std::endl;

		world.reset();
		world.start();
		world.display();

		std::cout << "Here we go. Above is the original generation and below is the next generation. Have fun!!!" << std::endl;

		do
		{
			world.generation();
			world.duplicate();
			world.display();
		}
		while (std::cin.get() == '\n');
	
		std::cout << "Try again?(y/n)" << std::endl;
		std::cin >> yn;
		std::cin.ignore(256, '\n');
	}
	while(yn == 'y');

	return 0;
}


void Conway::grid()
{
	for (int i = 0; i < row; i++)
    	{
    		for (int j = 0; j < column; j++)
		{
			wor.push_back('.');
			cop.push_back('.');
    		}
		world.push_back(wor);
		copy.push_back(cop);
	}
}

void Conway::reset()
{
	for (int i = 0; i < row; i++)
    	{
    		for (int j = 0; j < column; j++)
		{
			world[i][j] = '.';
			copy[i][j] = '.';
    		}
	}
}

void Conway::start()
{
	int option;

	do
	{
		std::cout << "Please choose your option. (Enter from 1 thru 5)" << std::endl
		<< "1 - Blinker" << std::endl
		<< "2 - Pulsar-die hard" << std::endl
		<< "3 - Glider" << std::endl
		<< "4 - Spaceship" << std::endl
		<< "5 - 1 thru 4 together" << std::endl
		<< "6 - Random" << std::endl;
		std::cin >> option;
		std::cin.ignore(256, '\n');

		if (option == 1)
		{	
			world[12][40] = '@';
			world[12][41] = '@';
			world[12][42] = '@';

			copy[12][40] = '@';
			copy[12][41] = '@';
			copy[12][42] = '@';
		}
		if (option == 2)
		{
			world[10][10] = '@';
			world[10][11] = '@';
			world[11][11] = '@';
			world[9][16] = '@';
			world[11][15] = '@';
			world[11][16] = '@';
			world[11][17] = '@';

			copy[10][10] = '@';
			copy[10][11] = '@';
			copy[11][11] = '@';
			copy[9][16] = '@';
			copy[11][15] = '@';
			copy[11][16] = '@';
			copy[11][17] = '@';
		}

		if (option == 3)
		{
			world[15][70] = '@';
			world[16][71] = '@';
			world[17][69] = '@';
			world[17][70] = '@';
			world[17][71] = '@';

			copy[15][70] = '@';
			copy[16][71] = '@';
			copy[17][69] = '@';
			copy[17][70] = '@';
			copy[17][71] = '@';
		}

		if (option == 4)
		{
			world[5][31] = '@';
			world[5][32] = '@';
			world[5][33] = '@';
			world[6][30] = '@';
			world[6][33] = '@';
			world[7][33] = '@';
			world[8][33] = '@';
			world[9][30] = '@';
			world[9][32] = '@';

			copy[5][31] = '@';
			copy[5][32] = '@';
			copy[5][33] = '@';
			copy[6][30] = '@';
			copy[6][33] = '@';
			copy[7][33] = '@';
			copy[8][33] = '@';
			copy[9][30] = '@';
			copy[9][32] = '@';
		}

		if (option == 5)
		{
			world[12][40] = '@';
			world[12][41] = '@';
			world[12][42] = '@';

			copy[12][40] = '@';
			copy[12][41] = '@';
			copy[12][42] = '@';
		
			world[10][10] = '@';
			world[10][11] = '@';
			world[11][11] = '@';
			world[9][16] = '@';
			world[11][15] = '@';
			world[11][16] = '@';
			world[11][17] = '@';

			copy[10][10] = '@';
			copy[10][11] = '@';
			copy[11][11] = '@';
			copy[9][16] = '@';
			copy[11][15] = '@';
			copy[11][16] = '@';
			copy[11][17] = '@';

			world[15][70] = '@';
			world[16][71] = '@';
			world[17][69] = '@';
			world[17][70] = '@';
			world[17][71] = '@';

			copy[15][70] = '@';
			copy[16][71] = '@';
			copy[17][69] = '@';
			copy[17][70] = '@';
			copy[17][71] = '@';
		
			world[5][31] = '@';
			world[5][32] = '@';
			world[5][33] = '@';
			world[6][30] = '@';
			world[6][33] = '@';
			world[7][33] = '@';
			world[8][33] = '@';
			world[9][30] = '@';
			world[9][32] = '@';

			copy[5][31] = '@';
			copy[5][32] = '@';
			copy[5][33] = '@';
			copy[6][30] = '@';
			copy[6][33] = '@';
			copy[7][33] = '@';
			copy[8][33] = '@';
			copy[9][30] = '@';
			copy[9][32] = '@';
		}

		if (option == 6)
		{
			srand(time(NULL));
			for (int i = 0; i < row; i++)
    			{
    				for (int j = 0; j < column; j++)
				{
					int rand_num = rand() % 5;
					
					if (rand_num == 1)
					{
						world[i][j] = '@';
						copy[i][j] = '@';
    					}
				}
			}
		}
	}	
	while(option < 1 || option > 6);
}

void Conway::generation()
{
	middle();

	edgeUpper();
	edgeLower();
	edgeLeft();
	edgeRight();
	
	cornerUL(); 
	cornerUR(); 
	cornerLL(); 
	cornerLR(); 
}

void Conway::middle()
{
	for (int i = 1; i < (row-1); i++)
    	{
	    	for (int j = 1; j < (column-1); j++)
		{
			int x=0;

        		if (world[i-1][j-1] == '@')
			{
				x++;
			}
        		if (world[i-1][j] == '@')
			{
				x++;
			}
        		if (world[i-1][j+1] == '@')
			{
				x++;
			}
        		if (world[i][j-1] == '@')
			{
				x++;
			}
        		if (world[i][j+1] == '@')
			{
				x++;
			}
        		if (world[i+1][j-1] == '@')
			{
				x++;
			}
        		if (world[i+1][j] == '@')
			{
				x++;
			}
        		if (world[i+1][j+1] == '@')
			{
				x++;
			}

			if (x <= 1)
			{
				copy[i][j] = '.';
			}
			
			else if (x > 3)
			{
				copy[i][j] = '.';
			}
	
			else if (x == 3)
			{
				copy[i][j] = '@';
			}
    		}
	}
}

void Conway::edgeUpper()
{

	for (int j = 1; j < column-1; j++)
	{
		int x=0;

       		if (world[21][j-1] == '@')
		{
			x++;
		}
        	if (world[21][j] == '@')
		{
			x++;
		}
        	if (world[21][j+1] == '@')
		{
			x++;
		}
        	if (world[0][j-1] == '@')
		{
			x++;
		}
        	if (world[0][j+1] == '@')
		{
			x++;
		}
        	if (world[1][j-1] == '@')
		{
			x++;
		}
        	if (world[1][j] == '@')
		{
			x++;
		}
        	if (world[1][j+1] == '@')
		{
			x++;
		}

		if (x <= 1)
		{
			copy[0][j] = '.';
		}
			
		else if (x > 3)
		{
			copy[0][j] = '.';
		}
	
		else if (x == 3)
		{
			copy[0][j] = '@';
		}
    	}
}

void Conway::edgeLower()
{

	for (int j = 1; j < column-1; j++)
	{
		int x=0;

       		if (world[20][j-1] == '@')
		{
			x++;
		}
        	if (world[20][j] == '@')
		{
			x++;
		}
        	if (world[20][j+1] == '@')
		{
			x++;
		}
        	if (world[21][j-1] == '@')
		{
			x++;
		}
        	if (world[21][j+1] == '@')
		{
			x++;
		}
        	if (world[0][j-1] == '@')
		{
			x++;
		}
        	if (world[0][j] == '@')
		{
			x++;
		}
        	if (world[0][j+1] == '@')
		{
			x++;
		}

		if (x <= 1)
		{
			copy[21][j] = '.';
		}
			
		else if (x > 3)
		{
			copy[21][j] = '.';
		}
	
		else if (x == 3)
		{
			copy[21][j] = '@';
		}
    	}
}

void Conway::edgeLeft()
{

	for (int i = 1; i < row-1; i++)
	{
		int x=0;

       		if (world[i-1][79] == '@')
		{
			x++;
		}
        	if (world[i][79] == '@')
		{
			x++;
		}
        	if (world[i+1][79] == '@')
		{
			x++;
		}
        	if (world[i-1][0] == '@')
		{
			x++;
		}
        	if (world[i+1][0] == '@')
		{
			x++;
		}
        	if (world[i-1][1] == '@')
		{
			x++;
		}
        	if (world[i][1] == '@')
		{
			x++;
		}
        	if (world[i+1][1] == '@')
		{
			x++;
		}

		if (x <= 1)
		{
			copy[i][0] = '.';
		}
			
		else if (x > 3)
		{
			copy[i][0] = '.';
		}
	
		else if (x == 3)
		{
			copy[i][0] = '@';
		}
    	}
}

void Conway::edgeRight()
{

	for (int i = 1; i < row-1; i++)
	{
		int x=0;

       		if (world[i-1][78] == '@')
		{
			x++;
		}
        	if (world[i][78] == '@')
		{
			x++;
		}
        	if (world[i+1][78] == '@')
		{
			x++;
		}
        	if (world[i-1][79] == '@')
		{
			x++;
		}
        	if (world[i+1][79] == '@')
		{
			x++;
		}
        	if (world[i-1][0] == '@')
		{
			x++;
		}
        	if (world[i][0] == '@')
		{
			x++;
		}
        	if (world[i+1][0] == '@')
		{
			x++;
		}

		if (x <= 1)
		{
			copy[i][79] = '.';
		}
			
		else if (x > 3)
		{
			copy[i][79] = '.';
		}
	
		else if (x == 3)
		{
			copy[i][79] = '@';
		}
    	}
}

void Conway::cornerUL()
{
	int x=0;

       	if (world[21][79] == '@')
	{
		x++;
	}
       	if (world[21][0] == '@')
	{
		x++;
	}
       	if (world[21][1] == '@')
	{
		x++;
	}
       	if (world[0][79] == '@')
	{
		x++;
	}
       	if (world[0][1] == '@')
	{
		x++;
	}
       	if (world[1][79] == '@')
	{
		x++;
	}
       	if (world[1][0] == '@')
	{
		x++;
	}
       	if (world[1][1] == '@')
	{
		x++;
	}

	if (x <= 1)
	{
		copy[0][0] = '.';
	}
			
	else if (x > 3)
	{
		copy[0][0] = '.';
	}
	
	else if (x == 3)
	{
		copy[0][0] = '@';
	}
}

void Conway::cornerUR()
{
	int x=0;

       	if (world[21][78] == '@')
	{
		x++;
	}
       	if (world[21][79] == '@')
	{
		x++;
	}
       	if (world[21][0] == '@')
	{
		x++;
	}
       	if (world[0][78] == '@')
	{
		x++;
	}
       	if (world[0][0] == '@')
	{
		x++;
	}
       	if (world[1][78] == '@')
	{
		x++;
	}
       	if (world[1][79] == '@')
	{
		x++;
	}
       	if (world[1][0] == '@')
	{
		x++;
	}

	if (x <= 1)
	{
		copy[0][79] = '.';
	}
			
	else if (x > 3)
	{
		copy[0][79] = '.';
	}
	
	else if (x == 3)
	{
		copy[0][79] = '@';
	}
}

void Conway::cornerLL()
{
	int x=0;

       	if (world[20][79] == '@')
	{
		x++;
	}
       	if (world[20][0] == '@')
	{
		x++;
	}
       	if (world[20][1] == '@')
	{
		x++;
	}
       	if (world[21][79] == '@')
	{
		x++;
	}
       	if (world[21][1] == '@')
	{
		x++;
	}
       	if (world[0][79] == '@')
	{
		x++;
	}
       	if (world[0][0] == '@')
	{
		x++;
	}
       	if (world[0][1] == '@')
	{
		x++;
	}

	if (x <= 1)
	{
		copy[21][0] = '.';
	}
			
	else if (x > 3)
	{
		copy[21][0] = '.';
	}
	
	else if (x == 3)
	{
		copy[21][0] = '@';
	}
}

void Conway::cornerLR()
{
	int x=0;

       	if (world[20][78] == '@')
	{
		x++;
	}
       	if (world[20][79] == '@')
	{
		x++;
	}
       	if (world[20][0] == '@')
	{
		x++;
	}
       	if (world[21][78] == '@')
	{
		x++;
	}
       	if (world[21][0] == '@')
	{
		x++;
	}
       	if (world[0][78] == '@')
	{
		x++;
	}
       	if (world[0][79] == '@')
	{
		x++;
	}
       	if (world[0][0] == '@')
	{
		x++;
	}

	if (x <= 1)
	{
		copy[21][79] = '.';
	}
			
	else if (x > 3)
	{
		copy[21][79] = '.';
	}
	
	else if (x == 3)
	{
		copy[21][79] = '@';
	}
}

void Conway::duplicate()
{

	for (int i = 0; i < row; i++)
    	{
    		for (int j = 0; j < column; j++)
		{
        		world[i][j] = copy[i][j];
    		}
	}
}
void Conway::display()
{
	for (int i = 0; i < row; i++)
    	{
    		for (int j = 0; j < column; j++)
		{
        		std::cout << world[i][j] << " ";
    		}
		std::cout << std::endl;
	}
}
