#include "../TAD_ABB/abb.h" // Importamos el arbol binario
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

//////////// Esta parte es solo para poder leer los arboles de los ficheros
#include "abb_E-S.h"
typedef int tElto;
const tElto fin = '#';
////////////////////////////////////

/*  EJERCICIO 2
    Un árbol binario de búsqueda se puede equilibrar realizando el recorrido en inorden
    del árbol para obtener el listado ordenado de sus elementos y a continuación, repartir
    equitativamente los elementos a izquierda y derecha colocando la mediana en la raíz y
    construyendo recursivamente los subárboles izquierdo y derecho de cada nodo.
    Implementa este algoritmo para equilibrar un ABB.
*/

// Recibe un árbol abb y un vector vacio
// Devuelve el vector recibido con los elementos del abb ordenados en él
template <typename T>
void abb2vector_rec(Abb<T> A, const vector<T> v){
    if(A.izqdo().vacio() && A.drcho().vacio()){ // Nodo hoja
        v.insert(v.first, A.elemento());
    }
    else {
        if(!A.izqdo().vacio()) { // Izquierdo
            abb2Vector(A.izqdo());
            v.insert(v.first, A.elemento());
        }
        if(!A.drcho().vacio()){ // Derecho
            v.insert(v.first, A.elemento());
            abb2Vector(A.drcho());
        }
    }
}

// Recibe un vector ordenado
// Devuelve un abb equilibrado
template <typename T>
void equilibrarAbb_rec(vector<T> v, size_t i){

}

template <typename T>
Abb<T> equilibrarAbb(Abb<int> A){
    vector<T> v = abb2vector(A);
    return equilibrarAbb_rec(v, v.size()/2);
}

int main(){
    Abb<tElto> A(), B();

    ifstream fa("AbbA.dat"); // Abrir fichero de entrada.
    rellenarAbb(fa, A); // Desde fichero.
    fa.close();

    B = equilibrarAbb(A);
    imprimirAbb(B);

    return 0;
}