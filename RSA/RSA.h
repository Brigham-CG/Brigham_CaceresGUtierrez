#include <iostream>
#include <vector>
#include <ctime>
#include <NTL/ZZ.h>
#include <sstream>

using namespace std;
using namespace NTL;

class RSA{

    public:
        // receptor
        RSA(int);
        //emisor
        RSA(ZZ, ZZ);
        // pruebas
        RSA(ZZ p, ZZ q, ZZ e, ZZ d);
        
        ZZ generate_bit();
        ZZ generate_random(int);
        ZZ generar_primo(int);
        ZZ left_to_right_binary_exponenciacion(ZZ, ZZ, ZZ);
        ZZ exponenciacion(ZZ, ZZ);
        long euclides(ZZ, ZZ);
        vector<ZZ> euclides_extendido(ZZ, ZZ);
        ZZ inversa(ZZ, ZZ);
        ZZ generar_aleatorio(int);
        bool miller_rabin(ZZ);
        ZZ restoChino(ZZ, ZZ, ZZ);

        ZZ getE();
        ZZ getN();
        string cifrar(string);
        string descifrar(string);

    private:

        ZZ d, e,N,p,q;
        string alfabeto = "abcdefghijklmnopqrstuvwxyz ";
};
