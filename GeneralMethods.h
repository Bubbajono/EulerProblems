#ifndef GeneralMethods_H
#define GeneralMethods_H
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

namespace GeneralMethods
{
    bool IsPrime(int num);
    bool IsMultipleOf(int num, int multiple);
    bool IsEven(int num);
    bool IsPalindrome(int num);
    std::vector<int> FindFactors(long int num);
    std::vector<int> FindPrimeFactors(long int num);
    std::vector<int> GenerateFibonnaci(int nMax);
    std::vector<int> GenerateFibonnaci(int nMax, int Threshold);
    void Print2DVec(std::vector<int> vec);
}

#endif