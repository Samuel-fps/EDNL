#include "../TAD_AGEN/agenlis.h" // Importamos el arbol binario
using namespace std;

//////////// Esta parte es solo para poder leer los arboles de los ficheros
#include <iostream>
#include <fstream>

#include "apo_E-S.h"
typedef int tElto;
const tElto fin = '#';
////////////////////////////////////

/*  EJERCICIO 5 - Blanco y Negro

    Implementa una función que dado un árbol de esta clase, con k+1 niveles,
    devuelva la figura asociada, representada como una matriz cuadrada de tamaño 2^K
    en la que cada celda representa un punto blanco o negro. 

*/

#include <vector>
#include <algorithm>

template <typename T>
int profundidadAgen(const Agen<T>& A, const typename Agen<T>::nodo n){
    if(n == Agen<T>::NODO_NULO){
        return 0;
    }
    else{
        Agen<char>::nodo hijo = I.hijoIzqdo(n);
        int profMax = 0;
        while(hijo != Agen<T>::NODO_NULO){
            profMax = std::max(profMax, profundidadAgen(A, hijo) + 1);
            hijo = I.hermDrcho(hijo);
        }
        return profMax;
    }
}

void dibujar(int){

}


void figuraMatriz_rec(const Agen<char>& I, vector<vector<char>>& m, const typename Agen<char>::nodo n, const int nivel){
    if(n != Agen<char>::NODO_NULO){
        if(I.elemento(n) == ' '){
            Agen<char>::nodo hijo = I.hijoIzqdo(n);
            while(hijo != Agen<char>::NODO_NULO){
                figuraMatriz_rec(I, m, hijo, nivel + 1);
                hijo = I.hermDrcho(hijo);
            }
        }
        else if(I.elemento(n) == 'B'){
            
        }
        else if(I.elemento(n) == 'N'){

        }
    }
}

template <typename T = char>
vector<vector<T>> figuraMatriz(Agen<T> I){
    vector<vector<T>> matriz;
    figuraMatriz_rec(I, matriz, I.raiz(), 0);
    return matriz;
}

int main(){
    Agen<tElto> A();

    ifstream fa("AbbA.dat"); // Abrir fichero de entrada.
    //rellenarAbb(fa, A); // Desde fichero.
    fa.close();
    
    // Llamada a la funcion del ejercicio
    //cout << "El desequilibrio del árbol es " <<  << endl;

    return 0;
}