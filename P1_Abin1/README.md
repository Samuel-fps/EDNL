
# Práctca 1 Árboles Binarios 1

## ÁRBOLES PARA EJERCICIOS

En los ficheros .dat están guardados los árboles que se leen con las funciones Abin_E-S.h y nos sirven para hacer pruebas de las funciones sin tener que introducir el árbol cada vez.

### abin.dat

### abinCompleto.dat

## EJERCICIOS

### Ejercicio 1

Implementa un subprograma que calcule el número de nodos de un árbol binario.

```cpp
template <typename T>
int numNodos_rec(const Abin<T>& A, const typename Abin<T>::nodo& n){
    if(n == Abin<T>::NODO_NULO)
        return 0;
    else
        return 1 + numNodos_rec(A, A.hijoIzqdo(n)) + numNodos_rec(A, A.hijoDrcho(n));
}

template <typename T>
int numNodos(const Abin<T>& A){
    return numNodos_rec(A, A.raiz());
}
```

### Ejercicio 2

Implementa un subprograma que calcule la altura de un árbol binario.

```cpp
template <typename T>
int alturaArbol_rec(const Abin<T> A, const typename Abin<T>::nodo n){
    if(n == Abin<T>::NODO_NULO)
        return -1;
    else
        return 1 + std::max(alturaArbol_rec(A, A.hijoIzqdo(n)), alturaArbol_rec(A, A.hijoDrcho(n)));
}

template <typename T>
int alturaArbol(Abin<T> A){
    return alturaArbol_rec(A, A.raiz());
}
```

### Ejercicio 3

Implementa un subprograma que, dados un árbol binario y un nodo del mismo, determine
la profundidad de este nodo en dicho árbol.

```cpp
template <typename T>
int profundidadNodo(const Abin<T>& A, const typename Abin<T>::nodo n){
    if(n == A.raiz())
        return 0;
    else
        return 1 + profundidadNodo(A, A.padre(n));
}
```

### Ejercicio 4

Añade dos nuevas operaciones al TAD árbol binario, una que calcule la profundidad de un nodo y otra que calcule la altura de un nodo en un árbol dado. Implementa esta operación para la representación vectorial (índices del padre, hijo izquierdo e hijo derecho)

```cpp
template <typename T>
int Abin<T>::alturaArbol(const nodo n) const {
    if(n == NODO_NULO)
        return -1;
    else
        return 1 + std::max(alturaArbol(nodos[n].hizq), alturaArbol(nodos[n].hder));
}

template <typename T>
int Abin<T>::profundidadNodo(nodo n) const {
    if(n == raiz())
        return 0;
    else
        return 1 + profundidadNodo(nodos[n].padre);
}
```

¿Es mejor usar directamente nodo[0] que la funcion raiz()?

### Ejercicio 5

Repite el ejercicio anterior para la representación enlazada de árboles binarios (punteros al padre, hijo izquierdo e hijo derecho).

```cpp
template <typename T>
template <typename T>
int Abin<T>::altura(const nodo n) const {
    if(n == NODO_NULO)
        return -1;
    else
        return 1 + std::max(altura(n->hizq), altura(n->hder));
}

template <typename T>
int Abin<T>::profundidadNodo(const nodo n) const {
    if(n == r)
        return 0;
    else
        return 1 + profundidadNodo(n->padre);
}
```

### Ejercicio 6

Implementa un subprograma que determine el nivel de desequilibrio de un árbol binario, definido como el máximo desequilibrio de todos sus nodos.
El desequilibrio de un nodo se define como la diferencia entre las alturas de los subárboles del mismo.

```cpp
template <typename T>
int desequilibrioAbin_rec(Abin<T> A, typename Abin<T>::nodo n){
    if(n == Abin<T>::NODO_NULO)
        return 0;
    else // Devolve el maximo desequilibrio (entre el actual, hizq, hder)
        return  std::max(std::abs(A.altura(A.hijoIzqdo(n)) - A.altura(A.hijoDrcho(n))),
                         std::max(desequilibrioAbin_rec(A, A.hijoIzqdo(n)), desequilibrioAbin_rec(A, A.hijoDrcho(n))));
}

template <typename T>
int desequilibrioAbin(Abin<T> A){
    return desequilibrioAbin_rec(A, A.raiz());
}
```

### Ejercicio 7

Implementa un subprograma que determine si un árbol binario es o no pseudocompleto.
En este problema entenderemos que un árbol es pseudocompleto, si en el penúltimo nivel
del mismo cada uno de los nodos tiene dos hijos o ninguno.

```cpp
template <typename T>
bool esPseudocompleto_rec(Abin<T> A, typename Abin<T>::nodo n){
    if(n == Abin<T>::NODO_NULO)
        return true;
    else if(A.altura(n) == 1 
            && A.hijoIzqdo(n) == Abin<T>::NODO_NULO && A.hijoDrcho(n) != Abin<T>::NODO_NULO
            || A.hijoIzqdo(n) != Abin<T>::NODO_NULO && A.hijoDrcho(n) == Abin<T>::NODO_NULO)
        return false;
    else
        return esPseudocompleto_rec(A, A.hijoIzqdo(n)) || esPseudocompleto_rec(A, A.hijoDrcho(n));
}

template <typename T>
bool esPseudocompleto(Abin<T> A){
    return esPseudocompleto_rec(A, A.raiz());
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