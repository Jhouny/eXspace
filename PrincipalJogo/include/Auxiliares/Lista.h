#ifndef _LISTA_H_
#define _LISTA_H_
#include "stdafx.h"

template <class LT> class Lista{
    private:
        // Classe elemento para armazenar objetos sem referência direta
        template<class EL> class Elemento {
            private:
                Elemento<EL> *pProx;
                Elemento<EL> *pAnte;
                EL* el;
            public:
                Elemento() {};
                ~Elemento() {};

                void setProx(Elemento<EL> *prox) { pProx = prox;}
                Elemento<EL> *getProx() { return pProx; }

                void setAnte(Elemento<EL> *ante) { pAnte = ante; }
                Elemento<EL> *getAnte() { return pAnte; }

                void setElemento(EL *cop) { el = cop; }
                EL *getElemento() { return el; } 
        };

        Elemento<LT> *pPrimeiro;
        Elemento<LT> *pUltimo;
        int tamanho;
    public:
        Lista();
        ~Lista();

        void push(LT* cop);
        void pop();
        
        int getTamanho() { return tamanho; }

        Elemento<LT>* getInicial() { return pPrimeiro; }

        LT* operator[](int index);
};

//construtora
template<class LT> 
inline Lista<LT>::Lista(){
    pPrimeiro = NULL;
    pUltimo = NULL;
    tamanho = 0;
}

//destrutora
template<class LT>
inline Lista<LT>::~Lista(){
    Elemento<LT>*tmp;
    while(pUltimo!=NULL){
        tmp=pPrimeiro->getProx();
        delete(pPrimeiro);
        pPrimeiro=tmp;
    }
    pPrimeiro = NULL;
    pUltimo = NULL;
}

//insere na lista:
template<class LT>
inline void Lista<LT>:: push(LT* cop) {
    if(cop != NULL) {  // Se o objeto passado for válido
        tamanho++;
        Elemento<LT>* tmp = new Elemento<LT>();
        tmp->setElemento(cop);
        if(pPrimeiro == NULL) {  // Se a lista estiver vazia
            pPrimeiro = tmp;
            pUltimo = tmp;
        } else {
            tmp->setAnte(pUltimo);
            pUltimo->setProx(tmp);
            pUltimo = tmp;
        }

    } else {
        cout << "Ponteiro para copia esta nulo" << endl;
    }
}

//exclui da lista:
template<class LT> 
inline void Lista<LT>::pop() {
    Elemento<LT>* tmp = pUltimo;
    tamanho--;
    if(tmp) {
        pUltimo = pUltimo->getAnte();
        delete (tmp);
    }
    tmp = NULL;
}

// Retorna um elemento específico
template<class LT> 
inline LT* Lista<LT>::operator[](int index) {
    if(index >= 0 && index < tamanho) {
        Elemento<LT> *pEl = pPrimeiro;
        int i;

        for(i = 0; i < index; i++) {  // Itera até o elemento do indice
            pEl = pEl->getProx();
        }

        return pEl->getElemento();
    } 
    else {
        cout << "Indice: " << index << " fora da lista" << endl;
        exit(1);
    }
}

//exclui elemento especifico da lista
/* TERMINAR */


//


#endif