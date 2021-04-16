// Pertenece a Brigham Cáceres
#include "stringInt.h"
#include <iostream>

using namespace std;

// 18.7

int main(){

    // Descomentar para probar cada uno de los programas

    // _________________________________________
    // 18.7
    string mensaje;
    cout << "Ingrese el mensaje: "; 
    getline(cin, mensaje);
    rot13 user01;
    mensaje = user01.cifrado(mensaje);
    cout << "mensaje cifrado: " << mensaje << endl;
    string mensaje_descifrado = user01.descifrado(mensaje);
    cout << "mensaje descifrado: " << mensaje_descifrado << endl;
    
    int llave = user01.fuerza_bruta(mensaje);
    if (llave != -1){
        cout << "La contraseña es: " << llave << endl;
    }
    else{
        cout << "La contraseña no se encontro" << endl;
    }

    // _________________________________________
    // 18.11
    // string nombre, apellido;
    // cout << "Ingrese el nombre: "; getline(cin, nombre);
    // cout << "Ingrese el apellido: "; getline(cin, apellido);
    // string nombre_completo = concatenar_nombre(nombre, apellido);
    // cout << "Nombre completo: " << nombre_completo << endl;

    // _________________________________________

    // 18.12
    // ahorcado();

    // _________________________________________
    // 18.19
    // string cadena;
    // cout << "Ingrese la cadena: "; getline(cin, cadena);
    // cout << insertar(cadena);

    // _________________________________________
    // 18.21

    // string cadena;

    // cout << "Ingrese una frase: ";
    // getline(cin, cadena);

    // int tamanio = cadena.length();
    // char *ptr = new char[tamanio + 1];
    // ptr[tamanio] = '\0';
    // cadena.copy(ptr, tamanio, 0);

    // separar(ptr, tamanio);
    
    // delete []ptr;

    // ptr1 = scadena.data();

    // _________________________________________
    // 18.22
    // reverse("hello world");


    // _________________________________________
    // 18.27

    //     const int tamanio = 5;
    //     string palabras[tamanio] = {"hacking", "computacion", "seguridad", "robotica", "reconocer"};

    //     cout << "Lista original: ";

    //     for (int i = 0; i < tamanio; i++){
    //         cout <<" " << palabras[i] << " ";
    //     }
    //     cout << endl;

    //     int seleccion = 0;
    //     cout << "Seleccione el tipo de orden\n1) Ascendente\n2) Descendente\n: ";
    //     cin >> seleccion;

    //     if (seleccion == 1){
    //         ordenar(palabras, tamanio, ascendente);
    //     }
    //     else{
    //         ordenar(palabras, tamanio, descendente);
    //     }

    //    cout << "Lista ordenada: ";

    //     for (int i = 0; i < tamanio; i++){
    //         cout <<" " << palabras[i] << " ";
    //     }
    //     cout << endl;

}