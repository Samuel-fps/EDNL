/*EJERCICIO 1 similares
Dos árboles binarios son similares cuando tienen idéntica estructura de ramificación,
es decir, ambos son vacíos, o en caso contrario, tienen subárboles izquierdo y derecho
similares. Implementa un subprograma que determine si dos árboles binarios son similares.
*/
template <typename T>
bool similares(const Abin<T>& A, const Abin<T>& B){
    return similaresRec(A, A.raiz(), B, B.raiz());
}

bool similaresRec(const Abin<T>& A, Abin<T>::nodo na, const Abin<T>& B, Abin<T>::nodo nb){
    if(na == Abin<T>::NODO_NULO && nb == Abin<T>::NODO_NULO) 
        return true;
    else if(na != Abin<T>::NODO_NULO && nb != Abin<T>::NODO_NULO)
        return similaresRec(A, A.hizq(na), B, B.hizq(nb)) && similaresRec(A, A.hder(na), B, B.hder(nb));
    else
        return false;
}

/*EJERCICIO 2 reflejo
Para un árbol binario B, podemos construir el árbol binario reflejado B^k
cambiando los subárboles izquierdo y derecho en cada nodo. Implementa un subprograma que devuelva
el árbol binario reflejado de uno dado.
*/
template <typename T>
Abin<T> reflejado(const Abin<T>& A){
    Abin<T> B;
    reflejadoRec(A, A.raiz(), B);
    return B;
}

void reflejadoRec(const Abin<T>& A, Abin<T>::nodo n, Abin<T>& B){
    if(A.hizq() != Abin<T>::NODO_NULO){
        B->insertarHizq(A.elemento(A.hizq(n)));
        reflejadoRec(A, A.hizq(n), B);
    }
    if(A.hder() != Abin<T>::NODO_NULO){
        B->insertarHder(A.elemento(A.hder(n)));
        reflejadoRec(A, A.hder(n), B);
    }
}


/*EJERCICIO  3
El TAD árbol binario puede albergar expresiones matemáticas mediante un árbol de
expresión. Dentro del árbol binario los nodos hojas contendrán los operandos, y el resto
de los nodos los operadores.
    a) Define el tipo de los elementos del árbol para que los nodos puedan almacenar
    operadores y operandos.
    b) Implementa una función que tome un árbol binario de expresión (aritmética) y
    devuelva el resultado de la misma. Por simplificar el problema se puede asumir que el
    árbol representa una expresión correcta. Los operadores binarios posibles en la expresión
    aritmética serán suma, resta, multiplicación y división.
*/

double resolver(const Abin<T>& A){
    resolverRec(A, A.raiz());
}

double resolverRec(const Abin<T>& A, Abin<T>::nodo n){
    switch(A.elemento(n)){
        case '+': return resolver(A, A.hizq()) + resolver(A, A.hder()); break;
        case '-': return resolver(A, A.hizq()) - resolver(A, A.hder()); break;
        case '*': return resolver(A, A.hizq()) * resolver(A, A.hder()); break;
        case '/': return resolver(A, A.hizq()) / resolver(A, A.hder()); break;
        default: return A.elemento(n);
    }
}