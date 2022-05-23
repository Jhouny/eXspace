#ifndef _LISTA_ENTIDADES_H_
#define _LISTA_ENTIDADES_H_

#include "../Auxiliares/Lista.h"
#include "../Ente/Entidades/Entidade.h"

class ListaEntidades{
    public:
        Lista<Entidade> le;

        Entidade* operator[](int index) {
            return le[index];
        }

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

        void print(){
            int i;
            for(i=0;i<le.getTamanho();i++){
                cout << "ID: " << le[i]->getID() << endl;
            }

        }


};



#endif