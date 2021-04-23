#include <iostream>

using namespace std;

class Cesar{

    public:

        int password = 0;
        
        string encrypted(string message);

        string decrypted(string message);
};

string break_cesar(string cadena);