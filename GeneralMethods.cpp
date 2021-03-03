#include "GeneralMethods.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

namespace GeneralMethods
{
    bool IsMultipleOf(int num, int multiple)
    {
        return (num % multiple == 0);
    }

}