# APO Especificación

## Definición

Un árbol parcialmente ordenado (o montículo) es un árbol completo en el que el valor de cualquier nodo es menor o igual que el de todos sus descendientes. Por tanto, para todo nodo x de un APO el valor en el padre de x es menor o igual que el valor en x (con excepción de la raíz, que no tiene padre).

## Operaciones

## Eficiencia

| Operación             | Eficiencia     |
|-----------------------|----------------|
| Constructor           | 1              |
| Destructor            | 1              |
| Insertar              | log n          |
| Suprimir              | log n          |
| Cima (cima)           | 1              |
| Vacío (vacio)         | 1              |
| Copia (Apo::Apo)      | n              |
| Asignación (operator=)| n              |

## Implementación

```cpp
#ifndef APO_H
#define APO_H

#include <cassert>

template <typename T>
class Apo {
    public:
        explicit Apo(size_t maxNodos); // constructor
        void insertar(const T& e);
        void suprimir();
        const T& cima() const;
        bool vacio() const;
        Apo(const Apo<T>& A); // ctor. de copia
        Apo<T>& operator =(const Apo<T>& A); // asignación de apo
        ~Apo(); // destructor

    private:
        typedef size_t nodo; // índice del vector
        // entre 0 y maxNodos-1
        T* nodos; // vector de nodos
        size_t maxNodos; // tamaño del vector
        size_t numNodos; // último nodo del árbol

        nodo padre(nodo i) const { return (i-1)/2; }
        nodo hIzq(nodo i) const { return 2*i+1; }
        nodo hDer(nodo i) const { return 2*i+2; }
        void flotar(nodo i);
        void hundir(nodo i);
};

template <typename T>
inline Apo<T>::Apo(size_t maxNodos) :
    nodos(new T[maxNodos]),
    maxNodos(maxNodos),
    numNodos(0) // Apo vacío.
{}

template <typename T>
inline const T& Apo<T>::cima() const
{
    assert(numNodos > 0); // Apo no vacío.
    return nodos[0];
}

template <typename T>
inline bool Apo<T>::vacio() const
{
    return (numNodos == 0);
}

template <typename T>
inline void Apo<T>::suprimir()
{
    assert(numNodos > 0); // Apo no vacío.
    if (--numNodos > 0) // Apo no queda vacío.
    {
        nodos[0] = nodos[numNodos];
        if (numNodos > 1) // Quedan dos o más elementos.
            hundir(0); // Reordenar.
    }
}

template <typename T>
void Apo<T>::hundir(nodo i)
{
    bool fin = false;
    T e = nodos[i];
    while (hIzq(i) < numNodos && !fin) // Hundir e.
    {
        nodo hMin; // Hijo menor del nodo i.
        if (hDer(i) < numNodos && nodos[hDer(i)] < nodos[hIzq(i)])
            hMin = hDer(i);
        else
            hMin = hIzq(i);
        if (nodos[hMin] < e) { // Subir el hijo menor.
            nodos[i] = nodos[hMin];
            i = hMin;
        }
        else // e <= nodos[hMin]
            fin = true;
    }
    nodos[i] = e; // Colocar e.
}

template <typename T>
inline Apo<T>::~Apo()
{
    delete[] nodos;
}

template <typename T>
Apo<T>::Apo(const Apo<T>& A) :
    nodos(new T[A.maxNodos]),
    maxNodos(A.maxNodos),
    numNodos(A.numNodos)
{
    // Copiar el vector.
    for (nodo n = 0; n < numNodos; n++)
        nodos[n] = A.nodos[n];
}

template <typename T>
Apo<T>& Apo<T>::operator =(const Apo<T>& A)
{
    if (this != &A) // Evitar autoasignación.
    { 
        // Destruir el vector y crear uno nuevo si es necesario.
        if (maxNodos != A.maxNodos)
        {
            delete[] nodos;
            maxNodos = A.maxNodos;
            nodos = new T[maxNodos];
        }
        numNodos = A.numNodos;
        
        // Copiar el vector
        for (nodo n = 0; n < numNodos; n++)
            nodos[n] = A.nodos[n];
    }
    return *this;
}

#endif // APO_H
```
