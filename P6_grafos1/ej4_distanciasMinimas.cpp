#include "../TAD_GRAFO/alg_grafoPMC.h"
#include "alg_grafo_E-S.h"
#include <iostream>

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
void viajeCiudades(const GrafoP<tCoste>& G){

}


int main() {
    GrafoP<int> grafo("GrafoA.txt");

    std::cout << grafo;

    // LLamada a funcion de ejercicio
    viajeCiudades(grafo);

    // Imprimir el resultado

    return 0;
}