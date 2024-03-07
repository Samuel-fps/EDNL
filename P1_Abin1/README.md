
# Práctca 1 Árboles Binarios 1

## Ejercicio 1

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

## Ejercicio 2

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

## Ejercicio 3

Implementa un subprograma que, dados un árbol binario y un nodo del mismo, determine
la profundidad de este nodo en dicho árbol.

```cpp
template <typename T>
int profundidadNodo(const Abin<T>& A, typename Abin<T>::nodo n){
    if(n == A.raiz())
        return 0;
    else
        return 1 + profundidadNodo(A, A.padre(n));
}
```

## Ejercicio 4

Añade dos nuevas operaciones al TAD árbol binario, una que calcule la profundidad de un nodo y otra que calcule la altura de un nodo en un árbol dado. Implementa esta operación para la representación vectorial (índices del padre, hijo izquierdo e hijo derecho)

```cpp

```

## Ejercicio 5

Repite el ejercicio anterior para la representación enlazada de árboles binarios (punteros al padre, hijo izquierdo e hijo derecho).

```cpp

```

## Ejercicio 6

Implementa un subprograma que determine el nivel de desequilibrio de un árbol binario,
definido como el máximo desequilibrio de todos sus nodos. El desequilibrio de un nodo se define como la diferencia entre las alturas de los subárboles del mismo.

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

## Ejercicio 7

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

```{css, echo=FALSE}
   h1, h2, h3 { text-align: center; }
```
