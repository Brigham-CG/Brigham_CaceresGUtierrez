
#include "stringInt.h"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cstring>

using namespace std;

string rot13::cifrado(string cadena){

    string alfabeto("abcdefghijklmnopqrstuvwxyz");
    string::const_iterator i(cadena.begin());
    string mensaje;
    while(i != cadena.end()){
        int pos = alfabeto.find(*i);
        if (pos==string::npos){
            mensaje+=*i;
        }
        else{
            pos +=rot13;
            if (pos> alfabeto.length() - 1){
                pos -= alfabeto.length();
            }
            mensaje+=alfabeto[pos];
        }
        i++;
    }

    return mensaje;
}

string rot13::descifrado(string cadena){
    
    string alfabeto("abcdefghijklmnopqrstuvwxyz");
    string::const_iterator i(cadena.begin());
    string mensaje;

    while(i != cadena.end()){
        int pos = alfabeto.find(*i);
        if (pos==string::npos){
            mensaje+=*i;
        }
        else{
            pos -=rot13;
            if (pos> alfabeto.length() - 1){
                pos += alfabeto.length();
            }
            mensaje+=alfabeto[pos];
        }
        i++;
    }

    return mensaje;
}

int rot13::fuerza_bruta(string cifrado){

    string alfabeto("abcdefghijklmnopqrstuvwxyz");

    string mensaje;

    int llave[cifrado.length()];
    for (int i = 0; i < cifrado.length(); i++){
        // iterar al mensaje cifrado
        for (int j = 0; j < alfabeto.length(); j++){
            //iterar al alfabeto

            bool romper = false;    
            for (int k = 0; k < alfabeto.length()-j; k++){
                // probar posibles claves
                int posPass = j + k;

                if (posPass > alfabeto.length() - 1){
                    posPass -= alfabeto.length();
                } 
                if (cifrado[i] == alfabeto[posPass])

                    llave[i] = k;
                    romper = true;
                    break;
                    cout << llave[i] << endl;
                    
            }
            if (romper){
                break;
            }
        }
        
    }
    
    for (int i = 1; i < cifrado.length(); i++){
        if (llave[0] != llave[i]){
            // no se encontro la llave
            return -1;
        }
    }

    // se devuelve la llave
    return llave[0];
}

// 18.11
string concatenar_nombre(string nombre, string apellido){

    return nombre + " " + apellido;
}

// 18.12

void ahorcado(){

    srand(time(0));
    int seleccion = rand() % 5;    
    string palabras[5] = {"hacking", "computacion", "seguridad", "robotica", "reconocer"};
    string cuerpo[7] = {"\t\t\t o\n", "\t\t\t/", "|", "\\\n", "\t\t\t |\n", "\t\t\t/ ", "\\"};
    string palabraSel(palabras[seleccion].length(), 'X');
    string intentos;
    int contInc = 0;

    while(contInc < 7){
        cout << "Adivine la palabra:    " << palabraSel << endl; 
        string letra; 
        cout << "Intentos: " << intentos << " Fallidos: " << contInc<< endl;
        cout << "Ingrese la posible letra: "; cin >> letra;
        int index = palabras[seleccion].find(letra);

        intentos.append(letra+", ");
        if (index != string::npos){
            cout << "Se encontro la letra en la palabra\n";
            for (int i = index; i < palabraSel.length(); i++){
                if(palabras[seleccion][index] == palabras[seleccion][i]){
                    palabraSel[i] = palabras[seleccion][index];
                }
            }
            cout << "\n\n";
        }else{
            cout << "No se encontro la letra en la palabra\n";
            contInc++;
            for (int i = 0; i < contInc; i++){
                cout <<cuerpo[i];
            }
            cout << "\n\n";
        }
        if (!palabras[seleccion].compare(palabraSel)){
            
            string sel;
            cout << "Felicididades!!! Adivino mi palabra. Desea jugar otra vez? si/no: ";
            cin.ignore();
            getline(cin ,sel);
            if (sel == "si" || sel == " si" || sel == "si " || sel== ""){
                ahorcado();
            }
            else{
                return;
            }
        }
    }
    cout << "\t\t    Ahorcado!!!\n";
}   

//18.19

string insertar(string cadena){
    int pos = cadena.length() / 2;
    cadena.insert(pos, "******");
    return cadena;
}

// 18.21

void separar(char *cadena, int tamanio){

    string alfabeto = "abcdefghijklmnoprstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
    // reemplazar signos de puntuacion;
    for (int i = 0; i < tamanio; i++){
        if (alfabeto.find(cadena[i]) == string::npos){
            cadena[i] = ' ';
        }
    }

    cout << cadena << endl;

    char *token = strtok(cadena, " ");

    while(token){
        cout << token << endl;
        token = strtok(NULL, " ");
    }
}

// 18.22

void reverse(string cadena){

    for (string::reverse_iterator i = cadena.rbegin(); i != cadena.rend(); i++){
        cout << *i;
    }
    cout << endl;
}   

// 18.27

bool ascendente(string a, string b){

    int comp = a.compare(b);

    if (comp >= 0)
        return true;
    else
        return false;
}

bool descendente(string a, string b){

    int comp = a.compare(b);

    if (comp < 0)
        return true;
    else
        return false;
}

void ordenar(string lista[], int tamanio, bool (*comparar)(string a, string b)){

    int menorOMayor;
    for (int i = 0; i < tamanio - 1; i++){
        menorOMayor = i;
        for (int index = i; index < tamanio; index++){
            if (comparar(lista[menorOMayor], lista[index]))
                menorOMayor = index;    
        }
        lista[menorOMayor].swap(lista[i]);
    }
}