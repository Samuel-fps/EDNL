#include "../TAD_AGEN/agenlis.h" // Importamos el arbol binario
using namespace std;

//////////// Esta parte es solo para poder leer los arboles de los ficheros
#include <iostream>
#include <fstream>

#include "agen_E-S.h"
typedef char tElto;
const tElto fin = '#';
////////////////////////////////////

/*  EJERCICIO 3
    Se define el desequilibrio de un árbol general como la máxima diferencia entre las alturas
    de los subárboles más bajo y más alto de cada nivel. Implementa un subprograma que calcule
    el grado de desequilibrio de un árbol general.
*/

template <typename T>
int desequilibrioAgen_rec(Agen<T> A, typename Agen<T>::nodo n){
    if(n == Agen<T>::NODO_NULO)
        return 0;
    else{
        typename Agen<T>::nodo hijo = A.hijoIzqdo(n);
        while(hijo != Agen<T>::NODO_NULO){
            
        }
        
    }
}

template <typename T>
int desequilibrioAgen(Agen<T> A){
    return desequilibrioAgen_rec(A, A.raiz());
}


int main(){
    Agen<tElto> A(32);

    ifstream fa("AgenA.dat"); // Abrir fichero de entrada.
    rellenarAgen(fa, A); // Desde fichero.
    fa.close();
    
    // Llamada a la funcion del ejercicio
    cout << "El desequilibrio del árbol es " << desequilibrioAgen(A) << endl;

    return 0;
}