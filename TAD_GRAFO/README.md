# TAD GRAFO

## Clase Grafo

### grafoMA.h - Grafo no ponderado mediante matriz de adyacencia

```cpp
class Grafo {
    public:
        typedef size_t vertice;

        explicit Grafo(size_t n): ady(n, vector<bool>(n, false)) {}
        explicit Grafo(const std::string& nf);
        template <typename T> Grafo(const GrafoP<T>& G);
        size_t numVert() const {return ady.size();}
        const vector<bool>& operator [](vertice v) const {return ady[v];}
        vector<bool>& operator [](vertice v) {return ady[v];}
        bool esDirigido() const;
    private:
        vector< vector<bool> > ady;
};
```

### grafoLA.h - Grafo no ponderado mediante listas de adyacencia

```cpp
class Grafo {
    public:
        typedef size_t vertice;

        explicit Grafo(size_t n): ady(n) {}
        explicit Grafo(const std::string& nf);
        size_t numVert() const {return ady.size();}
        const Lista<vertice>& adyacentes(vertice v) const {return ady[v];}
        Lista<vertice>& adyacentes(vertice v) {return ady[v];}
    private:
        std::vector< Lista<vertice> > ady; // vector de listas de v�rtices
};
```

### grafoPMC.h - Grafo ponderado con costes de tipo T representado mediante matriz de costes

```cpp
template <typename T> class GrafoP {
    public:
        typedef T tCoste;
        typedef size_t vertice;
        struct arista {
            vertice orig, dest;
            tCoste coste;
            explicit arista(vertice v = vertice(), vertice w = vertice(),
                            tCoste c = tCoste()): orig(v), dest(w), coste(c) {}
            bool operator <(const arista& a) const {return coste < a.coste;}
        };
        typedef Lista<vertice> tCamino;

        static const tCoste INFINITO;

        explicit GrafoP(size_t n): costes(n, vector<tCoste>(n, INFINITO)) {}
        explicit GrafoP(const std::string& nf);
        GrafoP(const Grafo& G);
        size_t numVert() const {return costes.size();}
        const vector<tCoste>& operator [](vertice v) const {return costes[v];}
        vector<tCoste>& operator [](vertice v) {return costes[v];}
        bool esDirigido() const;
    private:
        vector< vector<tCoste> > costes;
};
```

### grafoPLA - Grafo ponderado con costes de tipo T representado mediante listas de adyacencia

```cpp
template <typename T> class GrafoP {
    public:
        typedef T tCoste;
        typedef size_t vertice;
        typedef Lista<vertice> tCamino;

        struct vertice_coste {
            vertice v;
            tCoste c;
        };

        static const tCoste INFINITO;

        GrafoP(size_t n): ady(n) {}
        GrafoP(const std::string& nf);
        size_t numVert() const {return ady.size();}
        const Lista<vertice_coste>& adyacentes(vertice v) const {return ady[v];}
        Lista<vertice_coste>& adyacentes(vertice v) {return ady[v];}
    private:
        vector<Lista<vertice_coste>> ady;
};
```

## Algoritmos de Grafos

### alg_grafoMA.h

#### Warshall

Determina si hay un camino entre cada par de vértices del grafo no ponderado G.
Salida:

- Una matriz booleana cuadrada de tamaño G.numVert(), tal que una posición
[i][j] es true si existe al menos un camino entre el vértice i y el vértice j, y
false si no existe ningún camino entre estos vértices.

```cpp
matriz<bool> Warshall(const Grafo& G);
```

#### Recorridos del grafo

```cpp
Lista<Grafo::vertice> Profundidad(const Grafo& G, Grafo::vertice v);
```

```cpp
Lista<Grafo::vertice> Profundidad2(const Grafo& G, Grafo::vertice v);
```

```cpp
Lista<Grafo::vertice> Anchura(const Grafo& G, Grafo::vertice v);
```

### Eficiencia de algoritmos

| Método             | Eficiencia     |
|--------------------|----------------|
| Warshall()         | V^3            |
| Profundidad()      | V + A          |
| Profundidad2()     | V + A          |
| Anchura()          | V + A          |

V = Vertices  
A = Aritas

### alg_grafoPMC.h

#### Dijstra

Calcula los caminos de coste mínimo entre origen y todos los vértices del grafo G.
Salida:

- Un vector de costes mínimos de tamaño G.numVert().
- P, un vector de vértices de tamaño G.numVert(), tal que P[i] es el vértice
anterior a i en el camino de coste mínimo desde origen hasta i.

```cpp
vector<tCoste> Dijkstra(const GrafoP<tCoste>& G,
                        typename GrafoP<tCoste>::vertice origen,
                        vector<typename GrafoP<tCoste>::vertice>& P)
```

#### Floyd

Calcula los caminos de coste mínimo entre cada par de vértices del grafo G.
Salida:

- Una matriz de costes mínimos de tamaño n x n, con n = G.numVert()
- P, una matriz de vértices de tamaño n x n, tal que P[i][j] es un vértice
intermedio por el que pasa el camino de coste mínimo desde i a j.

```cpp
template <typename tCoste>
matriz<tCoste> Floyd(const GrafoP<tCoste>& G,
                     matriz<typename GrafoP<tCoste>::vertice>& P)
```

#### Prim

Devuelve un árbol generador de coste mínimo de un grafo no dirigido ponderado
y conexo G.

```cpp
template <typename tCoste>
GrafoP<tCoste> Prim(const GrafoP<tCoste>& G)
```

#### kruskall

Devuelve un árbol generador de coste mínimo de un grafo no dirigido ponderado
y conexo G

```cpp
GrafoP<tCoste> Kruskall(const GrafoP<tCoste>& G)
```

#### Otras funciones

```cpp
// Suma de costes (Dijkstra y Floyd)
template <typename tCoste> tCoste suma(tCoste x, tCoste y)

camino(typename GrafoP<tCoste>::vertice orig,
       typename GrafoP<tCoste>::vertice v,
       const vector<typename GrafoP<tCoste>::vertice>& P)
// Devuelve el camino de coste mínimo entre los vértices orig e v
// a partir de un vector P obtenido mediante la función Dijkstra().

caminoAux(typename GrafoP<tCoste>::vertice v,
          typename GrafoP<tCoste>::vertice w,
          const matriz<typename GrafoP<tCoste>::vertice>& P)
// Devuelve el camino de coste mínimo entre v y w, exluidos estos,
// a partir de una matriz P obtenida mediante la función Floyd().
```

| Método             | Eficiencia     |
|--------------------|----------------|
| Dijkstra()         | O(V^2)         |
| DijkstraInv()      | O(V^2)         |
| Floyd()            | O(V^3)         |
| Prim()             | O(V^2)         |
| Kruskall()         | O(A log V)     |

V = Vertices  
A = Aritas