#ifndef _LISTA_ENTIDADES_H_
#define _LISTA_ENTIDADES_H_

#include "../Auxiliares/Lista.h"
#include "../Entidades/Entidade.h"

class ListaEntidades{
    public:
        Lista<Entidade> le;
      
        auto getIterador() { return le.getIterador(); }

        void push(Entidade* ent) {
            le.push(ent);
        }


};



#endif