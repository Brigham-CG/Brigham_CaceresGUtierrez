#include <iostream>
#include "escitala.h"
using namespace std;

string escitala::encrypted(string message){

    string messageEncrypted;
    for (int j = 0; j < cols; j++){
        for (int i = 0; i < rows; i++){
            if (message.length() >= i * cols + j + 1){
                messageEncrypted += message[j + i * cols];
            }
            else{
                messageEncrypted += " ";
            }
        }
    }
    return messageEncrypted;
}

string escitala::decrypted(string messageEncrypted){    

    string messageDecrypted;
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            messageDecrypted += messageEncrypted[i + j * rows];
        }
    }
    return messageDecrypted;
}
