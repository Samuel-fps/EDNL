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

template <typename tCoste>
vector<bool> transporte(const GrafoP<tCoste>& C,
                const GrafoP<tCoste>& T,
                const GrafoP<tCoste>& A,
                const typename GrafoP<tCoste>::vertice& origen,
                tCoste dinero)
{
    typedef typename GrafoP<tCoste>::vertice vertice;
    static const tCoste INF = GrafoP<tCoste>::INFINITO;

    size_t n = A.numVert()
    vector<bool> alcanzables(n);

    matriz<tCoste> P;
    matriz<tCoste> carretera = Floyd(C, P);
    matriz<tCoste> tren = Floyd(T, P);
    matriz<tCoste> avion = Floyd(A, P);

    for(vertice i = 0 ; i < n ; i++){
        for(vertice j = 0 ; j < n ; j++){
            std::min(carretera[i][j], tren[i][j])
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