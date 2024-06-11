#include "../TAD_GRAFO/alg_grafoPMC.h"
#include "alg_grafo_E-S.h"
#include <iostream>
#include <vector>;

/*  EJERCICIO 13

    El archipiélago de las Huríes acaba de ser devastado por un maremoto de dimensiones desconocidas hasta 
    la fecha. La primera consecuencia ha sido que todos y cada uno de los puentes que unían las diferentes
    ciudades de las tres islas han sido destruidos. En misión de urgencia las Naciones Unidas han decidido
    construir el mínimo número de puentes que permitan unir las tres islas. Asumiendo que el coste de 
    construcción de los puentes implicados los pagará la ONU, por lo que se considera irrelevante, nuestro 
    problema es decidir qué puentes deben construirse. Las tres islas de las Huríes tienen respectivamente
    N1, N2 y N3 ciudades, de las cuales C1, C2 y C3 son costeras (obviamente C1 ≤ N1 , C2 ≤ N2 y C3 ≤ N3).
    Nuestro problema es elegir los puentes a construir entre todos los posibles. Por tanto, escogeremos 
    aquellos puentes que minimicen el coste global de viajar entre todas las ciudades de las tres islas,
    teniendo en cuenta las siguientes premisas:

    1. Se asume que el coste viajar entre las ciudades que unan los puentes es 0.
    2. La ONU subvencionará únicamente el número mínimo de puentes necesario para comunicar las tres islas.
    3. Para poder plantearse las mejoras en el transporte que implica la construcción de un puente frente a
       cualquier otro, se asume que se realizarán exactamente el mismo número de viajes entre cualesquiera
       ciudades del archipélago. Dicho de otra forma, todos los posibles trayectos a realizar dentro del 
       archipiélago son igual de importantes.

    Dadas las matrices de costes directos de las tres islas y las listas de ciudades costeras
    del archipiélago, implementad un subprograma que calcule los puentes a construir en las
    condiciones anteriormente descritas.
*/

/*
Igual que el anterior pero con tres islas
*/

template <typename tCoste>
void constriurPuentes(const GrafoP<tCoste>& I1,                     // Coste ciudades Isla 1
                      const GrafoP<tCoste>& I2,                     // Coste ciudades Isla 2
                      const GrafoP<tCoste>& I3,                     // Coste ciudades Isla 3
                      const vector<GrafoP<tCoste>::vertice> costeras1,   // Ciudades costeras
                      const vector<GrafoP<tCoste>::vertice> costeras2,   // Ciudades costeras
                      const vector<GrafoP<tCoste>::vertice> costeras3,   // Ciudades costeras
                      GrafoP<tCoste>::vertice& ciudad1,             // Ciudad donde construir el puente Isla 1
                      GrafoP<tCoste>::vertice& ciudad2,              // Ciudad donde construir el puente Isla 2
                      GrafoP<tCoste>::vertice& ciudad3)             // Ciudad donde construir el puente Isla 3
{
    typedef GrafoP<tCoste>::vertice vertice;
    size_t n1 = I1.numVert(),
           n2 = I2.numVert(),
           n3 = I3.numVert();

    matriz<vertice> P;
    matriz<tCoste> minI1 = Floyd(I1, P);
    matriz<tCoste> minI2 = Floyd(I2, P);
    matriz<tCoste> minI3 = Floyd(I3, P);

    int suma, minSuma;
    minSuma = GrafoP<tCoste>::INFINITO;

    // Enconstrar mejor ciudad Isla 1
    for(vertice costera : costeras1){
        suma = 0; // Suma de todos los caminos de ida y vuelta a la ciudad costera
        for(vertice j=0 ; j < n1 ; j++){
            suma += minI1[costera][j] + minI1[j][costera];
        }
        if(suma < minSuma){
            minSuma = suma;
            ciudad1 = costera;
        }
    }

    // Encontrar mejor ciudad Isla 2
    for(vertice costera : costeras2){
        suma = 0; // Suma de todos los caminos de ida y vuelta a la ciudad costera
        for(vertice j=0 ; j < n2 ; j++){
            suma += minI2[costera][j] + minI2[j][costera];
        }
        if(suma < minSuma){
            minSuma = suma;
            ciudad2 = costera;
        }
    }

    // Encontrar mejor ciudad Isla 3
    for(vertice costera : costeras3){
        suma = 0; // Suma de todos los caminos de ida y vuelta a la ciudad costera
        for(vertice j=0 ; j < n3 ; j++){
            suma += minI3[costera][j] + minI3[j][costera];
        }
        if(suma < minSuma){
            minSuma = suma;
            ciudad3 = costera;
        }
    }
}
