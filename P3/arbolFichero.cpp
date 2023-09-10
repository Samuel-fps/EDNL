#include <iostream>
#include <fstream>

#include "../../TAD_ABIN/ABinC.h"
#include "../abin_E-S.h" 

using namespace std;
typedef string tElto;
const tElto fin = "#"; // Fin de lectura. 

int main ()
{
    Abin<tElto> A, B;
    cout << "*** Lectura del árbol binario A ***\n";
    rellenarAbin(A, fin); // Desde std::cin
    ofstream fs("arbolA.dat"); // Abrir fichero de salida.
    imprimirAbin(fs, A, fin); // En fichero.
    fs.close();
    cout << "\n*** Árbol A guardado en fichero abin.dat ***\n";
    cout << "\n*** Lectura de árbol binario B de abin.dat ***\n";
    ifstream fe("arbolA.dat"); // Abrir fichero de entrada.
    rellenarAbin(fe, B); // Desde fichero.
    fe.close();
    cout << "\n*** Mostrar árbol binario B ***\n";
    imprimirAbin(B); // En std::cout
} 
