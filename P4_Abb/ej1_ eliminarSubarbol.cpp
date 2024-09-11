#include "../TAD_ABB/abb.h" // Importamos el arbol binario
using namespace std;

//////////// Esta parte es solo para poder leer los arboles de los ficheros
#include <iostream>
#include <fstream>

#include "abb_E-S.h"
typedef int tElto;
const tElto fin = '#';
////////////////////////////////////

/*  EJERCICIO 1

    Implementa una nueva operación del TAD Abb que tomando un elemento del mismo
    elimine al completo el subárbol que cuelga de él.
*/

template <typename T>
void eliminarSubarbol(Abb<T>& A){
    if(!A.izqdo().vacio())
        eliminarSubArbol(A.izqdo());
    if(!A.drcho().vacio())
        eliminarSubArbol(A.drcho());
    else
        A.eliminar(A.elemento());
}

template <typename T>
void eliminarSubarbolElto(Abb<T>& A, const T& elto){
    eliminarSubarbol(A.buscar(elto));
}
