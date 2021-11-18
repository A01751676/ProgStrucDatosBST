#include "BST.hpp"

int main(){
    BST<int> * arbol= new BST<int>();

    //generamos un arbol BST valido con la siguiente estructura
    //                      21
    //                 13          33
    //             10     18    25     40

    arbol->agregarNodo(21);
    arbol->agregarNodo(13);
    arbol->agregarNodo(10);
    arbol->agregarNodo(18);
    arbol->agregarNodo(33);
    arbol->agregarNodo(25);
    arbol->agregarNodo(40);

    cout << endl; cout << "--------------- PRIMER CASO DE PRUEBA ---------------" << endl; cout << endl;

    // probar visit
    cout << "Recorrido en preorden: ";
    arbol->visit(1);
    cout << "Recorrido en postorden: ";
    arbol->visit(2);
    cout << "Recorrido por nivel: ";
    arbol->visit(3);

    // probar height
    cout << "Numero de niveles del arbol: ";
    cout << arbol->height() << endl;

    // probar antesesor
    cout << "El antesesor del 33 es el: ";
    cout << arbol->antecesor(33)->getDato() << endl;

    // probar what level am I
    cout << "El 25 esta en el nivel: ";
    cout << arbol->whatlevelamI(25) << endl;

    cout << endl; cout << endl;

    // agregamos y eliminamos cosas del arbol 
    arbol->eliminarNodo(13);
    arbol->eliminarNodo(40);
    arbol->agregarNodo(-1);
    arbol->agregarNodo(-25);

    //                      21
    //                 18          33
    //             10          25
    //          -1
    //      -25

    cout << endl; cout << "--------------- SEGUNDO CASO DE PRUEBA ---------------" << endl; cout << endl;
    
    // probar visit
    cout << "Recorrido en preorden: ";
    arbol->visit(1);
    cout << "Recorrido en postorden: ";
    arbol->visit(2);
    cout << "Recorrido por nivel: ";
    arbol->visit(3);

    // probar height
    cout << "Numero de niveles del arbol: ";
    cout << arbol->height() << endl;

    // probar antesesor
    cout << "El antesesor del -1 es el: ";
    cout << arbol->antecesor(-1)->getDato() << endl;

    // probar what level am I
    cout << "El 10 esta en el nivel: ";
    cout << arbol->whatlevelamI(10) << endl;

    cout << endl; cout << endl;


    // agregamos y eliminamos cosas del arbol 
    arbol->eliminarNodo(21);
    arbol->agregarNodo(22);
    arbol->eliminarNodo(33);
    arbol->agregarNodo(8);
    arbol->agregarNodo(80);
    arbol->agregarNodo(56);
    arbol->agregarNodo(32);

    //                      25
    //                 18        80
    //             10         56      
    //          -1    22    32
    //      -25   8

    cout << endl; cout << "--------------- TERCER CASO DE PRUEBA ---------------" << endl; cout << endl;
    
    // probar visit
    cout << "Recorrido en preorden: ";
    arbol->visit(1);
    cout << "Recorrido en postorden: ";
    arbol->visit(2);
    cout << "Recorrido por nivel: ";
    arbol->visit(3);

    // probar height
    cout << "Numero de niveles del arbol: ";
    cout << arbol->height() << endl;

    // probar antesesor
    cout << "El antesesor del 56 es el: ";
    cout << arbol->antecesor(56)->getDato()<< endl;

    // probar what level am I
    cout << "El 18 esta en el nivel: ";
    cout << arbol->whatlevelamI(18) << endl;

    cout << endl; cout << endl;

    // agregamos y eliminamos cosas del arbol 
    arbol->eliminarNodo(10);
    arbol->agregarNodo(-30);
    arbol->eliminarNodo(8);
    arbol->agregarNodo(100);

    //                      25
    //                 18        80
    //             10         56      
    //          -1    22    32
    //      -25   8

    cout << endl; cout << "--------------- CUARTO CASO DE PRUEBA ---------------" << endl; cout << endl;
    
    // probar visit
    cout << "Recorrido en preorden: ";
    arbol->visit(1);
    cout << "Recorrido en postorden: ";
    arbol->visit(2);
    cout << "Recorrido por nivel: ";
    arbol->visit(3);

    // probar height
    cout << "Numero de niveles del arbol: ";
    cout << arbol->height() << endl;

    // probar antesesor
    cout << "El antesesor del 18 es el: ";
    cout << arbol->antecesor(18)->getDato()<< endl;

    // probar what level am I
    cout << "El -30 esta en el nivel: ";
    cout << arbol->whatlevelamI(-30) << endl;

    cout << endl; cout << endl;

    return 0;
}