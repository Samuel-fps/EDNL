#include "../TAD_APO/apo.h" // Importamos el arbol binario
using namespace std;

//////////// Esta parte es solo para poder leer los arboles de los ficheros
#include <iostream>
#include <fstream>

#include "apo_E-S.h"
typedef int tElto;
const tElto fin = '#';
////////////////////////////////////

/*  EJERCICIO 4

    Un árbol es estrictamente ternario si todos sus nodos son hojas o tienen tres hijos.
    Escribe una función que, dado un árbol de grado arbitrario, nos indique si es o no
    estrictamente ternario.
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