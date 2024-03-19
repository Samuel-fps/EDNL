#include "../TAD_ABB/abb.h" // Importamos el arbol binario
#include <iostream>
#include <fstream>

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

template <typename T>
Vector<T> abb2vector_rec(Abb<T> A){
    
}

template <typename T>
void equilibrarAbb_rec(Vector<T> v){

}

template <typename T>
Abb<T> equilibrarAbb(Abb<int> A){
    Vector<T> v = abb2vector(A);
    return equilibrarAbb_rec(v);
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