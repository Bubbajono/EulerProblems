#include "Euler_Q2.h"
#include "GeneralMethods.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

/*
Problem 2: Even Fibonacci numbers
Each new term in the Fibonacci sequence is generated by adding the previous two terms. By starting with 1 and 2, the first 10 terms will be:
1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.
*/

Euler_Q2::Euler_Q2(int Threshold)
{
    cout<< "Euler Q2:" <<endl;

    vector<int> vec = GeneralMethods::GenerateFibonnaci(Threshold,Threshold);

    int count = 0;

    for (int i : vec)
    {
        if (GeneralMethods::IsEven(i))
        {
            count = count + i;
        }

    }

    cout<< "Of the values of the Fibonacci Sequence that do not exceed " + to_string(Threshold) + ", the sum of the even values is: " + to_string(count) <<endl<<endl;

}
