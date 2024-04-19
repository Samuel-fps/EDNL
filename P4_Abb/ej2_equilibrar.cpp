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
void abb2vector_rec(Abb<T> A, vector<T>& v){
    if(!A.vacio()){
        abb2vector_rec(A.izqdo(), v);
        v.push_back(A.elemento());
        abb2vector_rec(A.drcho(), v);
    }
}

// Recibe un vector ordenado
// Devuelve un abb equilibrado
template <typename T>
Abb<T> equilibrarAbb_rec(const vector<T>& elementos, int inicio, int fin){
    if(inicio > fin){
        return Abb<T>{};
    }

    int mediana = (fin - inicio) / 2;
    Abb<T> arbol;
    arbol.insertar(elementos[mediana]);
    arbol = equilibrarAbb_rec(elementos, inicio, mediana-1);
    arbol = equilibrarAbb_rec(elementos, mediana+1 , fin);
    return arbol;
}

template <typename T>
Abb<T> equilibrarAbb(Abb<int> A){
    vector<T> v = abb2vector(A);
    return equilibrarAbb_rec(v, v.begin(), v.end());
}

int main(){
    Abb<tElto> A(), B();

    ifstream fa("AbbA.dat"); // Abrir fichero de entrada.
    /* rellenarAbb(fa, A); // Desde fichero.
    fa.close();

    B = equilibrarAbb(A);
    imprimirAbb(B);
    */
    return 0;
}