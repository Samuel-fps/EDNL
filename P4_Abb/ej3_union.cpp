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
bool pertenece(Conjunto<T> A, const T& elto){
    if(A.elemento() == elto)
        return true;
    else if(!A.drcho().vacio() && A.izqdo().vacion())
        return pertenece(A.izqdo(), elto);
    else if(A.drcho().vacio() && !A.izqdo().vacion())
        return pertenece(A.drcho(), elto);
    else  
        return false;
}

template <typename T>
Conjunto<T> union(Conjunto<T> A, Conjunto<T> B){
    if(pertenece(A, B.elemento()))
        return A;
    else 
        return B;
}

int main(){
    Abb<tElto> A();

    ifstream fa("AbbA.dat"); // Abrir fichero de entrada.
    rellenarAbb(fa, A); // Desde fichero.
    fa.close();
    
    // Llamada a la funcion del ejercicio
    //cout << "El desequilibrio del árbol es " <<  << endl;

    return 0;
}