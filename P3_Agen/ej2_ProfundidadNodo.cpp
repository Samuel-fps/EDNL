
#include "../TAD_AGEN/agenlis.h" // Importamos el arbol binario
using namespace std;

//////////// Esta parte es solo para poder leer los arboles de los ficheros
#include <iostream>
#include <fstream>

#include "agen_E-S.h"
typedef char tElto;
const tElto fin = '#';
////////////////////////////////////

/*  EJERCICIO 2

    Implementa un subprograma que dados un árbol y un nodo dentro de dicho árbol determine
    la profundidad de éste nodo en el árbol. 
*/

template <typename T>
int profundidadNodo(Agen<T> A, typename Agen<T>::nodo n){
    if(n == A.raiz())
        return 0;
    else
        return 1 + profundidadNodo(A, A.padre(n));
}

int main(){
    Agen<tElto> A(16);

    ifstream fa("AgenA.dat"); // Abrir fichero de entrada.
    rellenarAgen(fa, A); // Desde fichero.
    fa.close();
    

    // Llamada a la funcion del ejercicio
    cout << "El arbol tiene una profundidad de " << profundidadNodo(A, A.raiz()) << endl;

    //cout << "\n*** Mostrar árbol binario A ***\n";
    //imprimirAgen(A); // En std::cout

    return 0;
}