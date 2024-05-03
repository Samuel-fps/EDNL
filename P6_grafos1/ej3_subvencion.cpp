#include "../TAD_GRAFO/grafoPMC.h"
#include "alg_grafo_E-S.h"
#include <iostream>

/*  EJERCICIO 3

    Tu empresa de transportes “PEROTRAVEZUNGRAFO S.A.” acaba de recibir la lista de
    posibles subvenciones del Ministerio de Fomento en la que una de las más jugosas
    se concede a las empresas cuyo grafo asociado a su matriz de costes sea acíclico.
    ¿Puedes pedir esta subvención?
    Implementa un subprograma que a partir de la matriz de costes nos indique si tu
    empresa tiene derecho a dicha subvención.
*/

template <typename tCoste>
bool esAciclico_rec(typename GrafoP<tCoste>::vertice i,
                  std::vector<typename GrafoP<tCoste>::vertice> &visitado,
                  const GrafoP<tCoste> &G)
{
  typedef typename GrafoP<tCoste>::vertice vertice;
  static const tCoste INF = GrafoP<tCoste>::INFINITO;
  const size_t N = G.numVert();

  visitado.push_back(i);

  for (vertice j = 0; j < N; j++)
    if (i != j && // No visitamos la arista i->i (que no es "realmente" una arista)
        G[i][j] != INF && // Visitamos sólo aristas que existen
        (std::find(visitado.begin(), visitado.end(), j) != visitado.end() ||
        // Si j ya existe en el camino original, entonces hay ciclo
        !esAciclico_rec(j, visitado, G)
    ))
      return false; // Entonces el grafo no es acíclico

  visitado.pop_back();
  return true;
}

template <typename tCoste>
bool esSubvencionable(const GrafoP<tCoste>& G){
    typedef typename GrafoP<tCoste>::vertice vertice;
    static const tCoste INF = GrafoP<tCoste>::INFINITO;
    const size_t n = G.numVert();
    std::vector<vertice> visitado;

    for (vertice i = 0 ; i < n ; i++)
        if (!esAciclico_rec(i, visitado, G))
            return false;
    return true;
}

int main(){
    GrafoP<int> grafo("GrafoA.txt");

    std::cout << grafo;

    // LLamada a funcion de ejercicio
    if(esSubvencionable(grafo)) // Imprimir el resultado
        std::cout << "Puedes pedir la subvencion" << std::endl;
    else
        std::cout << "No es posible pedir la subvencion" << std::endl;
    
    return 0;
}