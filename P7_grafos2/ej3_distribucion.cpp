#include "../TAD_GRAFO/alg_grafoPMC.h"
#include "alg_grafo_E-S.h"
#include <iostream>
#include <vector>
#include <algorithm>

/*  EJERCICIO 3

    Eres el orgulloso dueño de una empresa de distribución. Tu misión radica en distribuir todo tu stock entre las
    diferentes ciudades en las que tu empresa dispone de almacén.
    Tienes un grafo representado mediante la matriz de costes, en el que aparece el coste (por unidad de producto)
    de transportar los productos entre las diferentes ciudades del grafo.
    Pero además resulta que los Ayuntamientos de las diferentes ciudades en las que tienes almacén están muy 
    interesados en que almacenes tus productos en ellas, por lo que están dispuestos a subvencionarte con un 
    porcentaje de los gastos mínimos de transporte hasta la ciudad. Para facilitar el problema, consideraremos 
    despreciables los costes de volver el camión a su base (centro de producción). 
    
    He aquí tu problema. Dispones de 
    
        - el  centro  de  producción, nodo origen en el que tienes tu producto (no tiene almacén), 
        - una cantidad de unidades de producto (cantidad), 
        - la matriz de costes del grafo de distribución con N ciudades, 
        - la capacidad de almacenamiento de cada una de ellas, 
        - el porcentaje de subvención (sobre los gastos mínimos) que te ofrece cada Ayuntamiento.

    Las diferentes ciudades (almacenes) pueden tener distinta  capacidad, y además la capacidad total puede ser 
    superior a la cantidad disponible de producto, por lo que debes decidir cuántas unidades de producto almacenas
    en cada una de las ciudades.
    Debes tener en cuenta además las subvenciones que recibirás de los diferentes Ayuntamientos, las cuales pueden
    ser distintas en cada uno y estarán entre el 0% y el 100% de los costes mínimos.
    La solución del problema debe incluir las cantidades a almacenar en cada ciudad bajo estas condiciones y el
    coste mínimo total de la operación de distribución para tu empresa.
*/

// Asumimos que en un trayecto se puede llevar todo el producto que cabe en un almacen y que no hacen faltan mas viajes
// Almacenes es el vector de tamaño n con la cantidad de producto en cada almacen
// Devuelve el coste total de llevar los productos a cada almacen
template <typename tCoste, typename capacidad>
tCoste distribucion(typename GrafoP<tCoste>::vertice origen,
                    unsigned cantidad,
                    const GrafoP<tCoste>& costes,
                    const std::vector<capacidad>& capacidades,
                    const std::vector<double>& subvenciones,
                    vector<capacidad>& almacenes) // Cantidad de producto en cada almacen
{
    typedef typename GrafoP<tCoste>::vertice vertice;
    size_t n = costes.numVert();

    vector<vertice> P;
    vector<tCoste> costesMin = Dijkstra(costes, origen, P);

    // Aplicar subvención
    for(vertice i=0 ; i < n ; i++)
        costesMin[i] *= (1-subvenciones[i]);
    
    // Sumar costes de distribuir la mercancia a los destinos mas baratos
    tCoste min, costeTotal=0;
    vertice nodoMin=0;
    for(vertice i=0 ; i < n || cantidad <= 0 ; i++){
        // Encontrar la ciudad de minimo coste O(n)
        min = GrafoP<tCoste>::INFINITO;
        for(vertice j=0 ; j < n ; j++){
            if(costesMin[j] < min){ 
                min = costesMin[j]; // Nuevo minimo
                nodoMin = j;        // Guardamos el vertice
            }
        }
        costeTotal += costesMin[nodoMin];              // Sumamos el coste al total
        if(capacidades[nodoMin] <= cantidad){          // Queda producto suficiente
            almacenes[nodoMin] = capacidades[nodoMin]; // Se llena el almacen
            cantidad -= capacidades[nodoMin];          // Restamos el producto ya asignado
        }
        else{
            almacenes[nodoMin] = cantidad; // Se lleva el producto restante
            cantidad = 0;
        }
        costesMin[nodoMin] = GrafoP<tCoste>::INFINITO; // Lo ponemos a infinito porque ya lo hemos usado
    }

    return costeTotal;
}
