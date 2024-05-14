#include "../TAD_GRAFO/alg_grafoPMC.h"
#include "alg_grafo_E-S.h"
#include <iostream>
#include <vector>;

/*  EJERCICIO 8

    “UN SOLO TRANSBORDO, POR FAVOR”. Este es el título que reza en tu
    flamante compañía de viajes. Tu publicidad explica, por supuesto, que ofreces viajes
    combinados de TREN y/o AUTOBÚS (es decir, viajes en tren, en autobús, o usando
    ambos), entre N ciudades del país, que ofreces un servicio inmejorable, precios muy
    competitivos, y que garantizas ante notario algo que no ofrece ninguno de tus
    competidores: que en todos tus viajes COMO MÁXIMO se hará un solo transbordo
    (cambio de medio de transporte).

    Bien, hoy es 1 de Julio y comienza la temporada de viajes.
    ¡Qué suerte! Acaba de aparecer un cliente en tu oficina. Te explica que quiere viajar
    entre dos ciudades, Origen y Destino, y quiere saber cuánto le costará.
    Para responder a esa pregunta dispones de dos grafos de costes directos (matriz de
    costes) de viajar entre las N ciudades del país, un grafo con los costes de viajar
    en tren y otro en autobús.

    Implementa un subprograma que calcule la tarifa mínima en estas condiciones.
    Mucha suerte en el negocio, que la competencia es dura.
*/

template <typename tCoste> 
double rutaCosteMin(const GrafoP<tCoste>& Tren,
                    const GrafoP<tCoste>& Bus,
                    const GrafoP<tCoste>::vertice origen,
                    const GrafoP<tCoste>::vertice destino)
{
    typedef GrafoP<tCoste>::vertice vertice;
    size_t N = Tren.numVert();

    matriz<vertice> RutaTren, RutaBus;
    matriz<tCoste> minTren = Floyd(Tren, RutaTren),
                   minBus = Floyd(Bus, RutaBus);

    grafoP<tCoste> Costes(N);
}

int main() {
    GrafoP<int> grafo("GrafoA.txt");

    std::cout << grafo;

    // LLamada a funcion de ejercicio
    // disMinZuelandia(grafo, ciudadesTomadas, estadoCarreteras, capital);

    // Imprimir el resultado

    return 0;
}