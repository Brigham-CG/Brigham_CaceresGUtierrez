#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

void question1(string cadena, int tamanio){

    string final;
    vector <string> vecStr;
    for (int i = 0; i < cadena.length(); i+=tamanio){
        string sub =cadena.substr(i , 4);
        if (sub.length() < tamanio){
            sub.append(tamanio-sub.length(), 'X');
        }
        vecStr.push_back(sub);
        final+=sub + "*";
    }
    final.pop_back();

    cout << final << endl;
    int vecLen = vecStr.size(); 
    for (int i = 0; i < vecLen; i++)
        cout << vecStr[i] << " " ;
}

int elevar(int b, int e){

    int numero = 1;
    for (int i = 0; i < e; i++){
        numero*=b;
    }
    return numero;
}

int question2(string numeroStr){

    int numeroInt = 0;
    for (int i = 0 ; i < numeroStr.length();  i++){
        numeroInt += (int) (numeroStr[i] - 48) * elevar(10, numeroStr.length()-i-1) ;
    }

    return numeroInt;
}   

string question3(int numeorInt){

    string numeroStr = to_string(numeorInt);
    return numeroStr;
    
}

int main(){

    // 1-------------------------------

    string cadena;
    cout << "ingrese una cadena: ";
    getline(cin, cadena);
    int tamanio = 0;
    cout << "ingrese el numero: ";
    cin >> tamanio;

    
    // 2-------------------------------
    // string numeroStr;
    // cout << "Ingrese un numero: "; getline(cin, numeroStr);
    // cout << question2(numeroStr) << endl;  

    // 3-------------------------------

    // question3();

    // int numeroInt;
    // cout << "ingrese un numero: "; cin >> numeroInt;


}