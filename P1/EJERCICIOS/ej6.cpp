
#include "../../TAD_ABIN/ABinC.h" // Importamos el arbol binario
#include <algorithm>
#include <cstdlib>
using namespace std;

//////////// Esta parte es solo para poder leer los arboles de los ficheros
#include <iostream>
#include <fstream>

#include "../abin_E-S.h"
typedef char tElto;
const tElto fin = '#';
////////////////////////////////////

/*
    EJERCICIO 6
    Implementa un subprograma que determine el nivel de desequilibrio de un árbol binario,
    definido como el máximo desequilibrio de todos sus nodos. El desequilibrio de un nodo se
    define como la diferencia entre las alturas de los subárboles del mismo. 
*/

template <typename T>
int desequilibrioAbin_rec(Abin<T> A, typename Abin<T>::nodo n){
    if(n == Abin<T>::NODO_NULO)
        return 0;
    else // Devolve el maximo desequilibrio (entre el actual, hizq, hder)
        return  std::max(std::abs(A.altura(A.hijoIzqdo(n)) - A.altura(A.hijoDrcho(n)), std::max(desequilibrioAbin_rec(A, A.hijoIzqdo(n)), desequilibrioAbin_rec(A, A.hijoDrcho(n))));
}

template <typename T>
int desequilibrioAbin(Abin<T> A){
    return desequilibrioAbin_rec(A, A.raiz());
}

int main(){
    // Leer Arbol del fichero
    Abin<tElto> A;
    cout << "\n*** Lectura de árbol binario B de abin.dat ***\n";
    ifstream fe("abin.dat"); // Abrir fichero de entrada.
    rellenarAbin(fe, A); // Desde fichero.
    fe.close();

    // Llamada a la funcion del ejercicio
    cout << "El arbol tiene un desequilibrio de " << desequilibrioAbin(A) << endl;

    //cout << "\n*** Mostrar árbol binario A ***\n";
    //imprimirAbin(A); // En std::cout

    return 0;
}