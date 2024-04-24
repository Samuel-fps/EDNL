#include "../TAD_ABIN/ABinEnla.h"

/*
    PARCIAL_1 - Contar descendientes

    Dado un arbol binario, cuenta el numero de nodos que tienen cuatro descendientes o
    mas
*/

// Devuelve los descendientes de un nodo
template <typename T>
int contarDescendientes(const Abin<T>& A, const typename Abin<T>::nodo& n){
     if(n == Abin<T>::NODO_NULO)
        return 0;
    else
        return 1 + contarDescendientes_rec(A.hijoIzqdo(n)) + contarDescendientes_rec(A.hijoDrcho(n));
}

// Devuelve los nodos que cumplen la condicion
template <typename T>
int nodosCuatro_rec(const Abin<T>& A, const typename Abin<T>::nodo& n){
    if(n == Abin<T>::NODO_NULO){
        return 0;
    }
    else{
        if(contarDescendientes(A, n) >= 4){
            return 1 + nodosCuatro_rec(A.hijoIzqdo(n)) + nodosCuatro_rec(A.hijoDercho(n));
        }
    }
}

// Llamada a funcion recursiva
template <typename T>
int nodosCuatro(const Abin<T>& A){
    return nodosCuatro_rec(A, A.raiz());
}
