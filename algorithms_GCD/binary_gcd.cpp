#include <iostream>
#include <NTL/ZZ.h>
#include "math.cpp"

using namespace std;
using namespace NTL;

ZZ binary_gcd(ZZ a, ZZ b){

    ZZ g(1);

    while (modulo(a, to_ZZ(2)) == 0 && modulo(b, to_ZZ(2)) == 0)
    {
        a /=2; 
        b /=2;
        g *=2;
    }   
    while(a!=0)
    {
        while(modulo(a,to_ZZ(2))==0)
            a/=2;
        while(modulo(b,to_ZZ(2))==0)
            b/=2;
        ZZ t = abs(a - b)/2;
        if(a >= b)
            a = t;
        else
            b = t;     
    }

    return g*b;
}