
#include "../TAD_ABIN/ABinC.h" // Importamos el arbol binario
using namespace std;

//////////// Esta parte es solo para poder leer los arboles de los ficheros
#include <iostream>
#include <fstream>

#include "abin_E-S.h"
typedef char tElto;
const tElto fin = '#';
////////////////////////////////////

/*
    EJERCICIO 2
    Implementa un subprograma que calcule la altura de un árbol binario.
*/

#include <algorithm> // Para usar std::max()

template <typename T>
int alturaArbol_rec(const Abin<T> A, const typename Abin<T>::nodo n){
    if(n == Abin<T>::NODO_NULO)
        return -1;
    else
        return 1 + std::max(alturaArbol_rec(A, A.hijoIzqdo(n)), alturaArbol_rec(A, A.hijoDrcho(n)));
}

template <typename T>
int alturaArbol(Abin<T> A){
    return alturaArbol_rec(A, A.raiz());
}


// Probar funcion
int main(){
    Abin<tElto> A;
    cout << "\n*** Lectura de árbol binario B de abin.dat ***\n";
    ifstream fe("abin.dat"); // Abrir fichero de entrada.
    rellenarAbin(fe, A); // Desde fichero.
    fe.close();

    cout << "El arbol tiene una altura de " << alturaArbol(A) << endl;

    //cout << "\n*** Mostrar árbol binario A ***\n";
    //imprimirAbin(A); // En std::cout

    return 0;
}