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
        - El sector del taxi, bastante conflictivo en nuestros problemas, sigue en huelga
          por lo que únicamente es posible cambiar de transporte en dos ciudades del grafo,
          cambio1 y cambio2, donde las estaciones de tren y autobús están unidas.

    Implementa un subprograma que calcule la ruta y el coste mínimo para viajar entre
    las ciudades Origen y Destino en estas condiciones.
*/

template <typename tCoste> 
tCoste rutaCosteMin(const GrafoP<tCoste>& Tren,     // Matriz de costes deviaje en tren
                    const GrafoP<tCoste>& Bus,      // Matriz de costes deviaje en bus
                    const typename GrafoP<tCoste>::vertice origen,      // Origen del viaje
                    const typename GrafoP<tCoste>::vertice destino,     // Destino del viaje
                    const typename GrafoP<tCoste>::vertice cambio1,     // Vertice en el que se permite transbordo
                    const typename GrafoP<tCoste>::vertice cambio2,     // Vertice en el que se permite transbordo
                    vector<typename GrafoP<tCoste>::vertice>& rutaOrigenCambio,     // Camino de origen a cambio
                    vector<typename GrafoP<tCoste>::vertice>& rutaCambioDestino)    // Camino de cambio a destino
{
    // Aplicamos Dijkstra en vertice origen para obtener las rutas minimas entre ellas origen -> cambio
    // Aplicamos DijkstraInv en vertice detino para obtener las rutas minimas entre ellas cambio -> destino
    vector<tCoste> origenCambio = Dijkstra(Tren, origen, rutaOrigenCambio);
    vector<tCoste> cambioDestino = DijkstraInv(Tren, destino, rutaCambioDestino);

    // ORIGEN --tren--> CAMBIO_1 --bus--> DESTINO
    tCoste cambio1 = suma(origenCambio[cambio1], cambioDestino[cambio1]);

    //ORIGEN --bus--> CAMBIO_2 --tren-->  DESTINO
    tCoste cambio2 = suma(origenCambio[cambio1], cambioDestino[cambio1]);

    return std::min(cambio1, cambio2);
}
