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
    if(n != Abin<T>::NODO_NULO){
        if(A.elemento(n) != elto){
            typename Abin<T>::nodo resultado = buscarNodo(A.hijoIzqdo(n)); // Busqueda por hijo izquierdo
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
    typename Abin<T>::nodo n, hIzq, hDer;

    actual = buscarNodo(A, A.raiz(), valor);
    hIzq = A.hijoIzqdo(actual);
    hDer = A.hijoDrcho(actual);

    while(hIzq != Abin<T>::NODO_NULO || hDer != Abin<T>::NODO_NULO){ // Mientra no sea nodo hoja
        typename Abin<T>::nodo candidato;
        if(hIzq != Abin<T>::NODO_NULO && hDer != Abin<T>::NODO_NULO){
            if(A.elemento(hIzq) > A.elemento(hDer))
                candidato = hIzq;
            else
                candidato = hDer;
        }
        else if(hIzq != Abin<T>::NODO_NULO){
            candidato = hIzq;
        }
        else{
            candidato = hDer;
        }
        
        A.elemento(actual) = candidato.elemento(candidato);

        actual = candidato;
        hIzq = A.hijoIzqdo(actual);
        hDer = A.hijoDrcho(actual);
    }

    if(actual == A.raiz()) // Actual es raiz
        A.eliminarRaiz();
    else if(A.hijoIzqdo(A.padre(actual)) == actual) // Actual es el hijo izquiero
        A.eliminarHijoIzqdo(A.padre(actual));
    else // Actual es hijo derecho
        A.eliminarHijoDrcho(A.padre(actual));
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