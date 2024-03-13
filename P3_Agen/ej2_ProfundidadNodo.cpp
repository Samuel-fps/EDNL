
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
int profundidadNodo(const Agen<T>& A, typename Agen<T>::nodo n){
    if(Agen<T>::NODO_NULO == n) 
        return -1;
    else
        return 1 + profundidadNodo(A, A.padre(n));
}

int main(){
    Agen<tElto> A(32);

    ifstream fa("AgenA.dat"); // Abrir fichero de entrada.
    rellenarAgen(fa, A); // Desde fichero.
    fa.close();
    

    // Llamada a la funcion del ejercicio podemos cambiar el nodo para ver que sea correcta
    cout << "El arbol tiene una profundidad de "
         << profundidadNodo(A, A.hijoIzqdo(A.hijoIzqdo(A.raiz()))) << endl;

    //cout << "\n*** Mostrar árbol binario A ***\n";
    //imprimirAgen(A); // En std::cout

    return 0;
}