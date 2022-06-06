#ifndef _LISTA_ENTIDADES_H_
#define _LISTA_ENTIDADES_H_

#include "../Auxiliares/Lista.h"
#include "../Ente/Entidades/Entidade.h"

class ListaEntidades{
    public:
        Lista<Entidades::Entidade> le;

        ListaEntidades(){}
        ~ListaEntidades(){}

        // Retorna o tamanho da lista de entidades
        const int getTamanho() { return le.getTamanho(); }

        // Adiciona um elemento
        void push(Entidades::Entidade* ent) {
            if(ent) {
                le.push(ent);
            }
        }

        // Remove o ultimo elemento
        void pop() {
            le.pop();
        }

        // Remove um elemento específico
        void removeIndice(int ind) {
            le.removeIndice(ind);
        }

        void clear() {
            while(getTamanho() > 0) {
                removeIndice(0);
            }
        }

        Entidades::Entidade* operator[](int ind) {
            return le[ind];
        }

        void print(){
            int i;
            for(i=0;i<le.getTamanho();i++){
                cout << "ID: " << le[i]->getID() << endl;
            }
        }
};



#endif