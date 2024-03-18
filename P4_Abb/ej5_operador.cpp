#include "../TAD_ABB/abb.h" // Importamos el arbol binario
using namespace std;

//////////// Esta parte es solo para poder leer los arboles de los ficheros
#include <iostream>
#include <fstream>

#include "abb_E-S.h"
typedef int tElto;
const tElto fin = '#';
////////////////////////////////////

/*  EJERCICIO 5
    Implementa el operador  para conjuntos definido como A  B = (A  B) - (A  B).
    La implementación del operador  debe realizarse utilizando obligatoriamente la
    operación , que nos indica si un elemento dado pertenece o no a un conjunto. La
    representación del tipo Conjunto debe ser tal que la operación de pertenencia esté en el
    caso promedio en O(log n).
*/


int main(){
    Abb<tElto> A();

    ifstream fa("AbbA.dat"); // Abrir fichero de entrada.
    rellenarAbb(fa, A); // Desde fichero.
    fa.close();
    
    // Llamada a la funcion del ejercicio
    //cout << "El desequilibrio del árbol es " <<  << endl;

    return 0;
}