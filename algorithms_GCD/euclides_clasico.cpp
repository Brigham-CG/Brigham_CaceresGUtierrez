#include <iostream>
#include <NTL/ZZ.h>
#include "math.cpp"

using namespace std;
using namespace NTL;

ZZ euclides_clasico(ZZ a, ZZ b)
{
    // r -> rest
    while(b != 0){
        ZZ r = modulo(a, b);
        a = b;
        b = r;
    }
    return a;
}