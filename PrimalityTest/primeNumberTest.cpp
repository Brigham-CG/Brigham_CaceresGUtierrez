#include <iostream>
#include <assert.h>
#include <NTL/ZZ.h>
#include <NTL/RR.h>
#include <bits/stdc++.h>
#include <sys/time.h>

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

ZZ exponenciacion_mod(ZZ b, ZZ e, ZZ n)
{

    ZZ result(1);

    while(e>0)
    {
        if(e % 2)
            result = (result*b) % n;

        b =  (b * b) % n;
        e /= 2; 
    }   
    return result;    
}

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

// ---------------------------//

bool ensayar_divisiones(ZZ n)
{   
    for (ZZ r(2); r <= SqrRoot(n); r++){
        if(divide(n, r))
            return false;
    }
    return true;
}

// ---------------------------//

ZZ jacobi(ZZ n, ZZ k) {

    ZZ t(1);

    while (n != 0) {
        while ((n & 1) == 0) {
            n /= 2;
            ZZ r = modulo(k, to_ZZ(8));

            if (r == 3 || r == 5)
                t = -t;
        }
        std::swap(n, k);
        if (modulo(n, to_ZZ(4)) == 3 && modulo(k, to_ZZ(4)) == 3)
            t = -t;
        n = modulo(n, k);
    }
    
    return k == 1 ? t: to_ZZ(0);
}

bool solovay_strassen(ZZ n)
{
    if ((n & 1) == 0)
        return false;

    ZZ a(2);

    for (int i = 0; i < 10; i++)
    {
        if(euclides_clasico(a, n) != 1){
            return false;
        }

        ZZ r = modulo(jacobi(a, n), n);
        ZZ _r = exponenciacion_mod(a, (n-1)/2,n);
        if (r != _r){
            return false;
        }
        do{
            a = RandomBnd(n);
        }while(a < 2);
    }
    return true;
}

// ---------------------------//

bool miller_rabin(ZZ n){
    
    if ((n & 1) == 0)
        return false;
    ZZ s(0);
    ZZ t = n - 1;
    while ((t & 1) == 0) {
        s++;
        t >>= 1;
    }
    ZZ a(2);
    for (int i = 0; i < 10; i++){

        ZZ x = exponenciacion_mod(a, t, n);
        if (x == 1 || x == (n-1))
            continue;
        for (ZZ r(0); r < (s-1); r++){
            x = exponenciacion_mod(x, to_ZZ(2), n);
            if(x == 1){
                return false;
            }
            else if(x == n - 1)
                break;
        }
        if(x != n - 1 )
            return false;
        ZZ a = RandomBnd(n-3) + 3;
    }

    return true;
}

// ---------------------------//

bool fermat(ZZ n){

    if ((n & 1) == 0)
        return false;
    ZZ a(2);
    for (int i = 0; i < 20; i++){
    
        if (exponenciacion_mod(a, n - 1, n) != 1){
            return false;
        }
        a = RandomBnd(n-2) + 2;

    }
    return true;
}

// ---------------------------//

int main(){

    // probe primal test

    // int bits = 0;
    // cout << "bits: "; cin >> bits;

    // for (int j = 0; j < 100; j++){

    //     for (int i = 0; i < 50; i++){

    //         ZZ number = RandomBits_ZZ(bits);
    //         while(number <3){
    //             number = RandomBits_ZZ(bits);
    //         }
    //         cout << number << endl;
    //         int r = ProbPrime(number);
    //         // int _r = ensayar_divisiones(number); 
    //         // int _r = solovay_strassen(number);
    //         // int _r = miller_rabin(number, 10);
    //         int _r = fermat(number);
    //         if (r != _r){

    //             cout <<" No son iguales\n";
    //             return 0;
    //         }
    //     }
    //     cout << "son iguales\n";
    // }
    

    // performance test

    int bits[8] = {8, 16, 32, 64, 128, 512, 1024, 2048};

    bool (*functions[3])(ZZ) = {solovay_strassen, miller_rabin, fermat};

    string names[3] = {"solovay", "miller", "fermat"};
    for (int i = 0; i < 8; i++){

        ZZ number = RandomBits_ZZ(bits[i]);

        while(number <3){
            number = RandomBits_ZZ(bits[i]);
        }
        // cout << number << endl;
        for(int j = 0; j < 3; j++){

            struct timespec start, end;
            cout << names[j] << " " << bits[i] <<"bits " << endl;

            clock_gettime(CLOCK_MONOTONIC, &start);
            ios_base::sync_with_stdio(false);

            functions[j](number);
            
            clock_gettime(CLOCK_MONOTONIC, &end);

            double time_taken;
            time_taken = (end.tv_sec - start.tv_sec) * 1e9;
            time_taken = (time_taken + (end.tv_nsec - start.tv_nsec)) * 1e-9;
        
            cout << "Tiempo: " << fixed
                << time_taken << setprecision(9);
            cout << " sec" << endl<<endl;
            
        }
        cout << "--------------------------------\n";
    }

}