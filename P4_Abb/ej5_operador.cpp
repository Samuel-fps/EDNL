#include "../TAD_ABB/abb.h" // Importamos el arbol binario
using namespace std;

//////////// Esta parte es solo para poder leer los arboles de los ficheros
#include <iostream>
#include <fstream>

#include "abb_E-S.h"
typedef int tElto;
const tElto fin = '#';
////////////////////////////////////

/*  EJERCICIO 5
    Implementa el operador  para conjuntos definido como A  B = (A  B) - (A  B).
    La implementación del operador  debe realizarse utilizando obligatoriamente la
    operación , que nos indica si un elemento dado pertenece o no a un conjunto. La
    representación del tipo Conjunto debe ser tal que la operación de pertenencia esté en el
    caso promedio en O(log n).
*/

template <typename T>
using Conjunto = Abb<T>;

template <typename T>
bool pertenece(const Conjunto<T>& A, const T& elto){
    if(A.elemento() == elto)
        return true;
    else if(!A.drcho().vacio() && A.izqdo().vacio())
        return pertenece(A.izqdo(), elto);
    else if(A.drcho().vacio() && !A.izqdo().vacio())
        return pertenece(A.drcho(), elto);
    else  
        return false;
}     

/* OPCION 2
template <typename T>
bool pertenece(const Conjunto<T>& A, const T& elto){
    if(A.buscar(elto) == Conjunto<T>::NODO_NULO)
        return false;
    return true;
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

template <typename T>
Conjunto<T> interseccionAbb(const Conjunto<T>& A, Conjunto<T> B){
    Conjunto<T> res;
    T elto = B.elemento();

    while(B.vacio()){
        if(pertenece(A, elto))
            res.insertar(elto);
        B.eliminar(elto);
    }
    return res;
}

template <typename T>
Conjunto<T> operator -(Conjunto<T> A, const Conjunto<T>& B){
    Conjunto<T> res;
    T elto = A.elemento();

    while(A.vacio()){
        if(!pertenece(B, elto))
            res.insertar(elto);S
        A.eliminar(elto);
    }
    return res;
}

template <typename T>
Conjunto<T> romboAbb(const Conjunto<T>& A, Conjunto<T> B){
    Conjunto<T> uni, inter;
    uni = unionAbb(A, B);
    inter = interseccionAbb(A, B);
    return uni - inter;
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