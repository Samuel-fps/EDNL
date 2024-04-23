# ABIN Especificación

## Definición

Un árbol binario se define como un árbol cuyos nodos son, a lo sumo, de grado 2, es
decir, tienen 0, 1 ó 2 hijos. Éstos se llaman hijo izquierdo e hijo derecho.

## Operaciones

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
