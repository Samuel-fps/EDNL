#include "../TAD_AGEN/agenlis.h" // Importamos el arbol binario
using namespace std;

//////////// Esta parte es solo para poder leer los arboles de los ficheros
#include <iostream>
#include <fstream>

#include "agen_E-S.h"
typedef int tElto;
const tElto fin = '#';
////////////////////////////////////

/*  EJERCICIO 4

    Un árbol es estrictamente ternario si todos sus nodos son hojas o tienen tres hijos.
    Escribe una función que, dado un árbol de grado arbitrario, nos indique si es o no
    estrictamente ternario.
*/

template <typename T>
bool esTernario(const Agen<T>& A, const typename Agen<T>::nodo n){
    if(n == Agen<T>::NODO_NULO){
        return true;
    }
    else {
        typename Agen<T>::nodo hijo = A.hijoIzqdo(n);
        int numhijos = 0;
        bool ternario = true;
        while(hijo = Agen<T>::NODO_NULO && numhijos > 3){
            ternario = ternario || esTernario(A, A.hijoIzqdo(hijo)) && esTernario(A, A.hijoDrcho(hijo));
            numHijos++;
            hijo = A.hermDrcho(hijo);
        }
        return numHijos == 0 || numHijos == 3 && ternario;
    }
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