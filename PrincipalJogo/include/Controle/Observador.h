#ifndef _OBSERVADOR_H_
#define _OBSERVADOR_H_

#include "../Gerenciadores/Entrada.h"

namespace Controle {
    class Observador {
        protected:
            int id;
            Gerenciadores::Entrada* pEntrada;
        public:
            static int cont;  // Contadora de IDs

            Observador();

            virtual ~Observador();

            int getID() const { return id; }

            virtual void compartilharTeclaPressionada() = 0;

            virtual void compartilharTeclaLiberada(std::string tecla) = 0;
    };
}

#endif