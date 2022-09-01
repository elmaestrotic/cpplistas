//
// Created by Alexander on 27/08/2022.
//

#ifndef LISTICAS_NODO_H
#define LISTICAS_NODO_H


class Nodo
        {
        protected:
            int dato;
            Nodo* enlace;
        public:
            Nodo(int t)
            {
                dato = t;
                enlace = 0; // 0 es el puntero NULL en C++
            }
            Nodo(int p, Nodo* n) // crea el nodo y lo enlaza a n
            {
                dato = p;
                enlace = n;
            }
            int datoNodo( ) const
            {
                return dato;
            }
            Nodo* enlaceNodo( ) const
            {
                return enlace;
            }
            void ponerEnlace(Nodo* sgte)
            {
                enlace = sgte;
            }
        };

#endif //LISTICAS_NODO_H
