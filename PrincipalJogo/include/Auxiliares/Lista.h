#ifndef _LISTA_H_
#define _LISTA_H_
#include "stdafx.h"

template <class LT> class Lista{
    private:
        // Classe elemento para armazenar objetos sem referência direta
        template<class EL> class Elemento{
            private:
                Elemento<EL> *pProx;
                Elemento<EL> *pAnte;
                EL* el;

            public:
                Elemento() {};
                ~Elemento() {};
                void setProx(Elemento<EL>*prox) { pProx = prox;}
                Elemento<EL>*getProx() { return pProx; }

                void setAnte(Elemento<EL>*ante) { pAnte = ante; }
                Elemento<EL>*getAnte() { return pAnte; }

                void setElemento(EL* cop) { el = cop; }
                EL* getElemento() { return el; } 
        };
        Elemento<LT> *itr;
        Elemento<LT> *pPrimeiro;
        Elemento<LT> *pUltimo;
        
    public:
        Lista();
        ~Lista();

        void push(LT* cop);
        void pop();
        
        Elemento<LT>* getIterador() { return itr; }

        Elemento<LT>* getInicial() { return pPrimeiro; }    
};

//construtora
template<class LT> 
inline Lista<LT>::Lista(){
    pPrimeiro=NULL;
    pUltimo=NULL;
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
    pPrimeiro=NULL;
    pUltimo=NULL;
}

//insere na lista:
template<class LT>
inline void Lista<LT>:: push(LT* cop) {
    if(cop){
        Elemento<LT>* tmp = new Elemento<LT>();
        tmp->setElemento(cop);
        if(pPrimeiro==NULL){
            pPrimeiro = tmp;
            pUltimo = tmp;
        }
        else{
            tmp->setAnte(pUltimo);
            pUltimo->setProx(tmp);
            pUltimo=tmp;
        }

    }
    else{
        cout << "Ponteiro para copia esta nulo" << endl;
    }
}

//exclui da lista:
template<class LT> 
inline void Lista<LT>::pop() {
    Elemento<LT>* tmp;
    tmp=pUltimo;
    pUltimo=pUltimo->getAnte();
    if(tmp)
        delete (tmp);
    tmp=NULL;
}

//exclui elemento especifico da lista
/* TERMINAR */


 //


#endif