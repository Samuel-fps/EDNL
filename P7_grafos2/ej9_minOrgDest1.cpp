#include "../TAD_GRAFO/alg_grafoPMC.h"
#include "alg_grafo_E-S.h"
#include <iostream>
#include <vector>;

/*  EJERCICIO 9
    
    Se dispone de dos grafos que representan la matriz de costes para viajes en un
    determinado país, pero por diferentes medios de transporte (tren y autobús, por 
    ejemplo). Por supuesto ambos grafos tendrán el mismo número de nodos, N. Dados 
    ambos grafos, una ciudad de origen, una ciudad de destino y el coste del taxi 
    para cambiar de una estación a otra dentro de cualquier ciudad (se supone 
    constante e igual para todas las ciudades), implementa un subprograma que 
    calcule el camino y el coste mínimo para ir de la ciudad origen a la ciudad 
    destino.
*/

/*
Solución: no usar las cidades sino estación de bus o de tren
ordenar tren despues bus y las ciudades en el mismo orden
devuelvo vector ganador, origen, destino
*/

template <typename tCoste> 
tCoste rutaCosteMin(const GrafoP<tCoste>& Tren,
                    const GrafoP<tCoste>& Bus,
                    const typename GrafoP<tCoste>::vertice origen,
                    const typename GrafoP<tCoste>::vertice destino,
                    const tCoste costeTaxi,
                    vector<typename GrafoP<tCoste>::vertice>& caminoCosteMin) // Vector donde se devuelve el camino de coste minimo
{
    typedef GrafoP<tCoste>::vertice vertice;
    size_t n = Tren.numVert();
    GrafoP<tCoste> G(2*n);

    // Rellenamos matriz de costes para aplicar Dijkstra
    for(vertice i=0 ; i < n ; i++){
        G[i][i+n] = costeTaxi;          // Tren -> Bus  (Segundo cuadrante)
        G[i+n][i] = costeTaxi;          // Bus  -> Tren (Tercer cuadrante)
        for(vertice j=0 ; j < n ; j++){
            G[i][j] = Tren[i][j];       // Tren -> Tren (Primer cuadrante)
            G[i+n][i+n] = Bus[i][j];    // Bus  -> Bus  (Cuarto cuadrante)
        }
    }

    // Aplicamos Dijkstra para obtener costes mínimos desde origen
    vector<tCoste> costeMin = Dijkstra(G, origen, caminoCosteMin);

    return costeMin[destino];
}
