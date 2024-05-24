# Práctica 8: Grafos 3

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

```

### Ejercicio 5

La nueva compañía de telefonía RETEUNI3 tiene que conectar entre sí, con fibra óptica, todas y cada una de las ciudades del país. Partiendo del grafo que representa las distancias entre todas las ciudades del mismo, implementad un subprograma que calcule la longitud mínima de fibra óptica necesaria para realizar dicha conexión.

```cpp

```

### Ejercicio 6

La empresa EMASAJER S.A. tiene que unir mediante canales todas las ciudades del valle del Jerte (Cáceres), teniendo en cuenta las siguientes premisas:

- El coste de abrir cada nuevo canal es casi prohibitivo, luego la solución final debe tener un número mínimo de canales.
- El Ministerio de Fomento nos subvenciona por m3/sg de caudal, luego el conjunto de los canales debe admitir el mayor caudal posible, pero por otra parte, el coste de abrir cada canal es proporcional a su longitud, por lo que el conjunto de los canales  también debería medir lo menos posible. Así pues, la solución óptima debería combinar adecuadamente ambos factores.

Dada la matriz de distancias entre las diferentes ciudades del valle del Jerte, otra matriz con los diferentes caudales máximos admisibles entre estas ciudades teniendo en cuenta su orografía, la subvención que nos da Fomento por m3/sg. de caudal y el coste por km. de canal, implementen un subprograma que calcule qué canales y de qué longitud y caudal deben construirse para minimizar el coste total de la red de canales.

```cpp

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

```
