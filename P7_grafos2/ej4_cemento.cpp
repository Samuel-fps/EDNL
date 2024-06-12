#include "../TAD_GRAFO/alg_grafoPMC.h"
#include "alg_grafo_E-S.h"
#include <iostream>
#include <vector>;

/*  EJERCICIO 4

    Eres el orgulloso dueño de la empresa “Cementos de Zuelandia  S.A”. Empresa dedicada a la fabricación y 
    distribución de cemento, sita en la capital de Zuelandia. Para la distribución del cemento entre tus diferentes
    clientes (ciudades de Zuelandia) dispones de una flota de camiones y de una plantilla de conductores zuelandeses.
    
    El problema a resolver tiene que ver con el carácter del zuelandés. El zuelandés es una persona que se toma
    demasiadas “libertades” en su trabajo, de hecho, tienes fundadas sospechas de que tus conductores utilizan los
    camiones de la empresa para usos particulares (es decir indebidos, y a tu costa) por lo que quieres controlar los
    kilómetros que recorren tus camiones.
    
    Todos los días se genera el parte de trabajo, en el que se incluyen el número de cargas de cemento 
    (1 carga = 1 camión lleno de cemento) que debes enviar a cadacliente (cliente = ciudad de Zuelandia). 
    Es innecesario indicar que no todos los días hay que enviar cargas a todos los clientes, y además, puedes suponer 
    razonablemente que tu flota de camiones es capaz de hacer el trabajo diario.
    
    Para la resolución del problema quizá sea interesante recordar que Zuelandia es un país cuya especial orografía 
    sólo permite que las carreteras tengan un sentido de circulación.

    Implementa una función que dado el grafo con las distancias directas entre las diferentes ciudades zuelandesas,
    el parte de trabajo diario, y la capital de Zuelandia, devuelva la distancia total en kilómetros que deben 
    recorrer tus camiones en el día, para que puedas descubrir si es cierto o no que usan tus camiones en actividades
    ajenas a la empresa.
*/

template <typename tCoste>
unsigned distanciaCamiones(const GrafoP<tCoste>& G, // Distancia entre ciudades
                           const typename GrafoP<tCoste>::vertice capital,
                           vector<int> pedidos) // Vector de tamaño G.numVert() con la cantidad a entregar
{
    typedef typename GrafoP<tCoste>::vertice vertice;
    size_t n = G.numVert();

    vector<tCoste> P;
    vector<tCoste> capitalCiudades = Dijkstra(G, capital, P), // Coste min desde capital a ciudades
                   vueltaCapital = DijkstraInv(G, capital, P); // Coste min desde ciudades a capital

    // Sumamos la distancia total multiplicando el numero de pedidos por la distancia de ir y volver a cada ciudad
    unsigned distancia = 0;
    for(vertice i = 0 ; i < n ; i++)
        distancia += pedidos[i] * suma(capitalcidades[i], vueltaCapital[i]);

    return distancia;
}
