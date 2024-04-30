#include "../TAD_GRAFO/grafoLA.h"
#include "alg_grafo_E-S.h"
#include <iostream>

/*  EJERCICIO 5

    Escribir una función genérica que implemente el algoritmo de Dijkstra usando un
    grafo ponderado representado mediante listas de adyacencia. 
*/

template <typename tCoste>
vector<tCoste> dijkstra(const GrafoP<tCoste>& G){

}


int main() {
    GrafoP<int> grafo("GrafoA.txt");

    std::cout << grafo;

    // LLamada a funcion de ejercicio
    dijkstra(grafo);

    // Imprimir el resultado

    return 0;
}