#include "../TAD_ABB/abb.h" // Importamos el arbol binario
using namespace std;

//////////// Esta parte es solo para poder leer los arboles de los ficheros
#include <iostream>
#include <fstream>

#include "abb_E-S.h"
typedef int tElto;
const tElto fin = '#';
////////////////////////////////////

/*  EJERCICIO 4 REPASAR ELIMINAR

    Dados dos conjuntos representados mediante árboles binarios de búsqueda,
    implementa la operación intersección de dos conjuntos, que devuelva como resultado
    otro conjunto que sea la intersección de ambos. El resultado debe quedar en un árbol
    equilibrado.
*/

template <typename T>
using Conjunto = Abb<T>;

// Dos implementaciones de la operación pertenece por si no quieres usar la operación buscar

/* OPCION 1 Usar el método buscar de la clase abb
template <typename T>
bool pertenece(const Conjunto<T>& A, const T& elto){
    if(A.buscar(elto) == Conjunto<T>::NODO_NULO)
        return false;
    return true;
}  
*/

// OPCION 2 Buscar el elemento sin usar operacion buscar()
template <typename T>
bool pertenece(Conjunto<T> A, const T& elto){
    if(A.vacio())
        return false
    else{
        if(A.elemento() == elto)
            return true;
        else
            return pertenece(A.izqdo(), elto) || pertenece(A.drcho(), elto);
    }
}

template <typename T>
Conjunto<T> interseccionAbb(const Conjunto<T>& A, Conjunto<T> B){
    Conjunto<T> res;
    T elto = B.elemento();

    while(B.vacio()){
        if(pertenece(A, elto)) // Si el elemento de B pertenece a A lo insertamo en el resultado
            res.insertar(B.elemento());
        elto = B.eliminar()
    }
    return res;
}
