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


int main() {
    GrafoP<int> grafo("GrafoA.txt");

    std::cout << grafo;

    // LLamada a funcion de ejercicio
    // disMinZuelandia(grafo, ciudadesTomadas, estadoCarreteras, capital);

    // Imprimir el resultado

    return 0;
}