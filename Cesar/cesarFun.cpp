#include <iostream>
#include "cesarInt.h"

using namespace std;

string alfabeto = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

string Cesar::encrypted(string message){

    string messageEncrypted;

    for(int i = 0; i < message.length(); i++){

        int pos = alfabeto.find(message[i]);
        // se busca una coincidencia con el alfabeto
        if (pos != string::npos){
            // se encontro una coincidencia
            pos += password;
            pos %= alfabeto.length();
            messageEncrypted += alfabeto[pos];
        }

        else{
            // no se encuentro, se añadira al mensaje cifrado                    
            messageEncrypted += message[i];
        }
    }
    return messageEncrypted;
}

string Cesar::decrypted(string message){

    string messageDecrypted;

    for (int i = 0; i < message.length(); i++){
        
        int pos = alfabeto.find(message[i]);

        // se busca una coincidencia con el alfabeto
        if (pos != string::npos){
            // se encontro una coincidencia
            pos -= password;

            // ya que el modulo de c++ funciona distinto de como deberia ser
            // se restara el tamaño y la pos:

            pos = (alfabeto.length() + pos) % alfabeto.length(); 
            messageDecrypted += alfabeto[pos];
        }
        else{
            // no se encuentro, se añadira al mensaje cifrado                    
            messageDecrypted += message[i];
        }
    }
    return messageDecrypted;   
}

string break_cesar(string cadena){

    string posiblesContr[26];
    for (int clave = 0 ; clave < alfabeto.length() ; clave++){

        string mensajeDescifrado;

        for (int i = 0; i < cadena.length(); i++){
            
            int pos = alfabeto.find(cadena[i]);

            if (pos != string::npos){

                pos -= clave;
                pos = (alfabeto.length() + pos) % alfabeto.length(); 
                mensajeDescifrado += alfabeto[pos];

            }
            else{
                mensajeDescifrado += cadena[i];
            }
        }
        posiblesContr[clave] = mensajeDescifrado;

        cout << "| clave: " << clave << " |  mensaje desencriptado: " << mensajeDescifrado << "|" << endl;
    } 

    cout << "Escoja la contraseña: " ;

    int clave = 0;
    cin >> clave;

    return posiblesContr[clave];
}