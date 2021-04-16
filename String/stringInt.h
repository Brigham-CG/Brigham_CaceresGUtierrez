#include <iostream>
using namespace std;

// 18.7
class rot13{

    int rot13 = 13;
    public:
        string cifrado(string cadena);

        string descifrado(string cadena);

        int fuerza_bruta(string cifrado);
            
};

// 18.11
string concatenar_nombre(string nombre, string apellido);

// 18.12

void ahorcado();

//18.19

string insertar(string cadena);

// 18.21

void separar(char *cadena, int tamanio);

// 18.22

void reverse(string cadena);

// 18.27

bool ascendente(string a, string b);

bool descendente(string a, string b);

void ordenar(string lista[], int tamanio, bool (*comparar)(string a, string b));