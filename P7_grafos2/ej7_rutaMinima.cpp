#include "../TAD_GRAFO/alg_grafoPMC.h"
#include "alg_grafo_E-S.h"
#include <iostream>
#include <vector>;

/*  EJERCICIO 7

    Se dispone de dos grafos (matriz de costes) que representan los costes de viajar entre
    N ciudades españolas utilizando el tren (primer grafo) y el autobús (segundo grafo).
    Ambos grafos representan viajes entre las mismas N ciudades.

    Nuestro objetivo es hallar el camino de coste mínimo para viajar entre dos ciudades
    concretas del grafo, origen y destino, en las siguientes condiciones:

        - La ciudad origen sólo dispone de transporte por tren.
        - La ciudad destino sólo dispone de transporte por autobús.
        - El sector del taxi, bastante conflictivo en nuestros problemas, sigue en huelga, por lo que únicamente es posible cambiar de transporte en dos ciudades del grafo, cambio1 y cambio2, donde las estaciones de tren y autobús están unidas.

    Implementa un subprograma que calcule la ruta y el coste mínimo para viajar entre
    las ciudades Origen y Destino en estas condiciones.
*/

/*
ORIGEN tren-> CAMBIO_1 bus-> DESTINO
ORIGEN bus-> CAMBIO_2 tren-> DESTINO
dijsktra de origen , cogemos los dos del cambio
inverso hasta destino y cogemos los dos cambio
suma de los dos tramos
*/

template <typename tCoste> 
double rutaCosteMin(const GrafoP<tCoste>& Tren,
                    const GrafoP<tCoste>& Bus,
                    const typename GrafoP<tCoste>::vertice origen,
                    const typename GrafoP<tCoste>::vertice destino,
                    const typename GrafoP<tCoste>::vertice cambio1,
                    const typename GrafoP<tCoste>::vertice cambio2)
{
    typedef GrafoP<tCoste>::vertice vertice;
    size_t N = Tren.numVert();

    GrafoP<tCoste> Costes;

    for(vertice i = 0 ; i < N ; i++){
        Costes[origen][i] = Tren[origen][i]; // Origen solo tren
        Costes[i][destino] = Bus[i][destino]; // Destino solo bus
        for(vertice j = 0 ; j < N ; j++){

        }
    }

    matriz<tCoste> Ruta;
}


int main() {
    GrafoP<int> grafo("GrafoA.txt");

    std::cout << grafo;

    // LLamada a funcion de ejercicio
    // disMinZuelandia(grafo, ciudadesTomadas, estadoCarreteras, capital);

    // Imprimir el resultado

    return 0;
}