#include "../TAD_APO/apo.h" // Importamos el arbol binario
using namespace std;

//////////// Esta parte es solo para poder leer los arboles de los ficheros
#include <iostream>
#include <fstream>

#include "apo_E-S.h"
typedef int tElto;
const tElto fin = '#';
////////////////////////////////////

/*  EJERCICIO 2 - Insertar en un APO MinMax

    Implementa una operación de orden logarítmico para añadir un elemento a un
    montículo min-max almacenado en un vector de posiciones relativa
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