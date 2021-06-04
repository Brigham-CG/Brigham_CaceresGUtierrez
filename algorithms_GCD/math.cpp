#include <iostream>
#include <NTL/ZZ.h>

using namespace std;
using namespace NTL;

ZZ modulo(ZZ a, ZZ n)
{   
    ZZ base = a - (a/n) * n;

    if (base == 0)
        return to_ZZ(0);
    else if(base > 0)
    {
        if (n>=0)
            return base;
        else 
            return base + n;
    }
    else
    {
        if (n>=0)
            return base + n;
        else 
            return base;
    }
}