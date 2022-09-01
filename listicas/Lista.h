//
// Created by Alexander on 27/08/2022.
//

#ifndef LISTICAS_LISTA_H
#define LISTICAS_LISTA_H


#include <cstddef>
#include "Nodo.h"

class Lista {
protected:
    Nodo *primero;
public:
    Lista() { primero = NULL; }

    void crearLista();

    void insertarCabezaLista(int entrada);

    void insertarUltimo(int entrada);

    void ultimo(int entrada);

    void insertarLista(int entrada);

    void insertarLista(Nodo* anterior, int entrada);//especial

    Nodo *buscarLista(int destino);

    void eliminar(int entrada);

    Nodo *ultimo();

    void visualizar();
};


#endif //LISTICAS_LISTA_H
