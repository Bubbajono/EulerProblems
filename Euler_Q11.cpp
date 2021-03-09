#include "Euler_Q11.h"
#include "GeneralMethods.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

/*
Problem 11 - Largest product in a grid

In the 20×20 grid below, four numbers along a diagonal line have been marked in red.

08 02 22 97 38 15 00 40 00 75 04 05 07 78 52 12 50 77 91 08
49 49 99 40 17 81 18 57 60 87 17 40 98 43 69 48 04 56 62 00
81 49 31 73 55 79 14 29 93 71 40 67 53 88 30 03 49 13 36 65
52 70 95 23 04 60 11 42 69 24 68 56 01 32 56 71 37 02 36 91
22 31 16 71 51 67 63 89 41 92 36 54 22 40 40 28 66 33 13 80
24 47 32 60 99 03 45 02 44 75 33 53 78 36 84 20 35 17 12 50
32 98 81 28 64 23 67 10 26 38 40 67 59 54 70 66 18 38 64 70
67 26 20 68 02 62 12 20 95 63 94 39 63 08 40 91 66 49 94 21
24 55 58 05 66 73 99 26 97 17 78 78 96 83 14 88 34 89 63 72
21 36 23 09 75 00 76 44 20 45 35 14 00 61 33 97 34 31 33 95
78 17 53 28 22 75 31 67 15 94 03 80 04 62 16 14 09 53 56 92
16 39 05 42 96 35 31 47 55 58 88 24 00 17 54 24 36 29 85 57
86 56 00 48 35 71 89 07 05 44 44 37 44 60 21 58 51 54 17 58
19 80 81 68 05 94 47 69 28 73 92 13 86 52 17 77 04 89 55 40
04 52 08 83 97 35 99 16 07 97 57 32 16 26 26 79 33 27 98 66
88 36 68 87 57 62 20 72 03 46 33 67 46 55 12 32 63 93 53 69
04 42 16 73 38 25 39 11 24 94 72 18 08 46 29 32 40 62 76 36
20 69 36 41 72 30 23 88 34 62 99 69 82 67 59 85 74 04 36 16
20 73 35 29 78 31 90 01 74 31 49 71 48 86 81 16 23 57 05 54
01 70 54 71 83 51 54 69 16 92 33 48 61 43 52 01 89 19 67 48

The product of these numbers is 26 × 63 × 78 × 14 = 1788696.

What is the greatest product of four adjacent numbers in the same direction (up, down, left, right, or diagonally) in the 20×20 grid?
*/

Euler_Q11::Euler_Q11(int nSearch)
{
    cout<< "Euler Q11:" <<endl;

    std::vector<vector<int>> array = GeneralMethods::ReadCharFileToArray("Euler_Q11.dat", char(32)); //char(32) is a space

    //Get number of numbers in row
    int CountNumbersInRow = GeneralMethods::GetCountNumbersInRowOfFile("Euler_Q11.dat", char(32));
    
    //Convert to 2D vec
    std::vector<int> vec = GeneralMethods::Convert2DVecTo1DVec(array);

    int row_product;
    int col_product;
    int diagL_product;
    int diagR_product;
    int row_search = 1;
    int col_search = CountNumbersInRow;
    int diagL_search = CountNumbersInRow + 1;
    int diagR_search = CountNumbersInRow - 1;
    int TotalNumbers = vec.size();
    int result = 0;
    int row_count;
    int col_count;
    int diagL_count;
    int diagR_count;
    int row_num = -1;


    //Search
    for (int i = 0; i < vec.size(); i++)
    {
        if (i % CountNumbersInRow == 0)
            row_num++;


        int row_product = vec[i];
        int col_product = vec[i];
        int diagL_product = vec[i];
        int diagR_product = vec[i];

        //Row check
        row_count = 1;
        for (int j = i + row_search; j < TotalNumbers; j += row_search)
        {
            if (j % CountNumbersInRow == 0)
            {
                //reset and go to next row
                break;
            }
            row_product *= vec[j]; 
            row_count++;
            if (row_count == nSearch)
                break;
        }

        //Col check
        col_count = 1;
        for (int j = i + col_search; j < TotalNumbers; j += col_search)
        {
            col_product *= vec[j];
            col_count++;
            if (col_count == nSearch)
                break;
        }
        if (col_count != nSearch) 
            col_product = 0;

        //Diag check UL to LR
        if (i <= (row_num * CountNumbersInRow) + (CountNumbersInRow - nSearch - 1))
        {
            diagL_count = 1;
            for (int j = i + diagL_search; j < TotalNumbers; j += diagL_search)
            {
                diagL_product *= vec[j];
                diagL_count++;
                if (diagL_count == nSearch)
                    break;
            }
            if (diagL_count != nSearch) 
                diagL_product = 0;
        }

        //Diag check UR to LL
        if (i >= (nSearch - 1 + row_num * CountNumbersInRow))
        {
            diagR_count = 1;
            for (int j = i + diagR_search; j < TotalNumbers; j += diagR_search)
            {
                diagR_product *= vec[j];
                diagR_count++;
                if (diagR_count == nSearch)
                    break;
            }
            if (diagR_count != nSearch) 
                diagR_product = 0;
        }

        result = std::max(result,std::max(row_product, std::max(col_product,std::max(diagL_product, diagR_product))));
    }

    std::cout<< "The greatest product of " + std::to_string(nSearch) + " adjacent numbers in the same direction is: "+ std::to_string(result) <<std::endl<<std::endl;

}
