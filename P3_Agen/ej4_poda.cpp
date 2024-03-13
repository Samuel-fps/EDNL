#include "../TAD_AGEN/agenlis.h" // Importamos el arbol binario
using namespace std;

//////////// Esta parte es solo para poder leer los arboles de los ficheros
#include <iostream>
#include <fstream>

#include "agen_E-S.h"
typedef char tElto;
const tElto fin = '#';
////////////////////////////////////

/*  EJERCICIO 4
    Dado un árbol general de enteros A y un entero x, implementa un subprograma que realice 
    la poda de A a partir de x. Se asume que no hay elementos repetidos en A.
*/

void encuentraEntero(Agen<int> A, int x){
    encuentraEntero_rec(A, A.raiz(), x);
}


void encuentraEntero_rec(Agen<int> A, typename Agen<int>::nodo n, int x){
    if(n != Agen<int>::NODO_NULO){
        typename Agen<int>::nodo hijo = A.hijoIzqdo(n);
        if(A.elemento(hijo) == x){
                podaNodo_rec(A, A.padre(hijo));
                A.eliminarHijoIzqdo(n);
        }
        else{
            while(hijo == Agen<int>::NODO_NULO){
                if(A.elemento(A.hermDrcho(hijo) ) == x){
                    podaNodo_rec(A, A.padre(hijo));
                    A.eliminarHermDrcho(hijo);
                }
                encuentraEntero_rec(A, hijo, x);
                hijo = A.hermDrcho(hijo);
            }
        }
    }
}

void podaNodo_rec(Agen<int> A, typename Agen<int>::nodo n){
    if(A.hijoIzqdo(n) == Agen<int>::NODO_NULO){
        
    }
    else{
        typename Agen<int>::nodo hijo = A.hijoIzqdo(n);
        while(hijo == Agen<int>::NODO_NULO){
            
            hijo = A.hermDrcho(hijo);
        }
    }
}

