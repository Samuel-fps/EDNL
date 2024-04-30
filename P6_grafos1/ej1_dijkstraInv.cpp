#include "../TAD_GRAFO/alg_grafoPMC.h"
#include "alg_grafo_E-S.h"

/*  EJERCICIO 1

    Añadir una función genérica, llamada DijkstraInv, en el fichero alg_grafoPMC.h 
    para resolver el problema inverso al de Dijkstra, con los mismos tipos de parámetros
    y de resultado que la función ya incluida para éste. La nueva función, por tanto, 
    debe hallar el camino de coste mínimo hasta un destino desde cada vértice del grafo 
    y su correspondiente coste. 
*/

template <typename tCoste>
vector<tCoste> Dijkstra(const GrafoP<tCoste>& G,
                        typename GrafoP<tCoste>::vertice origen,
                        vector<typename GrafoP<tCoste>::vertice>& P){

}

int main(){

}