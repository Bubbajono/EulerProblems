#include "Euler_Q6.h"
#include "GeneralMethods.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

/*
Problem 6 - Sum square difference
The sum of the squares of the first ten natural numbers is,
(see online)
The square of the sum of the first ten natural numbers is,
(see online)
Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is .
Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
*/

Euler_Q6::Euler_Q6(int nMax)
{
    cout<< "Euler Q6:" <<endl;

    int sumSquare = 0;
    int SquareSum = 0;
    int Sum = 0;

    for (int i = 1; i <= nMax; i++)
    {
        sumSquare += i * i;
        Sum += i;
    }

    SquareSum = Sum * Sum;

    int diff = SquareSum - sumSquare;


    std::cout<<"The difference between the sum of the squares of the first " + std::to_string(nMax) + " natural numbers and the square of the sum is: " + std::to_string(diff) << std::endl << std::endl;

}
