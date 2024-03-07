
#include "../TAD_ABIN/ABinC.h" // Importamos el arbol binario
using namespace std;

//////////// Esta parte es solo para poder leer los arboles de los ficheros
#include <iostream>
#include <fstream>

#include "abin_E-S.h"
typedef char tElto;
const tElto fin = '#';
////////////////////////////////////

/*  EJERCICIO 2 - Árbol reflejado

    Para un árbol binario B, podemos construir el árbol binario reflejado B^R cambiando los
    subárboles izquierdo y derecho en cada nodo. Implementa un subprograma que devuelva
    el árbol binario reflejado de uno dado.
*/

template <typename T>
void abinReflejado_rec(const Abin<T>& A, Abin<T>& R, const typename Abin<T>::nodo& nA, typename Abin<T>::nodo nR){    
    if(nA != Abin<T>::NODO_NULO){
        if(nA == A.raiz()){
            R.insertarRaiz(A.elemento(nA));
        }
        if(A.hijoIzqdo(nA) != Abin<T>::NODO_NULO){
            R.insertarHijoDrcho(nR, A.elemento(A.hijoIzqdo(nA)));       // Insertamos el nodo reflejado
            abinReflejado_rec(A, R, A.hijoIzqdo(nA), R.hijoDrcho(nR));  // Llamada recursiva hijo izquierdo
        }
        if(A.hijoDrcho(nA) != Abin<T>::NODO_NULO){
            R.insertarHijoIzqdo(nR, A.elemento(A.hijoDrcho(nA)));       // Insertamos el nodo reflejado
            abinReflejado_rec(A, R, A.hijoDrcho(nA), R.hijoIzqdo(nR));  // Llamada recursiva hijo derecho
        }
    }
}

template <typename T>
Abin<T> abinReflejado(const Abin<T>& A){
    Abin<T> R; // Árbol donde quedará el árbol A reflejado
    abinReflejado_rec(A, R, A.raiz(), R.raiz());
    imprimirAbin(R);
    return R;
}

int main(){
    // Leer Arbol del fichero
    Abin<tElto> A;
    cout << "\n*** Lectura de árbol binario B de abin.dat ***\n";
    ifstream fe("arbolB.dat"); // Abrir fichero de entrada.
    rellenarAbin(fe, A); // Desde fichero.
    fe.close();

    // Imprimimos el árbol original
    cout << "Arbol: " << endl;
    imprimirAbin(A);

    // Llamada a la funcion del ejercicio mostrando el árbol reflejado
    cout << "Arbol reflejado: " << endl;
    imprimirAbin(abinReflejado(A));

    return 0;
}