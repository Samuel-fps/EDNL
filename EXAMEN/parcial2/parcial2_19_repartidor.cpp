#include "../TAD_GRAFO/alg_grafoPMC.h"

int Pedido(){ return 10; }


template <typename tCoste>
tCoste distanciaCamion(const GrafoP<tCoste>& caminos,
                       const GrafoP<tCoste>::vertice almacen,
                       const int capacidad)
{
    typedef GrafoP<tCoste>::vertice vertice;
    tCoste distancia=0;
    size_t n = caminos.numVert();

    matriz<vertice> P;
    matriz<tCoste> caminosMin Floyd(caminos, P);

    tCoste rutaMin = GrafoP<tCoste>::INFINITO;
    vertice siguiente, actual;
    int carga, nAtendidos;
    vector<bool> atendidos(n, false); // Vector clientes atendidos

    actual = almacen;       // Iniciamos en el almacen
    carga = capacidad;      // Carga llena
    atendidos[almacen] = true; // Alamcen atendido (no tiene pedidos)
    nAtendidos = 0;         // Numero de clientes atendidos

    while(nAtendidos >= n-1){ // Mientras los clientes - Almacen no esten atendidos
        // Buscar mejor ruta
        for(vertice i=0 ; i < n ; i++){
            if(caminosMin[actual][i] < rutaMin && !atendidos[i]){
                rutaMin = caminosMin[actual][i];
                siguiente = i;
            }
        }

        // Mover camion
        distancia += caminosMin[actual][siguiente]; // Suma recorrido
        actual = siguiente; // Camnbio actual a siguiente
        if(carga >= Pedido()){
            // Entregar carga [Pedido() = 0]
            carga -= Pedido();  // Restamso la carga
            nAtendidos++;       // Cliente atendido
        }
        else{
            // Entregar carga [Pedido() -= carga]
            carga = 0;
        }

        // Camprobar si hay que volver al almacen
        if(carga == 0){
            distancia += caminosMin[actual][almacen];
            actual = almacen;
            carga = capacidad;
        }
    }
}