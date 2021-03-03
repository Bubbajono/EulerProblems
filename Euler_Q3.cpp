#include "Euler_Q3.h"
#include "GeneralMethods.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

/*
Problem 3: Largest prime factor
The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?
*/

Euler_Q3::Euler_Q3(long int num)
{
    cout<< "Euler Q3:" <<endl;

    vector<int> vec = GeneralMethods::FindPrimeFactors(num);

    if (vec.size() == 0)
    {
        cout<< "No prime factors found"<<endl;
        return;
    }

    int result = vec[vec.size()-1];

    cout<< "The largest prime factor of the number " + to_string(num) + "is: " + to_string(result) <<endl<<endl;

}
