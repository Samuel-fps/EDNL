#include "../TAD_GRAFO/alg_grafoPMC.h"
#include "alg_grafo_E-S.h"
#include <iostream>
#include <vector>

/*  EJERCICIO 7

    El archipiélago de Grecoland (Zuelandia) está formado únicamente por dos islas, Fobos y Deimos, que tienen
    N1 y N2 ciudades, respectivamente, de las cuales C1 y C2 ciudades son costeras (obviamente C1 ≤ N1 y C2 ≤ N2).
    Se dispone de las coordenadas cartesianas (x, y) de todas y cada una de las ciudades del archipiélago.
    El huracán Isadore acaba de devastar el archipiélago, con lo que todas las carreteras y puentes construidos en su
    día han desaparecido. En esta Terrible situación se pide ayuda a la ONU, que acepta reconstruir el archipiélago
    (es decir volver a comunicar todas las ciudades del archipiélago) siempre que se haga al mínimo coste.

    De cara a poder comparar costes de posibles reconstrucciones se asume lo siguiente:
    
        1. El coste de construir cualquier carretera o cualquier puente es proporcional a su longitud
        (distancia euclídea entre las poblaciones de inicio y fin de la carretera o del puente).
        2. Cualquier puente que se construya siempre será más caro que cualquier carretera que se construya.

    De cara a poder calcular los costes de VIAJAR entre cualquier ciudad del archipiélago se considerará lo siguiente:

        1. El coste directo de viajar, es decir de utilización de una carretera o de un puente, coincidirá con su
           longitud (distancia euclídea entre las poblaciones origen y destino de la carretera o del puente).

    En estas condiciones, implementa un subprograma que calcule el coste mínimo de viajar entre dos ciudades de 
    Grecoland, origen y destino, después de haberse  reconstruido el archipiélago, dados los siguientes datos:

        1. Lista de ciudades de Fobos representadas mediante sus coordenadas cartesianas.
        2. Lista de ciudades de Deimos representadas mediante sus coordenadas cartesianas.
        3. Lista de ciudades costeras de Fobos.
        4. Lista de ciudades costeras de Deimos.
        5. Ciudad origen del viaje.
        6. Ciudad destino del viaje.
*/

typedef struct {
    int x, y;
} Ciudad;

// Distancia euclidea entre dos ciudades
double distanciaCiudades(Ciudad c1, Ciudad c2){
    return sqrt(pow(c2.x - c1.x, 2) + pow(c2.y - c1.y, 2));
}

template <typename tCoste>
tCoste constriurPuentes(const vector<Ciudad>& ciudades1,
                        const vector<Ciudad>& ciudades2,
                        const vector<Ciudad>& costeras1,
                        const vector<Ciudad>& costeras2,
                        const GrafoP<tCoste>::vertice origen,
                        const GrafoP<tCoste>::vertice destino)
{
    typedef GrafoP<tCoste>::vertice vertice;
    size_t n1=ciudades1.size(), n2=ciudades2.size(), n=n1+n2;
    GrafoP<tCoste> distancias(n);

    // Coste de ir entre la primera isla por carretera
    for(size_t i=0 ; i < n1 ; i++){
        for(size_t j=0 ; j < n1 ; j++){
            distancias[i][j] = distancias[j][i] = distanciaCiudades(ciudades1[i], ciudades1[j]);
        }
    }

    // Coste de ir entre la segunda isla por carretera
    for(size_t i=0 ; i < n2 ; i++){
        for(size_t j=0 ; j < n2 ; j++){
            distancias[i][j] = distancias[j][i] = distanciaCiudades(ciudades2[i], ciudades2[j]);
        }
    }

    // Coste cidades costeras (puentes)
    for(size_t i=0 ; i < costeras1.size() ; i++){
        for(size_t j=0 ; j < costeras2.size() ; j++){
            distancias[i][j] = distancias[j][i] = distanciaCiudades(costeras1[i], ccosteras2[j]);
        }
    }

    // Árbol generador de coste mínimo
    GrafoP<tCoste> puentes = kruskall(distancias);

    // Caminos de coste mínomo desde origen
    vector<vertice> P;
    vector<tCoste> costeMin = Dijkstra(puentes, origen, P);
    
    return costeMin[destino];
}