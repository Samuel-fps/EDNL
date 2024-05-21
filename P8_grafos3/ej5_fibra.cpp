#include "../TAD_GRAFO/alg_grafoPMC.h"
#include "alg_grafo_E-S.h"
#include <iostream>
#include <vector>

/*  EJERCICIO 5

    La nueva compañía de telefonía RETEUNI3 tiene que conectar entre sí, con fibra óptica, todas
    y cada una de las ciudades del país. Partiendo del grafo que representa las distancias entre
    todas las ciudades del mismo, implementad un subprograma que calcule la longitud mínima de 
    fibra óptica necesaria para realizar dicha conexión.
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