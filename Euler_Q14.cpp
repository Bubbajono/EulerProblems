#include "Euler_Q14.h"
#include "GeneralMethods.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

/*
Problem 14 - Longest Collatz sequence

The following iterative sequence is defined for the set of positive integers:

n → n/2 (n is even)
n → 3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:

13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

Which starting number, under one million, produces the longest chain?

NOTE: Once the chain starts the terms are allowed to go above one million.
*/

Euler_Q14::Euler_Q14(int target)
{
    cout<< "Euler Q14:" <<endl;
    long num = 0;
    int max = 0;
    int count;
    int result = 0;
    for (int i = 1; i < 1000000; i++)
    {
        num = i;
        count = 0;
        while (num != 1)
        {
            count++;
            scan(num);
        }

        if (count > max)
        {
            max = count;
            result = i;
        }

    }
    std::cout<< "The value of the starting number, under one million, which produces the longest chain is: " + std::to_string(result)<<std::endl<<std::endl;
}

void Euler_Q14::scan(long &num)
{ 
    if (GeneralMethods::IsEven(num))
    {
        num = num/2;
    }
    else
    {
        num = 3 * num + 1;
    }
}
