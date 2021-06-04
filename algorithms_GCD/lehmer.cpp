#include <iostream>
#include <NTL/ZZ.h>
#include "math.cpp"
#include "euclides_clasico.cpp"

using namespace std;
using namespace NTL;

unsigned length(ZZ n){

    int d=1;
    if(n<=9){
        return d;
    }
    else{
        return d+length(n/10);
    }
}

ZZ radix(ZZ B, ZZ c){

    long i=0;
    ZZ a[length(c)];
    ZZ za=c;
    ZZ zq=za/B;
    a[i]=za-zq*B;
    while(zq>0l){
        i++;
        za=zq;
        zq=za/B;
        a[i]=za-zq*B;
    }
    c=a[i];
    return c;
}

ZZ lehmer_gcd(ZZ a, ZZ b, ZZ base)
{   
    ZZ xh, yh, q, qh, A, B, C, D;

    while(b >= base)
    {
        xh = radix(base,a);
        yh = radix(base,b);
        A = 1; 
        B = 0;
        C = 0; 
        D = 1;
        while(yh + C != 0 && yh + D != 0)
        {   
            q = (xh + A)/(yh + C);
            qh = (xh + B)/(yh +D);
            if (q!=qh)
                break;
            else
            {   // swap
                ZZ t = A - q*C; A = C; C =t;
                t = B -q*D; B = D; D = t;
                t = xh - q*yh; xh = yh; yh = t;
            }
        }
        
        if (B == 0)
        {   // swap
            ZZ t = modulo(a, b);
            a = b;
            b = t;
        }
        else
        {   // swap
            ZZ t = A*a + B*b;
            ZZ u = C*a + D*b;
            a = t;
            b = u;
        }
    }

    return euclides_clasico(a, b);
}