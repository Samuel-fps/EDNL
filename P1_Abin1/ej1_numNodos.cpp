#include <iostream>
#include <fstream>

#include "../TAD_ABIN/ABinEnla.h"
#include "abin_E-S.h"

using namespace std;
typedef char tElto;
const tElto fin = '#'; // Fin de lectura.

/*  EJERCICIO 1 - Número de nodos

    Implementa un subprograma que calcule el número de nodos de un árbol binario. 
*/

template <typename T>
int numNodos_rec(const Abin<T>& A, const typename Abin<T>::nodo& n){
    if(n == Abin<T>::NODO_NULO)
        return 0;
    else
        return 1 + numNodos_rec(A, A.hijoIzqdo(n)) + numNodos_rec(A, A.hijoDrcho(n));
}

template <typename T>
int numNodos(const Abin<T>& A){
    return numNodos_rec(A, A.raiz());
}

int main(){
    Abin<tElto> A;
    cout << "\n*** Lectura de árbol binario B de abin.dat ***\n";
    ifstream fe("abin.dat"); // Abrir fichero de entrada.
    rellenarAbin(fe, A); // Desde fichero.
    fe.close();

    cout << "El arbol tiene " << numNodos(A) << " nodos." << endl;

    return 0;
}