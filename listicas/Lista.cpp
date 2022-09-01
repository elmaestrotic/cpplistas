//
// Created by Alexander on 27/08/2022.
//

#include "Lista.h"
#include "Nodo.h"
#include <iostream>

using namespace std;

void Lista::Lista::crearLista() {
    int x;
    primero = NULL;
    cout << "Ingrese -1  para finalizar la lista: " << endl;
    do {
        cin >> x;
        if (x != -1) {
            primero = new Nodo(x, primero);
        }
    } while (x != -1);
}

void Lista::insertarCabezaLista(int entrada) {

    Nodo *nuevo;
    nuevo = new Nodo(entrada);
    nuevo->ponerEnlace(primero); // enlaza nuevo con primero
    primero = nuevo; // mueve primero y apunta al nuevo nodo
}

void Lista::insertarUltimo(int entrada) {
    Nodo *ultimo = this->ultimo();
    ultimo->ponerEnlace(new Nodo(entrada));
}

Nodo *Lista::ultimo() {
    Nodo *p = primero;
    if (p == NULL) throw "Error, lista vacía";
    while (p->enlaceNodo() != NULL) p = p->enlaceNodo();
    return p;
}

void Lista::insertarLista(Nodo *anterior, int entrada) {
    Nodo *nuevo;
    nuevo = new Nodo(entrada);
    nuevo->ponerEnlace(anterior->enlaceNodo());
    anterior->ponerEnlace(nuevo);
}

Nodo *Lista::buscarLista(int destino) {
    Nodo *indice;
    for (indice = primero; indice != NULL; indice = indice->enlaceNodo())
        if (destino == indice->datoNodo())
            return indice;
    return NULL;
}

void Lista::visualizar() {
    Nodo *n;
    int k = 0;
    n = primero;
    while (n != NULL) {
        char c;
        k++;
        c = (k % 15 != 0 ? ' ' : '\n');
        cout << n->datoNodo() << "|"<<c;
        n = n->enlaceNodo();
    }
}

void Lista::eliminar(int entrada) {
    Nodo *actual, *anterior;
    bool encontrado;
    actual = primero;
    anterior = NULL;
    encontrado = false;
    // búsqueda del nodo y del anterior
    while ((actual != NULL) && !encontrado) {
        encontrado = (actual->datoNodo() == entrada);
        if (!encontrado) {
            anterior = actual;
            actual = actual->enlaceNodo();
        }
    }
    // enlace del nodo anterior con el siguiente
    if (actual != NULL) {
        // distingue entre cabecera y resto de la lista
        if (actual == primero) {
            primero = actual->enlaceNodo();
        } else {
            anterior->ponerEnlace(actual->enlaceNodo());
        }
        delete actual;
    }
}