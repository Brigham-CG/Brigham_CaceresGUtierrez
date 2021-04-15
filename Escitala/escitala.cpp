// Tarea de Algebra abstracta
// V1.1
#include <iostream>

using namespace std;

class escitala{
    public:
        int rows = 0, cols = 0;
        
        string encrypted(string message){

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

        string decrypted(string messageEncrypted){

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
};

int main(){
    
    escitala user1;
    string message;

    cout << "Enter the message: ";
    getline(cin, message);
    cout << "Enter the password(rows): ";
    cin >> user1.rows;
    cout << "Enter the password(cols): ";
    cin >> user1.cols;

    message = user1.encrypted( message);
    if (message != ""){
        cout << "Mensaje encriptado: " << message << endl;
        message = user1.decrypted(message);
        cout << "Mensaje desencriptado: "<< message << endl;
    }
    else{
        cout << "No se pudo encriptar\n";
    }
}   