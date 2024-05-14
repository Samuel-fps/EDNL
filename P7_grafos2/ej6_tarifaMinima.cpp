#include "../TAD_GRAFO/alg_grafoPMC.h"
#include "alg_grafo_E-S.h"
#include <iostream>
#include <vector>;

/*  EJERCICIO 6

    Al dueño de una agencia de transportes se le plantea la siguiente situación. La
    agencia de viajes ofrece distintas trayectorias combinadas entre N ciudades españolas
    utilizando tren y autobús. Se dispone de dos grafos que representan los costes (matriz de
    costes) de viajar entre diferentes ciudades, por un lado en tren, y por otro en autobús
    (por supuesto entre las ciudades que tengan línea directa entre ellas). Además coincide
    que los taxis de toda España se encuentran en estos momentos en huelga general, lo que
    implica que sólo se podrá cambiar de transporte en una ciudad determinada en la que,
    por casualidad, las estaciones de tren y autobús están unidas.
    Implementa una función que calcule la tarifa mínima (matriz de costes mínimos) de
    viajar entre cualesquiera de las N ciudades disponiendo del grafo de costes en autobús,
    del grafo de costes en tren, y de la ciudad que tiene las estaciones unidas.
*/

template <typename tCoste> 
double tarifaMinima(const GrafoP<tCoste>& Bus,
                    const GrafoP<tCoste>& Tren,
                    const GrafoP<tCoste>::vertice& cambio){
    typedef GrafoP<tCoste>::vertice vertice;
    size_t N = G.numVert();

    matriz<tCoste> P;
    matriz<tCoste> minBus = Floyd(Bus, P);
    matriz<tCoste> minTren = Floyd(Tren, P);

    GrafoP<tCoste> Costes(N);
    for(vertice i = 0 ; i < N ; i++){
        for(vertice j = 0 ; j < N ; i++){
            Costes[i][j] = std::min(minBus[i][j], minTren[i][j]);
        }
    }
}


int main() {
    GrafoP<int> grafo("GrafoA.txt");

    std::cout << grafo;

    // LLamada a funcion de ejercicio
    // disMinZuelandia(grafo, ciudadesTomadas, estadoCarreteras, capital);

    // Imprimir el resultado

    return 0;
}