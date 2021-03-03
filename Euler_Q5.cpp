#include "Euler_Q5.h"
#include "GeneralMethods.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

/*
Problem 5 - Smallest Multiple
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
*/

Euler_Q5::Euler_Q5(int nMax)
{
    cout<< "Euler Q5:" <<endl;

    bool condition = false;
    int num = 0;
    int result = 0;
    while (condition == false)
    {
        num++;
        for (int i = 1; i <= nMax; i++)
        {
            condition = GeneralMethods::IsMultipleOf(num, i);

            if (!condition)
            {
                break;
            }
        }
        result = num;
    }

    std::cout<<"The smallest positive number that is evenly divisible by all of the numbers from 1 to " + std::to_string(nMax) + " is: " + std::to_string(result) << std::endl << std::endl;

}
