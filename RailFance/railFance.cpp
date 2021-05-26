#include <iostream>
#include "railFance.h"
using namespace std;

int main(){

    cout << "-----------------Rail Fance----------------\n";
    cout << "Encriptar Desencriptar------------1\n";
    cout << "Desencriptar----------------------2\n\n";
    cout << "seleccionar: ";
    int select = 0;
    cin >> select;
    cin.ignore();
    if(select == 1){

        RailFance emisor, receptor;
        string message;
        cout << "Ingrese el mensaje: ";

        getline(cin, message);

        do{
            cout << "Ingrese la contraseña: ";
            cin >> emisor.password; 
        }while(emisor.password < 2);

        message = emisor.encrypted(message);
        cout << "Mensaje encriptado: '"<< message<< "'" << endl;

        receptor.password = emisor.password;

        cout << "Mensaje desencriptado: '"<< receptor.decrypted(message)<< "'" << endl; 
    }
    else if(select == 2){

        RailFance receptor;
        string message;
        cout << "Ingrese el mensaje: ";

        getline(cin, message);

        do{
            cout << "Ingrese la contraseña: ";
            cin >> receptor.password; 
        }while(receptor.password < 2);

        cout << "Mensaje desencriptado: '"<< receptor.decrypted(message)<< "'" << endl; 
    }
    else{
        return 0;
    }
}