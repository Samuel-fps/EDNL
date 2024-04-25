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

## Implementacion

### Implementación vectorial

```cpp
// ARBOL BINARIO VECTORIAL

#ifndef ABIN_VEC0_H
#define ABIN_VEC0_H
#include <cassert>
#include <algorithm>
#include <cstddef>


template <typename T> class Abin {
  public:
		typedef size_t nodo; // �ndice de la matriz
		// entre 0 y maxNodos-1
		static const nodo NODO_NULO;
		explicit Abin(size_t maxNodos); // constructor
		void insertarRaiz(const T& e);
		void insertarHijoIzqdo(nodo n, const T& e);
		void insertarHijoDrcho(nodo n, const T& e);
		void eliminarHijoIzqdo(nodo n);
		void eliminarHijoDrcho(nodo n);
		void eliminarRaiz();
		bool arbolVacio() const;
		const T& elemento(nodo n) const; // acceso a elto, lectura
		T& elemento(nodo n); // acceso a elto, lectura/escritura

		int alturaArbol(const nodo n) const;
		int profundidadNodo(nodo n) const;
		
		nodo raiz() const;
		nodo padre(nodo n) const;
		nodo hijoIzqdo(nodo n) const;
		nodo hijoDrcho(nodo n) const;
		Abin(const Abin<T>& A); // ctor. de copia
		Abin<T>& operator =(const Abin<T>& A); // asig. de �rboles
		~Abin(); // destructor
	private:
		struct celda {
			T elto;
			nodo padre, hizq, hder;
		};
		celda *nodos; // vector de nodos
		size_t maxNodos; // tamaño del vector
		size_t numNodos; // numero de nodos del arbol
};

/* Definicion del nodo nulo */
template <typename T>
const typename Abin<T>::nodo Abin<T>::NODO_NULO(SIZE_MAX);

// EJERCICIO 4

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

template <typename T>
inline Abin<T>::Abin(size_t maxNodos) :
	nodos(new celda[maxNodos]),
	maxNodos(maxNodos),
	numNodos(0)
{}

template <typename T>
inline void Abin<T>::insertarRaiz(const T& e)
{
assert(numNodos == 0); // �rbol vac�o
numNodos = 1;
nodos[0].elto = e;
nodos[0].padre = NODO_NULO;
nodos[0].hizq = NODO_NULO;
nodos[0].hder = NODO_NULO;
}

template <typename T>
inline void Abin<T>::insertarHijoIzqdo(nodo n, const T& e)
{
	assert(n >= 0 && n < numNodos); // Nodo v�lido
	assert(nodos[n].hizq == NODO_NULO); // n no tiene hijo izqdo.
	assert(numNodos < maxNodos); // �rbol no lleno
	// A�adir el nuevo nodo al final de la secuencia.
	nodos[n].hizq = numNodos;
	nodos[numNodos].elto = e;
	nodos[numNodos].padre = n;
	nodos[numNodos].hizq = NODO_NULO;
	nodos[numNodos].hder = NODO_NULO;
	++numNodos;
}

template <typename T>
inline void Abin<T>::insertarHijoDrcho(nodo n, const T& e)
{
	assert(n >= 0 && n < numNodos); // Nodo v�lido
	assert(nodos[n].hder == NODO_NULO); // n no tiene hijo drcho.
	assert(numNodos < maxNodos); // �rbol no lleno
	// A�adir el nuevo nodo al final de la secuencia.
	nodos[n].hder = numNodos;
	nodos[numNodos].elto = e;
	nodos[numNodos].padre = n;
	nodos[numNodos].hizq = NODO_NULO;
	nodos[numNodos].hder = NODO_NULO;
	++numNodos;
}

template <typename T>
void Abin<T>::eliminarHijoIzqdo(nodo n)
{
	nodo hizqdo ;
	assert(n >= 0 && n < numNodos); // Nodo v�lido
	hizqdo = nodos[n].hizq;
	assert(hizqdo != NODO_NULO); // Existe hijo izqdo. de n.
	assert(nodos[hizqdo].hizq == NODO_NULO && // Hijo izqdo. de
	nodos[hizqdo].hder == NODO_NULO); // n es hoja.
	if (hizqdo != numNodos-1){
		// Mover el �ltimo nodo a la posici�n del hijo izqdo.
		nodos[hizqdo] = nodos[numNodos-1];
		// Actualizar la posici�n del hijo (izquierdo o derecho)
		// en el padre del nodo movido.
		if (nodos[nodos[hizqdo].padre].hizq == numNodos-1)
			nodos[nodos[hizqdo].padre].hizq = hizqdo;
		else
			nodos[nodos[hizqdo].padre].hder = hizqdo;
		// Si el nodo movido tiene hijos,
		// actualizar la posici�n del padre.
		if (nodos[hizqdo].hizq != NODO_NULO)
			nodos[nodos[hizqdo].hizq].padre = hizqdo;
		if (nodos[hizqdo].hder != NODO_NULO)
			nodos[nodos[hizqdo].hder].padre = hizqdo;
	}
	nodos[n].hizq = NODO_NULO;
	--numNodos;
}

template <typename T>
void Abin<T>::eliminarHijoDrcho(nodo n)
{
	nodo hdrcho;
	assert(n >= 0 && n < numNodos); // Nodo v�lido
	hdrcho = nodos[n].hder;
	assert(hdrcho != NODO_NULO); // Existe hijo drcho. de n.
	assert(nodos[hdrcho].hizq == NODO_NULO && // Hijo drcho. de
	nodos[hdrcho].hder == NODO_NULO); // n es hoja.
	if (hdrcho != numNodos-1){
		// Mover el �ltimo nodo a la posici�n del hijo drcho.
		nodos[hdrcho] = nodos[numNodos-1];
		// Actualizar la posici�n del hijo (izquierdo o derecho)
		// en el padre del nodo movido.
		if (nodos[nodos[hdrcho].padre].hizq == numNodos-1)
			nodos[nodos[hdrcho].padre].hizq = hdrcho;
		else
			nodos[nodos[hdrcho].padre].hder = hdrcho;
		// Si el nodo movido tiene hijos,
		// actualizar la posici�n del padre.
		if (nodos[hdrcho].hizq != NODO_NULO)
			nodos[nodos[hdrcho].hizq].padre = hdrcho;
		if (nodos[hdrcho].hder != NODO_NULO)
			nodos[nodos[hdrcho].hder].padre = hdrcho;
	}
	nodos[n].hder = NODO_NULO;
	--numNodos;
}

template <typename T>
inline void Abin<T>::eliminarRaiz()
{
	assert(numNodos == 1);
	numNodos = 0;
}

template <typename T>
inline bool Abin<T>::arbolVacio() const { return (numNodos == 0); }

template <typename T>
inline const T& Abin<T>::elemento(nodo n) const{
	assert(n >= 0 && n < numNodos);
	return nodos[n].elto;
}

template <typename T>
inline T& Abin<T>::elemento(nodo n){
	assert(n >= 0 && n < numNodos);
	return nodos[n].elto;
}

template <typename T>
inline typename Abin<T>::nodo Abin<T>::raiz() const { return (numNodos > 0) ? 0 : NODO_NULO; }

template <typename T> inline
typename Abin<T>::nodo Abin<T>::padre(nodo n) const {
	assert(n >= 0 && n < numNodos);
	return nodos[n].padre;
}

template <typename T> inline
typename Abin<T>::nodo Abin<T>::hijoIzqdo(nodo n) const
{
	assert(n >= 0 && n < numNodos);
	return nodos[n].hizq;
}
template <typename T> inline
typename Abin<T>::nodo Abin<T>::hijoDrcho(nodo n) const
{
	assert(n >= 0 && n < numNodos);
	return nodos[n].hder;
}

template <typename T>
Abin<T>::Abin(const Abin<T>& A) :
nodos(new celda[A.maxNodos]),
maxNodos(A.maxNodos),
numNodos(A.numNodos)
{
	// Copiar el vector.
	for (nodo n = 0; n <= numNodos-1; n++)
		nodos[n] = A.nodos[n];
}

template <typename T>
inline Abin<T>::~Abin() {
	delete[] nodos;
}

template <typename T>
Abin<T>& Abin<T>::operator =(const Abin<T>& A){
	if (this != &A) // Evitar autoasignaci�n.
	{
	// Destruir el vector y crear uno nuevo si es necesario.
	if (maxNodos != A.maxNodos)
	{
	delete[] nodos;
	maxNodos = A.maxNodos;
	nodos = new celda[maxNodos];
	}
	// Copiar el vector.
	numNodos = A.numNodos;
	for (nodo n = 0; n <= numNodos-1; n++)
	nodos[n] = A.nodos[n];
	}
	return *this;
}

#endif // ABIN_VEC0_H

```

### Implementación vectorial con posiciones relativas

```cpp
// ARBOL BINARIO VECTOR POSICIONES RELATIVAS

#ifndef ABIN_VEC1_H
#define ABIN_VEC1_H
#include <cassert>

template <typename T> class Abin {
	public:
		typedef size_t nodo; // indice del vector,
		// entre 0 y maxNodos-1
		static const nodo NODO_NULO;
		explicit Abin(size_t maxNodos, const T& e_nulo = T());
		void insertarRaiz(const T& e);
		void insertarHijoIzqdo(nodo n, const T& e);
		void insertarHijoDrcho(nodo n, const T& e);
		void eliminarHijoIzqdo(nodo n);
		void eliminarHijoDrcho(nodo n);
		void eliminarRaiz();
		bool arbolVacio() const;
		const T& elemento(nodo n) const; // acceso a elto, lectura
		T& elemento(nodo n); // acceso a elto, lectura/escritura
		nodo raiz() const;
		nodo padre(nodo n) const;
		nodo hijoIzqdo(nodo n) const;
		nodo hijoDrcho(nodo n) const;
		Abin(const Abin<T>& a); // ctor. de copia
		Abin<T>& operator =(const Abin<T>& a); // asig. de arboles
		~Abin(); // destructor
	private:
		T* nodos; // vector de nodos
		size_t maxNodos; // tamano del vector
		T ELTO_NULO; // marca celdas vacias
};

/* Definicion del nodo nulo */
template <typename T>
const typename Abin<T>::nodo Abin<T>::NODO_NULO(SIZE_MAX);

template <typename T>
Abin<T>::Abin(size_t maxNodos, const T& e_nulo) :
nodos(new T[maxNodos]),
maxNodos(maxNodos),
ELTO_NULO(e_nulo)
{
	// Marcar todas las celdas libres.
	for (nodo n = 0; n <= maxNodos-1; n++)
		nodos[n] = ELTO_NULO;
}

template <typename T>
inline void Abin<T>::insertarRaiz(const T& e)
{
	assert(nodos[0] == ELTO_NULO); // �rbol vac�o.
	nodos[0] = e;
}

template <typename T> inline
void Abin<T>::insertarHijoIzqdo(nodo n,const T& e)
{
	assert(n >= 0 && n <= maxNodos-1); // Nodo v�lido.
	assert(nodos[n] != ELTO_NULO); // Nodo del �rbol.
	assert(2*n+1 < maxNodos); // Hijo izqdo. cabe en el �rbol.
	assert(nodos[2*n+1] == ELTO_NULO); // n no tiene hijo izqdo.
	nodos[2*n+1] = e;
}
template <typename T> inline
void Abin<T>::insertarHijoDrcho(nodo n,const T& e)
{
	assert(n >= 0 && n < maxNodos-1); // Nodo v�lido
	assert(nodos[n] != ELTO_NULO); // Nodo del �rbol
	assert(2*n+2 < maxNodos); // Hijo drcho. cabe en el �rbol.
	assert(nodos[2*n+2] == ELTO_NULO); // n no tiene hijo drcho.
	nodos[2*n+2] = e;
}

template <typename T> inline
void Abin<T>::eliminarHijoIzqdo(nodo n)
{
	assert(n >= 0 && n <= maxNodos-1); // Nodo v�lido.
	assert(nodos[n] != ELTO_NULO); // Nodo del �rbol.
	assert(2*n+1 < maxNodos); // Hijo izqdo. cabe en el �rbol.
	assert(nodos[2*n+1] != ELTO_NULO); // n tiene hijo izqdo.
	if (4*n+4 < maxNodos) // Caben los hijos del hijo izqdo. de n
		assert(nodos[4*n+3] == ELTO_NULO && // Hijo izqdo. de
		nodos[4*n+4] == ELTO_NULO); // n es hoja
	else if (4*n+3 < maxNodos) //S�lo cabe h. izq. de h. izq. de n
		assert(nodos[4*n+3] == ELTO_NULO); //Hijo izq. de n es hoja
		nodos[2*n+1] = ELTO_NULO;
}

template <typename T> inline
void Abin<T>::eliminarHijoDrcho(nodo n)
{
	assert(n >= 0 && n <= maxNodos-1); // Nodo v�lido.
	assert(nodos[n] != ELTO_NULO); // Nodo del �rbol.
	assert(2*n+2 < maxNodos); // Hijo drcho. cabe en el �rbol.
	assert(nodos[2*n+2] != ELTO_NULO); // n tiene hijo drcho.
	if (4*n+6 < maxNodos) // Caben los hijos del hijo drcho. de n
		assert(nodos[4*n+5] == ELTO_NULO && // Hijo drcho. de
		nodos[4*n+6] == ELTO_NULO); // n es hoja
	else if (4*n+5 < maxNodos) //S�lo cabe h. izq. de h. drch de n
		assert(nodos[4*n+5] == ELTO_NULO); //Hijo drch de n es hoja
		nodos[2*n+2] = ELTO_NULO;
}

template <typename T>
inline void Abin<T>::eliminarRaiz(){
	assert(nodos[0] != ELTO_NULO); // �rbol no vac�o
	assert(nodos[1] == ELTO_NULO &&
	nodos[2] == ELTO_NULO); // La ra�z es hoja
	nodos[0] = ELTO_NULO;
}

template <typename T>
inline bool Abin<T>::arbolVacio() const
{
	return (nodos[0] == ELTO_NULO);
}

template <typename T>
inline const T& Abin<T>::elemento(nodo n) const
{
	assert(n >= 0 && n <= maxNodos-1); // Nodo v�lido.
	assert(nodos[n] != ELTO_NULO); // Nodo del �rbol.
	return nodos[n];
}

template <typename T>
inline T& Abin<T>::elemento(nodo n)
{
	assert(n >= 0 && n <= maxNodos-1); // Nodo v�lido.
	assert(nodos[n] != ELTO_NULO); // Nodo del �rbol.
	return nodos[n];
}

template <typename T>
inline typename Abin<T>::nodo Abin<T>::raiz() const
{
	return (nodos[0] == ELTO_NULO) ? NODO_NULO : 0;
}

template <typename T> inline
typename Abin<T>::nodo Abin<T>::padre(nodo n) const
{
	assert(n >= 0 && n <= maxNodos-1); // Nodo v�lido.
	assert(nodos[n] != ELTO_NULO); // Nodo del �rbol.
	return (n == 0) ? NODO_NULO : (n-1)/2;
}

template <typename T> inline
typename Abin<T>::nodo Abin<T>::hijoIzqdo(nodo n) const
{
	assert(n >= 0 && n <= maxNodos-1); // Nodo v�lido.
	assert(nodos[n] != ELTO_NULO); // Nodo del �rbol.
	return (2*n+1 >= maxNodos || nodos[2*n+1] == ELTO_NULO) ?
	NODO_NULO : 2*n+1;
}

template <typename T> inline
typename Abin<T>::nodo Abin<T>::hijoDrcho(nodo n) const
{
	assert(n >= 0 && n <= maxNodos-1); // Nodo v�lido.
	assert(nodos[n] != ELTO_NULO); // Nodo del �rbol.
	return (2*n+2 >= maxNodos || nodos[2*n+2] == ELTO_NULO) ?
	NODO_NULO : 2*n+2;
}

template <typename T>
Abin<T>::Abin(const Abin<T>& A) :
nodos(new T[A.maxNodos]),
maxNodos(A.maxNodos),
ELTO_NULO(A.ELTO_NULO)
{
	// Copiar el vector
	for (nodo n = 0; n <= maxNodos-1; n++)
		nodos[n] = A.nodos[n];
}

template <typename T>
inline Abin<T>::~Abin() { delete[] nodos; }

template <typename T>
Abin<T>& Abin<T>::operator =(const Abin<T>& A)
{
	if (this != &A) // Evitar autoasignaci�n.
	{
		// Destruir el vector y crear uno nuevo si es necesario
		if (maxNodos != A.maxNodos){
			delete[] nodos;
			maxNodos = A.maxNodos;
			nodos = new T[maxNodos];
		}
		ELTO_NULO = A.ELTO_NULO;
		// Copiar el vector.
		for (nodo n = 0; n <= maxNodos-1; n++)
			nodos[n] = A.nodos[n];
	}
	return *this;
}
#endif // ABIN_VEC1_H


````

### Implementación Celdas enlazadas

```cpp
#ifndef ABIN_H
#define ABIN_H
#include <cassert>
#include <algorithm>

template <typename T> class Abin {
		struct celda; // declaraci�n adelantada privada
		public:
			typedef celda* nodo;
			static const nodo NODO_NULO;
			Abin(); // constructor
			void insertarRaiz(const T& e);
			void insertarHijoIzqdo(nodo n, const T& e);
			void insertarHijoDrcho(nodo n, const T& e);
			void eliminarHijoIzqdo(nodo n);
			void eliminarHijoDrcho(nodo n);
			void eliminarRaiz();
			bool arbolVacio() const;

			int altura(const nodo n) const;
			int profundidadNodo(const nodo n) const;

			const T& elemento(nodo n) const; // acceso a elto, lectura
			T& elemento(nodo n); // acceso a elto, lectura/escritura
			nodo raiz() const;
			nodo padre(nodo n) const;
			nodo hijoIzqdo(nodo n) const;
			nodo hijoDrcho(nodo n) const;
			Abin(const Abin<T>& a); // ctor. de copia
			Abin<T>& operator =(const Abin<T>& A); // asig.de �rboles
		~Abin(); // destructor
	private:
		struct celda {
			T elto;
			nodo padre, hizq, hder;
			celda(const T& e, nodo p = NODO_NULO): elto(e),
			padre(p), hizq(NODO_NULO), hder(NODO_NULO) {}
		};
		
		nodo r; // nodo ra�z del �rbol
		void destruirNodos(nodo& n);
		nodo copiar(nodo n);
	};
	
/* Definici�n del nodo nulo */
template <typename T>
const typename Abin<T>::nodo Abin<T>::NODO_NULO(nullptr);

/*--------------------------------------------------------*/
/* M�todos p�blicos */
/*--------------------------------------------------------*/

// EJERCICIO 5

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


template <typename T>
inline Abin<T>::Abin() : r(NODO_NULO) {}

template <typename T>
inline void Abin<T>::insertarRaiz(const T& e)
{
	assert(r == NODO_NULO); // arbol vacio
	r = new celda(e);
}

template <typename T>
inline void Abin<T>::insertarHijoIzqdo(nodo n, const T& e)
{
	assert(n != NODO_NULO);
	assert(n->hizq == NODO_NULO); // No existe hijo izqdo.
	n->hizq = new celda(e, n);
}

template <typename T>
inline void Abin<T>::insertarHijoDrcho(nodo n, const T& e)
{
	assert(n != NODO_NULO);
	assert(n->hder == NODO_NULO); // No existe hijo drcho.
	n->hder = new celda(e, n);
}

template <typename T>
inline void Abin<T>::eliminarHijoIzqdo(nodo n)
{
	assert(n != NODO_NULO);
	assert(n->hizq != NODO_NULO); // Existe hijo izqdo.
	assert(n->hizq->hizq == NODO_NULO && // Hijo izqdo.
	n->hizq->hder == NODO_NULO); // es hoja.
	delete n->hizq;
	n->hizq = NODO_NULO;
}

template <typename T>
inline void Abin<T>::eliminarHijoDrcho(nodo n)
{
	assert(n != NODO_NULO);
	assert(n->hder != NODO_NULO); // Existe hijo drcho.
	assert(n->hder->hizq == NODO_NULO && // Hijo drcho.
	n->hder->hder == NODO_NULO); // es hoja
	delete n->hder;
	n->hder = NODO_NULO;
}

template <typename T>
inline void Abin<T>::eliminarRaiz()
{
	assert(r != NODO_NULO); // �rbol no vac�o.
	assert(r->hizq == NODO_NULO &&
	r->hder == NODO_NULO); // La ra�z es hoja.
	delete r;
	r = NODO_NULO;
}

template <typename T> inline bool Abin<T>::arbolVacio() const
{ return (r == NODO_NULO); }

template <typename T>
inline const T& Abin<T>::elemento(nodo n) const
{
	assert(n != NODO_NULO);
	return n->elto;
}

template <typename T>
inline T& Abin<T>::elemento(nodo n)
{
	assert(n != NODO_NULO);
	return n->elto;
}

template <typename T>
inline typename Abin<T>::nodo Abin<T>::raiz() const
{ return r; }

template <typename T> inline
typename Abin<T>::nodo Abin<T>::padre(nodo n) const
{
	assert(n != NODO_NULO);
	return n->padre;
}

template <typename T> inline
typename Abin<T>::nodo Abin<T>::hijoIzqdo(nodo n) const
{
	assert(n != NODO_NULO);
	return n->hizq;
}

template <typename T> inline
typename Abin<T>::nodo Abin<T>::hijoDrcho(nodo n) const
{
	assert(n != NODO_NULO);
	return n->hder;
}

template <typename T>
inline Abin<T>::Abin(const Abin<T>& A)
{
	r = copiar(A.r); // Copiar ra�z y descendientes.
}

template <typename T>
Abin<T>& Abin<T>::operator =(const Abin<T>& A)
{
	if (this != &A){
		this->~Abin(); // Vaciar el �rbol.
		r = copiar(A.r); // Copiar ra�z y descendientes.
	}
	return *this;
}

template <typename T>
inline Abin<T>::~Abin()
{
	destruirNodos(r); // Vaciar el �rbol.
}

/*--------------------------------------------------------*/
/* M�todos privados */
/*--------------------------------------------------------*/
// Destruye un nodo y todos sus descendientes
template <typename T>
void Abin<T>::destruirNodos(nodo& n)
{
	if (n != NODO_NULO){
		destruirNodos(n->hizq);
		destruirNodos(n->hder);
		delete n;
		n = NODO_NULO;
	}
}

// Devuelve una copia de un nodo y todos sus descendientes
template <typename T>
typename Abin<T>::nodo Abin<T>::copiar(nodo n)
{
	nodo m = NODO_NULO;
	if (n != NODO_NULO) {
		m = new celda(n->elto); // Copiar n.
		m->hizq = copiar(n->hizq); // Copiar sub�rbol izqdo.
		if (m->hizq != NODO_NULO) m->hizq->padre = m;
		m->hder = copiar(n->hder); // Copiar sub�rbol drcho.
		if (m->hder != NODO_NULO) m->hder->padre = m;
	}
	return m;
}

#endif // ABIN_H

```