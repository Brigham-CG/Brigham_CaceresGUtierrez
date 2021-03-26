// Tarea de Algebra abstracta

#include <iostream>

using namespace std;

string encrypted(int rows, int cols, string message){

    if (message.length() <= rows * cols){
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
    }else{
        return "";
    }
}

string decrypted(int rows, int cols, string messageEncrypted){

    if (messageEncrypted.length() == rows * cols){

        string messageDecrypted;
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < cols; j++){
                messageDecrypted += messageEncrypted[i + j * rows];
            }
        }
        return messageDecrypted;
    }
    else{
        return "";
    }
}

int main(){
    
    string message;
    int rows = 0, cols = 0;
    cout << "Enter the message: ";
    getline(cin, message);
    cout << "Enter the password(rows): ";
    cin >> rows;
    cout << "Enter the password(cols): ";
    cin >> cols;

    message = encrypted(rows, cols, message);
    // message = encrypted(rows, cols, message);
    if (message != ""){
        cout << "Mensaje encriptado: " << message << endl;
        message = decrypted(rows, cols, message);
        // message = decrypted(rows, cols, message);
        cout << "Mensaje desencriptado: "<< message << endl;
    }
    else{
        cout << "No se pudo encriptar\n";
    }
}   