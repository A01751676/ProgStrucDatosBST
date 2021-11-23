#include "nodoT.hpp"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

template <typename T>
class ListaSimple{
    //Atributos
    private:
    NodoT<T> * head;
    int tam;

    public:
    void setNodo(NodoT<T> * head){this->head = head;}
    void setTam(int tam){this->tam = tam;}

    NodoT<T> * getNodo(){return this-> head;}
    int getTam(){return this-> tam;}

    NodoT<T> * getHead(){return this->head;}
    void setHead(NodoT<T> * head){this->head = head;}

    ListaSimple(){
        this->head = nullptr;
        this->tam = 0;
    }

    // CRUD

    void agregarInicio(T valor){
        //Crear nuevo nodo y actualizar referrencia
        NodoT<T> * nuevo = new NodoT<T>(valor,this->head);
        //Actualizar el head de la lista a l nuevo nodo
        this-> head = nuevo;
        //Actualizar tam
        this->tam ++;

    }

    void agregarFinal(T valor){
        //crear el nuevo nodo
        // verificiar caso: lista vacia o con valores
        if(this->head){
            //Lista  con valores
            //agregar el nuevo nodo
            NodoT<T> *  ptr = this->head;
            
            while (ptr->getNodoSig()){
                ptr = ptr->getNodoSig();
            }
            
            NodoT<T> * nuevo = new NodoT<T>(valor,nullptr);
            ptr->setNodoSig(nuevo);
        }
        else {
            //Lista sin valores
            // head es igual a nuevo nodo 
            //Crear nuevo nodo y actualizar referrencia
            NodoT<T> * nuevo = new NodoT<T>(valor,this->head);
            //Actualizar el head de la lista a l nuevo nodo
            this-> head = nuevo;
        }
        //Actualizar el tam
        this->tam ++;

    }

    void imprimirLista(){
        NodoT<T> * nodo = this->head;
        while(nodo){
            cout << nodo->getDato() << " ";
            nodo = nodo->getNodoSig();
        }
        cout << endl;
    }

    NodoT<T> * buscarNodo(T dato){
        NodoT<T> * nodo = this->head;
        while(nodo){
            if (nodo->getDato() == dato)
            return nodo;

            nodo = nodo->getNodoSig();
        }
        return nullptr;
    }

    int buscarIndice(T dato){
        if(!this->head){
            return -1;
        }

        NodoT<T> * nodo = this->head;
        int ctr = 0;
        while(nodo){
            if (nodo->getDato() == dato){
                return ctr;
            }

            nodo = nodo->getNodoSig();
            ctr ++;
        }
        return -1;
    }

    NodoT<T> * nodoEnIndice(int ctr){
        NodoT<T> * nodo = this->head;
        int i = 0;
        while(i < ctr){
            nodo = nodo->getNodoSig();
        }
        return nodo;
    }

    
};