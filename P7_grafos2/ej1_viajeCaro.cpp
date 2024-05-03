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


int main() {
    GrafoP<int> grafo("GrafoA.txt");

    std::cout << grafo;

    // LLamada a funcion de ejercicio
    // disMinZuelandia(grafo, ciudadesTomadas, estadoCarreteras, capital);

    // Imprimir el resultado

    return 0;
}