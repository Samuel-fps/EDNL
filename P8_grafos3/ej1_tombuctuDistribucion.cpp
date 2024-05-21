#include "../TAD_GRAFO/alg_grafoMA.h"
#include "../TAD_GRAFO/alg_grafoPMC.h"
#include "alg_grafo_E-S.h"
#include <iostream>
#include <vector>

/*  EJERCICIO 1

    El archipiélago de Tombuctú, está formado por un número indeterminado de islas, cada una de las
    cuales tiene, a su vez, un número indeterminado de ciudades. En cambio, sí es conocido el 
    número total de ciudades de Tombuctú (podemos llamarlo N, por ejemplo). Dentro de cada una de 
    las islas existen carreteras que permiten viajar entre todas las ciudades de la isla. Se 
    dispone de las coordenadas cartesianas (x, y) de todas y cada una de las ciudades del 
    archipiélago. Se dispone de un grafo (matriz de adyacencia) en el que se indica si existe 
    carretera directa entre cualesquiera dos ciudades del archipiélago. El objetivo de nuestro 
    problema es encontrar qué ciudades de Tombuctú pertenecen a cada una de las islas del mismo y 
    cuál es el coste mínimo de viajar entre cualesquiera dos ciudades de una misma isla de Tombuctú.
    
    Así pues, dados los siguientes datos:

        - Lista de ciudades de Tombuctú representada cada una de ellas por sus coordenadas cartesianas.
        - Matriz de adyacencia de Tombuctú, que indica las carreteras existentes en dicho archipiélago.

    Implementen un subprograma que calcule y devuelva la distribución en islas de las ciudades de 
    Tombuctú, así como el coste mínimo de viajar entre cualesquiera dos ciudades de una misma isla del
    archipiélago.    
*/

typedef struct{
    int x, y;
} Ciudad;

// Distancia euclidea
double distancia(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

template <typename tCoste>
void constriurPuente(const vector<Ciudad>& Ciudades,
                     const GrafoMA& A)
{
    typedef GrafoMA::vertice vertice;
    size_t N = A.numVert();
    GrafoP<tCoste> C(N);

    for(vertice i=0 ; i < N ; i++)
        for(vertice j=0 ; j < N ; j++){
            if(A[i][j]) // Son adyacentes
                C[i][j] = distancia()
        }

    
}

// Se puede hacer algo como en el laberinto

int main() {
    GrafoP<int> grafo("GrafoA.txt");

    std::cout << grafo;

    // LLamada a funcion de ejercicio

    // Imprimir el resultado

    return 0;
}