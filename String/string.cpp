// Pertenece a Brigham Cáceres

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cstring>

using namespace std;

// 18.7
class rot13{

    int rot13 = 13;
    public:
        string cifrado(string cadena){

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

        string descifrado(string cadena){
            
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

        int fuerza_bruta(string cifrado){

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
};

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

int main(){

    // Descomentar para probar cada uno de los programas

    //_________________________________________
    // 18.7
    // string mensaje;
    // cout << "Ingrese el mensaje: "; 
    // getline(cin, mensaje);
    // rot13 user01;
    // mensaje = user01.cifrado(mensaje);
    // cout << "mensaje cifrado: " << mensaje << endl;
    // string mensaje_descifrado = user01.descifrado(mensaje);
    // cout << "mensaje descifrado: " << mensaje_descifrado << endl;
    
    // int llave = user01.fuerza_bruta(mensaje);
    // if (llave != -1){
    //     cout << "La contraseña es: " << llave << endl;
    // }
    // else{
    //     cout << "La contraseña no se encontro" << endl;
    // }

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