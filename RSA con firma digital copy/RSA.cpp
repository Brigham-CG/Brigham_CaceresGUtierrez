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

        RSA emisor(bits);

        // examples:
        // "vis an alii graeci ne magna elitr ubique per mei te quis reque epicuri libris deleniti appareat vel et at tale labores urbanitas sit duo eu noster epicurei consetetur sea sumo principes adversarium an prima audire apeirian ut usu nonumy complectitur vix ad id duo vero etiam adversarium et aliquam scaevola adipiscing vis nam at case salutatus contentiones decore facilis appareat eu qui ne omnesque consequuntur vim eos an amet vocent mei ei feugait salutandi mel novum causae in pro id duis dolore incorrupte option equidem sed no vis nullam menandri ullamcorper at nullam vocent splendide ut vel"
        // "el unico sistema completamente seguro es aquel que esta apagado encerrado en un bloque de cemento y sellado en una habitacion rodeada de alambradas y guardias armados"
        receptor.establecer(emisor.getE(), emisor.getN());
        emisor.establecer(receptor.getE(), receptor.getN());
        string mensaje = "el unico sistema completamente seguro es aquel que esta apagado encerrado en un bloque de cemento y sellado en una habitacion rodeada de alambradas y guardias armados";
        string mensajeCifrado = emisor.cifrar(mensaje);
        string firma = emisor.firma_digital_cifrado(emisor.leer_datos("firma.txt"));
        cout << "\nMensaje cifrado\n";

        cout << "Emisor: " << mensajeCifrado << endl;
        cout << "Firma: " << firma << endl; 
        cout << "\nMensaje descifrado\n";
        string mensajeDescifrado = receptor.descifrar(mensajeCifrado);
        string firmaDescifrada = receptor.firma_digital_descifrado(firma);

        cout << "Receptor: " << "'" << mensajeDescifrado <<"'"<< endl;
        cout << "Firma: " << "'" << firmaDescifrada << "'" << endl;
    }   
    else if(select == 2)
    {
        int bits = 0;
        cout << "Ingrese la cantidad de bits: "; cin >> bits;

        ZZ e, N;
        cout << "Receptor e: ";cin >> e;
        cout << "Receptor N: ";cin >> N;

        cin.ignore();
        RSA emisor(bits);
        emisor.establecer(e, N);
        string mensaje;
        getline(cin, mensaje);
        string mensajeCifrado = emisor.cifrar(mensaje);
        string firma = emisor.firma_digital_cifrado(emisor.leer_datos("firma.txt"));
        cout << "Mensaje cifrado: " << mensaje << endl;
        cout << "Emisor: " << mensajeCifrado << endl;
        cout << "Firma: " << firma << endl; 

    }
    else if(select == 3)
    {
        
        int bits = 0;
        cout << "Ingrese la cantidad de bits\n"; cin >> bits;
    
        RSA receptor(bits);
        cout << "e: " << receptor.getE() << endl;
        cout << "n: " << receptor.getN() << endl;

        ZZ e, N;
        cout << "Emisor e:";cin >> e;
        cout << "Emisor N: ";cin >> N;
        receptor.establecer(e, N);

        cin.ignore();
        string mensaje;
        cout << "Mensaje cifrado: ";
        getline(cin, mensaje);
        string firma;

        cout << "Firma: ";
        getline(cin, firma);

        cout << "Mensaje descifrado: " <<receptor.descifrar(mensaje) << endl;
        cout << "Firma: " << receptor.firma_digital_descifrado(firma) << endl;
    }
}