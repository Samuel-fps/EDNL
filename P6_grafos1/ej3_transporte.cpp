#include "../TAD_GRAFO/alg_grafoPMC.h"
#include "alg_grafo_E-S.h"
#include <iostream>

/*  EJERCICIO 2

    Tu empresa de transportes “PEROTRAVEZUNGRAFO S.A.” acaba de recibir la lista de
    posibles subvenciones del Ministerio de Fomento en la que una de las más jugosas
    se concede a las empresas cuyo grafo asociado a su matriz de costes sea acíclico.
    ¿Puedes pedir esta subvención?
    Implementa un subprograma que a partir de la matriz de costes nos indique si tu
    empresa tiene derecho a dicha subvención.
*/

template <typename tCoste>
bool esSubvencionable(const GrafoP<tCoste>& G){

}


int main() {
    GrafoP<int> grafo("GrafoA.txt");

    std::cout << grafo;

    // LLamada a funcion de ejercicio
    if(esSubvencionable(grafo)) // Imprimir el resultado
        std::cout << "Puedes pedir la subvencion" << std::endl;
    else
        std::cout << "No es posible pedir la subvencion" << std::endl;
    
    return 0;
}