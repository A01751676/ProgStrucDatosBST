#include "BST.hpp"

int main(){
    BST<int> * arbol= new BST<int>();
    arbol->agregarNodo(21);
    arbol->agregarNodo(13);
    arbol->agregarNodo(10);
    arbol->agregarNodo(18);
    arbol->agregarNodo(33);
    arbol->agregarNodo(25);
    arbol->agregarNodo(40);

    arbol->imprimirInOrder();
    arbol->imprimirPreOrden();
    arbol->imprimirPostOrden();
    /*
    arbol->eliminarNodo(18);
    arbol->imprimirInOrder();

    arbol->eliminarNodo(13);
    arbol->imprimirInOrder();

    arbol->eliminarNodo(33);
    arbol->imprimirInOrder();*/

    cout << arbol->whatlevelamI(25) << endl;
    arbol->visit(1);
    arbol->visit(2);
    arbol->visit(3);
    cout << arbol->height() << endl;
    return 0;
}