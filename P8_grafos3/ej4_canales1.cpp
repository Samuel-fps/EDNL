#include "../TAD_GRAFO/alg_grafoPMC.h"
#include "alg_grafo_E-S.h"
#include <iostream>
#include <vector>

/*  EJERCICIO 4

    La empresa EMASAJER S.A. tiene que unir mediante canales todas las ciudades del valle del Jerte
    (Cáceres). Calcula qué canales y de qué longitud deben construirse partiendo del grafo con las
    distancias entre las ciudades y asumiendo las siguientes premisas:

    - el coste de abrir cada nuevo canal es casi prohibitivo, 
      luego la solución final debe tener un número mínimo de canales.
    - el Ministerio de Fomento nos subvenciona por Kms de canal,
      luego los canales deben ser de la longitud máxima posible.
*/

template <typename tCoste>
void constriurPuente(GrafoP<tCoste> distancias)
{
  return KruskallMax(distancias); // Usamos el ejercicio 3
}