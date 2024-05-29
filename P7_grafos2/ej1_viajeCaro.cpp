#include "../TAD_GRAFO/alg_grafoPMC.h"
#include "alg_grafo_E-S.h"
#include <iostream>
#include <vector>;

/*  EJERCICIO 1

    Tu agencia de viajes “OTRAVEZUNGRAFO S.A.”  se enfrenta a un curioso cliente. 
    Es  un  personaje  sorprendente,  no  le  importa  el  dinero  y  quiere  hacer  el  viaje  más  caro  
    posible  entre  las  ciudades  que  ofertas.  Su  objetivo  es  gastarse  la  mayor  cantidad  de  
    dinero posible (ojalá todos los clientes fueran así), no le importa el origen ni el destino 
    del viaje. 
    Sabiendo que es imposible pasar dos veces por la misma ciudad, ya que casualmente 
    el grafo de tu agencia de viajes resultó ser acíclico, devolver el coste, origen y destino 
    de tan curioso viaje. Se parte de la matriz de costes directos entre las ciudades del grafo.
*/

template <typename tCoste>
matriz<tCoste> FloydMax(const GrafoP<tCoste>& G,
                        matriz<typename GrafoP<tCoste>::vertice>& P)
{
   typedef typename GrafoP<tCoste>::vertice vertice;
   const size_t n = G.numVert();
   matriz<tCoste> A(n);   // matriz de costes maximos

   // Iniciar A y P con caminos directos entre cada par de vértices.
   P = matriz<vertice>(n);
   for (vertice i = 0; i < n; i++) {
      A[i] = G[i];                    // copia costes del grafo
      A[i][i] = 0;                    // diagonal a 0
      P[i] = vector<vertice>(n, i);   // caminos directos
   }
   // Calcular costes maximos y caminos correspondientes
   // entre cualquier par de vértices i, j
   for(vertice k = 0; k < n; k++)
      for(vertice i = 0; i < n; i++)
         for(vertice j = 0; j < n; j++) {
            tCoste ikj = suma(A[i][k], A[k][j]);
            if(ikj > A[i][j]) {
               A[i][j] = ikj;
               P[i][j] = k;
            }
         }
   return A;
}

 template <typename tCoste>
 tCoste viajeCaro(const GrafoP<tCoste>& G,
                  typename GrafoP<tCoste>::vertice& origen,
                  typename GrafoP<tCoste>::vertice& destino)
{
    typedef typename GrafoP<tCoste>::vertice vertice;
    size_t n = G.numVert();
    tCoste max;
    matriz<tCoste> costes;
    matriz<vertice> rutas;
    
    costes = FloydMax(G, rutas);

    tCoste costeMax = 0;
    for(size_t i = 0 ; i < n ; ++i){
        for(size_t j = 0 ; j < n ; ++j){
            if(costes[i][j] > costeMax){
                costeMax = costes[i][j];
                origen = i;
                destino = j;
            }
        }
    }

    return costeMax;
}
