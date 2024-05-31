#include "../TAD_GRAFO/alg_grafoPMC.h"

typedef struct {
    size_t x, y;
} Casilla;

template <typename tCoste>
GrafoP<tCoste> CasillaToNodo(const Casilla& c, int N){
    return c.x * N + c.y;
}

template <typename tCoste>
Casilla nodoToCasilla(const GrafoP<tCoste>::vertice& n, int N){
    Casilla c;
    c.x = n / N;
    c.y = n % N;
    return c;
}

template <typename tCoste>
tCoste numSaltos(const int n, const int m,
                 const vector<Casilla>& trampas,
                 const vector<Casilla>& caballeros)
{
    typedef GrafoP<tCoste>::vertice vertice;
    tCoste nSaltos=0;
    size_t N = n*m;

    for(Casilla t : trampas){
        vertice trampa = CasillaToNodo(t, N);
    }

    GrafoP<tCoste> L(N);
    for(vertice i=0 ; i < N ; i++){
        for(vertice j=0 ;j < N ; j++){
            
        }
    }

    return nSaltos;
}