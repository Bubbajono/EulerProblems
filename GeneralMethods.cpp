#include "GeneralMethods.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <math.h>

namespace GeneralMethods
{
    bool IsPrime(int num)
    {
        if (num == 2)
        {
            return true;
        }

        for (int i = 2; i < num; i++)
        {
            if (num % i == 0)
            {
                return false;
            }
        }

        return true;
    }

    bool IsMultipleOf(int num, int multiple)
    {
        return (num % multiple == 0);
    }

    bool IsEven(int num)
    {
        return IsMultipleOf(num, 2);
    }

    bool IsPalindrome(int num)
    {
        std::string str = std::to_string(num);
        int length = str.length();
        int mid = ceil(length/2);
        
        char left, right;
        for (int i = 0; i < mid; i++)
        {
            left = str[i];
            right = str[length - i - 1];
            if (left != right)
            {
                return false;
            }
        }

        return true;
    }

    std::vector<int> FindFactors(long int num)
    {
        std::vector<int> vec;
        
        for (int i = 1; i < sqrt(num); i++)
        {
            if (num % i == 0)
            {
                vec.push_back(i);
            }
        }

        return vec;
    }

    std::vector<int> FindPrimeFactors(long int num)
    {
        std::vector<int> vec;
        
        for (int i = 1; i < sqrt(num); i++)
        {
            if (num % i == 0)
            {
                if (IsPrime(i))
                {
                    vec.push_back(i);
                }
            }
        }

        return vec;
    }

    std::vector<int> GenerateFibonnaci(int nMax)
    {
        int count;
        std::vector<int> fib;
        fib.push_back(1);
        fib.push_back(2);
        for (int i = 2; i < nMax; i++)
        {
            count = 0;
            for (int j = i - 2; j < i; j++)
            {
                count = count + fib[j];
            }
            fib.push_back(count);
        }
        return fib;
    }

    std::vector<int> GenerateFibonnaci(int nMax, int Threshold)
    {
        int count;
        std::vector<int> fib;
        fib.push_back(1);
        fib.push_back(2);
        for (int i = 2; i < nMax; i++)
        {
            count = 0;
            for (int j = i - 2; j < i; j++)
            {
                count = count + fib[j];
                if (count > Threshold)
                {
                    return fib;
                }
            }
            fib.push_back(count);
        }
        return fib;
    }

    void Print2DVec(std::vector<int> vec)
    {
        for (int x : vec)
            std::cout << x << " ";

    }

    std::vector<std::vector<int>> ReadCharFileToArray(std::string fileName)
    {
        std::string line;
        std::ifstream file(fileName);
        std::vector<std::vector<int>> array;
        if(file.is_open())
        {
            while ( std::getline (file,line) )
            {
                std::vector<int> row;
                for (char i: line)
                {
                    if (std::isdigit(i))
                    {
                        row.push_back(i - 48); //ASCII Conversion
                    }
                }
                array.push_back(row);
            }
            file.close();
        }

        return array;

    }

    std::vector<int> Convert2DVecTo1DVec(std::vector<std::vector<int>> vec)
    {
        std::vector<int> out;

        for (std::vector<int> row : vec)
        {
            for (int val : row)
            {
                out.push_back(val);
            }
        }

        return out;
    }
}