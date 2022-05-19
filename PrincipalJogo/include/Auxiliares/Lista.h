#ifndef _LISTA_H_
#define _LISTA_H_
#include "Copia.h"
#include "stdafx.h"

template <class LT> class Lista{
    private:
        Copia<LT> *pPrimeiro;
        Copia<LT> *pUltimo;
        
    public:
        Lista();
        ~Lista();

        void push(LT* cop);
        void pop();
        
        Copia<LT>* getInicial(){return pPrimeiro;}    
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
    Copia<LT>*tmp;
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
        Copia<LT>* tmp = new Copia<LT>();
        tmp->setCopia(cop);
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
    Copia<LT>* tmp;
    tmp=pUltimo;
    pUltimo=pUltimo->getAnte();
    if(tmp)
        delete (tmp);
}

//exclui elemento especifico da lista
/* TERMINAR */


 //


#endif