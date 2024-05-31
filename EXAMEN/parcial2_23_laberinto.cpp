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

bool alcanzable(const Casilla& fauno, const Casilla& c){
    return abs(fauno.x - c.x) + abs(fauno.y - c.y) == 3 
            && fauno.x != c.x  
            && fauno.y != c.y;
}

bool ady(const Casilla& c1, const Casilla& c2){
    return abs(c1.x - c2.x) + abs(c1.y - c2.y) == 1;
}

template <typename tCoste>
tCoste numSaltos(const int n, const int m,
                 const vector<Casilla>& trampas,
                 const vector<Casilla>& caballeros)
{
    typedef GrafoP<tCoste>::vertice vertice;
    size_t N = n*m;

    GrafoP<tCoste> L(N);
    for(vertice i=0 ; i < N ; i++){ // O(n^3)
        for(vertice j=0 ; j < N ; j++){
            if(alcanzable(CasillaToNodo(i), casillaToNodo(j))){ // Esta dentro de los movimientos del cababallo
                L[i][j] = 1;
                // ver si la casilla destino es adyacente a un caballero
                for(Casilla caballero : caballeros){
                    if(caballero, ady(nodoToCasilla(j))){
                        L[i][j] = GrafoP<tCoste>::INFINITO;
                    }
                }
            }

        }
    }

    for(Casilla trampa : trampas){ // O(n^2)
        vertice nTrampa = CasillaToNodo(trampa, N);
        for(vertice i=0 ; i < N ; i++){
            L[nTrampa][i] = L[i][nTrampa] = GrafoP<tCoste>::INFINITO;
        }
    }

    vertice origen = CasillaToNodo(Casilla(0,0)),
            destino = CasillaToNodo(Casilla(n-1,m-1));

    vector<vertice> P;
    vector<tCoste> costes = Dijkstra(L, origen, P);

    return costes[destino];
}