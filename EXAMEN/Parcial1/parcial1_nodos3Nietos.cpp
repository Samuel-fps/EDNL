/*
    PARCIAL 1 - Nodos con 3 nietos

    Implementa una función que devuelva el numero de nodos de un arbol binario que tienen tres nietos
*/

#include "../TAD_ABIN/ABinEnla.h"

template <typename T>
int nodos3nietos(const Abin<T>& A, const typename Abin<T>::nodo& n){
    if(n != Abin<T>::NODO_NULO){
        int numNietos = 0;
        typename Abin<T>::nodo  hIzqdo = A.hijoIzqdo(n),
                                hDrcho = A.hijoDrcho(n);

        if(hIzqdo != Abin<T>::NODO_NULO){
            if(A.hijoIzqdo(hIzqdo) != Abin<T>::NODO_NULO) numNietos++;
            if(A.hijoIzqdo(hDrcho) != Abin<T>::NODO_NULO) numNietos++;
        }
        if(hDrcho != Abin<T>::NODO_NULO){
            if(A.hijoDrcho(hIzqdo) != Abin<T>::NODO_NULO) numNietos++;
            if(A.hijoIzqdo(hDrcho) != Abin<T>::NODO_NULO) numNietos++;
        }
        if(numNietos == 3)
            return 1 + nodos3nietos(A, hIzqdo) + nodos3nietos(A, hDrcho);
        else 
            return nodos3nietos(A, hIzqdo) + nodos3nietos(A, hDrcho);
    }
}

