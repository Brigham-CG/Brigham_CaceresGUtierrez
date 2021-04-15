#include <iostream>

using namespace std;

class RailFance{

    public:

        int password = 0;

        string encrypted(string cadena){
            
            if (password >= 2){
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
            }else if(password == 1){

                return cadena;
            }else{
                
                return "";
            }
            
        }

        string decrypted(string cadena){
            
            if (password >= 2){

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

            }else if(password == 1){

                return cadena;
            }else{
                
                return "";
            }
            
        }
};

int main(){

    RailFance user01;
    string message;
    cout << "Ingrese el mensaje: ";

    getline(cin, message);

    cout << "Ingrese la contraseña: ";
    cin >> user01.password; 

    message = user01.encrypted(message);

    if (message == ""){
        cout << "No se pudo encriptar << endl";
    }
    else{
        cout << "'"<< message<< "'" << endl;

        cout << "'"<< user01.decrypted(message)<< "'" << endl; 
    }

}