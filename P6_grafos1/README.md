# Práctica 6: Grafos 1

## GRAFOS PARA EJERCICIOS

### GrafoA.dat

![GrafoA.dat](GrafoA.png)

### GrafoB.dat

![GrafoB.dat](GrafoB.png)

## EJERCICIOS

### Ejercicio 1

Añadir una función genérica, llamada DijkstraInv, en el fichero alg_grafoPMC.h para resolver el problema inverso al de Dijkstra, con los mismos tipos de parámetros y de resultado que la función ya incluida para éste. La nueva función, por tanto, debe hallar el camino de coste mínimo hasta un destino desde cada vértice del grafo y su correspondiente coste. 

```cpp

```

### Ejercicio 2

Definiremos el pseudocentro de un grafo conexo como el nodo del mismo que minimiza la suma de las distancias mínimas a sus dos nodos más alejados. Definiremos el diámetro del grafo como la suma de las distancias mínimas a los dos nodos más alejados del pseudocentro del grafo.  
Dado un grafo conexo representado mediante matriz de costes, implementa un subprograma que devuelva la longitud de su diámetro. 

```cpp

```

### Ejercicio 3

Tu empresa de transportes “PEROTRAVEZUNGRAFO S.A.” acaba de recibir la lista de posibles subvenciones del Ministerio de Fomento en la que una de las más jugosas se concede a las empresas cuyo grafo asociado a su matriz de costes sea acíclico. ¿Puedes pedir esta subvención?  
Implementa un subprograma que a partir de la matriz de costes nos indique si tu empresa tiene derecho a dicha subvención. 

```cpp

```

### Ejercicio 4

Se necesita hacer un estudio de las distancias mínimas necesarias para viajar entre
dos ciudades cualesquiera de un país llamado Zuelandia. El problema es sencillo pero
hay que tener en cuenta unos pequeños detalles:
- La orografía de Zuelandia es un poco especial, las carreteras son muy estrechas
y por tanto solo permiten un sentido de la circulación.
- Actualmente Zuelandia es un país en guerra. Y de hecho hay una serie de
ciudades del país que han sido tomadas por los rebeldes, por lo que no pueden
ser usadas para viajar.
- Los rebeldes no sólo se han apoderado de ciertas ciudades del país, sino que
también han cortado ciertas carreteras, (por lo que estas carreteras no pueden ser
usadas).
- Pero el gobierno no puede permanecer impasible ante la situación y ha exigido
que absolutamente todos los viajes que se hagan por el país pasen por la capital
del mismo, donde se harán los controles de seguridad pertinentes.

Dadas estas cuatro condiciones, se pide implementar un subprograma que dados
- el grafo (matriz de costes) de Zuelandia en situación normal,
- la relación de las ciudades tomadas por los rebeldes,
- la relación de las carreteras cortadas por los rebeldes
- y la capital de Zuelandia, calcule la matriz de costes mínimos para viajar entre cualesquiera dos ciudades zuelandesas en esta situación. 

```cpp

```

### Ejercicio 5

Escribir una función genérica que implemente el algoritmo de Dijkstra usando un grafo ponderado representado mediante listas de adyacencia. 

```cpp

```

## GRAFO Especificación

### Definición

### Operaciones
