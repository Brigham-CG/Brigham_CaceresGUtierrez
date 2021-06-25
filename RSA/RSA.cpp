// compile: g++ -g -O2 -std=c++11 -pthread -march=native RSA.cpp RSAFun.cpp-o RSA -lntl -lgmp -lm
#include <iostream>
#include <NTL/ZZ.h>
#include "RSA.h"

using namespace std;
using namespace NTL;
int main(){

    cout <<"\n        ____  ____    _    \n";
    cout <<"        |  _ \\/ ___|  / \\   \n";
    cout <<"        | |_) \\___ \\ / _ \\  \n";
    cout <<"        |  _ < ___) / ___ \\ \n";
    cout <<"        |_| \\_\\____/_/   \\_\\ \n\n\n";
    int select = 0;
    cout << "1) Muestra\n";
    cout << "2) Enviar mensaje\n";
    cout << "3) Recibir mensaje\n";
    cout << "Seleccione: ";
    cin >> select;
    
    if (select == 1){

        int bits = 0;
        cout << "Ingrese la cantidad de bits: "; cin >> bits;

        RSA receptor(bits);

        RSA emisor(receptor.getE(),receptor.getN());

        string mensaje = emisor.cifrar("el unico sistema completamente seguro es aquel que esta apagado encerrado en un bloque de cemento y sellado en una habitacion rodeada de alambradas y guardias armados");

        cout << "\nMensaje cifrado\n";

        cout << "Emisor: " << mensaje << endl;
        cout << "\nmensaje descifrado\n";
        cout << "Receptor: " << receptor.descifrar(mensaje) << endl;
    }
    else if(select == 2)
    {

        ZZ e, N;
        cout << "e: ";cin >> e;
        cout << "N: ";cin >> N;

        RSA emisor(e,N);

        string mensaje = emisor.cifrar("el unico sistema completamente seguro es aquel que esta apagado encerrado en un bloque de cemento y sellado en una habitacion rodeada de alambradas y guardias armados");
        cout << "Mensaje cifrado: " << mensaje << endl;

    }
    else if(select == 3)
    {

        // recibir mensaje 

    }


}   