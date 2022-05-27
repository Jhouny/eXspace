#ifndef _LISTA_ENTIDADES_H_
#define _LISTA_ENTIDADES_H_

#include "../Auxiliares/Lista.h"
#include "../Ente/Entidades/Entidade.h"

class ListaEntidades{
    public:
        Lista<Entidade> le;

        // Retorna o tamanho da lista de entidades
        int getTamanho() { return le.getTamanho(); }

        // Adiciona um elemento
        void push(Entidade* ent) {
            if(ent)
                le.push(ent);
        }

        // Remove o ultimo elemento
        void pop() {
            le.pop();
        }

        // Remove um elemento específico
        void removeIndice(int ind) {
            le.removeIndice(ind);
        }

        Entidade* operator[](int index) {
            return le[index];
        }

        void print(){
            int i;
            for(i=0;i<le.getTamanho();i++){
                cout << "ID: " << le[i]->getID() << endl;
            }

        }


};



#endif