#include "NodoBST.hpp"
#include "fila.hpp"

template <typename T>
class BST{
    NodoBST<T> * raiz;
    int numNodos;
    public:
        //getters y setters
        NodoBST<T> * getRaiz(){return this->raiz;}
        void setRaiz(NodoBST<T> * raiz){this->raiz=raiz;}
        int getNumNodos(){return this->numNodos;}
        void setNumNodos(int numNodos){this->numNodos=numNodos;} 
        //constructor
        BST(){
            this->raiz=nullptr;
            this->numNodos=0;
        }
        ~BST(){

        }

        void agregarNodo(T dato){
            NodoBST<T> * actual= this->raiz;
            NodoBST<T> * padre;
            int nivel = 0;
            if(this->raiz){//Arbol no vacio
                if(this->buscarNodo(dato)) //Nodo encontrado
                    cout<<"Nodo existente"<<endl;                
                else{ //Nodo inexistente, 
                    //Encontrar al nodo padre
                    while(actual){
                        padre=actual;
                        //Relacion de orden de los nodos
                        if(dato<actual->getDato())
                            actual=actual->getIzq();
                        else
                            actual=actual->getDer();
                        nivel++;
                    }
                    //Colocar el nuevo nodo
                    padre->getDato()>dato?padre->setIzq(new NodoBST<T>(padre,dato,nivel)):padre->setDer(new NodoBST<T>(padre,dato,nivel));
                    this->numNodos++;
                }
            }else{//Arbol vacio
                this->raiz = new NodoBST<T>(nullptr,dato, nivel);
                this->numNodos++;
                }
            
            return; //opcional
        }
        NodoBST<T> * buscarNodo(T dato){
            //Primer paso crear el apuntador a nodo raiz
            NodoBST<T> * actual = this->raiz;
            while(actual){
                //Si el nodo actual es el valor que busco
                if(actual->getDato()==dato)
                    return actual;
                else//cond?opc_verdadera:opc_falsa
                    actual=actual->getDato()>dato?actual->getIzq():actual->getDer();
            }
            return nullptr; //return actual;
        }

        void imprimirInOrder(){
            NodoBST<T>::recorridoInOrder(this->raiz);
            cout << endl;
        }

        void imprimirPreOrden(){
            NodoBST<T>::recorridoPreOrden(this->raiz);
            cout << endl;
        }

        void imprimirPostOrden(){
            NodoBST<T>::recorridoPostOrden(this->raiz);
            cout << endl;
        }

        void eliminarNodo(T dato){
            NodoBST<T> * eliminar = this->buscarNodo(dato);
            NodoBST<T> * padre = nullptr;

            if(eliminar){
                padre = eliminar->getPadre();

                // caso 1: eliminar raiz
                if(!eliminar->getIzq() && !eliminar->getDer()){
                    if(!padre){ // si es nodo raiz
                        this->raiz = nullptr;
                    }

                    else if (padre->getDato() > eliminar->getDato()){ // nodo hoja es hijo izq
                        padre->setIzq(nullptr);
                    }

                    else{ // nodo hoja es hijo derecho
                        padre->setDer(nullptr); 
                    }

                    this->numNodos--;
                    delete(eliminar);
                }

                // Caso 2: Eliminar nodo con 1 hijo
                
                else if(eliminar->getIzq() && !eliminar->getDer()){ // hijo izquierdo
                    if (!padre){
                        this->raiz = eliminar->getIzq();
                    }
                    else if (padre->getDato() > eliminar->getDato()){ // eliminar es izquierdo
                        padre->setIzq(eliminar->getIzq()); // izq izq
                    }
                    else{
                        padre->setDer(eliminar->getIzq());
                    }

                    eliminar->getIzq()->setPadre(padre);
                    eliminar->getIzq()->setNivel(padre->getNivel()+1);
                    delete(eliminar);
                    numNodos --;
                }

                else if (!eliminar->getIzq() && eliminar->getDer()){ // hijo derecho
                    
                    if (!padre){
                        this->raiz = eliminar->getDer();
                    }
                    else if (padre->getDato() > eliminar->getDato()){ // eliminar es izquierdo
                        padre->setDer(eliminar->getDer()); 
                    }
                    else{
                        padre->setIzq(eliminar->getDer());
                    }

                    eliminar->getDer()->setPadre(padre);
                    eliminar->getDer()->setNivel(padre->getNivel()+1);
                    delete(eliminar);
                    numNodos --;

                }

                else{ //  Caso 3: tiene dos hijos

                    // encontrar el sucesor
                    NodoBST<T> * sucesor = NodoBST<T>::valormenor(eliminar->getDer());
                    eliminar->setValor(sucesor->getDato());

                    if(sucesor->getPadre()->getIzq() == sucesor){
                        if (sucesor->getDer()){
                            sucesor->getPadre()->setIzq(sucesor->getDer());
                            sucesor->getDer()->setPadre(sucesor->getPadre());
                        }
                        else{
                            sucesor->getPadre()->setIzq(nullptr);
                        }
                    }

                    else if (sucesor->getDer()){
                            sucesor->getPadre()->setDer(sucesor->getDer());
                            sucesor->getDer()->setPadre(sucesor->getPadre());
                        }
                    else{
                        sucesor->getPadre()->setDer(nullptr);
                    }
                    delete(sucesor);
                }
                numNodos--;
            }
            else{
                cout << "Valor inexistente" << endl;
            }
        }

        int whatlevelamI(T dato){
            if (this->buscarNodo(dato)){
                return this->buscarNodo(dato)->getNivel();
            }
            else{
                return -1;
            }
        }

        NodoBST<T>* antecesor(T dato){
            if(this->buscarNodo(dato)){
                return NodoBST<T>::valormayor(this->buscarNodo(dato)->getIzq());
            }
            else{return nullptr;}
        }

        NodoBST<T>* sucesor(T dato){
            if(this->buscarNodo(dato)){
                return NodoBST<T>::valormenor(this->buscarNodo(dato)->getDer());
            }
            else{return nullptr;}
        }

        void byLevel(){
            Fila<NodoBST<T>*> fila;
            NodoBST<T>* dato = this->raiz;
            
            if(dato){
                fila.push(dato);
                while(fila.front()){
                    
                    dato = fila.pop()->getDato();
                    cout << dato->getDato() << " ";
                    
                    if (dato->getIzq()){
                        fila.push(dato->getIzq());
                    }

                    if (dato->getDer()){
                        fila.push(dato->getDer());
                    }
                    
                }
                
                cout << endl;
            }
            else{
                cout << "arbol vacio" << endl;
            }
            
        }

        int heightAux (NodoBST<T>* actual){
            if (actual){
                int izq = heightAux(actual->getIzq());
                int der = heightAux(actual->getDer());
                if (izq > der){
                    return izq +1;
                }
                else{
                    return der +1;
                }
            }
            else{
                return 0;
            }
        
        }

        int height(){
            return heightAux(this->raiz);
        }

        void visit(int opt){
            if (opt == 1){this->imprimirPreOrden();}
            else if (opt == 2){this->imprimirPostOrden();}
            else if (opt == 3){this->byLevel();}
            else{}
        }
};