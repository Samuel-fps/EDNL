#include "../TAD_GRAFO/alg_grafoPMC.h"
#include "alg_grafo_E-S.h"
#include <iostream>
#include <vector>

/*  EJERCICIO 6

    La empresa EMASAJER S.A. tiene que unir mediante canales todas las ciudades del valle del Jerte (Cáceres),
    teniendo en cuenta las siguientes premisas:

        - El coste de abrir cada nuevo canal es casi prohibitivo, luego la solución final debe tener un número mínimo de canales.
        - El Ministerio de Fomento nos subvenciona por m3/sg de caudal, luego el conjunto de los canales debe admitir el mayor caudal posible,
          pero por otra parte, el coste de abrir cada canal es proporcional a su longitud, por lo que el conjunto de los canales también 
          debería medir lo menos posible. Así pues, la solución óptima debería combinar adecuadamente ambos factores.

    Dada la matriz de distancias entre las diferentes ciudades del valle del Jerte, otra matriz con los 
    diferentes caudales máximos admisibles entre estas ciudades teniendo en cuenta su orografía, la subvención
    que nos da Fomento por m3/sg. de caudal y el coste por km. de canal, implementen un subprograma que calcule
    qué canales y de qué longitud y caudal deben construirse para minimizar el coste total de la red de canales.
*/

template <typename tCoste>
GrafoP<tCoste> constriurPuente(const GrafoP<tCoste>& distancias,
                               const GrafoP<tCoste>& caudales,
                               const double subvencion,
                               const double costeKm)
{
    typedef GrafoP<tCoste>::vertice vertice;
    size_t n = distancias.numVert();
    GrafoP<tCoste> caudalKm(n),
                   canales(n);

    for(vertice i=0 ; i < n ; i++)
        for(vertice j=0 ; j < n ; j++)
            caudalKm[i][j] = caudalKm[j][i] = distancias[i][j] * costeKm - caudales[i][j] * subvencion;

    return kruskall(caudalKm);
}