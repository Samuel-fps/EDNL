/*EJERCICIO 1
Implementa un subprograma que dado un árbol general nos calcule su grado.
*/

template <typename T>
int gradoMax(Agen<T> A){
    return gradoMaxRec(A, A.raiz());
}

template <typename T>
int gradoMaxRec(Agen<T> A, Agen<T>::nodo n){
    if(A.hizq(n) == Agen<T>::NODO_NULO) return 0;
    else{
        int gradoMax = numHijos(n, A);
        Agen<T>::nodo aux = n;
        while(aux != Agen<T>::NODO_NULO){ // Recorro hermanos
            gradoMax = std::max(gradoMax, gradoMaxRec(A, aux));
            aux = A.hermadoDer(aux);
        }
        return gradoMax;
    }
}

/*EJERCICIO 2
Implementa un subprograma que dados un árbol y un nodo dentro de dicho árbol determine
la profundidad de éste nodo en el árbol. 
*/
template <typename T>
profundidadNodo(Agen<T> A, Agen<T>::nodo n){
    if(Agen<T>::NODO_NULO == n) return 0;
    else return 1 + profundidadNodo(A, A.padre());
}

/*EJERCICIO 3
Se define el desequilibrio de un árbol general como la máxima diferencia entre las alturas
de los subárboles más bajo y más alto de cada nivel. Implementa un subprograma que calcule
el grado de desequilibrio de un árbol general.
*/
template <typename T>
int desequilibrio(Agen<T> A){
    return desequilibrioRec(A,  A.raiz());
}

template <typename T>
return desequilibrioRec(Agen<T> A, Agen<T>::nodo n){
    if(Agen<T>::NODO_NULO == A.hizq(n)) return 0;
    else{
        int minimo = 1000000;
        Agen<T>::nodo aux = A.hizq(n);
        while(aux != Agen<T>::NODO_NULO){
            minimo = std::min(minimo, desequilibrioRec(A, aux));
            aux = A.hermanoDrch(aux);
        }
        return 1 + minimo;
    }
}


/*EJERCICIO 4
Dado un árbol general de enteros A y un entero x, implementa un subprograma que realice
la poda de A a partir de x. Se asume que no hay elementos repetidos en A. 
*/

template <typename T>
void poda(Agen<T> A, Agen<T>::nodo poda){
    podaRec(A,  A.raiz(), n);
}

void podaRec(Agen<T> A, Agen<T>::nodo n, Agen<T>::nodo poda){
    if(n == poda){ // encuenta el nodo
        
    }
    else if(Agen<T>::NODO_NULO == A.hizq(n)){  // esto else reorren el arbol
        podaRec(A, A.hizq(n), poda);
    else{  
        Agen<T>::nodo aux = A.hizq(n);
        while(aux != Agen<T>::NODO_NULO){
            podaRec(A, aux, poda);
            aux = A.hermanoDrch(aux);
        }
    }
}

