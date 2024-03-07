
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
    EJERCICIO 

*/

int main(){
    Abin<tElto> A;
    
    ifstream fa("abin.dat"); // Abrir fichero de entrada.
    rellenarAbin(fa, A); // Desde fichero.
    fa.close();

    // Llamada a la funcion del ejercicio
    cout << "El arbol tiene una altura de " << alturaArbol(A) << endl;

    //cout << "\n*** Mostrar árbol binario A ***\n";
    //imprimirAbin(A); // En std::cout

    return 0;
}