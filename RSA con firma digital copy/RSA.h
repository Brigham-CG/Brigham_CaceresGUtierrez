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
        void establecer(ZZ, ZZ);
        string cifrar(string);
        string descifrar(string);
        string firma_digital_cifrado(string);
        string firma_digital_descifrado(string);
        string leer_datos(string);

    private:

        ZZ d, e,N,p,q, eR, NR;
        string alfabeto = "abcdefghijklmnopqrstuvwxyz -0123456789";
        
};