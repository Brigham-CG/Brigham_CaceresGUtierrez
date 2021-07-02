// compile: g++ -g -O2 -std=c++11 -pthread -march=native RSA.cpp RSAFun.cpp -o RSA -lntl -lgmp -lm
#include <iostream>
#include <NTL/ZZ.h>
#include "RSA.h"

using namespace std;
using namespace NTL;
int main(){

    cout <<"\n         ____  ____    _    \n";
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
        cin.ignore();
        RSA receptor(bits);

        RSA emisor(receptor.getE(),receptor.getN());

        // examples:
        // "vis an alii graeci ne magna elitr ubique per mei te quis reque epicuri libris deleniti appareat vel et at tale labores urbanitas sit duo eu noster epicurei consetetur sea sumo principes adversarium an prima audire apeirian ut usu nonumy complectitur vix ad id duo vero etiam adversarium et aliquam scaevola adipiscing vis nam at case salutatus contentiones decore facilis appareat eu qui ne omnesque consequuntur vim eos an amet vocent mei ei feugait salutandi mel novum causae in pro id duis dolore incorrupte option equidem sed no vis nullam menandri ullamcorper at nullam vocent splendide ut vel"
        // "el unico sistema completamente seguro es aquel que esta apagado encerrado en un bloque de cemento y sellado en una habitacion rodeada de alambradas y guardias armados"
        string mensaje;

        cout << "ingrese el mensaje: ";
        getline(cin, mensaje);
        string mensajeCifrado = emisor.cifrar(mensaje);

        cout << "\nMensaje cifrado\n";

        cout << "Emisor: " << mensajeCifrado << endl;
        cout << "\nmensaje descifrado\n";
        string mensajeDescifrado = receptor.descifrar(mensajeCifrado);
        cout << "Receptor: " << "'" << mensajeDescifrado <<"'"<< endl;
    }   

    else if(select == 2)
    {

        ZZ e, N;
        cout << "e: ";cin >> e;
        cout << "N: ";cin >> N;

        cin.ignore();
        RSA emisor(e,N);
        string mensaje;
        getline(cin, mensaje);
        mensaje = emisor.cifrar(mensaje);
        cout << "Mensaje cifrado: " << mensaje << endl;

    }
    else if(select == 3)
    {
        ZZ p, q, e, d;
        cout << "p: " ; cin >> p;
        cout << "q: " ; cin >> q;
        cout << "e: " ; cin >> e;
        cout << "d: " ; cin >> d;
        cin.ignore();

        RSA receptor(p, q, e, d);
        string mensaje; 
        cout << "Mensaje cifrado: ";
        getline(cin, mensaje);

        cout << "Mensaje descifrado: " <<receptor.descifrar(mensaje) << endl;
    }
}