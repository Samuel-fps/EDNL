#include "../TAD_ABB/abb.h" // Importamos el arbol binario
using namespace std;

//////////// Esta parte es solo para poder leer los arboles de los ficheros
#include <iostream>
#include <fstream>

#include "abb_E-S.h"
typedef int tElto;
const tElto fin = '#';
////////////////////////////////////

/*  EJERCICIO 4
    Dados dos conjuntos representados mediante árboles binarios de búsqueda,
    implementa la operación intersección de dos conjuntos, que devuelva como resultado
    otro conjunto que sea la intersección de ambos. El resultado debe quedar en un árbol
    equilibrado.
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