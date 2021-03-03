#include "Euler_Q1.h"
#include "GeneralMethods.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

/*
Problem 1: Multiples of 3 and 5
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
Find the sum of all the multiples of 3 or 5 below 1000.
*/

Euler_Q1::Euler_Q1(int nMax)
{
    cout<< "Euler Q1:" <<endl;

    int count = 0;
    for (int i = 1; i < nMax; i++)
    {
        if (GeneralMethods::IsMultipleOf(i, 3) || GeneralMethods::IsMultipleOf(i, 5))
        {
            count = count + i;
        }
    }

    cout<< "The sum of all multiples of 3 or 5 below " + to_string(nMax) + " = " + to_string(count) <<endl<<endl;
}
