#include <stack>

/*REPASO
Dado un árbol comprobar si es simetrico
*/

template <typename T>
bool esSimetrico(Abin<T> A, Abin<T>::nodo n){
    return esSimetrico_rec(A,  A.raiz());
}

template <typename T>
bool esSimetrico_rec(Abin<T> A, Abin<T>::nodo n){
    if(A.hijoIzqdo(n) == Abin<T>::NODO_NULO && A.hijoDrcho(n) == Abin<T>::NODO_NULO)
        return true;
    else if(A.hijoIzqdo(n) == Abin<T>::NODO_NULO || A.hijoDrcho(n) == Abin<T>::NODO_NULO)
        return false;
    else
        return A.elemento(A.hijoIzqdo()) == A.elemento(A.hijoDrcho(n)) && esSimetrico_rec(A, A.hijoIzqdo(n)) && esSimetrico_rec(A, A.hijoDrcho(n));
}


/*
Comprobar que dado un arbol todos los valores del subarbol izquierdos son menores,
mientras que todos los valores del arbol derecho deben ser mayores que el propio nodo
Arbol debúsqueda ordenado(se dara en teoria)
*/

template <typename T>
bool izqdoMenores(Abin<T> A, Abin<T>::nodo n){
    return izqdoMenores_rec(A,  A.raiz(), 0, 1000);
}

template <typename T>
bool izqdoMenores_rec(Abin<T> A, Abin<T>::nodo n, int min, int max){
    if(A.hijoIzqdo(n) == Abin<T>::NODO_NULO && A.hijoDrcho(n) == Abin<T>::NODO_NULO)
        return true;
    else if (A.elemento(n) < min || A.elemento(n) > max)
        return false;
    else 
        return izqdoMenores_rec(A, A.hijoIzqdo(n), min, A.elemento(n)) && izqdoMenores_rec(A, A.hijoDrch(n), A.elemento(n), max);
}

/*
Dado un arbol y un nodo devolver en el caso en el que exsta ese nodo en el arbol
 el camino que me lleva a ese nodo
 */

template <typename T>
Abin<T> caminoNodo(Abin<T> A, T valor){
    assert(A.raiz(), Abin<T>::NODO_NULO);
    return caminoNodo_rec(A,  A.raiz(), valor);
}

template <typename T>
void caminoNodo(Abin<T> A, Abin<T>::nodo n, T objetivo){
    if(n != Abin<T>::NODO_NULO){
        if(A.elemento(n) == objetivo){
            std::stack<T> pila;
            pila.push(A.elemento(n))
            while(n != A.raiz()){
                n = A.padre();
                pila.push(A.elemento(n));
            }
            while(!pila.emty()){
                cout << pila.top();
                pila.pop();
            }
        }
        else{
            caminoNodo(A, A.hijoIzqdo(n), objetivo);
            caminoNodo(A, A.hijoDrcho(n), objetivo);
        } 
    } 
}

/*
Cada nodo es mas rico que sus antecesores pero mas pobre que sus sucesores
*/

template <typename T>
bool riquezaNodo(Abin<T> A){
    return riquezaNodo_rec(A,  A.raiz(), 1000000, 0);
}

template <typename T>
bool riquezaNodo_rec(Abin<T> A, Abin<T>::nodo n, int min, int max){
    if(n == Abin<T>::NODO_NULO)
        return true;
    if(A.elemento(n) > A.elemento(n).padre())
        return false;
    else
        riqueaNodo_rec(A, A.hojoIzqdo(n), )
}