#include "Euler_Q4.h"
#include "GeneralMethods.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

/*
Problem 4: Largest palindrome product
A palindromic number reads the same both ways. 
The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
Find the largest palindrome made from the product of two 3-digit numbers. ?
*/

Euler_Q4::Euler_Q4(int nDigits)
{
    if (nDigits < 2)
    {
        std::cout<< "Invalid nDigits";
    }

    cout<< "Euler Q4:" <<endl;

    std::string strStart = "1";
    std::string strEnd = "9";

    for (int i = 1; i < nDigits; i++)
    {
        strStart.append("0");
        strEnd.append("9");
    }

    int num;
    int result = 0;
    for (int i = stoi(strStart); i <= stoi(strEnd); i++)
    {
        for (int j = stoi(strStart); j <= stoi(strEnd); j++)
        {
            num = i * j;
            if (GeneralMethods::IsPalindrome(num) && num > result)
            {
                result = num;
            }
        }
    }

    if (result == 0)
    {
        std::cout<<"No palindrom found";
    }

    cout<< "The largest palindrome made from the product of two " + std::to_string(nDigits) + "-digit numbers is: " + std::to_string(result) <<endl<<endl;

}
