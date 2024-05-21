#include "../TAD_GRAFO/alg_grafoPMC.h"
#include "alg_grafo_E-S.h"
#include <iostream>
#include <vector>

/*  EJERCICIO 3

    Implementa un subprograma para encontrar un árbol de extensión máximo. 
    ¿Es más difícil que encontrar un árbol de extensión mínimo?
*/

template <typename tCoste>
void constriurPuente()
{
    typedef GrafoP<tCoste>::vertice vertice;
    
}

int main() {
    GrafoP<int> grafo("GrafoA.txt");

    std::cout << grafo;

    // LLamada a funcion de ejercicio

    // Imprimir el resultado

    return 0;
}