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

#include <cmath>
#include <algorithm>

template <typename T>
int alturaNodo(const Agen<T>& A, const typename Agen<T>::nodo& n){
    if(n == Agen<T>::NODO_NULO)
        return -1;
    else{
        typename Agen<T>::nodo hijo = A.hijoIzqdo(n);
        int alturaMax=0, altura;
        while(hijo != Agen<T>::NODO_NULO){
            altura = 1 + std::max(alturaNodo(A, A.hijoIzqdo(hijo)), alturaNodo(A, A.hijoDrcho(hijo)));
            if(altura > alturaMax)
                alturaMax = altura;
            hijo = A.hermDrcho(hijo);
        }
        return alturaMax;
    }
}

template <typename T>
int desequilibrioAgen_rec(const Agen<T>& A, const typename Agen<T>::nodo& n){
    if(n == Agen<T>::NODO_NULO)
        return 0;
    else{
        typename Agen<T>::nodo hijo = A.hijoIzqdo(n);
        int max, min, altura;
        max = min = altura = alturaNodo(A, hijo);
        while(hijo != Agen<T>::NODO_NULO){
            altura = alturaNodo(A, hijo);
            if(altura > max)
                max = altura;
            if(altura < min)
                min = altura;
            hijo = A.hermDrcho(hijo);
        }
        return std::abs(max-min);
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