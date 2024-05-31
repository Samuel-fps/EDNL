#include "../TAD_GRAFO/alg_grafoPMC.h"

typedef struct {
    size_t x, y;
} Casilla;

template <typename tCoste>
tCoste numSaltos(const int n, const int m,
                 const vector<Casilla>& trampas,
                 const vector<Casilla>& caballeros)
{
    typedef GrafoP<tCoste>::vertice vertice;
    tCoste nSaltos=0;
    size_t N = n*m; 

    GrafoP<tCoste> L(N);
    for(vertice i=0 ; i < )

    return nSaltos;
}