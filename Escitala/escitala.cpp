#include <iostream>
#include "escitala.h"

using namespace std;

int main(){

    cout << "------------------------Escitala-------------------------\n"; 
    cout << "Encriptar/Desencriptar------------------1\n";
    cout << "Desencriptar----------------------------2\n\n";
    cout << "Seleccionar: ";
    int select = 0;
    cin >> select;
    cin.ignore();
    if(select == 1){

        escitala emisor;
        escitala receptor;
        string message;

        cout << "Enter the message: ";
        getline(cin, message);

        do{
            cout << "Enter the password(rows): ";
            cin >> emisor.rows;
            cout << "Enter the password(cols): ";
            cin >> emisor.cols;

        }while(message.length() > emisor.rows * emisor.cols);
        cin.ignore();
        receptor.rows = emisor.rows;
        receptor.cols = emisor.cols;
        message = emisor.encrypted(message);
        cout << "Mensaje encriptado: " << message << endl;
        message = receptor.decrypted(message);
        cout << "Mensaje desencriptado: "<< message << endl;
    }
    else if(select == 2){
        // pruebas 
        escitala receptor;
        string message;
        cout << "Enter the message: ";
        getline(cin, message);
        do{
            cout << "Enter the password(rows): ";
            cin >> receptor.rows;
            cout << "Enter the password(cols): ";
            cin >> receptor.cols;

        }while(message.length() > receptor.rows * receptor.cols);
        cin.ignore();
        message = receptor.decrypted(message);
        cout << "Mensaje desencriptado: "<< message << endl;
    }
    else{
        return 0;
    }
}   