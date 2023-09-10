
#include "../../TAD_ABIN/ABinC.h" // Importamos el arbol binario
using namespace std;

//////////// Esta parte es solo para poder leer los arboles de los ficheros
#include <iostream>
#include <fstream>

#include "../abin_E-S.h"
typedef char tElto;
const tElto fin = '#';
////////////////////////////////////

/*  EJERCICIO 2 - Arbol reflejado

    Para un árbol binario B, podemos construir el árbol binario reflejado B^R cambiando los
    subárboles izquierdo y derecho en cada nodo. Implementa un subprograma que devuelva
    el árbol binario reflejado de uno dado.
*/

template <typename T>
void abinReflejado_rec(const Abin<T>& A, Abin<T>& C, typename Abin<T>::nodo nA, typename Abin<T>::nodo nC){
    if(n != Abin<T>::NODO_NULO){
        if(A.hijoIzqdo(nA) != Abin<T>::NODO_NULO){
            C.insertarHijoDrcho(nC, A.elemento(A.hijoIzqdo(nA)));
            abinReflejado_rec(A, C, A.hijoIzqdo(nA), C.hijoDrcho(nC));
        }
        if(A.hijoDrcho(nA) != Abin<T>::NODO_NULO){
            C.insertarHijoIzqdo(nC, A.elemento(A.hijoDrcho(nA)));
            abinReflejado_rec(A, C, A.hijoDrcho(nA), C.hijoIzqdo(nC));
        }
    }
}

template <typename T>
Abin<T> abinReflejado(const Abin<T>& A){
    Abin<T> copia{A};
    abinReflejado_rec(A, copia, A.raiz());
    return copia;
}

int main(){
    // Leer Arbol del fichero
    Abin<tElto> A;
    cout << "\n*** Lectura de árbol binario B de abin.dat ***\n";
    ifstream fe("abin.dat"); // Abrir fichero de entrada.
    rellenarAbin(fe, A); // Desde fichero.
    fe.close();

    // Llamada a la funcion del ejercicio
    cout << "Arbol: " << endl;
    imprimirAbin(A);

    cout << "Arbol reflejado: " << endl;
    imprimirAbin(abinReflejado(A));

    //cout << "\n*** Mostrar árbol binario A ***\n";
    //imprimirAbin(A); // En std::cout

    return 0;
}