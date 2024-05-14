#include "../TAD_GRAFO/alg_grafoPMC.h"
#include "alg_grafo_E-S.h"
#include <iostream>
#include <vector>;

/*  EJERCICIO 5

    Se dispone de tres grafos que representan la matriz de costes para viajes en un  
    determinado país pero por diferentes medios de transporte, por supuesto todos los grafos 
    tendrán el mismo número de nodos. El primer grafo representa los costes de ir por
    carretera, el segundo en tren y el tercero en avión. Dado un viajero que dispone de una 
    determinada cantidad de dinero, que es alérgico a uno de los tres medios de transporte, y 
    que sale de una ciudad determinada, implementar un subprograma que determine las
    ciudades a las que podría llegar nuestro infatigable viajero.
*/

enum Alergia{coche, tren, avion};

template <typename tCoste>
vector<bool> transporte(const GrafoP<tCoste>& T1,
                const GrafoP<tCoste>& T2,
                const typename GrafoP<tCoste>::vertice& origen,
                tCoste dinero)
{
    typedef typename GrafoP<tCoste>::vertice vertice;
    static const tCoste INF = GrafoP<tCoste>::INFINITO;

    size_t n = A.numVert()
    vector<bool> alcanzables(n);

    vector<tCoste> P;


    for(vertice i = 0 ; i < n ; i++){
        for(vertice j = 0 ; j < n ; j++){
            std::min(carretera[i][j], tren[i][j])
        }
    }
}

template <typename tCoste>
vector<bool> viajeAlergia(const GrafoP<tCoste>& C,
                const GrafoP<tCoste>& T,
                const GrafoP<tCoste>& A,
                const typename GrafoP<tCoste>::vertice& origen,
                tCoste dinero,
                Alergia alergia)
{
    vector<bool> resultado;
    switch(alergia){
        case coche:
            resultado = transporte(T, A, origen, dinero);
            break;
        case avion:
            resultado = transporte(T, C, origen, dinero);
            break;
        case tren:
            resultado = transporte(C, A, origen, dinero);
            break;
    }

    return resultado;
}


int main() {
    GrafoP<int> grafo("GrafoA.txt");

    std::cout << grafo;

    // LLamada a funcion de ejercicio
    // disMinZuelandia(grafo, ciudadesTomadas, estadoCarreteras, capital);

    // Imprimir el resultado

    return 0;
}