#include "../TAD_GRAFO/alg_grafoPMC.h"
#include "alg_grafo_E-S.h"
#include <iostream>
#include <vector>

/*  EJERCICIO 12

    El archipiélago de Grecoland (Zuelandia) está formado únicamente por dos islas, Fobos y Deimos, que 
    tienen N1 y N2 ciudades, respectivamente, de las cuales C1 y C2 ciudades son costeras (obviamente 
    C1 ≤ N1 y C2 ≤ N2). Se desea construir un puente que una ambas islas. Nuestro problemaes elegir el 
    puente a construir entre todos los posibles, sabiendo que el coste de construcción del puente se 
    considera irrelevante. Por tanto, escogeremos aquel puente que minimice el coste global de viajar 
    entre todas las ciudades de las dos islas, teniendo en cuenta las siguientes premisas:

        1. Se asume que el coste viajar entre las dos ciudades que una el puente es 0.
        2. Para poder plantearse las mejoras en el transporte que implica la construcción de un puente
           frente a cualquier otro, se asume que se realizarán exactamente el mismo número de viajes 
           entre cualesquiera ciudades del archipiélago. Por ejemplo, se considerará que el número de 
           viajes entre la ciudad P de Fobos y la Q de Deimos será el mismo que entre las ciudades R 
           y S de la misma isla. Dicho de otra forma, todos los posibles trayectos a realizar dentro 
           del archipiélago son igual de importantes.

    Dadas las matrices de costes directos de Fobos y Deimos y las listas de ciudades costeras de ambas
    islas, implementa un subprograma que calcule las dos ciudades que unirá el puente.
*/

/*
    Hay c1 * c2 posibles puentes
    Tengo que encontrar la mejor ciudad costera de cada isla para construir el puente
*/

// Devuelve las ciudades entre las cuales construir el puente
template <typename tCoste>
void constriurPuente(const GrafoP<tCoste>& Fobos,                       // Coste ciudades Fobos
                     const GrafoP<tCoste>& Deimos,                      // Coste ciudades Deimos
                     const vector<typename GrafoP<tCoste>::vertice> costeras1,   // Ciudades costeras
                     const vector<typename GrafoP<tCoste>::vertice> costeras2,   // Ciudades costeras
                     typename GrafoP<tCoste>::vertice& ciudad1,                  // Ciudad donde construir el puente
                     typename GrafoP<tCoste>::vertice& ciudad2)                  // Ciudad donde construir el puente
{
    typedef typename GrafoP<tCoste>::vertice vertice;
    size_t nF = Fobos.numVert(),
           nD = Deimos.numVert();

    matriz<vertice> P;
    matriz<tCoste> minFobos = Floyd(Fobos, P);
    matriz<tCoste> minDeimos = Floyd(Deimos, P);

    int suma, minSuma;
    minSuma = GrafoP<tCoste>::INFINITO;

    // Encontrar mejor ciudad Fobos
    for(vertice costera : costeras1){
        suma = 0; // Suma de todos los caminos de ida y vuelta a la ciudad costera
        for(vertice j=0 ; j < nF ; j++){
            suma += minFobos[costera][j] + minFobos[j][costera];
        }
        if(suma < minSuma){
            minSuma = suma;
            ciudad1 = costera;
        }
    }
    
    // Enconstrar mejor ciudad Deimos
    for(vertice costera : costeras2){
        suma = 0; // Suma de todos los caminos de ida y vuelta a la ciudad costera
        for(vertice j=0 ; j < nF ; j++){
            suma += minFobos[costera][j] + minFobos[j][costera];
        }
        if(suma < minSuma){
            minSuma = suma;
            ciudad2 = costera;
        }
    }
}
