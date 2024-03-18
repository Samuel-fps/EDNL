#include "../TAD_ABB/abb.h" // Importamos el arbol binario
using namespace std;

//////////// Esta parte es solo para poder leer los arboles de los ficheros
#include <iostream>
#include <fstream>

#include "abb_E-S.h"
typedef int tElto;
const tElto fin = '#';
////////////////////////////////////

/*  EJERCICIO 2
    Un árbol binario de búsqueda se puede equilibrar realizando el recorrido en inorden
    del árbol para obtener el listado ordenado de sus elementos y a continuación, repartir
    equitativamente los elementos a izquierda y derecha colocando la mediana en la raíz y
    construyendo recursivamente los subárboles izquierdo y derecho de cada nodo.
    Implementa este algoritmo para equilibrar un ABB.
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