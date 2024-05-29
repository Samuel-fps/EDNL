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
    c.fila*N + c.col

    Ponr dos infinitos pq no es dirigido

    camino hay que implementarla en el examen
*/

struct Casilla {
    size_t x, y;
};

struct Pared {
    Casilla c1, c2;
};

// Convierte una Casilla en un Vertice
template <typename tCoste>
typename GrafoP<tCoste>::vertice casillaToVertice(const Casilla& c, const int N){
    return c.fila*N + c.col;
}

// Convierte un Vertice en una Casilla
template <typename tCoste>
Casilla verticeToCasilla(typename GrafoP<tCoste>::vertice n, const int N){
    Casilla c;
    c.fila = n / N;
    c.col = n % N;
    return c;
}

// Devuelve true si dos casillas son adyacentes
template <typename tCoste>
bool adyacentes(const Casilla& c1, const Casilla& c2){
    return (1 == abs(c1.fila-c2.fila) + abs(c1.columna-c2.columna));
}

// Función declarada en alg_grafoPMC.h (en el examen hay que implementarla para usarla)
template <typename tCoste> typename GrafoP<tCoste>::tCamino
camino(typename GrafoP<tCoste>::vertice orig,
       typename GrafoP<tCoste>::vertice v,
       const vector<typename GrafoP<tCoste>::vertice>& P)
// Devuelve el camino de coste mínimo entre los vértices orig e v
// a partir de un vector P obtenido mediante la función Dijkstra().
{
   typename GrafoP<tCoste>::tCamino C;

   C.insertar(v, C.primera());
   do {
      C.insertar(P[v], C.primera());
      v = P[v];
   } while (v != orig);
   return C;
}

/* Precondiciones: las casillas de las paredes son casillas del laberinto
                   las casillas de Entrada y Salida son casillas del laberinto
*/
template <typename tCoste>
tCoste resolverLaberinto(const int dimension,           // Dimensiones del laberinto cuadrado
                         const vector<Pared>& paredes,  // Lista de paredes del laberinto
                         const Casilla entrada,         // Entrada al alberinto
                         const Casilla salida,          // Salida del laberinto
                         vector<Casilla>& path)         // Camino de Casillas donde se devuelve el camino solucion
{
    typedef GrafoP<tCoste>::vertice vertice;
    static const tCoste inf = GrafoP<tCoste>::INFINITO;

    GrafoP<tCoste> G(dimension * dimension);    // Un vertice por casilla
    size_t n = G.numVert();

    // Rellenar matriz de costes con 1 en casillas adyacentes
    for(vertice i = 0 ; i < n ; i++)
        for(vertice j = 0 ; j < n ; j++)
            if(adyacentes(verticeToNodo(i, n), verticeToNodo(i, n))) // Son adyacentes
                G[i][j] = 1;
    
    // Cerramos el camino entre casillas con paredes en medio
    for(Pared p : paredes){
        vertice c1 = CasillaToNodo(p.c1), 
                c2 = CasillaToNodo(p.c2);
        G[c1][c2] = G[c2][c1] == GrafoP<tCoste>::INFINITO;
    }


    // Aplicamos Dijkstra
    vector<tCoste> P;
    vector<tCoste> costesMin = Dijkstra(L, casillaToVertice(entrada, n), P);

    // Guardar camino de entrada a salida
    vector<vertice> c = camino(casillaToVertice(entrada, n), casillaToVertice(salida, n), P);

    // Pasar de vertices a Casillas
    for(size_t k = 0 ; k < c.size() ; k++)
        path[k] = verticeToCasilla(c[k], n);

    return costesMin[casillaToVertice(salida, n)];
}
