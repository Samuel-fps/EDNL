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
tCoste constriurPuente(cosnt GrafoP<tCoste>& distancias)
{
    size_t n = distancias.numVert();

    GrafoP<tCoste> min = kruskal(distancias);

    // sumar distancia de arbol de coste mínimo
    // Como el coste de ir de i a j es igual que de j a i no basta con sumar una de las diagonales, en este caso la superior -> j=i
    // El coste de la diagonal principal será 0 por lo que también nos lo podemos ahorrar -> j=i+1
    tCoste distancia=0;
    for(size_t i=0 ; i < n ; i++)
        for(size_t j=i+1 ; j < n ; j++)
            if (min[i][j] != GrafoP<double>::INFINITO)
                distancia += min[i][j];

    return distancia;
}
