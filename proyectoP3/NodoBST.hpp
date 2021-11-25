#ifndef NODOBST
#define NODOBST

#include <iostream>
using namespace std;

template <typename T>
class NodoBST{
    T dato;
    NodoBST<T> * izq;
    NodoBST<T> * der;
    NodoBST<T> * padre;
    int nivel;

    public:
        //getters y setters
         T getDato(){return this->dato;}
        NodoBST<T> * getIzq(){return this->izq;}
        NodoBST<T> * getDer(){return this->der;}
        NodoBST<T> * getPadre(){return this->padre;}
        int getNivel(){return this->nivel;}
        //Métodos set
        void setValor(T dato){this->dato=dato;}
        void setIzq(NodoBST<T> * izq){this->izq=izq;}
        void setDer(NodoBST<T> * der){this->der=der;}
        void setPadre(NodoBST<T> * padre){this->padre=padre;}
        void setNivel(int nivel){this->nivel = nivel;}

        //Constructores
        NodoBST(NodoBST<T> * padre, T dato, int nivel){
            this->izq=nullptr;
            this->der=nullptr;
            this->padre=padre;
            this->dato=dato;
            this->nivel=nivel;
        }
        //Destructor (delete)
        ~NodoBST(){
            cout<<"Destruccion"<<endl;
        }

        // Metodos de clase
        static void recorridoInOrder(NodoBST<T>* actual){
            if (actual){
                recorridoInOrder(actual->getIzq());
                cout << actual->getDato()->getNumAcceos() << "\t";
                //actual->getDato()->getListaIP()->imprimirLista();
                recorridoInOrder(actual->getDer());
            }
        }

        static void recorridoPreOrden(NodoBST<T>* actual){
            if (actual){
                cout << actual->getDato()->getNumAcceos() << "\t";
                //actual->getDato()->getListaIP()->imprimirLista();
                recorridoPreOrden(actual->getIzq());
                recorridoPreOrden(actual->getDer());
            }
        }

        static void recorridoPostOrden(NodoBST<T>* actual){
            if (actual){
                recorridoPostOrden(actual->getIzq());
                recorridoPostOrden(actual->getDer());
                cout << actual->getDato()->getNumAcceos() << "\t";
                //actual->getDato()->getListaIP()->imprimirLista();
            }
        }

        static NodoBST<T> * valormenor(NodoBST<T> * actual){
            if (actual){
                while(actual->getIzq()){
                    actual= actual->getIzq();
                }
            }
            return actual;
        }

        static NodoBST<T> * valormayor(NodoBST<T> * actual){
            if (actual){
                while(actual->getDer()){
                    actual= actual->getDer();
                }
            }
            return actual;
        }

};

#endif