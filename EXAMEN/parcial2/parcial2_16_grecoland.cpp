#include "../TAD_GRAFO/alg_grafoPMC.h"

// Devuelve las ciudades entre las cuales construir el puente
template <typename tCoste>
void constriurPuente(const GrafoP<tCoste>& Fobos,                       // Coste ciudades Fobos
                     const GrafoP<tCoste>& Deimos,                      // Coste ciudades Deimos
                     const vector<GrafoP<tCoste>::vertice> costeras1,   // Ciudades costeras
                     const vector<GrafoP<tCoste>::vertice> costeras2,   // Ciudades costeras
                     GrafoP<tCoste>::vertice& ciudad1,                  // Ciudad donde construir el puente
                     GrafoP<tCoste>::vertice& ciudad2)                  // Ciudad donde construir el puente
{
    typedef GrafoP<tCoste>::vertice vertice;
    size_t nF = Fobos.numVert(),
           nD = Deimos.numVert();

    matriz<vertice> P;
    matriz<tCoste> minFobos = Floyd(Fobos, P);
    matriz<tCoste> minDeimos = Floyd(Deimos, P);

    int suma, minSuma;
    minSuma = GrafoP<tCoste>::INFINITO;

    // Encontrar mejor ciudad Fobos
    for(vertice costera : costeras1){
        suma = 0; // Suma de todos los caminos de ida y vuelta a la ciudad costera
        for(vertice j=0 ; j < nF ; j++){
            suma += minFobos[costera][j] + minFobos[j][costera];
        }
        if(suma < minSuma){
            minSuma = suma;
            ciudad1 = costera;
        }
    }
    
    // Enconstrar mejor ciudad Deimos
    for(vertice costera : costeras2){
        suma = 0; // Suma de todos los caminos de ida y vuelta a la ciudad costera
        for(vertice j=0 ; j < nF ; j++){
            suma += minFobos[costera][j] + minFobos[j][costera];
        }
        if(suma < minSuma){
            minSuma = suma;
            ciudad2 = costera;
        }
    }
}


template <typename tCoste> class GrafoP {
public:
   GrafoP(size_t n);
   size_t numVert() const {return costes.size();}
   const vector<tCoste>& operator [](vertice v) const {return costes[v];}
   vector<tCoste>& operator [](vertice v) {return costes[v];}
private:
   vector< vector<tCoste> > costes;
};

matriz<tCoste> Floyd(const GrafoP<tCoste>& G, GrafoP<GrafoP::vertice>& P);