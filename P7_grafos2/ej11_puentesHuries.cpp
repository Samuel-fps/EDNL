#include "../TAD_GRAFO/alg_grafoPMC.h"
#include "alg_grafo_E-S.h"
#include <iostream>
#include <vector>

/*  EJERCICIO 11

    Disponemos de tres grafos (matriz de costes) que representan los costes directos de viajar entre
    las ciudades de tres de las islas del archipiélago de las Huríes (Zuelandia).  

    Para poder viajar de una isla a otra se dispone de una serie de puentes que conectan ciudades de
    las diferentes islas a un precio francamente asequible (por decisión del Prefecto de las Huríes,
    el uso de los puentes es absolutamente gratuito).

    Si el alumno desea simplificar el problema, puede numerar las N1 ciudades de la isla
    1, del 0 al N1-1, las N2 ciudades de la isla 2, del N1 al N1+N2-1, y las N3 de la última, del
    N1+ N2 al N1+N2+ N3-1.

    Disponiendo de las tres matrices de costes directos de viajar dentro de cada una de
    las islas, y la lista de puentes entre ciudades de las mismas, calculad los costes mínimos
    de viajar entre cualesquiera dos ciudades de estas tres islas.
    ¡¡¡ QUE DISFRUTÉIS EL VIAJE !!!
*/

typedef struct {
    size_t origen, destino;
} Puente;

template <typename tCoste>
matriz<tCoste> puentesHuries(const GrafoP<tCoste>& I1,
                             const GrafoP<tCoste>& I2,
                             const GrafoP<tCoste>& I3,
                             const vector<Puente> Puentes)
{
    typedef GrafoP<tCoste>::vertice vertice;
    size_t n1 = I1.numVert(), n2 = I2.numVert(), n3 = I3.numVert(); // Número de ciudades en cada isla
    size_t n = n1 + n2 + n3; // Número de ciudades totales
    GrafoP<tCoste> A(n);

    // Coste 0 de viajar por los puentes
    for(Puente p : Puentes){
        A[p.origen][p.destino] = 0;
        A[p.destino][p.origen] = 0;
    }

    // Rellenar con la matriz de costes isla 1
    for(vertice i=0 ; i < n1 ; i++)
        for(vertice j=0 ; j < I.numVert() ; j++)
            A[i][j] = I1[i][j];

    // Rellenar con la matriz de costes isla 2
    for(vertice i=n1  ; i < n1+n2 ; i++)
        for(vertice j=0 ; j < I.numVert() ; j++)
            A[i][j] = I2[i][j];

    // Rellenar con la matriz de costes isla 3
    for(vertice i=n1+n2 ; i < n1+n2+n3 ; i++)
        for(vertice j=0 ; j < I.numVert() ; j++)
            A[i][j] = I3[i][j];
    
    matriz<vertice> P;
    matriz<tCoste> Costes = Floyd(A, P);

    return A;
}


int main() {
    GrafoP<int> grafo("GrafoA.txt");

    std::cout << grafo;

    // LLamada a funcion de ejercicio
    // disMinZuelandia(grafo, ciudadesTomadas, estadoCarreteras, capital);

    // Imprimir el resultado

    return 0;
}