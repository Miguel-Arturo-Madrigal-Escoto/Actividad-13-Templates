#ifndef ARREGLO_H
#define ARREGLO_H

#include <iostream>
using namespace std;

template <class T>
class Arreglo{
private:
    T *arreglo;
    size_t tam;
    size_t cont;
    const static size_t MAX = 5;

    void expandir();

public:
    Arreglo();

    void insertar_inicio(const T& v);
    void insertar_final(const T& v);
    void insertar(const T& v, size_t p);

    void eliminar_inicio();
    void eliminar_final();
    void eliminar(size_t p);

    size_t size();

    T operator[](size_t pos){
        return arreglo[pos];
    }

    ~Arreglo();
};

template <class T>
Arreglo<T>::Arreglo(){
    arreglo = new T[MAX];
    this->cont = 0;
    this->tam = MAX;
}

template <class T>
Arreglo<T>::~Arreglo(){
    delete[] arreglo;
}

template <class T>
void Arreglo<T>::insertar_inicio(const T& v){
    if(cont == tam) expandir();

    for(size_t i(cont); i > 0; i--){
        arreglo[i] = arreglo[i - 1];
    }

    arreglo[0] = v;
    cont++;
}

template <class T>
void Arreglo<T>::insertar(const T& v, size_t p){
    if(p >= cont){
         cout << "Posicion no valida";
         return;
    }

    if(cont == tam) expandir();

    for(size_t i(cont); i > p; i--){
        arreglo[i] = arreglo[i - 1];
    }
    arreglo[p] = v;
    cont++;
}

template <class T>
void Arreglo<T>::eliminar_final(){
    if(cont == 0){
        cout << "Arreglo vacio." << endl;
        return;
    }
    cont--;    
}

template <class T>
void Arreglo<T>::eliminar_inicio(){
    if(cont == 0){
        cout << "Arreglo vacio." << endl;
        return;
    }
    for(size_t i(0); i < cont-1; i++){
        arreglo[i] = arreglo[i + 1];
    }
    cont--;
}

template <class T>
void Arreglo<T>::eliminar(size_t p){
    if(cont == 0){
        cout << "Arreglo vacio." << endl;
        return;
    }
    for(size_t i(p); i < cont-1; i++){
        arreglo[i] = arreglo[i + 1];
    }
    cont--;
}

template <class T>
void Arreglo<T>::insertar_final(const T& v){
    if(cont == tam) expandir();
    arreglo[cont++] = v;
}

template <class T>
size_t Arreglo<T>::size(){
    return this->cont;
}

template <class T>
void Arreglo<T>::expandir(){
    T *nuevo = new T[tam + MAX];

    for(size_t i(0); i < cont; i++){
        nuevo[i] = arreglo[i];
    }

    /// liberar memoria arreglo pequeño
    delete[] arreglo;

    //copiar direccion de memoria
    arreglo = nuevo;

    this->tam += MAX;
}


#endif