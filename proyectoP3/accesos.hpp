#include "listaSimple.hpp"
#include <string>

using namespace std;

class Accesos{
    int numAccesos;
    ListaSimple<string>* listaIP;

    void setNumAcceos(int numAccesos){this->numAccesos = numAccesos;}
    int getNumAcceos(){return this->numAccesos;}

    ListaSimple<string>*  getListaIP(){return this->listaIP;}

};