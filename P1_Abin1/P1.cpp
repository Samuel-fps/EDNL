#include <algorithm>

/* EJERCICIO 1 Contar Nodos
Implementa un subprograma que dado un árbol general nos calcule su grado. 
*/
template <typename T>
int contarNodos(const Abin<T>& A){
    return contarNodosRec(A, A.raiz());
}

template <typename T>
int contarNodosRec(const Abin<T>& A, Abin<T>::nodo n){
    if(Abin<T>::NODO_NULO == n) return 0;
    else return 1 + contarNodosRec(A, A.hizq(n)) + contarNodosRec(A, A.hder(n))
}

/*EJERCICIO 2 Altura
Implementa un subprograma que calcule la altura de un árbol binario. 
*/
template <typename T>
int alturaArbol(const Abin<T>& A){
    return alturaArbolRec(A, A.raiz());
}

template <typename T>
int alturaArbolRec(const Abin<T>& A, Abin<T>::nodo n){
    if(Abin<T>::NODO_NULO == n) return -1;
    else return std::max(alturaArbolRec(A, A.hizq(n)), alturaArbolRec(A, A.hder(n)));
}

/*EJERCICIO 3 Profundidad nodo
Implementa un subprograma que, dados un árbol binario y un nodo del mismo, determine
la profundidad de este nodo en dicho árbol. 
*/

template <typename T>
int profundidadNodo(const Abin<T>& A, Abin<T>::nodo n){
    if(Abin<T>::NODO_NULO == n) return 0;
    else return 1 + profundidadArbolRec(A, A.padre());
}

/*EJERCICIO 6
Implementa un subprograma que determine el nivel de desequilibrio de un árbol binario,
definido como el máximo desequilibrio de todos sus nodos. El desequilibrio de un nodo se
define como la diferencia entre las alturas de los subárboles del mismo. 
*/
template <typename T>
int desequilibrioArbol(const Abin<T>& A){
    return desequilibrioArbolRec(A, A.raiz());
}

int desequilibrioArbolRec(const Abin<T>& A, Abin<T>::nodo n){
    if(Abin<T>::NODO_NULO == n) return 0;
    else return max(std::abs(alturaArbolRec(A, A.hizq) - alturaArbolRec(A, A.hder)),) max(desequilibrioArbolRec(A, A.hizq), desequilibrioArbolRec(A, A.hder));
}

/*EJERCICIO 7 pseudocompleto
Implementa un subprograma que determine si un árbol binario es o no pseudocompleto.
En este problema entenderemos que un árbol es pseudocompleto, si en el penúltimo nivel
del mismo cada uno de los nodos tiene dos hijos o ninguno.
*/
template <typename T>
bool pseudocompleto(const Abin<T>& A){
    return pseudocompletoRec(A, A,raiz());
}

bool pseudocompletoRec(const Abin<T>& A, Abin<T>::nodo n){
    if(Abin<T>::NODO_NULO == n) return true;
    else if(alturaArbolRec(A, n) == 1 
    && Abin<T>::NODO_NULO == A.hizq(n) && Abin<T>::NODO_NULO != A.hder(n)
    || Abin<T>::NODO_NULO != A.hizq(n) && Abin<T>::NODO_NULO == A.hder(n)
    ) return false;
    else return pseudocompletoRec(A, A.hizq(n) && pseudocompletoRec(A, A.hder(n)));
}