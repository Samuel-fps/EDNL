#include "../TAD_GRAFO/alg_grafoPMC.h"

template <typename tCoste>
void capitalToxica(const GrafoP<tCoste>& costes,
                   typename GrafoP<tCoste>::vertice capital){

    typedef typename GrafoP<tCoste>::vertice vertice;
    size_t n = costes.numVert();

    for(vertice i=0 ; i < n ; i++){
        costes[capital][i] = costes[i][capital] = GrafoP<tCoste>::INFINITO;
    }

    matriz<vertice> P;
    matriz<tCoste> Floyd(costes, P);

    // Creo que falta información en el enunciado
}