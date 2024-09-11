#include "../TAD_ABB/abb.h" // Importamos el arbol binario
using namespace std;

//////////// Esta parte es solo para poder leer los arboles de los ficheros
#include <iostream>
#include <fstream>

#include "abb_E-S.h"
typedef int tElto;
const tElto fin = '#';
////////////////////////////////////

/*  EJERCICIO 3

    Dados dos conjuntos representados mediante árboles binarios de búsqueda,
    implementa la operación unión de dos conjuntos que devuelva como resultado otro
    conjunto que sea la unión de ambos, representado por un ABB equilibrado.
*/

template <typename T>
using Conjunto = Abb<T>;

template <typename T>
Conjunto<T> unionAbb(const Conjunto<T>& A, Conjunto<T> B){
    Conjunto<T> res(A);
    while(B.vacio()){
        res.insertar(B.elemento()); 
        B.eliminar(B.elmento());
    }
    return res;
}

/* Se podria comprobar si el elemento está repetido para no añadir dos iguales,
pero por defecto la operación insertar no agrega elementos repetidos (especificado en el TAD)*/
