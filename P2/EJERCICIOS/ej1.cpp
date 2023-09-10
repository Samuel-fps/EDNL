
#include "../../TAD_ABIN/ABinC.h" // Importamos el arbol binario
using namespace std;

//////////// Esta parte es solo para poder leer los arboles de los ficheros
#include <iostream>
#include <fstream>

#include "../abin_E-S.h"
typedef char tElto;
const tElto fin = '#';
////////////////////////////////////

/*  EJERCICIO 1 - Similares

    Dos árboles binarios son similares cuando tienen idéntica estructura de ramificación,
    es decir, ambos son vacíos, o en caso contrario, tienen subárboles izquierdo y derecho
    similares. Implementa un subprograma que determine si dos árboles binarios son
    similares.
*/

template <typename T>
bool abinSimilares_rec(Abin<T> A, Abin<T> B, typename Abin<T>::nodo nA, typename Abin<T>::nodo nB){
    if(nA == Abin<T>::NODO_NULO && nB == Abin<T>::NODO_NULO) // Los dos son nulos
        return true;
    else if(nA == Abin<T>::NODO_NULO || nB == Abin<T>::NODO_NULO) // Uno es nulo y el otro no (por el if anteriro sabemos que no son los dos nulos)
        return false;
    else // Ninguno es nulo
        return abinSimilares_rec(A, B, A.hijoIzqdo(nA), B.hijoDrcho(nB)) 
            && abinSimilares_rec(A, B, A.hijoDrcho(nA), B.hijoIzqdo(nB));
}

template <typename T>
bool abinSimilares(Abin<T> A, Abin<T> B){
    return  abinSimilares_rec(A, B, A.raiz(), B.raiz());
}

int main(){
    // Leer Arbol del fichero
    Abin<tElto> A, B;

    ifstream fa("arbolA.dat"); // Abrir fichero de entrada.
    rellenarAbin(fa, A); // Desde fichero.
    fa.close();

    ifstream fb("arbolB.dat"); // Abrir fichero de entrada.
    rellenarAbin(fb, B); // Desde fichero.
    fb.close();

    // Llamada a la funcion del ejercicio
    if(abinSimilares(A, A))
        cout << "CORRECTO El arbol A es similar a si mismo." << endl;
    else
        cout << "INCORRECTO El arbol A es debe ser similar a si mismo." << endl;
    if(abinSimilares(A, B))
        cout << "INCORRECTO El arbol A no debe ser similar a B." << endl;
    else 
        cout << "CORRECTO El arbol A y el B no seon similares." << endl;

    //cout << "\n*** Mostrar árbol binario A ***\n";
    //imprimirAbin(A); // En std::cout

    return 0;
}