
#include "../../TAD_ABIN/ABinC.h" // Importamos el arbol binario
using namespace std;

//////////// Esta parte es solo para poder leer los arboles de los ficheros
#include <iostream>
#include <fstream>

#include "../abin_E-S.h"
typedef char tElto;
const tElto fin = '#';
////////////////////////////////////

/*
    EJERCICIO 3
    Implementa un subprograma que, dados un árbol binario y un nodo del mismo, determine
    la profundidad de este nodo en dicho árbol.
*/

template <typename T>
int profundidadNodo(const Abin<T>& A, typename Abin<T>::nodo n){
    if(n == A.raiz())
        return 0;
    else
        return 1 + profundidadNodo(A, A.padre(n));
}

int main(){
    // Leer árbol del fichero
    Abin<tElto> A;
    cout << "\n*** Lectura de arbol binario B de abin.dat ***\n";
    ifstream fe("abin.dat"); // Abrir fichero de entrada.
    rellenarAbin(fe, A); // Desde fichero.
    fe.close();

    Abin<char>::nodo raiz = A.raiz(); // Obtén la referencia al nodo raíz.
    cout << "El nodo raiz tiene una profundidad de " << profundidadNodo(A, raiz) << endl;

    Abin<char>::nodo hijoDerecho = A.hijoDrcho(raiz); // Obtén el hijo derecho de la raíz.
    cout << "El nodo hijoDerecho de la raiz tiene una profundidad de " << profundidadNodo(A, hijoDerecho) << endl;
    
    Abin<char>::nodo hijoIzquierdo = A.hijoIzqdo(hijoDerecho); // Obtén el hijo izquierdo con profundidad 2
    cout << "El nodo hijo izquiero del hijoDerecho de la raiz tiene una profundidad de " << profundidadNodo(A, hijoIzquierdo) << endl;

    //cout << "\n*** Mostrar árbol binario A ***\n";
    //imprimirAbin(A); // En std::cout

    return 0;
}