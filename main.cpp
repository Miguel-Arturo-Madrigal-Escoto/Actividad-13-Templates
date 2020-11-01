#include <iostream>
#include "arreglo.h"

using namespace std;

int main()
{
    Arreglo <string> arreglo;

    // agregar 4 string's a arreglo usando insertar_final e insersar_inicio()
    arreglo.insertar_final("Ultimate");
    arreglo.insertar_final("NSwitch");
    arreglo.insertar_inicio("Smash");
    arreglo.insertar_inicio("Super");
    
    // mostrar() los elementos de arreglo
    for(size_t i(0); i < arreglo.size(); i++){
        cout << arreglo[i] << " ";
    }
    
    // insertar() el elemento en la posición 2
    arreglo.insertar("Bros", 2);

    cout << endl << endl;

    // mostrar() los elementos de arreglo
    for(size_t i(0); i < arreglo.size(); i++){
        cout << arreglo[i] << " ";
    }

    cout << endl << endl;

    // eliminar_inicio() y eliminar_final()
    arreglo.eliminar_inicio();
    arreglo.eliminar_final();

    // eliminar() el elemento de la posición 1
    arreglo.eliminar(1);

    // mostrar() los elementos de arreglo
    for(size_t i(0); i < arreglo.size(); i++){
        cout << arreglo[i] << " ";
    }

    return 0;
}
