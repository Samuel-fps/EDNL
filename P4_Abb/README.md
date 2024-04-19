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
template <typename T>
void eliminarSubarbol(Abb<T>& A){
    if(!A.izqdo().vacio())
        eliminarSubArbol(A.izqdo());
    if(!A.drcho().vacio())
        eliminarSubArbol(A.drcho());
    else
        A.eliminar(A.elemento());
}

template <typename T>
void eliminarSubarbolElto(Abb<T>& A, const T& elto){
    Abb<T> subarbol = A.buscar(elto);
    eliminarSubarbol(subarbol);
}
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

Dados dos conjuntos representados mediante árboles binarios de búsqueda, implementa la operación unión de dos conjuntos que devuelva como resultado otro
conjunto que sea la unión de ambos, representado por un ABB equilibrado.

```cpp
template <typename T>
using Conjunto = Abb<T>;

template <typename T>
Conjunto<T> unionAbb(const Conjunto<T>& A, Conjunto<T> B){
    Conjunto<T> res(A);
    while(B.vacio()){
        res.insertar(B.elemento());
        B.eliminar(B.elmento());
    }
    return res;
}
```

### Ejercicio 4

Dados dos conjuntos representados mediante árboles binarios de búsqueda, implementa la operación intersección de dos conjuntos, que devuelva como resultado otro conjunto que sea la intersección de ambos. El resultado debe quedar en un árbol equilibrado.

```cpp
template <typename T>
bool pertenece(const Conjunto<T>& A, const T& elto){
    if(A.buscar(elto) == Conjunto<T>::NODO_NULO)
        return false;
    return true;
}  

template <typename T>
Conjunto<T> interseccionAbb(const Conjunto<T>& A, Conjunto<T> B){
    Conjunto<T> res;
    T elto = B.elemento();

    while(B.vacio()){
        if(pertenece(A, elto))
            res.insertar(B.elemento());
    }
    return res;
}
```

### Ejercicio 5

Implementa el operador  para conjuntos definido como A  B = (A  B) - (A  B).
La implementación del operador  debe realizarse utilizando obligatoriamente la
operación , que nos indica si un elemento dado pertenece o no a un conjunto. La representación del tipo Conjunto debe ser tal que la operación de pertenencia esté en el
caso promedio en O(log n).

```cpp
template <typename T>
Conjunto<T> operator -(Conjunto<T> A, const Conjunto<T>& B){
    Conjunto<T> res;
    T elto = A.elemento();

    while(A.vacio()){
        if(!pertenece(B, elto))
            res.insertar(elto);S
        A.eliminar(elto);
    }
    return res;
}

template <typename T>
Conjunto<T> romboAbb(const Conjunto<T>& A, Conjunto<T> B){
    Conjunto<T> uni, inter;
    uni = unionAbb(A, B);
    inter = interseccionAbb(A, B);
    return uni - inter;
}
```

## ABB Especificación

### Definición

Un árbol binario de búsqueda es un árbol binario en el que los nodos almacenan elementos de un conjunto (no existen elementos repetidos). La propiedad que define a estos árboles es que todos los elementos almacenados en el subárbol izquierdo de cualquier nodo n son menores que el elemento de n, y todos los elementos almacenados en el subárbol derecho de n son mayores que el elemento almacenado en el mismo.
Consideraremos que existe un orden lineal definido sobre el tipo de los elementos dado por el operador <.

### Operaciones

- Abb()
  - Post: Construye un árbol binario de búsqueda vacío.
- const Abb& buscar(const T& e) const
  - Post: Si el elemento e pertenece al árbol, devuelve el subárbol en cuya raíz se encuentra e; en caso contrario, devuelve un árbol vacío.  
- void insertar(const T& e)
  - Post: Si e no pertenece al árbol, lo inserta; en caso contrario,   el árbol no semodifica.
- void eliminar(const T& e)
  - Post: Elimina el elemento e del árbol. Si e no se encuentra, el árbol no se modifica.
- bool vacio() const
  - Post: Devuelve true si el árbol está vacío y false en caso contrario.
- const T& elemento() const
  - Pre: Árbol no vacío.
  - Post: Devuelve el elemento de la raíz de un árbol binario de búsqueda.
- const Abb& izqdo() const
  - Pre: Árbol no vacío.  
  - Post: Devuelve el subárbol izquierdo.
- const Abb& drcho() const
  - Pre: Árbol no vacío.  
  - Post: Devuelve el subárbol derecho.  
