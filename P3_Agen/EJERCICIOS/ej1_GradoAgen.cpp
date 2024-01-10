
#include "../../TAD_AGEN/agenlis.h" // Importamos el arbol binario
using namespace std;

//////////// Esta parte es solo para poder leer los arboles de los ficheros
#include <iostream>
#include <fstream>

#include "../../agen_E-S.h"
typedef char tElto;
const tElto fin = '#';
////////////////////////////////////

/*  EJERCICIO 1

    Implementa un subprograma que dado un árbol general nos calcule su grado. 
*/

#include <algorithm>

template <typename T>
int grado_rec(const Agen<T>& A, typename Agen<T>::nodo n, int gradoMax){
    if(n == Agen<T>::NODO_NULO)
        return 0;
    else{
        typename Agen<T>::nodo hijo = A.hijoIzqdo(n); // Primero hijo izquierdo, si es nulo no tiene hijos
        int nHijos = 0;
        while(hijo != Agen<T>::NODO_NULO){ 
            gradoMax = std::max(gradoMax, grado_rec(A, A.hermDrcho(hijo), gradoMax)); // LLamada al hermano y cojo el mayor
            nHijos++; // Sumar el grado del nodo actual
            hijo = A.hermDrcho(hijo); // Avanzar bucle (Pasar hermano)
        }
        return ++nHijos; // Se suma porque el ultimo hermano no se suma
    }
}

template <typename T>
int gradoAgen(const Agen<T>& A){
    return grado_rec(A, A.raiz(), 0);
}

int main(){
    Agen<tElto> A(16);

    ifstream fa("A.dat"); // Abrir fichero de entrada.
    rellenarAgen(fa, A); // Desde fichero.
    fa.close();
    
    // Llamada a la funcion del ejercicio
    cout << "El arbol grado del arbol A es " << gradoAgen(A) << endl;

    //cout << "\n*** Mostrar árbol binario A ***\n";
    //imprimirAgen(A); // En std::cout

    return 0;
}