#include "../TAD_ABIN/ABinEnla.h" // Importamos el arbol binario
using namespace std;

//////////// Esta parte es solo para poder leer los arboles de los ficheros
#include <iostream>
#include <fstream>

#include "apo_E-S.h"
typedef int tElto;
const tElto fin = '#';
////////////////////////////////////

/*  EJERCICIO 1 - Eliminar Nodo

    Dado un árbol binario de enteros donde el valor de cada nodo es menor que el de sus
    hijos, implementa un subprograma para eliminar un valor del mismo preservando la
    propiedad de orden establecida. Explica razonadamente la elección de la estructura de
    datos. 
*/

template <typename T>
typename Abin<T>::nodo buscarNodo(Abin<T>& A, const typename Abin<T>::nodo n, const T& elto){
    typename Abin<T>::nodo resultado;
    if(n != Abin<T>::NODO_NULO){
        if(A.elemento(n) != elto){
            resultado = buscarNodo(A.hijoIzqdo(n)); // Busqueda por hijo izquierdo
            if(resultado != Abin<T>::NODO_NULO) // Encontado en hijo izquierdo
                return resultado;
            resultado = buscarNodo(A.hijoDrcho(n)); // Busqueda en hijo derecho
            if(resultado != Abin<T>::NODO_NULO) // Encontrado en hijo derecho
                return resultado;
        } 
        else {
            return n;
        }
    }
    else {
        return Abin<T>::NODO_NULO;
    }

}

template <typename T>
void eliminarValor(Abin<T>& A, const T& valor){
    typename Abin<T>::nodo nodo = buscarNodo(A, A.raiz(), valor);

    if(nodo != Abin<T>::NODO_NULO){ // Encontrado

    }

}


int main(){
    Abin<tElto> A();

    ifstream fa("AbbA.dat"); // Abrir fichero de entrada.
    //rellenarAbb(fa, A); // Desde fichero.
    fa.close();
    
    // Llamada a la funcion del ejercicio
    //cout << "El desequilibrio del árbol es " <<  << endl;

    return 0;
}