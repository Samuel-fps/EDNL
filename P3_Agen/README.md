# Práctica 3: Árboles Generales

## ÁRBOLES PARA EJERCICIOS

Los ficheros .dat contienen unos árboles de ejemplo para probar los ejercicios sin necesidad de introducir un árbol manualmente, se leen gracias al fichero agen_E-S.h.
A continuación se muestra una imagen que representa los árboles guardados en cada fichero.

### AgenA.dat

![AgenA.dat](AgenA.png)

### AgenB.dat

Se usa para podar el árbol desde el nodo con el elemento 6 marcado en naranja.

![AgenB.dat](AgenB.png)

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
int profundidadNodo(const Agen<T>& A, typename Agen<T>::nodo n){
    if(Agen<T>::NODO_NULO == n) 
        return -1;
    else
        return 1 + profundidadNodo(A, A.padre(n));
}
```

### Ejercicio 3

Se define el desequilibrio de un árbol general como la máxima diferencia entre las alturas de los subárboles más bajo y más alto de cada nivel. Implementa un subprograma que calcule el grado de desequilibrio de un árbol general.

```cpp
template <typename T>
int alturaNodo(const Agen<T>& A, const typename Agen<T>::nodo& n){
    if(n == Agen<T>::NODO_NULO)
        return -1;
    else{
        typename Agen<T>::nodo hijo = A.hijoIzqdo(n);
        int alturaMax=0, altura;
        while(hijo != Agen<T>::NODO_NULO){
            altura = 1 + std::max(alturaNodo(A, A.hijoIzqdo(hijo)), alturaNodo(A, A.hijoDrcho(hijo)));
            if(altura > alturaMax)
                alturaMax = altura;
            hijo = A.hermDrcho(hijo);
        }
        return alturaMax;
    }
}

template <typename T>
int desequilibrioAgen_rec(const Agen<T>& A, const typename Agen<T>::nodo& n){
    if(n == Agen<T>::NODO_NULO)
        return 0;
    else{
        typename Agen<T>::nodo hijo = A.hijoIzqdo(n);
        int max, min, altura;
        max = min = altura = alturaNodo(A, hijo);
        while(hijo != Agen<T>::NODO_NULO){
            altura = alturaNodo(A, hijo);
            if(altura > max)
                max = altura;
            if(altura < min)
                min = altura;
            hijo = A.hermDrcho(hijo);
        }
        return std::abs(max-min);
    }
}

template <typename T>
int desequilibrioAgen(Agen<T> A){
    return desequilibrioAgen_rec(A, A.raiz());
}
```

### Ejercicio 4

Dado un árbol general de enteros A y un entero x, implementa un subprograma que realice la poda de A a partir de x. Se asume que no hay elementos repetidos en A.

```cpp
void podaNodo_rec(Agen<int>& A, typename Agen<int>::nodo n){
    if(n != Agen<int>::NODO_NULO){
        typename Agen<int>::nodo hijo = A.hijoIzqdo(n);
        while(hijo != Agen<int>::NODO_NULO){
            if(A.hijoIzqdo(hijo) == Agen<int>::NODO_NULO){ // No tiene hijos
                A.eliminarHijoIzqdo(A.hijoIzqdo(A.padre(hijo)));
            }
            else{
                podaNodo_rec(A, A.hijoIzqdo(hijo));
            }
            hijo = A.hermDrcho(hijo);
        }
    }
}

void encuentraEntero_rec(Agen<int>& A, typename Agen<int>::nodo n, int x){
    if(n != Agen<int>::NODO_NULO){
        typename Agen<int>::nodo hijo = A.hijoIzqdo(n);
        if(A.elemento(hijo) == x){
                podaNodo_rec(A, hijo);
                A.eliminarHijoIzqdo(n);
        }
        else{
            while(hijo != Agen<int>::NODO_NULO){
                if(A.elemento(A.hermDrcho(hijo) ) == x){
                    podaNodo_rec(A, hijo);
                    A.eliminarHermDrcho(hijo);
                }
                encuentraEntero_rec(A, hijo, x);
                hijo = A.hermDrcho(hijo);
            }
        }
    }
}

void encontrarEntero(Agen<int>& A, int x){
    encuentraEntero_rec(A, A.raiz(), x);
}
```

## AGEN Especificación

### Definición

Un árbol general se define como un árbol cuyos nodos son de cualquier grado, esdecir, pueden tener un número cualquiera de hijos. Los hijos de un nodo estánordenados de izquierda a derecha, de tal forma que el primer hijo de un nodo sellama hijo izquierdo, el segundo es el hermano derecho de éste, el tercero es el hermano derecho del segundo y así sucesivamente.

### Operaciones

- Agen()
  - Post: Construye un árbol vacío.
- void insertarRaiz (const T& e)
  - Pre: El árbol está vacío.
  - Post: Inserta el nodo raíz de A cuyo contenido será e.
- void insertarHijoIzqdo(nodo n, const T& e)
  - Pre: n es un nodo del árbol.
  - Post: Inserta el elemento e como hijo izquierdo del nodo n. Si ya existe hijo
    izquierdo, éste se convierte en el hermano derecho del nuevo nodo.
- void insertarHermDrcho(nodo n, const T& e)
  - Pre: n es un nodo del árbol y no es el nodo raíz.
  - Post: Inserta el elemento e como hermano derecho del nodo n del árbol.
    Si ya existe hermano derecho, éste se convierte en el hermano derecho
del nuevo nodo.
- void eliminarHijoIzqdo(nodo n)
  - Pre: n es un nodo del árbol. Existe hijoIzqdo(n) y es una hoja.
  - Post: Destruye el hijo izquierdo del nodo n. El segundo hijo, si existe, se convierte en el nuevo hijo izquierdo de n.
- void eliminarHermDrcho(nodo n)
  - Pre: n es un nodo del árbol. Existe hermDrcho(n) y es una hoja.
  - Post: Destruye el hermano derecho del nodo n. El siguiente hermano se convierte en el nuevo hermano derecho de n.
- void eliminarRaiz()
  - Pre: El árbol no está vacío y raiz() es una hoja.
  - Post: Destruye el nodo raíz. El árbol queda vacío.
- const T& elemento(nodo n) const
|| const T& elemento(nodo n)
  - Pre: n es un nodo del árbol.
  - Post: Devuelve el elemento del nodo n.
- nodo raiz() const
  - Post: Devuelve el nodo raíz del árbol. Si el árbol está vacío, devuelve NODO_NULO.
- nodo padre(nodo n) const
  - Pre: n es un nodo del árbol.
  - Post: Devuelve el padre del nodo n. Si n es el nodo raíz, devuelve NODO_NULO.
- nodo hijoIzqdo(nodo n) const
  - Pre: n es un nodo del árbol.
  - Post: Devuelve el hijo izquierdo del nodo n. Si no existe, devuelve NODO_NULO.
- nodo hermDrcho(nodo n) const
  - Pre: n es un nodo del árbol.
  - Post: Devuelve el hermano derecho del nodo n. Si no existe, devuelve NODO_NULO.