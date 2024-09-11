#include "../TAD_AGEN/agenlis.h" // Importamos el arbol binario
using namespace std;

//////////// Esta parte es solo para poder leer los arboles de los ficheros
#include <iostream>
#include <fstream>

#include "agen_E-S.h"
typedef int tElto;
const tElto fin = '#';
////////////////////////////////////

/*  EJERCICIO 4

    Dado un árbol general de enteros A y un entero x, implementa un subprograma que realice 
    la poda de A a partir de x. Se asume que no hay elementos repetidos en A.
*/

void podaNodo_rec(Agen<int>& A, typename Agen<int>::nodo n){
    if(n != Agen<int>::NODO_NULO){
        typename Agen<int>::nodo hijo = A.hijoIzqdo(n);
        while(hijo != Agen<int>::NODO_NULO){
            podaNodo_rec(A, A.hijoIzqdo(hijo)); // Podamos la rama del hIzq
            A.eliminarHijoIzqdo(n); // Eliminamos hIzq que ya no tiene hijos
            hijo = A.hijoIzqdo(n); // Obtenemos nuevo hIzq(anteriormente hermano derecho)
        }
    }
}

void encuentraEntero_rec(Agen<int>& A, typename Agen<int>::nodo n, int x){
    if(n != Agen<int>::NODO_NULO){
        if(A.elemento(n) == x){ 
            podaNodo_rec(A, n);
            // Eliminamos el propio nodo n
            typename Agen<int>::nodo hijo = A.hijoIzqdo(A.padre(n));
            if(hijo == n){
                A.eliminarHijoIzqdo(A.padre(n));
            }
            else{
                while (hijo != Agen<int>::NODO_NULO){
                    if(A.hermDrcho(hijo) == n){
                        A.eliminarHermDrcho(hijo);
                    }
                    hijo = A.hermDrcho(hijo);
                }
            }
            
        }
        else{
            typename Agen<int>::nodo hijo = A.hijoIzqdo(n);
            while(hijo != Agen<int>::NODO_NULO){
                
                encuentraEntero_rec(A, hijo, x);
                hijo = A.hermDrcho(hijo);
            }
        }
    }
}

void encontrarEntero(Agen<int>& A, int x){
    encuentraEntero_rec(A, A.raiz(), x);
}

int main(){
    Agen<tElto> A(32);

    ifstream fa("AgenB.dat"); // Abrir fichero de entrada.
    rellenarAgen(fa, A); // Desde fichero.
    fa.close();
    // rellenarAgen(A, fin);
    cout << "\n*** Mostrar arbol antes de podar ***\n";
    imprimirAgen(A); // En std::cout
    
    encontrarEntero(A, 6);

    cout << "\n*** Mostrar arbol podado ***\n";
    imprimirAgen(A); // En std::cout

    return 0;
}