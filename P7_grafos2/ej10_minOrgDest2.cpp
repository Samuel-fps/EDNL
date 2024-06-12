#include "../TAD_GRAFO/alg_grafoPMC.h"
#include "alg_grafo_E-S.h"
#include <iostream>
#include <vector>;

/*  EJERCICIO 10

    Se dispone de tres grafos que representan la matriz de costes para viajes en un determinado país, pero por diferentes medios de
    transporte (tren, autobús y avión).
    Por supuesto los tres grafos tendrán el mismo número de nodos, n.

    Dados los siguientes datos:

        - los tres grafos,
        - una ciudad de origen,
        - una ciudad de destino,
        - el coste del taxi para cambiar, dentro de una ciudad, de la estación de tren a la de autobús o viceversa(taxi-tren-bus) y
        - el coste del taxi desde el aeropuerto a la estación de tren o la de autobús, o viceversa (taxi-aeropuerto-tren/bus)

    y asumiendo que ambos costes de taxi (distintos entre sí, son dos costes diferentes) son
    constantes e iguales para todas las ciudades, implementa un subprograma que calcule el
    camino y el coste mínimo para ir de la ciudad origen a la ciudad destino.
*/

template <typename tCoste> 
tCoste rutaCosteMin(const GrafoP<tCoste>& Tren,
                    const GrafoP<tCoste>& Bus,
                    const GrafoP<tCoste>& Avion,
                    const typename GrafoP<tCoste>::vertice origen,
                    const typename GrafoP<tCoste>::vertice destino,
                    const tCoste taxiBusTren,
                    const tCoste taxiAvion,
                    vector<typename GrafoP<tCoste>::vertice>& caminoCosteMin)
{
    typedef typename GrafoP<tCoste>::vertice vertice;
    size_t n = Tren.numVert();
    GrafoP<tCoste> G(3*n);

    // Rellenamos matriz de costes para aplicar Dijkstra
    for(vertice i=0 ; i < n ; i++){
        G[i]  [i+n] = taxiBusTren;      // Tren -> Bus
        G[i+n][i] = taxiBusTren;        // Bus  -> Tren

        G[i]    [i+n+n] = taxiAvion;    // Tren -> Avion
        G[i+n]  [i+n+n] = taxiAvion;    // Bus -> Avion
        G[i+n+n][i]     = taxiAvion;    // Avion -> Tren
        G[i+n+n][i+n]   = taxiAvion;    // Avion -> Bus

        for(vertice j=0 ; j < n ; j++){
            G[i][j] = Tren[i][j];           // Tren -> Tren 
            G[i+n][j+n] = Bus[i][j];        // Bus  -> Bus 
            G[i+n+n][j+n+n] = Avion[i][j];    // Avion  -> Avion
        }
    }

    vector<tCoste> costesMin = Dijkstra(G, origen, caminoCosteMin);

    return costesMin[destino];
}
