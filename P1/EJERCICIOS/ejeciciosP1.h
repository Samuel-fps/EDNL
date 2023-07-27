#include "AbinC.h"
#include <algorithm>

// EJERCICIO 1
/*Implementa un subprograma que calcule el número de nodos de un árbol binario.*/

template <typename T>
int numNodes (Abin<T> A){
	return numNodes_rec(A, A.raiz());
}

template <typename T>
int numNodes_rec(Abin<T> A, const typename Abin<T>::nodo &n){
	if(n == Abin<T>::NODO_NULO)
		return 0;
	else
		return 1 + numNodes_rec(A, A.hijoIzqdo(n)) + numNodes_rec(A, A.hijoDrcho(n));
}

// EJERCICIO 2
/*Implementa un subprograma que calcule la altura de un árbol binario. */
/*
template <typename T>
int height(Abin<T> A){
	return height_rec(A, A.raiz());
}

template <typename T>
int height_rec(Abin<T> A, const typename Abin<T>::nodo n){
	if(n == Abin<T>::NODO_NULO)
		return -1;
	else
		return 1 + max(height_rec(A, A.hijoIzqdo()), height_rec(A, A.hijoDrcho()));
}

/* EJERCICIO 3

Implementa un subprograma que, dados un árbol binario y un nodo del mismo, determine 
la profundidad de este nodo en dicho árbol. */
/*
template <typename T>
int deep_rec(Abin<T> A, Abin<T>::nodo n){
	if(n == A.raiz())
		return 0;
	else
		return 1 + (deep_rec(A, A.padre(n));
}

/* EJERCICIO 4

Añade dos nuevas operaciones al TAD árbol binario, una que calcule la profundidad de un 
nodo y otra que calcule la altura de un nodo en un árbol dado. Implementa esta operación para 
la representación vectorial (índices del padre, hijo izquierdo e hijo derecho). */

// EJERCICIO 5

// EJERCICIO 6

// EJERCICIO 7
