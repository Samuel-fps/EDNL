#include "../TAD_GRAFO/alg_grafoPMC.h"
#include "alg_grafo_E-S.h"
#include <iostream>

/*  EJERCICIO 2

    Definiremos el pseudocentro de un grafo conexo como el nodo del mismo que minimiza
    la suma de las distancias mínimas a sus dos nodos más alejados. Definiremos el 
    diámetro del grafo como la suma de las distancias mínimas a los dos nodos más 
    alejados del pseudocentro del grafo.  
    Dado un grafo conexo representado mediante matriz de costes, implementa un 
    subprograma que devuelva la longitud de su diámetro. 
*/

template <typename tCoste>
int pseudocentro(const GrafoP<tCoste>& G){

}


int main() {
    GrafoP<int> grafo("GrafoA.txt");

    std::cout << grafo;

    // LLamada a funcion de ejercicio
    int diametro = pseudocentro(grafo);

    // Imprimir el resultado
    std::cout << "El diámetro del grafo es: " << diametro << std::endl;

    return 0;
}