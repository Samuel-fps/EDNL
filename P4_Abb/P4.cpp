/*EJERCICIO 1
 Un árbol binario de búsqueda se puede equilibrar realizando el recorrido en inorden
del árbol para obtener el listado ordenado de sus elementos y a continuación, repartir
equitativamente los elementos a izquierda y derecha colocando la mediana en la raíz y
construyendo recursivamente los subárboles izquierdo y derecho de cada nodo.
Implementa este algoritmo para equilibrar un ABB. 
*/
template <typename T>
Abb<T> equilibrarAbb(const Abb<T>& A) {
    std::vector<T> elementos;
    insertar_inorden(A, elementos);
    return construir_arbol_equilibrado(elementos, 0, elementos.size() - 1);
}

template <typename T>
void insertar_inorden(const Abb<T>& A, std::vector<T>& elementos) {
    if (!A.vacio()) {
        insertar_inorden(A.izqdo(), elementos);S
        elementos.push_back(A.elemento());
        insertar_inorden(A.drcho(), elementos);
    }
}

template <typename T>
Abb<T> construir_arbol_equilibrado(const std::vector<T>& elementos, int inicio, int fin) {
    if (inicio > fin) {
        return Abb<T>();
    }
    
    int mediana = (inicio + fin) / 2;
    Abb<T> arbol;
    arbol.insertar(elementos[mediana]);
    arbol.asignar_izqdo(construir_arbol_equilibrado(elementos, inicio, mediana - 1));
    arbol.asignar_drcho(construir_arbol_equilibrado(elementos, mediana + 1, fin));
    return arbol;
}

/*EJERCICIO 2
Dados dos conjuntos representados mediante árboles binarios de búsqueda,
implementa la operación unión de dos conjuntos que devuelva como resultado otro
conjunto que sea la unión de ambos, representado por un ABB equilibrado. 
*/

/*EJERCICIO 3
Dados dos conjuntos representados mediante árboles binarios de búsqueda,
implementa la operación intersección de dos conjuntos, que devuelva como resultado
otro conjunto que sea la intersección de ambos. El resultado debe quedar en un árbol
equilibrado. 
*/

/*EJERCICIO 4
Implementa el operador  para conjuntos definido como A  B = (A  B) - (A  B).
La implementación del operador  debe realizarse utilizando obligatoriamente la
operación , que nos indica si un elemento dado pertenece o no a un conjunto. La
representación del tipo Conjunto debe ser tal que la operación de pertenencia esté en el
caso promedio en O(log n). 
*/