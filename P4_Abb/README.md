# Práctica 4: Árboles Binarios de Búsqueda

## ÁRBOLES PARA EJERCICIOS

Los ficheros .dat contienen unos árboles de ejemplo para probar los ejercicios sin necesidad de introducir un árbol manualmente, se leen gracias al fichero agen_E-S.h.
A continuación se muestra una imagen que representa los árboles guardados en cada fichero.

### AbbA.dat

![AbbA.dat](AbbA.png)

### AbbB.dat

![AbbB.dat](AbbB.png)

## EJERCICIOS

### Ejercicio 1

Implementa una nueva operación del TAD Abb que tomando un elemento del mismo
elimine al completo el subárbol que cuelga de él.

```cpp

```

### Ejercicio 2

Un árbol binario de búsqueda se puede equilibrar realizando el recorrido en inorden
del árbol para obtener el listado ordenado de sus elementos y a continuación, repartir
equitativamente los elementos a izquierda y derecha colocando la mediana en la raíz y
construyendo recursivamente los subárboles izquierdo y derecho de cada nodo.
Implementa este algoritmo para equilibrar un ABB.

```cpp

```

### Ejercicio 3

Dados dos conjuntos representados mediante árboles binarios de búsqueda,
implementa la operación unión de dos conjuntos que devuelva como resultado otro
conjunto que sea la unión de ambos, representado por un ABB equilibrado.

```cpp

```

### Ejercicio 4

Dados dos conjuntos representados mediante árboles binarios de búsqueda,
implementa la operación intersección de dos conjuntos, que devuelva como resultado
otro conjunto que sea la intersección de ambos. El resultado debe quedar en un árbol
equilibrado.

```cpp

```

### Ejercicio 5

Implementa el operador  para conjuntos definido como A  B = (A  B) - (A  B).
La implementación del operador  debe realizarse utilizando obligatoriamente la
operación , que nos indica si un elemento dado pertenece o no a un conjunto. La
representación del tipo Conjunto debe ser tal que la operación de pertenencia esté en el
caso promedio en O(log n).

```cpp

```
