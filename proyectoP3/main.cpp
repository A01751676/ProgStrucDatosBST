#include "IPs.hpp"
#include "listaCircularT.hpp"
#include "listaSimple.hpp"
#include "accesos.hpp"

#include <iostream>
#include <string>
#include <fstream> 
#include <vector>

using namespace std;

void leerArchivo(string nomArch, ListaSimple<string>* &IP, ListaSimple<int>*  &veces){

    // --- Lectura de archivos separada
    ifstream datos;
    datos.open(nomArch);
    string mes, dia, hora, ipp, falla;

    while (datos.good()){
        getline(datos, mes,' ');
        getline(datos, dia,' ');
        getline(datos, hora,' ');
        getline(datos, ipp,' ');
        getline(datos, falla);

        ipp.pop_back();
        ipp.pop_back();
        ipp.pop_back();
        ipp.pop_back();
        ipp.pop_back();

        cout << ipp << endl;
        
        if (IP->getHead()){
            // significa que existe un registro 
            cout << "CASO 1" << endl;

            int indice = IP->buscarIndice(ipp);
            cout << indice << endl;

            if (indice == -1){
                cout << "Caso 2" << endl;
                // significa que no hay registro 
                IP->agregarFinal(ipp);
                veces->agregarFinal(1);
                cout << "1" << endl;
            }

            else{
                cout << "CASO 3" << endl;
                int ctrIP = veces->nodoEnIndice(indice)->getDato();
                cout << ctrIP << endl;
                veces->nodoEnIndice(indice)->setDato(ctrIP + 1);
            }

        }

        else{
            // significa que no hay registro 
            IP->agregarFinal(ipp);
            veces->agregarFinal(1);
            cout << "1" << endl;
        }

    }
    datos.close();
    cout << "Lectura exitosa" << endl;
    
}

void imprimirDosListasArchivo(string nomArch, ListaSimple<string>* lista1, ListaSimple<int>* lista2){
        if (lista1->getTam() != lista2->getTam()){
            cout << "las listas son de diferente tamaño" << endl;
            return;
        }

        ofstream miArchivo(nomArch + ".txt");
        NodoT<string> * nodoLista1 = lista1->getHead();
        NodoT<int> * nodoLista2 = lista2->getHead();

        miArchivo << "IP\t\t\t\t\t\t" << "Ocurrecia   " << endl;
        while(nodoLista1){

            miArchivo << nodoLista1->getDato() << "\t\t\t" << nodoLista2->getDato() << endl;
            cout << nodoLista1->getDato() << "\t\t\t" << nodoLista2->getDato() << endl;
            nodoLista1 = nodoLista1->getNodoSig();
            nodoLista2 = nodoLista2->getNodoSig();
        }
        miArchivo.close();
        cout << endl;
    }

int main(){

    ListaSimple<string>* IP = new ListaSimple<string>();
    ListaSimple<int>*  veces = new ListaSimple<int>();

    leerArchivo("bitacoraPrueba.txt",IP, veces);
    imprimirDosListasArchivo("Informacion IP y Ocurrencia", IP, veces);
}