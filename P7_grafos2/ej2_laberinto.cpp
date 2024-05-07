#include "../TAD_GRAFO/alg_grafoPMC.h"
#include "alg_grafo_E-S.h"
#include <iostream>
#include <vector>;

/*  EJERCICIO 2

    Se dispone de un laberinto de NxN  casillas del que se conocen las casillas de entrada 
    y salida del mismo. Si te encuentras en una casilla sólo puedes moverte en las siguientes 
    cuatro direcciones (arriba, abajo, derecha, izquierda). Por otra parte, entre algunas de las 
    casillas hay una pared que impide moverse entre las dos casillas que separa dicha pared 
    (en caso contrario  no sería un verdadero laberinto).

    Implementa un subprograma que dados 
        - N (dimensión del laberinto),  
        - la lista de paredes del laberinto, 
        - la casilla de entrada, y 
        - la casilla de salida, 
    calcule el camino más corto para ir de la entrada a la salida y su longitud.
*/

struct Casilla{
    size_t x, y;
};

// Convierte casillas en vertices
template <typename tCoste>
typename GrafoP<tCoste>::vertice casillas2vertice(GrafoP<tCoste>& G, const Casilla& c){
    for(GrafoP<tCoste>::vertice i = 0 ; i < G.numVert() ; ++i)
        for(size_t j = 0 ; j < G.numVert() ; ++j)
            if(c.x == i && c.y == j)
                return

}

/*
Diagonal a 0
1 en las adyacentes 
e infinito con pared
Hacer funcion que diga cuando dos casillas son adyacentes
¿cuandos son adyacentes? -> abs(c1.fila-c2.fila) + abs(c1.columna-c2.columna)

Casilla nodo2casilla(nodo n, int N)
    c.fila = n / N
    c.col = n % N

nodo casilla2nodo(Casilla c, int N)
    c,fila*N + c.col

    Ponr dos infinitos pq no es dirigido

    camino hay que implementarla en el examen
*/

/* Precondiciones: las casillas de las paredes son casillas del laberinto
                   las casillas de Entrad y Salida son casillas del laberinto
*/
template <typename tCoste>
tCoste resolverLaberinto(const int dimension,
                         const vector<Casilla>& paredes,
                         const Casilla entrada,
                         const Casilla salida)
{
    typedef GrafoP<tCoste>::vertice vertice;
    static const tCoste INF = GrafoP<tCoste>::INFINITO;
    matriz<tCoste> laberinto(dimension);
    
    // Rellenar casillas(Grafo) con coste 1
    for(size_t i = 0 ; i < n ; ++i)
        for(size_t j = 0 ; j < n ; ++j)
            laberinto[i][j] = 1;

    // Rellenar casillas(Grafo) con pared a infinito
    for (Casilla c : paredes)
        laberinto[c.x][c.y] = INF;

    // Creamos un grafo a partir de la matriz de costes para aplicarle Dijkstra
    size_t n = dimension * dimension;   // Numero de vertices
    GrafoP<tCoste> L(n);                // Inicialización de grafo

    for(size_t i = 0 ; i < n ; ++i)
        for(size_t j = 0 ; j < n ; ++j)
            L[i][j] = laberinto[i][j];

    // Convertir casillas en vertices
    for(size_t i = 0 ; i < n ; ++i)
        for(size_t j = 0 ; j < n ; ++j)

    
    // Aplicamos Dijkstra
    vector<tCoste> P;
    vector<tCoste> costes = Dijkstra(L, e, P);

    return costes[s];
}

/*
Segun el enunciado puedo recibir un vertice?

*/


int main() {
    GrafoP<int> grafo("GrafoA.txt");

    std::cout << grafo;

    // LLamada a funcion de ejercicio
    // disMinZuelandia(grafo, ciudadesTomadas, estadoCarreteras, capital);

    // Imprimir el resultado

    return 0;
}