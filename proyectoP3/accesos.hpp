#ifndef ACCESOS
#define ACCESOS
#include "listaSimple.hpp"
#include <string>

using namespace std;

class Accesos{
    int numAccesos;
    ListaSimple<string>* listaIP;

    public:
    
    void setNumAcceos(int numAccesos){this->numAccesos = numAccesos;}
    int getNumAcceos(){return this->numAccesos;}

    ListaSimple<string>*  getListaIP(){return this->listaIP;}

    Accesos(){
        this->numAccesos = 0;
        this->listaIP = new ListaSimple<string>();
    }

};

#endif