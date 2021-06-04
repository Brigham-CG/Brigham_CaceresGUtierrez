#include <iostream>
#include <NTL/ZZ.h>

using namespace std;
using namespace NTL;

ZZ euclides_menor_resto(ZZ a, ZZ b){

    ZZ c, d, r;
    if (a == 0)
        c = b;
    else
    {
        c = a;
        d = b;
        while(d != 0)
        {
            r = c - d * (c/d + 1/2);
            c = d;
            d = r;
        }
    }
    return abs(c);
}
