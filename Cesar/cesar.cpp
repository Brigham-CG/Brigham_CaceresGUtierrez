#include <iostream>
#include "cesarInt.h"

using namespace std;

int main(){
    // menu de seleccion para encriptar y romper 

    cout << "Encriptar/Desencriptar ---- 1\n";
    cout << "Romper                 ---- 2\n";
    cout << "Seleccione: ";
    int seleccion = 0;
    cin >> seleccion;
    cin.ignore();

    if(seleccion == 1){
        Cesar emisor;
        Cesar receptor;

        string original;
        cout << "-----Emisor----\n";
        cout << "Ingrese el mensaje: ";

        getline(cin, original);

        cout << "Ingrese la contraseña: ";
        cin >> emisor.password;
        receptor.password = emisor.password;

        string message = emisor.encrypted(original);
        
        cout << "mensaje encriptado: '" << message << "'" << endl;
        cout << "-----Receptor----\n";
        cout << "mensaje desencriptado: '" << receptor.decrypted(message) << "'" << endl;
    }       
    else if(seleccion == 2){

        cout << "Ingrese el mensaje a romper: ";
        string message;
        getline(cin, message);
        cout << break_cesar(message) << endl;

    }   
}