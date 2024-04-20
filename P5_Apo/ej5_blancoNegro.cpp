#include "../TAD_APO/apo.h" // Importamos el arbol binario
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
    devuelva la figura asociada, representada como una matriz cuadrada de tamaño 2^4
    en la que cada celda representa un punto blanco o negro. 

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