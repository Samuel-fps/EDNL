# Práctica 7: Grafos 2

## INTRODUCCIÓN

## EJERCICIOS

### Ejercicio 1

Tu agencia de viajes “OTRAVEZUNGRAFO S.A.” se enfrenta a un curioso cliente. Es un personaje sorprendente, no le importa el dinero y quiere hacer el viaje más caro posible entre las ciudades que ofertas. Su objetivo es gastarse la mayor cantidad de dinero posible (ojalá todos los clientes fueran así), no le importa el origen ni el destino del viaje.

Sabiendo que es imposible pasar dos veces por la misma ciudad, ya que casualmente el grafo de tu agencia de viajes resultó ser acíclico, devolver el coste, origen y destino de tan curioso viaje. Se parte de la matriz de costes directos entre las ciudades del grafo.

```cpp
template <typename tCoste>
matriz<tCoste> FloydMax(const GrafoP<tCoste>& G,
                        matriz<typename GrafoP<tCoste>::vertice>& P)
{
   typedef typename GrafoP<tCoste>::vertice vertice;
   const size_t n = G.numVert();
   matriz<tCoste> A(n);   // matriz de costes maximos

   // Iniciar A y P con caminos directos entre cada par de vértices.
   P = matriz<vertice>(n);
   for (vertice i = 0; i < n; i++) {
      A[i] = G[i];                    // copia costes del grafo
      A[i][i] = 0;                    // diagonal a 0
      P[i] = vector<vertice>(n, i);   // caminos directos
   }
   // Calcular costes maximos y caminos correspondientes
   // entre cualquier par de vértices i, j
   for (vertice k = 0; k < n; k++)
      for (vertice i = 0; i < n; i++)
         for (vertice j = 0; j < n; j++) {
            tCoste ikj = suma(A[i][k], A[k][j]);
            if (ikj > A[i][j]) {
               A[i][j] = ikj;
               P[i][j] = k;
            }
         }
   return A;
}

 template <typename tCoste>
 tCoste viajeCaro(const GrafoP<tCoste>& G,
                  typename GrafoP<tCoste>::vertice& origen,
                  typename GrafoP<tCoste>::vertice& destino)
{
    typedef typename GrafoP<tCoste>::vertice vertice;
    size_t n = G.numVert();
    tCoste max;
    matriz<tCoste> costes;
    matriz<vertice> rutas;
    
    costes = FloydMax(G, rutas);

    tCoste costeMax = 0;
    for(size_t i = 0 ; i < n ; ++i){
        for(size_t j = 0 ; j < n ; ++j){
            if(costes[i][j] > costeMax){
                costeMax = costes[i][j];
                origen = i;
                destino = j;
            }
        }
    }

    return costeMax;
}
```

### Ejercicio 2

Se dispone de un laberinto de NxN casillas del que se conocen las casillas de entrada y salida del mismo. Si te encuentras en una casilla sólo puedes moverte en las siguientes cuatro direcciones (arriba, abajo, derecha, izquierda). Por otra parte, entre algunas de las casillas hay una pared que impide moverse entre las dos casillas que separa dicha pared (en caso contrario no sería un verdadero laberinto).  

Implementa un subprograma que dados

- N (dimensión del laberinto),
- la lista de paredes del laberinto,
- la casilla de entrada, y
- la casilla de salida,  
calcule el camino más corto para ir de la entrada a la salida y su longitud.

```cpp

```

### Ejercicio 3

Eres el orgulloso dueño de una empresa de distribución. Tu misión radica en distribuir todo tu stock entre las diferentes ciudades en las que tu empresa dispone de almacén.

Tienes un grafo representado mediante la matriz de costes, en el que aparece el coste (por unidad de producto) de transportar los productos entre las diferentes ciudades del grafo.

Pero además resulta que los Ayuntamientos de las diferentes ciudades en las que tienes almacén están muy interesados en que almacenes tus productos en ellas, por lo que están dispuestos a subvencionarte con un porcentaje de los gastos mínimos de transporte hasta la ciudad. Para facilitar el problema, consideraremos despreciables los costes de volver el camión a su base (centro de producción).

He aquí tu problema. Dispones de

- el centro de producción, nodo origen en el que tienes tu producto (no tiene
almacén),
- una cantidad de unidades de producto (cantidad),
- la matriz de costes del grafo de distribución con N ciudades,
- la capacidad de almacenamiento de cada una de ellas,
- el porcentaje de subvención (sobre los gastos mínimos) que te ofrece cada Ayuntamiento.

Las diferentes ciudades (almacenes) pueden tener distinta capacidad, y además la capacidad total puede ser superior a la cantidad disponible de producto, por lo que debes decidir cuántas unidades de producto almacenas en cada una de las ciudades.

Debes tener en cuenta además las subvenciones que recibirás de los diferentes Ayuntamientos, las cuales pueden ser distintas en cada uno y estarán entre el 0% y el 100% de los costes mínimos.

La solución del problema debe incluir las cantidades a almacenar en cada ciudad bajo estas condiciones y el coste mínimo total de la operación de distribución para tu
empresa.

```cpp

```

### Ejercicio 4

Eres el orgulloso dueño de la empresa “Cementos de Zuelandia S.A”. Empresa dedicada a la fabricación y distribución de cemento, sita en la capital de Zuelandia. Para la distribución del cemento entre tus diferentes clientes (ciudades de Zuelandia) dispones de una flota de camiones y de una plantilla de conductores zuelandeses.

El problema a resolver tiene que ver con el carácter del zuelandés. El zuelandés es una persona que se toma demasiadas “libertades” en su trabajo, de hecho, tienes fundadas sospechas de que tus conductores utilizan los camiones de la empresa para usos particulares (es decir indebidos, y a tu costa) por lo que quieres controlar los kilómetros que recorren tus camiones.

Todos los días se genera el parte de trabajo, en el que se incluyen el número de cargas de cemento (1 carga = 1 camión lleno de cemento) que debes enviar a cada cliente (cliente = ciudad de Zuelandia). Es innecesario indicar que no todos los días hay que enviar cargas a todos los clientes, y además, puedes suponer razonablemente que tu flota de camiones es capaz de hacer el trabajo diario.

Para la resolución del problema quizá sea interesante recordar que Zuelandia es un país cuya especial orografía sólo permite que las carreteras tengan un sentido de circulación.

Implementa una función que dado el grafo con las distancias directas entre las diferentes ciudades zuelandesas, el parte de trabajo diario, y la capital de Zuelandia, devuelva la distancia total en kilómetros que deben recorrer tus camiones en el día, para que puedas descubrir si es cierto o no que usan tus camiones en actividades ajenas a la empresa.

```cpp
template <typename tCoste>
unsigned distanciaCamiones(const GrafoP<tCoste>& G, // Distancia entre ciudades
                           const typename GrafoP<tCoste>::vertice capital,
                           vector<int> pedidos) // Vector de tamaño G.numVert() con la cantidad a entregar
{
    typedef GrafoP<tCoste>::vertice vertice;
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
```

### Ejercicio 5

Se dispone de tres grafos que representan la matriz de costes para viajes en un determinado país pero por diferentes medios de transporte, por supuesto todos los grafos tendrán el mismo número de nodos. El primer grafo representa los costes de ir por carretera, el segundo en tren y el tercero en avión. Dado un viajero que dispone de una determinada cantidad de dinero, que es alérgico a uno de los tres medios de transporte, y que sale de una ciudad determinada, implementar un subprograma que determine las ciudades a las que podría llegar nuestro infatigable viajero.

```cpp
enum Alergia{coche, tren, avion};

template <typename tCoste>
vector<bool> transporte(const GrafoP<tCoste>& T1,
                        const GrafoP<tCoste>& T2,
                        const typename GrafoP<tCoste>::vertice& origen,
                        tCoste dinero)
{
    typedef typename GrafoP<tCoste>::vertice vertice;
    size_t n = T1.numVert();
    vector<bool> alcanzables(n);

    vector<vertice> P;
    vector<tCoste> t1Coste = Dijkstra(T1, origen, P),
                   t2Coste = Dijkstra(T2, origen, P);

    // rellenamos el vector con true si el presupuiesto >= que el coste minimo
    for(vertice i=0 ; i < n ; i++)
        alcanzables[i] = dinero >= std::min(t1Coste[i], t2Coste[i]);
    
    return alcanzables;
}

template <typename tCoste>
vector<bool> viajeAlergia(const GrafoP<tCoste>& C,
                          const GrafoP<tCoste>& T,
                          const GrafoP<tCoste>& A,
                          const typename GrafoP<tCoste>::vertice& origen,
                          tCoste dinero,
                          Alergia alergia)
{
    vector<bool> resultado;
    switch(alergia){
        case coche:
            resultado = transporte(T, A, origen, dinero);
            break;
        case avion:
            resultado = transporte(T, C, origen, dinero);
            break;
        case tren:
            resultado = transporte(C, A, origen, dinero);
            break;
    }

    return resultado;
}
```

### Ejercicio 6

Al dueño de una agencia de transportes se le plantea la siguiente situación. La agencia de viajes ofrece distintas trayectorias combinadas entre N ciudades españolas utilizando tren y autobús. Se dispone de dos grafos que representan los costes (matriz de costes) de viajar entre diferentes ciudades, por un lado en tren, y por otro en autobús (por supuesto entre las ciudades que tengan línea directa entre ellas). Además coincide que los taxis de toda España se encuentran en estos momentos en huelga general, lo que implica que sólo se podrá cambiar de transporte en una ciudad determinada en la que, por casualidad, las estaciones de tren y autobús están unidas.

Implementa una función que calcule la tarifa mínima (matriz de costes mínimos) de viajar entre cualesquiera de las N ciudades disponiendo del grafo de costes en autobús, del grafo de costes en tren, y de la ciudad que tiene las estaciones unidas.

```cpp
template <typename tCoste> 
GrafoP<tCoste> tarifaMinima(const GrafoP<tCoste>& Bus,
                            const GrafoP<tCoste>& Tren,
                            const typename GrafoP<tCoste>::vertice& cambio){
    typedef GrafoP<tCoste>::vertice vertice;
    size_t N = G.numVert();
    GrafoP<tCoste> costesMin(N); // Matriz de constes  a devolver

    matriz<vertice> P; // Necesaria para algoritmo pero no la usaremos
    // Solo bus
    matriz<tCoste> minBus = Floyd(Bus, P);
    // Solo tren
    matriz<tCoste> minTren = Floyd(Tren, P);

    // Rellenamos la matriz con el coste minimo entre las cuatro opciones posibles
    tCoste minDirecto, minCambio;
    for(vertice i=0 ; i < N ; i++){
        for(vertice j=0 ; j < N ; j++){
            minDirecto  = std::min(minTren[i][j], minBus[i][j]); // Solo Tren || solo Bus
            minCambio   = std::min(suma(minTren[i][cambio], minBus[cambio][i]),  // Tren-> cambio ->bus
                                   suma(minBus[i][cambio], minTren[cambio][i])); // bus-> cambio ->tren 
            G[i][j]     = std::min(minDirecto, minCambio); // Guardamos la mejor opcion entre las cuatro
        }    
    }

    return G;
}
```

### Ejercicio 7

Se dispone de dos grafos (matriz de costes) que representan los costes de viajar entre N ciudades españolas utilizando el tren (primer grafo) y el autobús (segundo grafo).
Ambos grafos representan viajes entre las mismas N ciudades.

Nuestro objetivo es hallar el camino de coste mínimo para viajar entre dos ciudades
concretas del grafo, origen y destino, en las siguientes condiciones:

- La ciudad origen sólo dispone de transporte por tren.
- La ciudad destino sólo dispone de transporte por autobús.
- El sector del taxi, bastante conflictivo en nuestros problemas, sigue en huelga, por lo que únicamente es posible cambiar de transporte en dos ciudades del grafo, cambio1 y cambio2, donde las estaciones de tren y autobús están unidas.

Implementa un subprograma que calcule la ruta y el coste mínimo para viajar entre las ciudades Origen y Destino en estas condiciones.

```cpp
template <typename tCoste> 
tCoste rutaCosteMin(const GrafoP<tCoste>& Tren,     // Matriz de costes deviaje en tren
                    const GrafoP<tCoste>& Bus,      // Matriz de costes deviaje en bus
                    const typename GrafoP<tCoste>::vertice origen,      // Origen del viaje
                    const typename GrafoP<tCoste>::vertice destino,     // Destino del viaje
                    const typename GrafoP<tCoste>::vertice cambio1,     // Vertice en el que se permite transbordo
                    const typename GrafoP<tCoste>::vertice cambio2,     // Vertice en el que se permite transbordo
                    vector<typename GrafoP<tCoste>::vertice>& rutaOrigenCambio,     // Camino de origen a cambio
                    vector<typename GrafoP<tCoste>::vertice>& rutaCambioDestino)    // Camino de cambio a destino
{
    typedef GrafoP<tCoste>::vertice vertice;
    size_t N = Tren.numVert();

    // Aplicamos Dijkstra en vertice origen para obtener las rutas minimas entre ellas origen -> cambio
    // Aplicamos DijkstraInv en vertice detino para obtener las rutas minimas entre ellas cambio -> destino
    vector<tCoste> origenCambio = Dijkstra(Tren, origen, rutaOrigenCambio);
    vector<tCoste> cambioDestino = DijkstraInv(Tren, destino, rutaCambioDestino);

    // ORIGEN --tren--> CAMBIO_1 --bus--> DESTINO
    tCoste cambio1 = suma(origenCambio[cambio1], cambioDestino[cambio1]);

    //ORIGEN --bus--> CAMBIO_2 --tren-->  DESTINO
    tCoste cambio2 = suma(origenCambio[cambio1], cambioDestino[cambio1]);

    return std::min(cambio1, cambio2);
}
```

### Ejercicio 8

“UN SOLO TRANSBORDO, POR FAVOR”. Este es el título que reza en tu flamante compañía de viajes. Tu publicidad explica, por supuesto, que ofreces viajes combinados de TREN y/o AUTOBÚS (es decir, viajes en tren, en autobús, o usando ambos), entre N ciudades del país, que ofreces un servicio inmejorable, precios muy competitivos, y que garantizas ante notario algo que no ofrece ninguno de tus competidores: que en todos tus viajes COMO MÁXIMO se hará un solo transbordo (cambio de medio de transporte).

Bien, hoy es 1 de Julio y comienza la temporada de viajes. ¡Qué suerte!  
Acaba de aparecer un cliente en tu oficina. Te explica que quiere viajar entre dos ciudades, Origen y Destino, y quiere saber cuánto le costará. Para responder a esa pregunta dispones de dos grafos de costes directos (matriz de costes) de viajar entre las N ciudades del país, un grafo con los costes de viajar en tren y otro en autobús.

Implementa un subprograma que calcule la tarifa mínima en estas condiciones.
Mucha suerte en el negocio, que la competencia es dura.

```cpp
template <typename tCoste> 
double tarifaMinima(const GrafoP<tCoste>& Tren,
                    const GrafoP<tCoste>& Bus,
                    const typename GrafoP<tCoste>::vertice origen,
                    const typename GrafoP<tCoste>::vertice destino)
{
    typedef GrafoP<tCoste>::vertice vertice;

    vector<vertice> ruta; // No nos pide la ruta por lo que usamos el mismo vector
    vector<tCoste> origenTren = Dijkstra(Tren, origen, ruta),
                   destinoTren = DijkstraInv(Tren, origen, ruta),
                   origenBus = Dijkstra(Bus, origen, ruta),
                   destinoBus = DijkstraInv(Bus, origen, ruta);

    // Camino con transbordo de minimo coste tren->bus
    tCoste<tCoste> minTrenBus = suma(origenTren[0], destinoBus[0]);
    for(size_t i = 0 ; i < origenTren.size() ; i++)
        if(minTrenBus < suma(origenTren[i], destinoBus[i])) // Hacer transbordo en i es menos costoso
            minTrenBus = suma(origenTren[i], destinoBus[i]);

    // Camino con transbordo de minimo coste bus->tren
    tCoste<tCoste> minBusTren = suma(origenBus[0], destinoTren[0]);
    for(size_t i = 0 ; i < origenBus.size() ; i++)
        if(minBusTren < suma(origenBus[i], destinoTren[i])) // Hacer transbordo en i es menos costoso
            minBusTren = suma(origenBus[i], destinoTren[i]);
    
    return std::min(minTrenBus, minBusTren);
}
```

¿typedef al principio?¿hace falta typename?¿se puede usar en el examen?

### Ejercicio 9

Se dispone de dos grafos que representan la matriz de costes para viajes en un determinado país, pero por diferentes medios de transporte (tren y autobús, por ejemplo). Por supuesto ambos grafos tendrán el mismo número de nodos, N. Dados ambos grafos, una ciudad de origen, una ciudad de destino y el coste del taxi para cambiar de una estación a otra dentro de cualquier ciudad (se supone constante e igual para todas las ciudades), implementa un subprograma que calcule el camino y el coste mínimo para ir de la ciudad origen a la ciudad destino.

```cpp
template <typename tCoste> 
tCoste rutaCosteMin(const GrafoP<tCoste>& Tren,
                    const GrafoP<tCoste>& Bus,
                    const typename GrafoP<tCoste>::vertice origen,
                    const typename GrafoP<tCoste>::vertice destino,
                    const tCoste costeTaxi,
                    vector<typename GrafoP<tCoste>::vertice>& caminoCosteMin) // Vector donde se devuelve el camino de coste minimo
{
    typedef GrafoP<tCoste>::vertice vertice;
    size_t N = Tren.numVert();
    GrafoP<tCoste> G(2*N);

    // Rellenamos matriz de costes para aplicar Dijkstra
    for(vertice i=0 ; i < N ; i++){
        G[i][i+n] = costeTaxi;          // Tren -> Bus  (Segundo cuadrante)
        G[i+n][i] = costeTaxi;          // Bus  -> Tren (Tercer cuadrante)
        for(vertice j=0 ; j < N ; j++){
            G[i][j] = Tren[i][j];       // Tren -> Tren (Primer cuadrante)
            G[i+n][2+n] = Bus[i][j];    // Bus  -> Bus  (Cuarto cuadrante)
        }
    }

    // Aplicamos Dijkstra para obtener costes mínimos desde origen
    vector<tCoste> costeMin = Dijkstra(G, origen, caminoCosteMin);

    return costeMin[destino];
}
     
```

### Ejercicio 10

Se dispone de tres grafos que representan la matriz de costes para viajes en un determinado país, pero por diferentes medios de transporte (tren, autobús y avión). Por supuesto los tres grafos tendrán el mismo número de nodos, N.

Dados los siguientes datos:

- los tres grafos,
- una ciudad de origen,
- una ciudad de destino,
- el coste del taxi para cambiar, dentro de una ciudad, de la estación de tren a la de autobús o viceversa(taxi-tren-bus) y
- el coste del taxi desde el aeropuerto a la estación de tren o la de autobús, o viceversa (taxi-aeropuerto-tren/bus)

y asumiendo que ambos costes de taxi (distintos entre sí, son dos costes diferentes) son constantes e iguales para todas las ciudades, implementa un subprograma que calcule el camino y el coste mínimo para ir de la ciudad origen a la ciudad destino.

```cpp
template <typename tCoste> 
tCoste rutaCosteMin(const GrafoP<tCoste>& Tren,
                    const GrafoP<tCoste>& Bus,
                    const GrafoP<tCoste>& Avion,
                    const typename GrafoP<tCoste>::vertice origen,
                    const typename GrafoP<tCoste>::vertice destino,
                    const tCoste taxiBusTren,
                    const tCoste taxiAvion,
                    vector<typename GrafoP<tCoste>::vertice>& caminoCosteMin)
{
    typedef GrafoP<tCoste>::vertice vertice;
    size_t N = Tren.numVert();
    GrafoP<tCoste> G(3*N);

    // Rellenamos matriz de costes para aplicar Dijkstra
    for(vertice i=0 ; i < N ; i++){
        G[i]  [i+n] = taxiBusTren;      // Tren -> Bus
        G[i+n][i] = taxiBusTren;        // Bus  -> Tren

        G[i]    [i+n+n] = taxiAvion;    // Tren -> Avion
        G[i+n]  [i+n+n] = taxiAvion;    // Bus -> Avion
        G[i+n+n][i]     = taxiAvion;    // Avion -> Tren
        G[i+n+n][i+n]   = taxiAvion;    // Avion -> Bus

        for(vertice j=0 ; j < N ; j++){
            G[i][j] = Tren[i][j];           // Tren -> Tren 
            G[i+n][j+n] = Bus[i][j];        // Bus  -> Bus 
            G[i+n+n][j+n+n] = Bus[i][j];    // Avion  -> Avion
        }
    }

    vector<tCoste> costesMin = Dijkstra(G, origen, caminoCosteMin);

    return costesMin[destino];
}
```

### Ejercicio 11

Disponemos de tres grafos (matriz de costes) que representan los costes directos de viajar entre las ciudades de tres de las islas del archipiélago de las Huríes (Zuelandia).  

Para poder viajar de una isla a otra se dispone de una serie de puentes que conectan ciudades de las diferentes islas a un precio francamente asequible (por decisión del Prefecto de las Huríes, el uso de los puentes es absolutamente gratuito).

Si el alumno desea simplificar el problema, puede numerar las N1 ciudades de la isla
1, del 0 al N1-1, las N2 ciudades de la isla 2, del N1 al N1+N2-1, y las N3 de la última, del
N1+ N2 al N1+N2+ N3-1.

Disponiendo de las tres matrices de costes directos de viajar dentro de cada una de
las islas, y la lista de puentes entre ciudades de las mismas, calculad los costes mínimos
de viajar entre cualesquiera dos ciudades de estas tres islas.
¡¡¡ QUE DISFRUTÉIS EL VIAJE !!!

```cpp

```

### Ejercicio 12

El archipiélago de Grecoland (Zuelandia) está formado únicamente por dos islas, Fobos y Deimos, que tienen N1 y N2 ciudades, respectivamente, de las cuales C1 y C2 ciudades son costeras (obviamente C1 ≤ N1 y C2 ≤ N2). Se desea construir un puente que una ambas islas. Nuestro problema es elegir el puente a construir entre todos los posibles, sabiendo que el coste de construcción del puente se considera irrelevante. Por tanto, escogeremos aquel puente que minimice el coste global de viajar entre todas las ciudades de las dos islas, teniendo en cuenta las siguientes premisas:

1. Se asume que el coste viajar entre las dos ciudades que una el puente es 0.
2. Para poder plantearse las mejoras en el transporte que implica la construcción de un puente frente a cualquier otro, se asume que se realizarán exactamente el mismo número de viajes entre cualesquiera ciudades del archipiélago. Por ejemplo, se considerará que el número de viajes entre la ciudad P de Fobos y la Q de Deimos será el mismo que entre las ciudades R y S de la misma isla. Dicho de otra forma, todos los posibles trayectos a realizar dentro del archipiélago son igual de importantes.

Dadas las matrices de costes directos de Fobos y Deimos y las listas de ciudades
costeras de ambas islas, implementa un subprograma que calcule las dos ciudades que
unirá el puente.

```cpp

```

### Ejercicio 13

El archipiélago de las Huríes acaba de ser devastado por un maremoto de dimensiones desconocidas hasta la fecha. La primera consecuencia ha sido que todos y cada uno de los puentes que unían las diferentes ciudades de las tres islas han sido destruidos. En misión de urgencia las Naciones Unidas han decidido construir el mínimo número de puentes que permitan unir las tres islas. Asumiendo que el coste de construcción de los puentes implicados los pagará la ONU, por lo que se considera irrelevante, nuestro problema es decidir qué puentes deben construirse. Las tres islas de las Huríes tienen respectivamente N1, N2 y N3 ciudades, de las cuales C1, C2 y C3 son costeras (obviamente C1 ≤ N1 , C2 ≤ N2 y C3 ≤ N3) . Nuestro problema es elegir los puentes a construir entre todos los posibles. Por tanto, escogeremos aquellos puentes que minimicen el coste global de viajar entre todas las ciudades de las tres islas, teniendo en cuenta las siguientes premisas:

1. Se asume que el coste viajar entre las ciudades que unan los puentes es 0.
2. La ONU subvencionará únicamente el número mínimo de puentes necesario para comunicar las tres islas.
3. Para poder plantearse las mejoras en el transporte que implica la construcción de un puente frente a cualquier otro, se asume que se realizarán exactamente el mismo número de viajes entre cualesquiera ciudades del archipélago. Dicho de otra forma, todos los posibles trayectos a realizar dentro del archipiélago son igual de importantes.

Dadas las matrices de costes directos de las tres islas y las listas de ciudades costeras
del archipiélago, implementad un subprograma que calcule los puentes a construir en las
condiciones anteriormente descritas.

```cpp

```
