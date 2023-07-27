#include <iostream>

#include "ejeciciosP1.h"
#include "AbinC.h"

#include <iostream>
#include <fstream>
#include "abin_E-S.h"

using namespace std;

typedef char tElto;
const tElto fin = '#'; // Fin de lectura.

int main (){
	
	 Abin<tElto> A, B;
	 /*
	 cout << "*** Lectura del �rbol binario A ***\n";
	 rellenarAbin(A, fin); // Desde std::cin
	 ofstream fs("abin.dat"); // Abrir fichero de salida.
	 imprimirAbin(fs, A, fin); // En fichero.
	 fs.close();
	 cout << "\n*** �rbol A guardado en fichero abin.dat ***\n";
	 */
	 cout << "\n*** Lectura de �rbol binario B de abin.dat ***\n";
	 ifstream fe("abin.dat"); // Abrir fichero de entrada.
	 rellenarAbin(fe, B); // Desde fichero.
	 fe.close();
	 cout << "\n*** Mostrar �rbol binario B ***\n";
	 imprimirAbin(B); // En std::cout
	 cout << "El numero de nodos del arbol b es: " << numNodes(B);
} 
