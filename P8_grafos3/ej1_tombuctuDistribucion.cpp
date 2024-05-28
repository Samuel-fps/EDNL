#include "../TAD_GRAFO/alg_grafoMA.h"
#include "../TAD_GRAFO/alg_grafoPMC.h"
#include "alg_grafo_E-S.h"
#include "particion.h"
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

/*
Usar particiones, cuidado con cumplir condiciones
primero comprobar si estan juntos, y luego yusamos encontrar para unirlo al representante
Se puede usar warshall
*/

typedef struct{
    double x, y;
} Ciudad;

// Distancia euclidea entre dos ciudades
double distanciaCiudades(Ciudad c1, Ciudad c2){
    return sqrt(pow(c2.x - c1.x, 2) + pow(c2.y - c1.y, 2));
}

template <typename tCoste>
Particion tombuctuDistribucion(const vector<Ciudad>& ciudades,  // Vector ciudades(x, y)
                               const matriz<bool>& ady,         // matriz adyacencia
                               matriz<tCoste>& costesMin)       // Costes minimos entre ciudades
{
    typedef GrafoPMC::vertice vertice;
    size_t N = ady.dimension();
    GrafoP<tCoste> C(N);

    // Unir cada ciudad con su isla
    Particion islas(N); // Particion de n ciudades
    for(int i=0 ; i < n ; i++)
        for(int j=0 ; j < n ; j++)
            if(ady[i][j] && islas.encontrtar(i) != islas.encontrar(j)) // Son adyacentes && Aun no la hemos unido a la isla (precondicion unir)
                islas.unir(i, j);

    // Crear matriz de costes
    for(vertice i=0 ; i < N ; i++)
        for(vertice j=0 ; j < N ; j++)
            if(ady[i][j])
                C[i][j] = distanciaCiudades(ciudades[i], ciudades[j]);

    // Calcular costes minimos
    matriz<vertice> P;
    costesMin = Floyd(C, P);

    return islas;
}
