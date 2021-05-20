#include <iostream>
#include "railFance.h"

using namespace std;

string RailFance::encrypted(string cadena){
    
    string messageEncrypted;

    for (int i = 0; i < password; i++){

        int row = i;
        int move = 1;

        for (int j = i; j < cadena.length(); j++){
            
            if (row == i){
                messageEncrypted += cadena[j];
            }
            if (row + move >= password || row + move < 0){
                move *= -1;        
            }
            row += move;

        }
    }
    return messageEncrypted;

}

string RailFance::decrypted(string cadena){

    string message;

    message.resize(cadena.length(), ' ');

    int col = 0;
    for (int i = 0; i < password; i++){

        int row = i;
        int move = 1;
        for (int j = i; j < cadena.length(); j++){
            
            if (row == i){
                message[j] = cadena[col];
                col++;
            }
            if (row + move >= password || row + move < 0){
                move *= -1;        
            }
            row += move;
        }
    }   
    
    return message;
}
