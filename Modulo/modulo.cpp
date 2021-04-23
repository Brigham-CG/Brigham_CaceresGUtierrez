#include<iostream>

using namespace std;

int modulo(int a, int n){

    int base = a - (a/n) * n;
    
    if (base == 0){
        return 0;
    }
    else if (base > 0){
        if ( n >= 0)
            return base;
        else
            return base + n;    
    }
    else
        if (n >= 0)
            return base + n;
        else
            return base;
}

int main(){
    int a, n;
    cout << "ingrese a: "; cin >> a;
    cout << "ingrese n: "; cin >> n;
    cout << "a mod n = " << modulo(a, n) << endl;
}