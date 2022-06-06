#ifndef _OBSTACULO_H_
#define _OBSTACULO_H_

#include "../Entidade.h"    
namespace Entidades::Obstaculos{
    class Obstaculo: public Entidade {
        protected:
            bool daDano;
            bool ultrapassavel;
        public:
            Obstaculo(Coordenada tam, Coordenada pos, bool dano, bool ultra, ID id = vazio);
            ~Obstaculo();

            bool Danoso() const { return daDano; }
            bool Ultrapassavel() const { return ultrapassavel; }
    };
}
#endif
