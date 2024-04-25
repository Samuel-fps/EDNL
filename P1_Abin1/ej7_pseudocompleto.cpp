
#include "../TAD_ABIN/ABinEnla.h" // Importamos el arbol binario
using namespace std;

//////////// Esta parte es solo para poder leer los arboles de los ficheros
#include <iostream>
#include <fstream>

#include "abin_E-S.h"
typedef char tElto;
const tElto fin = '#';
////////////////////////////////////

/*
    EJERCICIO 7
    Implementa un subprograma que determine si un árbol binario es o no pseudocompleto.
    En este problema entenderemos que un árbol es pseudocompleto, si en el penúltimo nivel
    del mismo cada uno de los nodos tiene dos hijos o ninguno.
*/

template <typename T>
bool esPseudocompleto_rec(Abin<T> A, typename Abin<T>::nodo n){
    if(n == Abin<T>::NODO_NULO)
        return true;
    else if(A.altura(n) == 1 
            && A.hijoIzqdo(n) == Abin<T>::NODO_NULO && A.hijoDrcho(n) != Abin<T>::NODO_NULO
            || A.hijoIzqdo(n) != Abin<T>::NODO_NULO && A.hijoDrcho(n) == Abin<T>::NODO_NULO)
        return false;
    else
        return esPseudocompleto_rec(A, A.hijoIzqdo(n)) || esPseudocompleto_rec(A, A.hijoDrcho(n));
}

template <typename T>
bool esPseudocompleto(Abin<T> A){
    return esPseudocompleto_rec(A, A.raiz());
}

int main(){
    // Leer Arbol del fichero
    Abin<tElto> A, B;
    ifstream fa("abin.dat"); // Abrir fichero de entrada de un arbol no completo
    rellenarAbin(fa, A); // Desde fichero.
    fa.close();
     ifstream fb("abinCompleto.dat"); // Abrir fichero de entrada de un arbol completo
    rellenarAbin(fb, B); // Desde fichero.
    fb.close();

    // Llamada a la funcion del ejercicio
    if(esPseudocompleto(A))
        cout << "El arbol A es pseudocompleto" << endl;
    else
        cout << "El arbol A NO es pseudocompleto" << endl;
    
    if(esPseudocompleto(B))
        cout << "El arbol B es pseudocompleto" << endl;
    else
        cout << "El arbol B NO es pseudocompleto" << endl;

    //cout << "\n*** Mostrar árbol binario A ***\n";
    //imprimirAbin(A); // En std::cout

    return 0;
}