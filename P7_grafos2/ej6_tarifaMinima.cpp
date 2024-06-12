#include "../TAD_GRAFO/alg_grafoPMC.h"
#include "alg_grafo_E-S.h"
#include <iostream>
#include <vector>;

/*  EJERCICIO 6

    Al dueño de una agencia de transportes se le plantea la siguiente situación. La
    agencia de viajes ofrece distintas trayectorias combinadas entre N ciudades españolas
    utilizando tren y autobús. Se dispone de dos grafos que representan los costes (matriz de
    costes) de viajar entre diferentes ciudades, por un lado en tren, y por otro en autobús
    (por supuesto entre las ciudades que tengan línea directa entre ellas). Además coincide
    que los taxis de toda España se encuentran en estos momentos en huelga general, lo que
    implica que sólo se podrá cambiar de transporte en una ciudad determinada en la que,
    por casualidad, las estaciones de tren y autobús están unidas.
    Implementa una función que calcule la tarifa mínima (matriz de costes mínimos) de
    viajar entre cualesquiera de las N ciudades disponiendo del grafo de costes en autobús,
    del grafo de costes en tren, y de la ciudad que tiene las estaciones unidas.
*/

/*
    4 formas de viajar
    Floyd(tren)
    Floyd(bus)
    Primero llegar a cambio, luego llegar a destino
    Se podrían devolver las cuatro matrices en vez de unirlasen una
*/

template <typename tCoste> 
GrafoP<tCoste> tarifaMinima(const GrafoP<tCoste>& Bus,
                            const GrafoP<tCoste>& Tren,
                            const typename GrafoP<tCoste>::vertice& cambio){
    typedef typename GrafoP<tCoste>::vertice vertice;
    size_t n = G.numVert();
    GrafoP<tCoste> costesMin(n); // Matriz de constes a devolver

    matriz<vertice> P; // Necesaria para algoritmo pero no la usaremos
    // Solo bus
    matriz<tCoste> minBus = Floyd(Bus, P);
    // Solo tren
    matriz<tCoste> minTren = Floyd(Tren, P);

    GrafoP<tCoste> G(n);

    // Rellenamos la matriz con el coste minimo entre las cuatro opciones posibles
    tCoste minDirecto, minCambio;
    for(vertice i=0 ; i < n ; i++){
        for(vertice j=0 ; j < n ; j++){
            minDirecto  = std::min(minTren[i][j], minBus[i][j]); // Solo Tren || solo Bus
            minCambio   = std::min(suma(minTren[i][cambio], minBus[cambio][i]),  // Tren-> cambio ->bus
                                   suma(minBus[i][cambio], minTren[cambio][i])); // bus-> cambio ->tren 
            G[i][j]     = std::min(minDirecto, minCambio); // Guardamos la mejor opcion entre las cuatro
        }    
    }

    return G;
}
