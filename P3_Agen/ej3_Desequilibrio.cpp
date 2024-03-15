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