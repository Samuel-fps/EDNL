#include "../TAD_GRAFO/alg_grafoPMC.h"
#include "alg_grafo_E-S.h"
#include <iostream>
#include <vector>;

/*  EJERCICIO 4

    Se necesita hacer un estudio de las distancias mínimas necesarias para viajar entre
    dos ciudades cualesquiera de un país llamado Zuelandia. El problema es sencillo pero
    hay que tener en cuenta unos pequeños detalles:
        - La orografía de Zuelandia es un poco especial, las carreteras son muy estrechas
        y por tanto solo permiten un sentido de la circulación.
        - Actualmente Zuelandia es un país en guerra. Y de hecho hay una serie de
        ciudades del país que han sido tomadas por los rebeldes, por lo que no pueden
        ser usadas para viajar.
        - Los rebeldes no sólo se han apoderado de ciertas ciudades del país, sino que
        también han cortado ciertas carreteras, (por lo que estas carreteras no pueden ser
        usadas).
        - Pero el gobierno no puede permanecer impasible ante la situación y ha exigido
        que absolutamente todos los viajes que se hagan por el país pasen por la capital
        del mismo, donde se harán los controles de seguridad pertinentes.

    Dadas estas cuatro condiciones, se pide implementar un subprograma que dados
        - el grafo (matriz de costes) de Zuelandia en situación normal,
        - la relación de las ciudades tomadas por los rebeldes,
        - la relación de las carreteras cortadas por los rebeldes
        - y la capital de Zuelandia, calcule la matriz de costes mínimos para viajar entre
        cualesquiera dos ciudades zuelandesas en esta situación. 
*/

template <typename tCoste>
matriz<tCoste> disMinZuelandia(const GrafoP<tCoste>& G,
                   const std::vector<typename GrafoP<tCoste>::vertice>& ciudadesTomadas,
                   const matriz<bool>& estadoCarreteras,
                   const typename grafoP<tCoste>::vertice& capital){

    const size_t n = G.numVert();
    const tCoste INF = GrafoP<tCoste>::INFINITO;
    typedef typename GrafoP<tCoste>::vertice vertice;
    
    // Eliminar carreteras(aristas) que se dirijan a ciudades tomadas o que vengan de ciudades tomadas
    for(vertice i = 0 ; i < ciudadesTomada.size() ; i++){
        for(vertice j = 0 ; j < n ; i++){
            G[ciudadesTomadas[i]][j] = INF; // desde ciudades tomadas
            G[j][ciudadesTomadas[i]] = INF; // hacia ciudades tomadas
        }
    }

    // Eliminamos las carreteras(aristas) cortadas
    for(vertice i = 0 ; i < n ; i++){
        for(vertice j = 0 ; j < n ; j++){
            if(!estadoCarreteras[i][j]){
                G[i][j] = INF;
            }
        }
    }

    // Aplicamos Dijkstra y DijkstraInv para obtener distacias minimas desde la capital a todas las ciudades y viceversa
    vector<tCoste> P;
    vector<tCoste> haciaCapital = DijkstraInv(capital, G, P),
                   desdeCapital = Dijkstra(capital, G, P);

    // Creamos un grafo con los nuevos costes
    GrafoP<tCoste> distanciaMin(n); 
    for (vertice i = 0 ; i < n ; i++)
        for (vertice j = 0 ; j < n ; i++)
            distanciaMin[i][j] = suma(haciaCapital[i], desdeCapital[j]);

    return distanciaMin;
    
}

/*
    ¿Es mejor deividir en subfunciones?
    ¿Recibir vertor de vertices o vector bool -> ciudades tomadas?
    ¿DijtrakInv se puede usar en el examen?
    ¿Esta bine declarado INF?
*/


int main() {
    GrafoP<int> grafo("GrafoA.txt");

    std::cout << grafo;

    // LLamada a funcion de ejercicio
    // disMinZuelandia(grafo, ciudadesTomadas, estadoCarreteras, capital);

    // Imprimir el resultado

    return 0;
}