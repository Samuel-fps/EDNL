#include "../TAD_GRAFO/alg_grafoPMC.h"
#include "alg_grafo_E-S.h"
#include <iostream>
#include <vector>

/*  EJERCICIO 2

    El archipiélago de Tombuctú2 está formado por un número desconocido de islas, cada una de las 
    cuales tiene, a su vez, un número desconocido de ciudades, las cuales tienen en común que todas
    y cada una de ellas dispone de un aeropuerto. Sí que se conoce el número total de ciudades del
    archipiélago (podemos llamarlo N, por ejemplo). Dentro de cada una de las islas existen 
    carreteras que permiten viajar entre todas las ciudades de la isla. No existen puentes que 
    unan las islas y se ha decidido que la opción de comunicación más económica de implantar será
    el avión. Se dispone de las coordenadas cartesianas (x, y) de  todas y cada una de las 
    ciudades del archipiélago. Se dispone de un grafo (matriz de adyacencia) en el que se indica 
    si existe carretera directa entre cualesquiera dos ciudades del archipiélago. El objetivo de 
    nuestro problema es encontrar qué líneas aéreas debemos implantar para poder viajar entre todas 
    las ciudades del archipiélago, siguiendo los siguientes criterios:

        1. Se implantará una y sólo una  línea aérea entre cada par de islas.
        2. La línea aérea escogida entre cada par de islas será la más corta entre todas las posibles.

    Así pues, dados los siguientes datos:
        - Lista de ciudades de Tombuctú2 representada cada una de ellas por sus coordenadas cartesianas.
        - Matriz de adyacencia de Tombuctú que indica las carreteras existentes en dicho archipiélago,
        
    Implementen un subprograma que calcule y devuelva las líneas aéreas necesarias para comunicar 
    adecuadamente el archipiélago  siguiendo los criterios anteriormente expuestos.
    
*/

/*Está pidiendo un grafo completo

Numero de islas N - 1 cada vez que unamos particion
el bucle interno empezarlo por i para no meter dos veces la misma ciudad
matriz bool para saber si ya hemos visitado una isla*/

typedef struct{
    int x, y;
} Ciudad;

// Distancia euclidea entre ciudades
double distancia(Ciudad c1, Ciudad c2) {
    return sqrt(pow(c2.x - c1.x, 2) + pow(c2.y - c1.y, 2));
}

template <typename tCoste>
matiz<tCoste> tombuctuAereas(const vector<Ciudad>& Ciudades, // Lista de ciudades de Tombuctú2
                                   const matriz<bool>& A)    // Matriz de adyacencia de Tombuctú
{
    typedef GrafoP<tCoste>::vertice vertice;
    size_t N = A.dimension();
    
}

int main() {
    GrafoP<int> grafo("GrafoA.txt");

    std::cout << grafo;

    // LLamada a funcion de ejercicio

    // Imprimir el resultado

    return 0;
}