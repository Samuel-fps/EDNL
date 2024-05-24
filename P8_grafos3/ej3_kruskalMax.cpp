#include "../TAD_GRAFO/alg_grafoPMC.h"
#include "alg_grafo_E-S.h"
#include <iostream>
#include <vector>

/*  EJERCICIO 3

    Implementa un subprograma para encontrar un árbol de extensión máximo. 
    ¿Es más difícil que encontrar un árbol de extensión mínimo?

    SOLUCIÓN
        - Tiene la misma complejidad el maximo que el minimo.
        - En este caso usaría el mismo algoritmo de kruskal pero usando un APO invertido que tenga
        el máximo en la cima, de esta forma el algoritmo cogería siempre la arista de mayor coste.
*/

template <typename tCoste>
void kruskalMax(const GrafoP<tCoste>& G)
// Devuelve un árbol generador de coste máximo
// de un grafo no dirigido ponderado y conexo G.
{
    assert(!G.esDirigido());

   typedef typename GrafoP<tCoste>::vertice vertice;
   typedef typename GrafoP<tCoste>::arista arista;
   const tCoste INFINITO = GrafoP<tCoste>::INFINITO;
   const size_t n = G.numVert();
   GrafoP<tCoste> g(n);     // Árbol generador de coste máximo
   Particion P(n);          // Partición inicial del conjunto de vértices de G.
   Apo<arista> A(n*n);      // Aristas de G ordenadas por costes teniendo max en la cima.
    
    // Copiar aristas del grafo G en el APO A.
   for (vertice u = 0; u < n; u++)
      for (vertice v = u+1; v < n; v++)
         if(G[u][v] != INFINITO)
            A.insertar(arista(u, v, G[u][v]));

   size_t i = 1;
   while (i <= n-1) {   // Seleccionar n-1 aristas.
      arista a = A.cima(); // arista de mayor coste
      A.suprimir();
      vertice u = P.encontrar(a.orig);
      vertice v = P.encontrar(a.dest);
      if (u != v) { // Los extremos de a pertenecen a componentes distintas
         P.unir(u, v);
         // Incluir la arista a en el árbol g
         g[a.orig][a.dest] = g[a.dest][a.orig] = a.coste;
         i++;
      }
   }
   return g;
}
