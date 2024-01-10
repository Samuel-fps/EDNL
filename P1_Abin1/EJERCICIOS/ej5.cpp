
#include "../../TAD_ABIN/ABinC.h" // Importamos el arbol binario
using namespace std;
#include <cstddef>

//////////// Esta parte es solo para poder leer los arboles de los ficheros
#include <iostream>
#include <fstream>

#include "../abin_E-S.h"
typedef char tElto;
const tElto fin = '#';
////////////////////////////////////

/*
    EJERCICIO 5
    
*/

/*
    FUNCIONES DECLARADAS EN AbinC (No olvide agragar la declaracion en la parte publica de la clase)
    
        template <typename T>
        int Abin<T>::alturaArbol(const nodo n){
            if(n == NODO_NULO)
                return -1;
            else
                return 1 + std::max(alturaArbol(n->hizq), alturaArbol(n->hder));
        }

        template <typename T>
        int Abin<T>::profundidadNodo(const nodo n){
            if(n == r)
                return 0;
            else
                return 1 + profundidadNodo(n->padre);
        }
*/

int main(){
    // Leer Arbol del fichero
    Abin<tElto> A;
    cout << "\n*** Lectura de árbol binario B de abin.dat ***\n";
    ifstream fe("abin.dat"); // Abrir fichero de entrada.
    rellenarAbin(fe, A); // Desde fichero.
    fe.close();

    // Llamada a la funcion creada en el arbol por celdas enlazadas
    cout << "El arbol tiene una altura de " << A.altura(A.raiz()) << endl;
    cout << "El arbol tiene una profundidad de " << A.profundidadNodo(A.raiz()) << endl;

    //cout << "\n*** Mostrar árbol binario A ***\n";
    //imprimirAbin(A); // En std::cout

    return 0;
}