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

// OPCION 1 Usar el método buscar de la clase abb
template <typename T>
bool pertenece(const Conjunto<T>& A, const T& elto){
    if(A.buscar(elto) == Conjunto<T>::NODO_NULO)
        return false;
    return true;
}  

/* OPCION 2 Buscar el elemento
template <typename T>
bool pertenece(Conjunto<T> A, const T& elto){
    if(A.elemento() == elto)
        return true;
    else if(!A.drcho().vacio() && A.izqdo().vacio())
        return pertenece(A.izqdo(), elto);
    else if(A.drcho().vacio() && !A.izqdo().vacio())
        return pertenece(A.drcho(), elto);
    else  
        return false;
}
*/

template <typename T>
Conjunto<T> unionAbb(const Conjunto<T>& A, Conjunto<T> B){
    Conjunto<T> res(A);
    while(B.vacio()){
        res.insertar(B.elemento());
        B.eliminar(B.elmento());
    }
    return res;
}

int main(){
    Abb<tElto> A();

    ifstream fa("AbbA.dat"); // Abrir fichero de entrada.
    // rellenarAbb(fa, A); // Desde fichero.
    fa.close();
    
    // Llamada a la funcion del ejercicio
    //cout << "El desequilibrio del árbol es " <<  << endl;

    return 0;
}