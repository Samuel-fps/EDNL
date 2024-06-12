/*
    PARCIAL_1 - Infimo y supremo

    Dado un conjunto ordenado no vacío A, se define el ínfimo de x como el mayor elemento de A
    menor o igual que x, si existe.
    Análogamente, el supremo de x en A, si existe, es el menor elemento de A mayor o igual que x.

    Implementa dos funciones de O(log n) en promedio que dados un valor x cualquiera y un Abb A no
    vacío devuelvan, respectivamente, el ínfimo y el supremo de x en A. Si no existe el ínfimo de x en A,
    la función correspondiente devolverá el mínimo de A. Así mismo, la otra función devolverá el
    máximo de A, en el caso de que no exista el supremo.

    Nota: Es absolutamente necesario definir todos los tipos de datos implicados en la resolución del
    ejercicio, así como los prototipos de las operaciones utilizadas de los TADs conocidos
*/

#include "../TAD_ABB/abb.h"
#include <algorithm>

// El tipo t debe tener operador <
template <typename T>
const T& infimo(const Abb<T>& A, const T& x){
    T max = A.elemento(),
            infimo = infimo_rec(A, x, max);
    
    if(infimo <= x)
        return infimo;
    elseS
        return max;
}

template <typename T>
const T& infimo_rec(const Abb<T>& A, const T& x, T& max){
    if(!A.vacio()){
        if(A.elemento() <= x)
            return std::max(A.elemento(), std::max(infimo_rec(A, x, max), infimo_rec(A, x)));
        else if(A.elemento() > max)
            max = A.elemento();
        return std::max(infimo_rec(A, x, max), infimo_rec(A, x, max));
    }
}

// El tipo t debe tener operador <
template <typename T>
const T& supremo(const Abb<T>& A, const T& x){

}