#include <iostream>

#include "ejeciciosP1.h"
#include "AbinV.h"

int main(){
	size_t maxNodos = 20;
	Abin<int> A(maxNodos);
	A.insertarRaiz(1);
	A.insertarHijoDrcho(A.raiz(), 2);
	A.insertarHijoIzqdo(A.raiz(), 3);
	
	
	return 0;
}
