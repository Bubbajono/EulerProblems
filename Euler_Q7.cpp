#include "Euler_Q7.h"
#include "GeneralMethods.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

/*
Problem 7 - 10001st prime
By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
What is the 10 001st prime number?
*/

Euler_Q7::Euler_Q7(long target)
{
    cout<< "Euler Q7:" <<endl;

    long counter = 1;
    long search = 2; //1st prime

    while (counter < target)
    {
        if (GeneralMethods::IsPrime(search))
        {
            counter++;
        }
        search++; 
    }

    std::cout<<"The 10001st prime number is: " + to_string(search) <<std::endl<<std::endl;

}
