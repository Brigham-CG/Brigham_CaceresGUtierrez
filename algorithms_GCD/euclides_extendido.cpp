#include <iostream>
#include <NTL/ZZ.h>
#include "math.cpp"
#include <vector>

using namespace std;
using namespace NTL;

vector<ZZ> euclides_extendido(ZZ a, ZZ b)
{   
    // a >= b
    // numbers[0] -> x
    // numbers[1] -> y
    // numbers[2] -> d

    vector<ZZ> numbers(3);
    if (b == 0)
    {
        numbers[0]= 1;
        numbers[1] = 0;
        numbers[2] = a;
    }

    ZZ x2(1), x1(0), y2(0), y1(1);
    while(b > 0)
    {
        ZZ q = a / b;
        ZZ r = a - q*b;
        numbers[0] = x2 - q*x1;
        numbers[1] = y2 - q*y1;
        a = b;
        b = r;
        x2 = x1;
        x1 = numbers[0];
        y2 = y1;
        y1 = numbers[1];
    }

    numbers[2] = a;
    numbers[0] = x2;
    numbers[1] = y2;
    return numbers;
}