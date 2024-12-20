# Práctica 8: Grafos 3

## INTRODUCCIÓN

Antes de ver las soluciones de los ejercicios te recomiendo intentar hacerlo tú mismo y asistir a clase de prácticas porque así es como de verdad aprendes a resolver estos ejercicios y cualquiera que te puedan poner en el examen.
DISCLAIMER Esta son mis soluciones a los ejercicios propuestos en clase de prácticas, ten en cuenta que es mi solución y que no tiene porque ser correcta ni la única solución posible.

## EJERCICIOS

### Ejercicio 1

El archipiélago de Tombuctú, está formado por un número indeterminado de islas, cada una de las cuales tiene, a su vez, un número indeterminado de ciudades. En cambio, sí es conocido el número total de ciudades de Tombuctú (podemos llamarlo N, por ejemplo). Dentro de cada una de las islas existen carreteras que permiten viajar entre todas las ciudades de la isla. Se dispone de las coordenadas cartesianas (x, y) de todas y cada una de las ciudades del archipiélago. Se dispone de un grafo (matriz de adyacencia) en el que se indica si existe carretera directa entre cualesquiera dos ciudades del archipiélago. El objetivo de nuestro problema es encontrar qué ciudades de Tombuctú pertenecen a cada una de las islas del mismo y cuál es el coste mínimo de viajar entre cualesquiera dos ciudades de una misma isla de Tombuctú.

Así pues, dados los siguientes datos:

- Lista de ciudades de Tombuctú representada cada una de ellas por sus coordenadas cartesianas.
- Matriz de adyacencia de Tombuctú, que indica las carreteras existentes en dicho archipiélago.

Implementen un subprograma que calcule y devuelva la distribución en islas de las ciudades de Tombuctú, así como el coste mínimo de viajar entre cualesquiera dos ciudades de una misma isla del archipiélago.

```cpp
typedef struct{
    double x, y;
} Ciudad;

// Distancia euclidea entre dos puntos
double calcularDistanciaEuclidea(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

template <typename tCoste>
Particion tombuctuDistribucion(const vector<Ciudad>& ciudades,  // Vector ciudades(x, y)
                               const matriz<bool>& ady,         // matriz adyacencia
                               matriz<tCoste>& costesMin)       // Costes minimos entre ciudades
{
    typedef GrafoPMC::vertice vertice;
    size_t N = ady.dimension();
    GrafoP<tCoste> C(N);

    // Unir cada ciudad con su isla
    Particion islas(N); // Particion de n ciudades
    for(int i=0 ; i < n ; i++)
        for(int j=0 ; j < n ; j++)
            if(ady[i][j] && islas.encontrtar(i) != islas.encontrar(j)) // Son adyacentes && Aun no la hemos unido a la isla (precondicion unir)
                islas.unir(i, j);

    // Crear matriz de costes
    for(vertice i=0 ; i < N ; i++)
        for(vertice j=0 ; j < N ; j++)
            if(ady[i][j])
                C[i][j] = distancia(ciudades[i].x, ciudades[i].y, ciudades[j].x, ciudades[j].y);

    // Calcular costes minimos
    matriz<vertice> P;
    costesMin = Floyd(C, P);

    return islas;
}
```

### Ejercicio 2

El archipiélago de Tombuctú2 está formado por un número desconocido de islas, cada una de las cuales tiene, a su vez, un número desconocido de ciudades, las cuales tienen en común que todas y cada una de ellas dispone de un aeropuerto. Sí que se conoce el número total de ciudades del archipiélago (podemos llamarlo N, por ejemplo). Dentro de cada una de las islas existen carreteras que permiten viajar entre todas las ciudades de la isla. No existen puentes que unan las islas y se ha decidido que la opción de comunicación más económica de implantar será el avión. Se dispone de las coordenadas cartesianas (x, y) de  todas y cada una de las ciudades del archipiélago. Se dispone de un grafo (matriz de adyacencia) en el que se indica si existe carretera directa entre cualesquiera dos ciudades del archipiélago. El objetivo de nuestro problema es encontrar qué líneas aéreas debemos implantar para poder viajar entre todas las ciudades del archipiélago, siguiendo los siguientes criterios:

1. Se implantará una y sólo una  línea aérea entre cada par de islas.
2. La línea aérea escogida entre cada par de islas será la más corta entre todas las posibles.

Así pues, dados los siguientes datos:

- Lista de ciudades de Tombuctú2 representada cada una de ellas por sus coordenadas cartesianas.
- Matriz de adyacencia de Tombuctú que indica las carreteras existentes en dicho archipiélago,
Implementen un subprograma que calcule y devuelva las líneas aéreas necesarias para comunicar adecuadamente el archipiélago siguiendo los criterios anteriormente expuestos.

```cpp
typedef struct{
    int x, y;
} Ciudad;

// Representa la linea aerea entre dos vertices del grafo y la distancia entre ellos
template <typename tCoste>
struct LineaAerea {
    typedef GrafoP<tCoste>::vertice vertice;
    vertice origen, destino;
    tCoste distancia;

    LineaAerea::LineaAerea(vertice o, vertice d, tCoste dist) : origen(o), destino(d), distancia(dist){}
    bool LineaAerea::operator <(const LineaAerea& l1, const LineaAerea& l2){ return l1.distancia < l2.distancia; }
};

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


```

### Ejercicio 3

Implementa un subprograma para encontrar un árbol de extensión máximo. ¿Es más difícil que encontrar un árbol de extensión mínimo?

```cpp
template <typename tCoste>
void kruskalMax(const GrafoP<tCoste>& G)
// Devuelve un árbol generador de coste máximo
// de un grafo no dirigido ponderado y conexo G.
{
    assert(!G.esDirigido());

   typedef typename GrafoP<tCoste>::vertice vertice;
   typedef typename GrafoP<tCoste>::arista arista;
   const tCoste INFINITO = GrafoP<tCoste>::INFINITO;
   const size_t n = G.numVert();
   GrafoP<tCoste> g(n);     // Árbol generador de coste máximo
   Particion P(n);          // Partición inicial del conjunto de vértices de G.
   Apo<arista> A(n*n);      // Aristas de G ordenadas por costes teniendo max en la cima.
    
    // Copiar aristas del grafo G en el APO A.
   for (vertice u = 0; u < n; u++)
      for (vertice v = u+1; v < n; v++)
         if(G[u][v] != INFINITO)
            A.insertar(arista(u, v, G[u][v]));

   size_t i = 1;
   while (i <= n-1) {   // Seleccionar n-1 aristas.
      arista a = A.cima(); // arista de mayor coste
      A.suprimir();
      vertice u = P.encontrar(a.orig);
      vertice v = P.encontrar(a.dest);
      if (u != v) { // Los extremos de a pertenecen a componentes distintas
         P.unir(u, v);
         // Incluir la arista a en el árbol g
         g[a.orig][a.dest] = g[a.dest][a.orig] = a.coste;
         i++;
      }
   }
   return g;
}
```

### Ejercicio 4

La empresa EMASAJER S.A. tiene que unir mediante canales todas las ciudades del valle del Jerte (Cáceres). Calcula  qué  canales y de qué longitud deben construirse partiendo del grafo con las distancias entre las ciudades y asumiendo las siguientes premisas:

- el coste de abrir cada nuevo canal es casi prohibitivo, luego la solución final debe tener un número mínimo de canales.
- el Ministerio de Fomento nos subvenciona por Kms de canal, luego los canales deben ser de la longitud máxima posible.

```cpp
template <typename tCoste>
GrafoP<tCoste> constriurCanales(const GrafoP<tCoste>& distancias)
{
  return KruskallMax(distancias); // Usamos el ejercicio 3
}
```

### Ejercicio 5

La nueva compañía de telefonía RETEUNI3 tiene que conectar entre sí, con fibra óptica, todas y cada una de las ciudades del país. Partiendo del grafo que representa las distancias entre todas las ciudades del mismo, implementad un subprograma que calcule la longitud mínima de fibra óptica necesaria para realizar dicha conexión.

```cpp
template <typename tCoste>
tCoste constriurPuente(cosnt GrafoP<tCoste>& distancias)
{
    size_t n = distancias.numVert();

    GrafoP<tCoste> min = kruskal(distancias);

    // sumar distancia de arbol de coste mínimo
    // Como el coste de ir de i a j es igual que de j a i no basta con sumar una de las diagonales, en este caso la superior -> j=i
    // El coste de la diagonal principal será 0 por lo que también nos lo podemos ahorrar -> j=i+1
    tCoste distancia=0;
    for(size_t i=0 ; i < n ; i++)
        for(size_t j=i+1 ; j < n ; j++)
            distancia += min[i][j];

    return distancia;
}
```

### Ejercicio 6

La empresa EMASAJER S.A. tiene que unir mediante canales todas las ciudades del valle del Jerte (Cáceres), teniendo en cuenta las siguientes premisas:

- El coste de abrir cada nuevo canal es casi prohibitivo, luego la solución final debe tener un número mínimo de canales.
- El Ministerio de Fomento nos subvenciona por m3/sg de caudal, luego el conjunto de los canales debe admitir el mayor caudal posible, pero por otra parte, el coste de abrir cada canal es proporcional a su longitud, por lo que el conjunto de los canales  también debería medir lo menos posible. Así pues, la solución óptima debería combinar adecuadamente ambos factores.

Dada la matriz de distancias entre las diferentes ciudades del valle del Jerte, otra matriz con los diferentes caudales máximos admisibles entre estas ciudades teniendo en cuenta su orografía, la subvención que nos da Fomento por m3/sg. de caudal y el coste por km. de canal, implementen un subprograma que calcule qué canales y de qué longitud y caudal deben construirse para minimizar el coste total de la red de canales.

```cpp
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
```

### Ejercicio 7

El archipiélago de Grecoland (Zuelandia) está formado únicamente por dos islas, Fobos y Deimos, que tienen N1 y N2 ciudades, respectivamente, de las cuales C1 y C2 ciudades son costeras (obviamente C1 ≤  N1 y C2 ≤ N2). Se dispone de las coordenadas cartesianas (x, y) de todas y cada una de las ciudades del archipiélago. El huracán Isadore acaba de devastar el archipiélago, con lo que todas las carreteras y puentes construidos en su día han desaparecido. En esta terrible situación se pide ayuda a la ONU, que acepta reconstruir el archipiélago (es decir volver a comunicar todas las ciudades del archipiélago) siempre que se haga al mínimo coste.
De cara a poder comparar costes de posibles reconstrucciones se asume lo siguiente:

1. El coste de construir cualquier carretera o cualquier puente es proporcional a su longitud (distancia euclídea entre las poblaciones de inicio y fin de la carretera o del puente).
2. Cualquier puente que se construya siempre será más caro que cualquier carretera que se construya.

De cara a poder calcular los costes de VIAJAR entre cualquier ciudad del archipiélago se considerará lo siguiente:

1. El coste directo de viajar, es decir de utilización de una carretera o de un puente, coincidirá con su longitud (distancia euclídea entre las poblaciones origen y destino de la carretera o del puente).

En estas condiciones, implementa un subprograma que calcule el coste mínimo de viajar entre dos ciudades de Grecoland, origen y destino, después de haberse  reconstruido el archipiélago, dados los siguientes datos:

1. Lista de ciudades de Fobos representadas mediante sus coordenadas cartesianas.
2. Lista de ciudades de Deimos representadas mediante sus coordenadas cartesianas.
3. Lista de ciudades costeras de Fobos.
4. Lista de ciudades costeras de Deimos.
5. Ciudad origen del viaje.
6. Ciudad destino del viaje.

```cpp
typedef struct {
    int x, y;
} Ciudad;

// Distancia euclidea entre dos puntos
double distanciaEuclidea(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

template <typename tCoste>
tCoste constriurPuentes(const vector<Ciudad>& ciudades1,
                        const vector<Ciudad>& ciudades2,
                        const vector<Ciudad>& costeras1,
                        const vector<Ciudad>& costeras2,
                        const GrafoP<tCoste>::vertice origen,
                        const GrafoP<tCoste>::vertice destino)
{
    typedef GrafoP<tCoste>::vertice vertice;
    size_t n1=ciudades1.size(), n2=ciudades2.size(), n=n1+n2;
    GrafoP<tCoste> distancias(n);

    // Coste de ir entre la primera isla por carretera
    for(size_t i=0 ; i < n1 ; i++){
        for(size_t j=0 ; j < n1 ; j++){
            distancias[i][j] = distancias[j][i] = distanciaEuclidea(ciudades1[i], ciudades1[j]);
        }
    }

    // Coste de ir entre la segunda isla por carretera
    for(size_t i=0 ; i < n2 ; i++){
        for(size_t j=0 ; j < n2 ; j++){
            distancias[i][j] = distancias[j][i] = distanciaEuclidea(ciudades2[i], ciudades2[j]);
        }
    }

    // Coste cidades costeras (puentes)
    for(size_t i=0 ; i < costeras1.size() ; i++){
        for(size_t j=0 ; j < costeras2.size() ; j++){
            distancias[i][j] = distancias[j][i] = distanciaEuclidea(costeras1[i], ccosteras2[j]);
        }
    }

    // Árbol generador de coste mínimo
    GrafoP<tCoste> puentes = kruskall(distancias);

    // Caminos de coste mínomo desde origen
    vector<vertice> P;
    vector<tCoste> costeMin = Dijkstra(puentes, origen, P);
    
    return costeMin[destino];
}
```

¿como implemento el "Cualquier puente que se construya siempre será más caro que cualquier carretera que se construya."?