#include "../TAD_GRAFO/alg_grafoPMC.h"
#include "alg_grafo_E-S.h"
#include <iostream>
#include <vector>;

/*  EJERCICIO 8

    “UN SOLO TRANSBORDO, POR FAVOR”. Este es el título que reza en tu
    flamante compañía de viajes. Tu publicidad explica, por supuesto, que ofreces viajes
    combinados de TREN y/o AUTOBÚS (es decir, viajes en tren, en autobús, o usando
    ambos), entre N ciudades del país, que ofreces un servicio inmejorable, precios muy
    competitivos, y que garantizas ante notario algo que no ofrece ninguno de tus
    competidores: que en todos tus viajes COMO MÁXIMO se hará un solo transbordo
    (cambio de medio de transporte).

    Bien, hoy es 1 de Julio y comienza la temporada de viajes.
    ¡Qué suerte! Acaba de aparecer un cliente en tu oficina. Te explica que quiere viajar
    entre dos ciudades, Origen y Destino, y quiere saber cuánto le costará.
    Para responder a esa pregunta dispones de dos grafos de costes directos (matriz de
    costes) de viajar entre las N ciudades del país, un grafo con los costes de viajar
    en tren y otro en autobús.

    Implementa un subprograma que calcule la tarifa mínima en estas condiciones.
    Mucha suerte en el negocio, que la competencia es dura.
*/

/*
Dijkstra(Tren) + inverso (bus)
Dijkstra(bus) + inverso (tren)
No es necesario solo tren o solo bus porque es un caso especifico de las otras dos opciones
Si no cambias de trasporte el transbordo es al final y la suma es coste_origen_transbordo + 0 (coste de ir transbordo_destino)
*/

template <typename tCoste> 
tCoste tarifaMinima(const GrafoP<tCoste>& Tren,
                    const GrafoP<tCoste>& Bus,
                    const typename GrafoP<tCoste>::vertice origen,
                    const typename GrafoP<tCoste>::vertice destino)
{
    typedef typename GrafoP<tCoste>::vertice vertice;

    vector<vertice> ruta; // No nos pide la ruta por lo que usamos el mismo vector
    vector<tCoste> origenTren = Dijkstra(Tren, origen, ruta),
                   destinoTren = DijkstraInv(Tren, origen, ruta),
                   origenBus = Dijkstra(Bus, origen, ruta),
                   destinoBus = DijkstraInv(Bus, origen, ruta);

    // Camino con transbordo de minimo coste tren->bus
    tCoste minTrenBus = suma(origenTren[0], destinoBus[0]);
    for(size_t i = 0 ; i < origenTren.size() ; i++)
        if(minTrenBus < suma(origenTren[i], destinoBus[i])) // Hacer transbordo en i es menos costoso
            minTrenBus = suma(origenTren[i], destinoBus[i]);

    // Camino con transbordo de minimo coste bus->tren
    tCoste minBusTren = suma(origenBus[0], destinoTren[0]);
    for(size_t i = 0 ; i < origenBus.size() ; i++)
        if(minBusTren < suma(origenBus[i], destinoTren[i])) // Hacer transbordo en i es menos costoso
            minBusTren = suma(origenBus[i], destinoTren[i]);
    
    return std::min(minTrenBus, minBusTren);
}
