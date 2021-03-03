#include "Euler_Q9.h"
#include "GeneralMethods.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

/*
Problem 9 - Special Pythagorean triplet
A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,

(see online)

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.
*/

Euler_Q9::Euler_Q9(int target)
{
    cout<< "Euler Q9:" <<endl;

    long a, b, c, product;
    for (a = 1; a < target; a++)
    {
        for (b = 1; b < target; b++)
        {
            for (c = 1; c < target; c++)
            {
                if ((a + b + c == 1000) && (a * a + b * b == c * c))
                {
                    product = a * b * c;
                    break;
                } 
            }
        }
    }

    std::cout<< "The product of the pythagorean triplet for which a + b + c = 1000 is: " + std::to_string(product) <<std::endl<<std::endl;

}
