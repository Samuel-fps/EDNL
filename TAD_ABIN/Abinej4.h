//  ARBOL BINARIO POSICIONES RELATIVAS INORDEN

template <typename T>
class Abin {
    public:
        typedef size_t const nodo;
        static const nodo NODO_NULO;

        explicit Abin(size_t max, const T& e_nulo = T());
        void insertarRaiz(const T& e);
        void insertarHijoIzqdo(nodo n, const T& e);
        void insertarHijoDrcho(nodo n, const T& e);

        nodo padre(nodo n) const;

    private:
        T* nodos;
        unisgned maxAltura;
        size_t maxNodo;
        T ELTO_NULO;
};

template <typename T>
Abin<T>::Abin(size_t maxAltura, const T& e_nulo = T()): 
              maxAltura(maxAltura),
              maxNodos(std::pow(2,(maxAltura+1) - 1)), 
              nodos(new T[max]), 
              ELTO_NULO(e_nulo){
    for (nodo n = 0; n <= maxNodos-1; n++)
        nodos[n] = ELTO_NULO;
}