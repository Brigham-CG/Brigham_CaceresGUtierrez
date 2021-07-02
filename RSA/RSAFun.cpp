#include <iostream>
#include <vector>
#include <ctime>
#include <NTL/ZZ.h>
#include <sstream>
#include <math.h>
#include <chrono>
#include <time.h>
#include "RSA.h"

using namespace std;
using namespace NTL;

// math 

string toBinary(ZZ n)
{
	string r;
	while (n != 0) {
		r += (n % 2 == 0 ? "0" : "1");
		n /= 2;
	}
	return r;
}

int cantDigitos(ZZ N){

    ZZ n(N);

    int dividir = 0;

    do {
        ++dividir; 
        n /= 10;
    } while (n != 0);

    return dividir;
}

ZZ modulo(ZZ(a1), ZZ (b1)) {

	ZZ r;
	if (a1 >= ZZ(0)) {
		r = a1 - ((a1 / b1) *b1);
	}
	else {
		r = a1 + abs((a1 / b1) * b1);
	}
	return r;
}

ZZ generarsemilla() {

	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();// Start clock
	cout << "Se esta generando la semilla aleatoria . . . " << endl; //Linea opcional para incrementar variabilidad de la semilla
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();// End clock

	ZZ seed(std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count());
    cout << "termino la generacion\n";
	return seed;
}

RSA::RSA(int bits){

    // SetSeed(generarsemilla());
    srand(time(0));

    this-> p = generar_primo(bits);
    
    this-> q = generar_primo(bits);
    
    this-> N = p * q;
    
    ZZ fN = (p-1)*(q-1);
    
    do{
        this-> e = generar_aleatorio(bits);
    }while(euclides(e, fN)!=1);
    
    this-> d = inversa(e, fN);

    cout << "p: " << p << endl;
    cout << "q: " << q << endl;
    cout << "N: " << N << endl;
    cout << "e: " << e << endl;
    cout << "d: " << d << endl;
}

RSA::RSA(ZZ p, ZZ q, ZZ e, ZZ d){

    this->p = p;
    this->q = q;
    this->N = p * q;
    this->e = e;
    this->d = d;
}

ZZ RSA::generar_primo(int bits){

    ZZ prime;

    for (;!miller_rabin(prime);prime = generar_aleatorio(bits));

    return prime;
}



ZZ RSA::generar_aleatorio(int bits){

    ZZ min(exponenciacion(to_ZZ(2), to_ZZ(bits))>>1), max(exponenciacion(to_ZZ(2), to_ZZ(bits)) - 1);

    ZZ number;
    do{
        number = generate_random(bits);
    }while(number < min || number > max);

    return number;
}


ZZ RSA::generate_bit() {

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();// Start clock
    // cout << "."; // Linea important para incrementar la variabilidad
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();// End clock

    ZZ seed(std::chrono::duration_cast<std::chrono::microseconds> (end - begin).count());

    ZZ seed_2 = modulo(seed, ZZ(2));

    return seed_2;
}

ZZ RSA::generate_random(int bits) {
	ZZ random(0);
	ZZ power(2);
	random = random + (generate_bit());
	for (int i = 1;i<bits;i++) {
		random = random + (generate_bit()*power);
		power = power * 2;
	}
    cout << "random: " << random << endl;
	return random;
}


RSA::RSA(ZZ e, ZZ N){
    // put values
    this->e = e;
    this->N = N;
}

vector<ZZ> RSA::euclides_extendido(ZZ a, ZZ b)
{   
    // a >= b
    // numbers[0] -> x
    // numbers[1] -> y
    // numbers[2] -> d

    vector<ZZ> numbers(3);
    if (b == 0)
    {
        numbers[0]= 1;
        numbers[1] = 0;
        numbers[2] = a;
    }

    ZZ x2(1), x1(0), y2(0), y1(1);
    while(b > 0)
    {
        ZZ q = a / b;
        ZZ r = a - q*b;
        numbers[0] = x2 - q*x1;
        numbers[1] = y2 - q*y1;
        a = b;
        b = r;
        x2 = x1;
        x1 = numbers[0];
        y2 = y1;
        y1 = numbers[1];
    }

    numbers[2] = a;
    numbers[0] = x2;
    numbers[1] = y2;
    
    return numbers;
}

ZZ RSA::restoChino(ZZ c, ZZ d, ZZ N)
{

    vector <ZZ> a = {left_to_right_binary_exponenciacion(c,modulo(d, p - 1), N), left_to_right_binary_exponenciacion(c,modulo(d, q- 1), N)};

    vector<ZZ> inversos = euclides_extendido(p, q);

    return modulo(a[0]*q*modulo(inversos[1],N) + a[1]*p*modulo(inversos[0],N), N);
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

ZZ RSA::left_to_right_binary_exponenciacion(ZZ a, ZZ e, ZZ n) {
	ZZ A(1);
	string bin = toBinary(e);
	for (int i = bin.size(); i != -1; i--) {
		A = modulo(A * A, n);
		if (bin[i] == '1') {
			A = modulo(A * a, n);
		}
	}
	return A;
}

bool RSA::miller_rabin(ZZ n){
    
    if ((n & 1) == 0){
        return false;
    }
    ZZ s(0);
    ZZ t = n - 1;
    while ((t & 1) == 0) {
        s++;
        t >>= 1;
    }
    ZZ a(2);
    for (int i = 0; i < 10; i++){

        ZZ x = left_to_right_binary_exponenciacion(a, t, n);
        if (x == 1 || x == (n-1))
            continue;
        for (ZZ r(0); r < (s-1); r++){
            x = left_to_right_binary_exponenciacion(x, to_ZZ(2), n);
            if(x == 1){
                return false;
            }
            else if(x == n - 1)
                break;
        }
        if(x != n - 1 )
            return false;
        ZZ a = RandomBnd(n-3) + 3;
    }
    
    return true;
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

ZZ RSA::inversa(ZZ e, ZZ N){

    ZZ inversa = euclides_extendido(e, N)[0];
    if (inversa < 0){
        inversa = modulo(euclides_extendido(e, N)[0], N);
    }
    return inversa;
}

string ZZ_to_string(ZZ num)
{
    stringstream buffer;

    buffer<<num;

    return buffer.str();  
};

string RSA::cifrar(string mensaje){

    string transform;

    // obtener la cantidad de digitos de N
    int cantN = ZZ_to_string(N).length();

    cantN--;

    // cantidad de digitos del alfabeto

    int cantA = to_string(alfabeto.length() - 1).length();

    // separando en numeros

    for (int i = 0; i < mensaje.length(); i ++){

        string pos = to_string(alfabeto.find(mensaje[i]));

        int tamanio = cantA-pos.length();

        transform.append(tamanio, '0');
        transform +=pos;
    
    }
    
    // tamaño de alfabeto
    string alfLen = to_string(alfabeto.length());

    // dividir

    while(modulo(to_ZZ(transform.size()), to_ZZ(cantN)) != 0){

        transform+=alfLen;
    }

    cout << "transform: " << transform << endl;
    // exponenciacion
    
    string cifrado;
    
    for (int i = 0; i < transform.length(); i += cantN)
    {  
        ZZ number(conv<ZZ>(transform.substr(i,cantN).c_str()));
        
        ZZ exp = left_to_right_binary_exponenciacion(number, e, N);
        string ci = ZZ_to_string(exp);
        int tamanio = cantN-ci.length()+1;
        
        cifrado.append(tamanio, '0');

        cifrado +=ci;
    }
    
    return cifrado;
}

string RSA::descifrar(string mensaje){

    // obtener la cantidad de digitos de N

    int cantN = ZZ_to_string(N).length();
    
    // exponenciacion

    string transform;

    for (int i = 0; i < mensaje.length(); i+=cantN)
    {
        ZZ number(conv<ZZ>(mensaje.substr(i,cantN).c_str()));
        ZZ des = restoChino(number, d, N);

        string di = ZZ_to_string(des);

        int tamanio = cantN-di.length()-1;

        transform.append(tamanio, '0');

        transform += di;
    }
    // cantidad de digitos del alfabeto
    cout << "transform: " << transform << endl;

    int cantA = to_string(alfabeto.length() - 1).length();

    // tamaño de alfabeto
    string alfLen = to_string(alfabeto.length());
    int fin = transform.find(alfLen);

    transform = transform.substr(0, fin);

    // separando en numeros
    string descifrado;

    for (int i = 0; i < transform.length(); i+=cantA){
        
        int pos = stoi(transform.substr(i, cantA));
        char carc = alfabeto[pos];

        descifrado += carc;
    }
    return descifrado;
}

ZZ RSA::getE()
{
    return e;   
}

ZZ RSA::getN()
{   
    return N;
}