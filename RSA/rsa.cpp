// compile: g++ -g -O2 -std=c++11 -pthread -march=native rsa.cpp -o rsa -lntl -lgmp -lm

#include <iostream>
#include <vector>
#include <NTL/ZZ.h>


using namespace std;
using namespace NTL;

class RSA{

    public:
        RSA(int bits);
        RSA(ZZ, ZZ);
        ZZ exponenciacion();
        ZZ resto_chino(ZZ);
        string cifrar(string);
        string descifrar(string);
        long euclides(ZZ a, ZZ b);
        ZZ generar_aleatorio(int n);
        vector<int> extendido_euclides(ZZ a, ZZ b);

    private:
        ZZ d, e, N, p, q;
        string alfabeto;
};

RSA::RSA(int bits){
    // generate
    if(bits == 512){
        
    }
    else if (bits == 1024){

    }
    else if(bits == 2048){

    }
}

ZZ generar_aleatorio(int n){

    ZZ iMenor, iMayor;
    2

}
RSA::RSA(ZZ p, ZZ q){
    // put values
}

int main(){
    vector<int> num = {1,2,3,4};
}