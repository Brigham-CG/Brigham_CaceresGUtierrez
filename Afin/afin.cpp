// afin.cpp
// uso de interfaz Afin

#include <iostream>
#include <cstdlib>
#include <ctime>

#include "afinInt.h"
using namespace std;

int main(){

    // menu

    int select = 0;
    cout << "Cifrar mensaje / descifrar --> 1\n";
    cout << "Descifrar mensaje          --> 2\n";

    do{
        cout << "seleccione: ";
        cin >> select;

    }while(select != 1 && select != 2);

    cin.ignore();

    if(select == 1){

        // demostracion de funcionalidad

        srand(time(NULL));

        Afin emisor;

        string mensaje;

        cout << "Ingrese el mensaje: ";
        getline(cin, mensaje);

        string mensajeCifrado = emisor.cifrar(mensaje);
        cout << "mensaje cifrado: '" << mensajeCifrado << "'" <<endl; 

        Afin receptor(emisor.a, emisor.b);
        string mensajeDescifrado;
        mensajeDescifrado = receptor.descifrar(mensajeCifrado);
        cout << "mensaje descifrado: '" << mensajeDescifrado << "'" <<endl; 
    }
    else if(select == 2){
        
        int a = 0, b = 0;
        cout << "Ingrese a: ";
        cin >> a ;
        cout << "Ingrese b: ";
        cin >> b;
        cin.ignore();
        
        Afin receptor(a, b);
        string mensajeCifrado, mensajeDescifrado;
        mensajeDescifrado = receptor.descifrar(mensajeCifrado);
        cout << "mensaje descifrado: '" << mensajeDescifrado << "'" <<endl; 
    }
    else{
        return 0;
    }
    
}