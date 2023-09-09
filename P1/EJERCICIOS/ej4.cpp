
#include "../../TAD_ABIN/ABinV.h" // Importamos el arbol binario
using namespace std;
#include <cstddef>

//////////// Esta parte es solo para poder leer los arboles de los ficheros
#include <iostream>
#include <fstream>

#include "../abin_E-S.h"
typedef char tElto;
const tElto fin = '#';
////////////////////////////////////

/*
    EJERCICIO 4
    Añade dos nuevas operaciones al TAD árbol binario, una que calcule la profundidad de un
    nodo y otra que calcule la altura de un nodo en un árbol dado. Implementa esta operación para
    la representación vectorial (índices del padre, hijo izquierdo e hijo derecho)
*/

/*
    FUNCIONES DE AbinV (Implementación vectorial)

        template <typename T>
        int Abin<T>::alturaArbol(const nodo n){
            if(n == NODO_NULO)
                return -1;
            else
                return 1 + std::max(alturaArbol(nodos[n].hizq), alturaArbol(nodos[n].hder));
        }

        template <typename T>
        int Abin<T>::profundidadNodo(nodo n){
            if(n == raiz())
                return 0;
            else
                return 1 + profundidadNodo(nodos[n].padre);
        }
*/

int main(){
    // Leer Arbol del fichero
    Abin<tElto> A(50);
    cout << "\n*** Lectura de árbol binario B de abin.dat ***\n";
    ifstream fe("abin.dat"); // Abrir fichero de entrada.
    rellenarAbin(fe, A); // Desde fichero.
    fe.close();

    // Llamada a la funcion del ejercicio
    cout << "El arbol tiene una altura de " << A.alturaArbol(A.raiz()) << endl;

    //cout << "\n*** Mostrar árbol binario A ***\n";
    //imprimirAbin(A); // En std::cout

    return 0;
}