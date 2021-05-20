// afinInt.cpp
// interfaz Afin

#include <iostream>

using namespace std;
class Afin {

    string alf = "abcdefghijklmnopqrstuvwxyz,.-_ABCDEFGHIJKLMNOPQRSTUVWXYZ 0123456789()";
    public: 
        int a = 0, b = 0, invA = 0;
        Afin();
        Afin(int a, int b);
        int generar_claves();
        string cifrar(string);
        string descifrar(string);
        
};

int aleatorio();

int modulo(int a, int n);

int mcd(int a, int b);

int inverso(int a, int n);