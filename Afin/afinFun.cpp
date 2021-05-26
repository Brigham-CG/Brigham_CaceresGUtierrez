// afinFun.cpp
// clases y funciones en Afin

#include <iostream>
#include <cstdlib>
#include "afinInt.h"

using namespace std;

int aleatorio(){
    
    // generador de aleatorio
    return rand() % 100 + 1;
}   

int mcd(int a, int b){

    // algoritmo de maximo comun divisor de Euclides
    if (b == 0)
        return a;
    else{
        int q = a / b, r =  a - q*b;
        return mcd(b, r);
    }
}

int modulo(int a, int n){
    // Mi algoritmo de modulo para evitar fallas con el modulo predeterminado de C++
    int base = a - (a/n) * n;
    if (base == 0){
        return 0;
    }
    else if (base > 0){
        if ( n > 0)
            return base;
        else
            return base + n;    
    }
        if (n > 0)
            return base + n;
        else
            return base;
}

int inverso(int a, int n){
    int invA = 0;

    for (int i = 1; i < n; i++){
        //  encontrar el inverso multiplicativo de 'a' y almacenarlo en 'invA'
        invA = (a * i) % n; 
        if(invA == 1) {
            invA = i;
            return invA;
        }
    }
}

Afin::Afin(){

    generar_claves();
}

Afin::Afin(int a, int b){
    
    this->invA = inverso(a, alf.length());
    this->b = b;
    cout << a << " " << b << endl;
}

string Afin::cifrar(string mensaje){

    string mensajeCifrado; 
    for (int i = 0; i < mensaje.length(); i++){

        int pos = alf.find(mensaje[i]);
        if (pos != string::npos){
            // operacion de cifrado si se encontro una coincidencia con el alfabeto
            pos = modulo((a * pos + b), alf.length());
            mensajeCifrado += alf[pos];
        }   
        else{
            mensajeCifrado += mensaje[i];
        }
    }
    return mensajeCifrado;
};

string Afin::descifrar(string mensajeCifrado){

    string mensajeDescifrado;
    
    for (int i = 0; i < mensajeCifrado.length(); i++){

        int pos = alf.find(mensajeCifrado[i]);
        if(pos != string::npos){
            // operacion de cifrado si se encontro una coincidencia con el alfabeto
            pos = modulo(invA * (pos - b), alf.length());
            mensajeDescifrado += alf[pos];
        }
        else{
            // si no se encuentra en el alfabeto, añadirlo a la salida
            mensajeDescifrado += mensajeCifrado[i];
        }
    }
    return mensajeDescifrado;
}

int Afin::generar_claves(){

    // generar claves a y b, con las propiedades de Afin
    int A = 0;
    do{
        a = aleatorio();
        A = mcd(a, alf.length());
    }while(A != 1);

    b = aleatorio() % alf.length();
    cout << a << " " << b << endl;
}