#include "../TAD_GRAFO/alg_grafoPMC.h"

struct Casilla{
    int x, y, z;
};

bool adyacentes(const Casilla& c1, const Casilla& c2){
     return 1 == std::abs(c1.x - c2.x) + std::abs(c1.y - c2.y) + std::abs(c1.z - c2.z);
}

template <typename tCoste>
GrafoP<tCoste>::vertice casillaToNodo(const Casilla& c, const int N){
    return c.x + c.y*N + c.z*(N*N);
}

template <typename tCoste>
Casilla nodoToCasilla(typename GrafoP<tCoste>::vertice nodo, const int N){
    Casilla c;
    c.x = nodo % N;
    c.y = (nodo / N) % N;
    c.z = nodo / (N*N);
    return c;
}

template <typename tCoste>
tCoste laberinto3d(const int N,
                 const vector<Casilla>& piedras,
                 const Casilla& entrada,
                 const Casilla& salida){
    typedef typename GrafoP<tCoste>::vertice vertice;
    size_t n = N*N*N;
    GrafoP<tCoste> L(n);

    for(vertice i=0 ; i < n ; i++)
        for(vertice j=0 ; j < n ; j++)
            if(adyacentes(nodoToCasilla(i), nodoToCasilla(j)))
                L[i][j] = L[j][i] = 1;

    for(Casilla piedra : piedras){
        vertice p = casillaToNodo(piedra);
        for(vertice i=0 ; i < n ; i++)
            L[p][i] = L[i][p] = GrafoP<tCoste>:INFINITO;
    }

    vector<vertice> P;
    vector<tCoste> costeMin = Dijkstra(L, casillaToNodo(entrada), P);

    return costesMin[casillaToNodo(salida)];
}

/*
template <typename tCoste>
GrafoP<tCoste>{
    public:
        explicit GrafoP(size_t N);
        size_t numVert();
    private:
        vector<vector<tCoste>> costes;
}

template <typename tCoste>
Dijkstra(const GrafoP<tCoste>& G, 
         typename GrafoP<tCoste>::vertice origen,
         vector<typename GrafoP<tCoste>::vertice>& P;)

*/