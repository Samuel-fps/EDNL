# Práctica 3: Árboles Generales

## ÁRBOLES PARA EJERCICIOS

En los ficheros .dat están guardados los árboles que se leen con las funciones Abin_E-S.h y nos sirven para hacer pruebas de las funciones sin tener que introducir el árbol cada vez.

### arbolA.dat

### arbolB.dat

## EJERCICIOS

### Ejercicio 1

Implementa un subprograma que dado un árbol general nos calcule su grado.

```cpp
template <typename T>
int grado_rec(const Agen<T>& A, typename Agen<T>::nodo n){
    if(n == Agen<T>::NODO_NULO)
        return 0;
    else{
        typename Agen<T>::nodo hijo = A.hijoIzqdo(n); // Primero hijo izquierdo, si es nulo no tiene hijos
        int nHijos = 0, grado = 0;
        while(hijo != Agen<T>::NODO_NULO){ 
            grado = std::max(grado, grado_rec(A, A.hermDrcho(hijo), grado)); // LLamada al hermano y cojo el mayor
            nHijos++; // Sumar el grado del nodo actual
            hijo = A.hermDrcho(hijo); // Avanzar bucle (Pasar hermano)
        }
        return std::max(grado, nHijos);
    }
}

template <typename T>
int gradoAgen(const Agen<T>& A){
    return grado_rec(A, A.raiz());
}
```

### Ejercicio 2

Implementa un subprograma que dados un árbol y un nodo dentro de dicho árbol determine la profundidad de éste nodo en el árbol.

```cpp
template <typename T>
int profundidadNodo(Agen<T> A, typename Agen<T>::nodo n){
    if(n == A.raiz())
        return 0;
    else
        return 1 + profundidadNodo(A, A.padre(n));
}
```

### Ejercicio 3

Implementa un subprograma que dados un árbol y un nodo dentro de dicho árbol determine la profundidad de éste nodo en el árbol.

```cpp

```

### Ejercicio 4

Implementa un subprograma que dados un árbol y un nodo dentro de dicho árbol determine la profundidad de éste nodo en el árbol.

```cpp

```
