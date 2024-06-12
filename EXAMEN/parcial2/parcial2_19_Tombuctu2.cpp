#include "../TAD_GRAFO/alg_grafoPMC.h"

typedef struct{
    int x, y;
} Ciudad;

// Representa la linea aerea entre dos vertices del grafo y la distancia entre ellos
template <typename tCoste>
typedef struct {
    typedef GrafoP<tCoste>::vertice vertice;
    vertice origen, destino;
    tCoste distancia;

    LineaAerea::LineaAerea(vertice o, vertice d, tCoste dist) : origen(o), destino(d), distancia(dist){}
    bool LineaAerea::operator <(const LineaAerea& l1, const LineaAerea& l2){ return l1.distancia < l2.distancia; }
} LineaAerea;

// Distancia euclidea entre ciudades
double distanciaCiudades(Ciudad c1, Ciudad c2) {
    return sqrt(pow(c2.x - c1.x, 2) + pow(c2.y - c1.y, 2));
}

// Función principal
template <typename tCoste>
vector<LineaAerea> tombuctuAereas(const vector<Ciudad>& ciudades, // Lista de ciudades de Tombuctú2
                             const matriz<bool>& Ady)    // Matriz de adyacencia de Tombuctú
{
    typedef GrafoP<tCoste>::vertice vertice;
    size_t n = A.dimension();
    vector<LineaAerea> lineasSolucion;

     // Unir cada ciudad con su isla
    Particion islas(n); // Particion de n ciudades
    for(int i=0 ; i < n ; i++)
        for(int j=0 ; j < n ; j++)
            if(ady[i][j] && islas.encontrtar(i) != islas.encontrar(j)) // Son adyacentes && Aun no la hemos unido a la isla (precondicion unir)
                islas.unir(i, j);
    
    GrafoP<tCoste> lineas(n);
    Apo<LineaAerea> lineasOrdenadas;
    Particion conectadas(n);
    int numLineas=0;

    // Metemos las lineas en un apo para ordenarlas de mejor a peor opcion
    for(int i=0 ; i < n ; i++)
        for(int j=i ; j < n ; j++) // Empezamos en i porque el coste igual de A a B que de B a A
            lineasOrdenadas.insertar(LineaAerea(i, j, distanciaCiudades(ciudades[i], ciudades[j])));
    
    
    // Sacamos la linea mas corta si es entre ciudades de distintas islas que todavía no están conectadas, esta será la mejor opción
    // Seguimos este bucle hasta tener n-1 lineas que son las mínimas para conectar todas entre sí
    while(numLineas <= n-1  && lineasOrdenadas.numNodos() != 0){
        LineaAerea actual = lineasOrdenadas.cima(); // Mejor linea
        lineasOrdenadas.suprimir(actual);
        vertice o = actual.origen,  // vertice origen de la linea
                d = actual.destino; // vertice destino de la linea
        if(islas.encontrtar(o) != islas.encontrar(d)){              // No son ciudades de la misma isla
            if(conectadas.encontrar(o) != conectadas.encontrar(d)){ // Comprobar que no esten ya conectadas
                conectadas.unir(o, d);                              // Islas conectadas por linea aerea
                lineasSolucion.push_back(actual);                   // Guardamos la Linea en el vector solucion
                numLineas++;                                        // Sumamos una linea aerea
            }
        }
    }

    return lineasSolucion;
}