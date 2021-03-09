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

        /*
            NEED TO INVESTIGATE Sieve of Eratosthenes
            algorithm Sieve of Eratosthenes is
                input: an integer n > 1.
                output: all prime numbers from 2 through n.

                let A be an array of Boolean values, indexed by integers 2 to n,
                initially all set to true.
                
                for i = 2, 3, 4, ..., not exceeding √n do
                    if A[i] is true
                        for j = i2, i2+i, i2+2i, i2+3i, ..., not exceeding n do
                            A[j] := false

                return all i such that A[i] is true.
        */
        if (num == 2)
        {
            return true;
        }

        for (int i = 2; i < sqrt(num); i++)
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

        if (num == 1)
        {
            vec.push_back(1);
            return vec;
        }

        for (int i = 1; i < num; i++)
        {
            if (num % i == 0)
            {
                vec.push_back(i);
            }
        }

        return vec;
    }

    long CountDivisors(int num)
    {
		long count = 0;
		for (int i = 1; i <= sqrt(num); i++) 
        {
			if (num % i == 0)
				count += 2;
		}
		return count;
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

    std::vector<std::vector<int>> ReadCharFileToArray(std::string fileName, char delimiter)
    {
        std::string line;
        std::ifstream file(fileName);
        std::vector<std::vector<int>> array;
        std::string grouping;
        if(file.is_open())
        {
            while ( std::getline (file,line) )
            {
                std::vector<int> row;
                for (char i: line)
                {
                    if (i == delimiter)
                    {
                        row.push_back(stoi(grouping));
                        grouping = "";
                    }
                    if (i == '\r') //new line
                    {
                        row.push_back(stoi(grouping));
                        grouping = "";
                    }
                    grouping += i;
                }  
                //Get last number of entire file
                if (file.eof())
                {
                    row.push_back(stoi(grouping));
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

    std::vector<std::vector<int> > TransposeVecVec(const std::vector<std::vector<int> > data) 
    {
        //Assumes a square array
        std::vector<std::vector<int> > result(data[0].size(), std::vector<int>(data.size()));
        
        for (std::vector<int>::size_type i = 0; i < data[0].size(); i++)
        {
            for (std::vector<int>::size_type j = 0; j < data.size(); j++) 
            {
                result[i][j] = data[j][i];
            }
        }

        return result;
    }

    int GetCountNumbersInRowOfFile(std::string fileName, char delimiter)
    {
        std::string line;
        std::ifstream file(fileName);
        int CountNumbersInRow = 0;
        if (file.is_open())
        {
            std::getline (file,line);
            for (char i: line)
            {
                if (i == delimiter)
                {
                    CountNumbersInRow++;
                }
            }
            //Last number
            CountNumbersInRow++;
            file.close();
        }
        return CountNumbersInRow;
    }

    std::vector<int> GetTriangleNumbers (int nAmount)
    {
        std::vector<int> numbers;
        for (int i = 1; i <= nAmount; i++)
        {
            numbers.push_back(i);
        }

        std::vector<int> vec;
        int count = 1;
        
        while (count <= nAmount)
        {
            long sum = 0;
            for (int i = 0; i < count; i++)
            {
                sum += numbers[i];
            }
            vec.push_back(sum);
            count++;
        }

        return vec;
    }
}