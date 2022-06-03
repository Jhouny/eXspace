#ifndef _OBSERVADOR_H_
#define _OBSERVADOR_H_

#include "../Gerenciadores/Entrada.h"

namespace Controle {
    class Observador {
        protected:
            int id;
            Gerenciadores::Entrada* pEntrada;
            bool ativo;
        public:
            static int cont;  // Contadora de IDs

            Observador();

            virtual ~Observador();

            int getID() const { return id; }

            void ativar() { ativo = true; }

            void desativar() { ativo = false; }

            bool getAtivo() { return ativo; }

            virtual void compartilharTeclaPressionada(std::string tecla) = 0;

            virtual void compartilharTeclaLiberada(std::string tecla) = 0;
    };
}

#endif