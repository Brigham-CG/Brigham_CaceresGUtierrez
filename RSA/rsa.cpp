// compile: g++ -g -O2 -std=c++11 -pthread -march=native rsa.cpp -o rsa -lntl -lgmp -lm

#include <iostream>
#include <vector>
#include <ctime>
#include <NTL/ZZ.h>
#include <sstream>

using namespace std;
using namespace NTL;

class RSA{

    public:

        RSA(int);
        RSA(ZZ, ZZ);
        RSA(ZZ p, ZZ q, ZZ e, ZZ d);
        ZZ generar_primo(int);
        ZZ exponenciacion_mod(ZZ, ZZ, ZZ);
        ZZ exponenciacion(ZZ, ZZ);
        long euclides(ZZ, ZZ);
        vector<ZZ> extendido_euclides(ZZ, ZZ);
        ZZ inversa(ZZ, ZZ);
        ZZ generar_aleatorio(int);
        bool test_primalidad(ZZ);

        string cifrar(string);
        string descifrar(string);

    private:

        ZZ d, e,N,p,q;
        string alfabeto = "abcdefghijklmnopqrstuvwxyz ";
};

RSA::RSA(int bits){

    this-> p = generar_primo(bits);
    // cout << "p:" << p << endl;
    this-> q = generar_primo(bits);
    // cout << "q:" << q << endl;
    this-> N = p * q;
    cout << "N: " << N << endl;
    ZZ fN = (p-1)*(q-1);
    // cout << "fN: " << fN << endl;
    do{
        this-> e = generar_aleatorio(bits);
    }while(euclides(e, fN)!=1);
    // cout << "mcd: " <<euclides(e, fN) << endl;
    this-> d = inversa(e, fN);
    cout << "e: " << e << endl;
    // cout << "d: " << d <<endl;
}

RSA::RSA(ZZ p, ZZ q, ZZ e, ZZ d){

    this-> p =  p;
    this-> q = q;
    this-> N = p * q;
    this->e = e;
    this->d = d;
}

ZZ RSA::generar_primo(int bits){

    ZZ prime;
    do{
        prime = generar_aleatorio(bits);
    }while(!test_primalidad(prime));

    return prime;
}

RSA::RSA(ZZ e, ZZ N){
    // put values
    this->e = e;
    this->N = N;
}

ZZ RSA::exponenciacion_mod(ZZ b, ZZ e, ZZ n){

    ZZ result(1);

    while(e>0){
        if(e % 2)
            result = (result*b) % n;
        b =  (b * b) % n;
        e /= 2;
    }
    return result;    
}

ZZ RSA::exponenciacion(ZZ b, ZZ e){
    
    ZZ result(1);

    while(e>0){
        if(e % 2)
            result = (result*b);
        b =  (b * b);
        e /= 2;
    }
    return result;
}

ZZ RSA::generar_aleatorio(int bits){

    // ZZ primeNumber = RandomPrime_ZZ(bits);
    ZZ min(exponenciacion(to_ZZ(2), to_ZZ(bits))/2), max(exponenciacion(to_ZZ(2), to_ZZ(bits)) - 1);

    ZZ number;
    do{
        number = RandomLen_ZZ(bits);

    }while(number < min || number > max);

    return number;

}

bool RSA::test_primalidad(ZZ number){

    // test de Fermat
    if (exponenciacion_mod(to_ZZ(2), number - 1, number) == 1){

        return true;
    }
    return false;
}

long RSA::euclides(ZZ e, ZZ N){
    
    ZZ q, r;
    do{
        q = e/N;
        r = e - N*q;
        e = N;
        N = r;

    }while(r != 0);
    long result = 0;
    conv(result, e);
    return result;
}

vector<ZZ> RSA::extendido_euclides(ZZ a, ZZ b){

    vector<ZZ> numbers(3);
    ZZ x(0), y(0), d(0), x1(0), x2(1), y1(1), y2(0), q(0), r(0);

    if (b == 0){
        numbers[0] = a;
        numbers[1] = 1;
        numbers[2] = 0; 
    }
    else{
        while(b > 0){
            q = a / b;
            r = a - q*b;
            x = x2 -q*x1;
            y = y2 -q*y1;
            a = b;
            b = r;
            x2 = x1;
            x1 = x;
            y2 = y1;
            y1 = y;
        }
        numbers[0] = a;
        numbers[1] = x2;
        numbers[2] = y2;
    }
    return numbers;
}

ZZ RSA::inversa(ZZ e, ZZ N){

    vector<ZZ> numbers = extendido_euclides(e, N);

    if (numbers[2] < 0){
        return numbers[2] + N;
    }
    return numbers[2];
}

string RSA::cifrar(string mensaje){

    string transform;

    ZZ n(this->N);
    long dividir = 0;

    do {
        ++dividir; 
        n /= 10;
    } while (n != 0);

    dividir--;
    // tranformando en numeros
    int digitos = to_string(alfabeto.length() - 1).length();
    for (int i = 0; i < mensaje.length(); i ++){

        string pos = to_string(alfabeto.find(mensaje[i]));
        int tamanio = digitos-pos.length();
        for (int j = 0; j < tamanio; j++){

            transform += "0";
        }
        transform +=pos;
    }
    string ult = to_string(alfabeto.length());

    // dividir
    while(transform.size() % dividir != 0){
        
        transform+=ult;
    }
    cout << transform << endl;

    // exponenciacion
    int i = 0;
    string cifrado;
    cout << dividir << endl;
    
    while(i < transform.length()){
        
        ZZ number(conv<ZZ>(transform.substr(i,dividir).c_str()));
        
        ZZ exp = exponenciacion_mod(number, e, N);
        i += dividir;

        stringstream buffer;
        buffer<<exp;
        string ci = buffer.str();

        int tamanio = dividir-ci.length()+1;
        
        for (int i = 0; i < tamanio; i++){

            cifrado += "0";
        }

        cifrado +=ci;
    }
    
    return cifrado;
}

string RSA::descifrar(string mensaje){

    ZZ n(this->N);

    long dividir = 0;

    do {    
        ++dividir; 
        n /= 10;
    } while (n != 0);
    cout << "dividir: "<< dividir << endl;
    int i = 0;

    string transform;

    while(i < mensaje.length()){
        
        ZZ number(conv<ZZ>(mensaje.substr(i,dividir).c_str()));
        i += dividir;
        
        ZZ des = exponenciacion_mod(number, this->d, this->N);
        
        stringstream buffer;
        buffer<< des;
        string di = buffer.str();

        int tamanio = dividir-di.length() - 1;

        for (int j = 0; j < tamanio; j++){

            transform += "0";
        }
        
        transform += di;
        
    }

    cout << "transform: " << transform << endl;
    string descifrado;
    int digitos = to_string(alfabeto.length() - 1).length();
    cout << "digitos " << digitos << endl;

    for (int i = 0; i < transform.length(); i+=digitos){
        
        int pos = stoi(transform.substr(i, digitos));
    
        descifrado += alfabeto[pos];

    }
    return descifrado;
}

int main(){

    SetSeed(to_ZZ(time(0)));
    
    // // int bits = 0;
    // // RSA user01(1024);
    // // ZZ e, n;
    // // cout << "e: " ;
    // // cin >> e;
    // // cout << "N: ";
    // // cin >> n;

    // // // cout << "e: " << user01.e << endl;
    // // RSA user02(e,n);

    // // string mensaje = user02.cifrar("lazarus group");
    // // cout << "user02:" << mensaje << endl;

    // // cout << "user01:" << user01.descifrar(mensaje) << endl;

    // RSA user01(to_ZZ(17),to_ZZ(59),to_ZZ(3),to_ZZ(619));
    // RSA user02(to_ZZ(17),to_ZZ(59),to_ZZ(3),to_ZZ(619));

    // // string mensaje = user01.cifrar("hack life");
    // // cout << mensaje << endl;

    // // cout << user02.descifrar(mensaje) << endl;

    // cout << user02.exponenciacion_mod(to_ZZ(), to_ZZ(), to_ZZ()) << endl;

}   