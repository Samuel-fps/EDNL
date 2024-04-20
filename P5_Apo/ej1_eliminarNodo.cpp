#include "../TAD_APO/apo.h" // Importamos el arbol binario
using namespace std;

//////////// Esta parte es solo para poder leer los arboles de los ficheros
#include <iostream>
#include <fstream>

#include "apo_E-S.h"
typedef int tElto;
const tElto fin = '#';
////////////////////////////////////

/*  EJERCICIO 1 - Eliminar Nodo

    Dado un árbol binario de enteros donde el valor de cada nodo es menor que el de sus
    hijos, implementa un subprograma para eliminar un valor del mismo preservando la
    propiedad de orden establecida. Explica razonadamente la elección de la estructura de
    datos. 
*/



int main(){
    Apo<tElto> A();

    ifstream fa("AbbA.dat"); // Abrir fichero de entrada.
    //rellenarAbb(fa, A); // Desde fichero.
    fa.close();
    
    // Llamada a la funcion del ejercicio
    //cout << "El desequilibrio del árbol es " <<  << endl;

    return 0;
}