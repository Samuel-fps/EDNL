/*
SEPTIEMBRE 2022 - ARBOLES

    Construye una función que, dado un Árbol Binario, devuelva true si es un
    AVL y false en el caso contrario.
    *Nota: definir tipos de datos y prototipos de las operaciones de los TADs
    usados
*/

#include "../TAD_ABIN/ABinEnla.h"

template <typename T>
bool esAbb(const Abin<T>& A){
    return esAbb_rec(A, A.raiz());
}

template <typename T>
bool esAbb_rec(const Abin<T>& A, const typename Abin<T>::nodo& n){
    if(n == Abin<T>::NODO_NULO){
        return true;
    }
    else{
        if(A.hijoIzqdo(n) != Abin<T>::NODO_NULO && A.hijoDrcho(n) != Abin<T>::NODO_NULO){
            if(A.elemento(A.hijoIzqdo(n)) < A.elemento(n) && A.elemento(A.hijoDrch(n)) > A.elemento(n))
                return esAbb_rec(A, A.hijoIzqdo(n)) && esAbb_rec(A, A.hijoDrcho(n));
            else
                return false;
        }
        else{
            return esAbb_rec(A, A.hijoIzqdo(n)) && esAbb_rec(A, A.hijoDrcho(n));
        }
    }
}

template <typename T>
int alturaArbol_rec(const Abin<T> A, const typename Abin<T>::nodo n){
    if(n == Abin<T>::NODO_NULO)
        return -1;
    else
        return 1 + std::max(alturaArbol_rec(A, A.hijoIzqdo(n)), alturaArbol_rec(A, A.hijoDrcho(n)));
}

template <typename T>
int desequilibrioAbin_rec(Abin<T> A, typename Abin<T>::nodo n){
    if(n == Abin<T>::NODO_NULO)
        return 0;
    else // Devolve el maximo desequilibrio (entre el actual, hizq, hder)
        return  std::max(std::abs(A.altura(A.hijoIzqdo(n)) - A.altura(A.hijoDrcho(n))),
                         std::max(desequilibrioAbin_rec(A, A.hijoIzqdo(n)), desequilibrioAbin_rec(A, A.hijoDrcho(n))));
}

template <typename T>
int desequilibrioAbin(Abin<T> A){
    return desequilibrioAbin_rec(A, A.raiz());
}

template <typename T>
bool esAvl(const Abin<T>& A){
    return esAbb(A) && desequilibrioAbin(A) <= 1;
}