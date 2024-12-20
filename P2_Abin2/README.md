# Práctica 2: Árboles Binarios 2

## ÁRBOLES PARA EJERCICIOS

En los ficheros .dat están guardados los árboles que se leen con las funciones Abin_E-S.h y nos sirven para hacer pruebas de las funciones sin tener que introducir el árbol cada vez.

### arbolA.dat

### arbolB.dat

## EJERCICIOS

### Ejercicio 1

Dos árboles binarios son similares cuando tienen idéntica estructura de ramificación, es decir, ambos son vacíos, o en caso contrario, tienen subárboles izquierdo y derecho similares. Implementa un subprograma que determine si dos árboles binarios son similares.

```cpp
template <typename T>
bool abinSimilares_rec(Abin<T> A, Abin<T> B, typename Abin<T>::nodo nA, typename Abin<T>::nodo nB){
    if(nA == Abin<T>::NODO_NULO && nB == Abin<T>::NODO_NULO) // Los dos son nulos
        return true;
    else if(nA == Abin<T>::NODO_NULO || nB == Abin<T>::NODO_NULO) // Uno es nulo y el otro no (por el if anterior sabemos que no son los dos nulos)
        return false;
    else // Ninguno es nulo
        return abinSimilares_rec(A, B, A.hijoIzqdo(nA), B.hijoDrcho(nB)) 
            && abinSimilares_rec(A, B, A.hijoDrcho(nA), B.hijoIzqdo(nB));
}

template <typename T>
bool abinSimilares(Abin<T> A, Abin<T> B){
    return  abinSimilares_rec(A, B, A.raiz(), B.raiz());
}
```

### Ejercicio 2

Para un árbol binario B, podemos construir el árbol binario reflejado B^R cambiando los subárboles izquierdo y derecho en cada nodo. Implementa un subprograma que devuelva el árbol binario reflejado de uno dado.

```cpp
template <typename T>
void abinReflejado_rec(const Abin<T>& A, Abin<T>& C, typename Abin<T>::nodo nA, typename Abin<T>::nodo nC){
    if(n != Abin<T>::NODO_NULO){
        if(A.hijoIzqdo(nA) != Abin<T>::NODO_NULO){
            C.insertarHijoDrcho(nC, A.elemento(A.hijoIzqdo(nA)));
            abinReflejado_rec(A, C, A.hijoIzqdo(nA), C.hijoDrcho(nC));
        }
        if(A.hijoDrcho(nA) != Abin<T>::NODO_NULO){
            C.insertarHijoIzqdo(nC, A.elemento(A.hijoDrcho(nA)));
            abinReflejado_rec(A, C, A.hijoDrcho(nA), C.hijoIzqdo(nC));
        }
    }
}

template <typename T>
Abin<T> abinReflejado(const Abin<T>& A){
    Abin<T> reflejado;
    abinReflejado_rec(A, copia, A.raiz(), reflejado);
    return copia;
}
```

## Ejercicio 3

El TAD árbol binario puede albergar expresiones matemáticas mediante un árbol de expresión. Dentro del árbol binario los nodos hojas contendrán los operandos, y el resto de los nodos los operadores.

```cpp
// Los decimales deben estar con un '.' y no con una ','
double resolver_rec(const Abin<string> e, typename Abin<string>::nodo n){
    if(e.hijoIzqdo(n) == Abin<string>::NODO_NULO) // Si uno es nulo ambos hijos lo son, No puedes tenr esto : (5 + )
        return std::stod(e.elemento(n));            // Devolvemos el numero
    else
        if(e.elemento(n) == "+")
            return resolver_rec(e, e.hijoIzqdo(n)) + resolver_rec(e, e.hijoDrcho(n));
        else if(e.elemento(n) == "-")
            return resolver_rec(e, e.hijoIzqdo(n)) - resolver_rec(e, e.hijoDrcho(n));
        else if(e.elemento(n) == "*")
            return resolver_rec(e, e.hijoIzqdo(n)) * resolver_rec(e, e.hijoDrcho(n));
        else if(e.elemento(n) == "/")
            return resolver_rec(e, e.hijoIzqdo(n)) / resolver_rec(e, e.hijoDrcho(n));

}

double resolver(const Abin<string> e){
    return resolver_rec(e, e.raiz());
}
```

## Ejercicio 4

Una posible representación del TAD Árbol Binario consiste en almacenar los elementos del árbol en un vector cuyo tamaño, 𝑁 = 2^(𝐻+1) − 1 , depende de la altura máxima 𝐻 que pueda llegar a alcanzar el árbol. Cada nodo del árbol se corresponde con una única posición del vector, la cual viene determinada por el recorrido en inorden del árbol. Es decir, en el vector aparecen primero los nodos del subárbol izquierdo en inorden, luego la raíz y a continuación los nodos del subárbol derecho también en inorden. Por ejemplo, el árbol de la figura se representa como el vector

(-, -, -, n, -, -, -, a, f, l, -, b, -, d, -, h, -, -, -, -, -, -, -, m, -, c, -, j, -, -, -),

donde ‘-’ representa una posición vacía.

1. Define la clase genérica Abin\<T> para esta representación.
2. Implementa una función miembro privada que calcule la altura de un nodo de un árbol binario representado de la forma descrita.
3. Para esta representación implementa, al menos, el constructor de árboles vacíos y las operaciones insertarRaiz(), insertarHijoIzqdo() y padre(), según la especificación del TAD Árbol Binario vista en clase.

```cpp

```

## ABIN Especificación

### Definición

Un árbol binario se define como un árbol cuyos nodos son, a lo sumo, de grado 2, es
decir, tienen 0, 1 ó 2 hijos. Éstos se llaman hijo izquierdo e hijo derecho.

### Operaciones

- Abin()

  - Post: Crea y devuelve un árbol vacío.
- void insertarRaiz (const T& e)

  - Pre: El árbol está vacío.
  - Post: Inserta el nodo raíz cuyo contenido será e.
- void insertarHijoIzqdo (nodo n, const T& e)

  - Pre: n es un nodo del árbol que no tiene hijo izquierdo.
  - Post: Inserta el elemento e como hijo izquierdo del nodo n.
- void insertarHijoDrcho (nodo n, const T& e)

  - Pre: n es un nodo del árbol que no tiene hijo derecho.
  - Post: Inserta el elemento e como hijo derecho del nodo n.
- void eliminarHijoIzqdo (nodo n)

  - Pre: n es un nodo del árbol.
Existe hijoIzqdoB(n) y es una hoja.
  - Post: Destruye el hijo izquierdo del nodo n.
- void eliminarHijoDrcho (nodo n)

  - Pre: n es un nodo del árbol.
Existe hijoDrchoB(n) y es una hoja.
  - Post: Destruye el hijo derecho del nodo n.
- void eliminarRaiz ()
  - Pre: El árbol no está vacío y raiz() es una hoja.
  - Post: Destruye el nodo raíz. El árbol queda vacío.
- bool arbolVacio () const
  - Post: Devuelve true si el árbol está vacío y false en caso contrario.
- const T& elemento(nodo n) const
const T& elemento(nodo n)
  - Pre: n es un nodo del árbol.
  - Post: Devuelve el elemento del nodo n.
- nodo raíz () const
  - Post: Devuelve el nodo raíz del árbol. Si el árbol está vacío, devuelve NODO_NULO.
- nodo padre (nodo n) const
  - Pre: n es un nodo del árbol.
  - Post: Devuelve el padre del nodo n. Si n es el nodo raíz, devuelve NODO_NULO.
- nodo hijoIzqdo (nodo n) const
  - Pre: n es un nodo del árbol.
  - Post: Devuelve el nodo hijo izquierdo del nodo n. Si no existe, devuelve NODO_NULO.
- nodo hijoDrcho (nodo n) const
  - Pre: n es un nodo de A.
  - Post: Devuelve el nodo hijo derecho del nodo n. Si no existe, devuelve NODO_NULO.
