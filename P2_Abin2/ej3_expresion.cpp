
#include "../TAD_ABIN/ABinEnla.h" // Importamos el arbol binario
using namespace std;

//////////// Esta parte es solo para poder leer los arboles de los ficheros
#include <iostream>
#include <fstream>

#include "abin_E-S.h"
typedef std::string tElto;
const tElto fin = "#";
////////////////////////////////////

/*  EJERCICIO 3 - Expresiones matemáticas

    El TAD árbol binario puede albergar expresiones matemáticas mediante un árbol de
    expresión. Dentro del árbol binario los nodos hojas contendrán los operandos, y el resto
    de los nodos los operadores.
*/
#include <string>

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

int main(){
    // Leer Arbol del fichero
    Abin<string> A;
    // Introducir los valores en este orden: * 7 # # / - 15 # # 3.2 # # 2 # # 
    rellenarAbin(A, fin);

    cout << "Resultado = 7*(15-3.2)/2" << resolver(A) << endl;
    cout << "Resultado Esperado = 41.3" << endl;
    
    //cout << "\n*** Mostrar árbol binario A ***\n";
    //imprimirAbin(A); // En std::cout

    return 0;
}