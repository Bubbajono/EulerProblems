#include "Euler_Q15.h"
#include "GeneralMethods.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

/*
Problem 15 - Lattice Paths

Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.

How many such routes are there through a 20×20 grid?
*/

Euler_Q15::Euler_Q15(int length)
{
    //For 2 by 2 grid, 9 point, 

    unsigned long long result;
    unsigned long long array[length + 1][length + 1];

    //Initial conditions (left and upper borders have one possible)
    for (int i = 0; i < length + 1; i++)
    {
        array[0][i] = 1;
        array[i][0] = 1;
    }

    /*
    Value of possible routes for particular grid point is equal to grid point value above + grid point value to the left
    */

    for (int i = 1; i < length + 1; i++)
    {
        for (int j = 1; j < length + 1; j++)
        {
            array[i][j] = array[i - 1][j] + array[i][j - 1];
        }
    }

    result = array[length][length];

    std::cout<< "The number of routes for a " +std::to_string(length)+ "x" + std::to_string(length) + " grid is: " + std::to_string(result)<<std::endl<<std::endl;

}
