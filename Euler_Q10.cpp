#include "Euler_Q10.h"
#include "GeneralMethods.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

/*
Problem 10 - Summation of primes

The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
Find the sum of all the primes below two million.
*/

Euler_Q10::Euler_Q10(long nMax)
{
    cout<< "Euler Q10:" <<endl;

    long sum = 0;
    for (int i = 2; i < nMax; i++)
    {
        if (GeneralMethods::IsPrime(i))
        {
            sum += i;
        }
    }


    std::cout<< "The sum of all the primes below " + std::to_string(nMax) + " is: "+ std::to_string(sum) <<std::endl<<std::endl;

}
