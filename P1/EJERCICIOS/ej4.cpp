
#include "../../TAD_ABIN/ABinC.h" // Importamos el arbol binario
using namespace std;

//////////// Esta parte es solo para poder leer los arboles de los ficheros
#include <iostream>
#include <fstream>

#include "../abin_E-S.h"
typedef char tElto;
const tElto fin = '#';
////////////////////////////////////

/*
    EJERCICIO 6
    Implementa un subprograma que determine el nivel de desequilibrio de un árbol binario,
    definido como el máximo desequilibrio de todos sus nodos. El desequilibrio de un nodo se
    define como la diferencia entre las alturas de los subárboles del mismo.
*/

int main(){
    // Leer Arbol del fichero
    Abin<tElto> A;
    cout << "\n*** Lectura de árbol binario B de abin.dat ***\n";
    ifstream fe("abin.dat"); // Abrir fichero de entrada.
    rellenarAbin(fe, A); // Desde fichero.
    fe.close();

    // Llamada a la funcion del ejercicio
    cout << "El arbol tiene una altura de " << alturaArbol(A) << endl;

    //cout << "\n*** Mostrar árbol binario A ***\n";
    //imprimirAbin(A); // En std::cout

    return 0;
}