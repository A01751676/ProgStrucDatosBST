#include "IPs.hpp"
#include "listaCircularT.hpp"

#include <iostream>
#include <string>
#include <fstream> 

using namespace std;

int leerArchivo(string nomArch, ListaCircular <IP *> &logDatos){
    int tam = 0;
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

        // se crean los objetos en el heap, regresan una direccion de memoria y la guardamos en un vector de apuntadores en el stack
        logDatos.agregarFin(new IP(//////////////////////));
        tam++;
    }
    datos.close();
    cout << "Lectura exitosa" << endl;
    return tam;
}

int main(){

}