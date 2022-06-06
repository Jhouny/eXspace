#ifndef _CONTROLE_JOGADOR_H_
#define _CONTROLE_JOGADOR_H_

#include "Observador.h"
namespace Entidades::Personagens {
    class Jogador;
}

namespace Controle {
    class ControleJogador: public Observador  {
        private:
            Entidades::Personagens::Jogador* pJogador;
            std::map<std::string, bool> teclasPressionadas;
            std::string pular;
            std::string esquerda;
            std::string direita;
            std::string atacar;
        public:
            ControleJogador(Entidades::Personagens::Jogador* pJog);

            ~ControleJogador();

            void compartilharTeclaPressionada(std::string tecla);

            void compartilharTeclaLiberada(std::string tecla);

            void setJogador(Entidades::Personagens::Jogador* pJog) { pJogador = pJog; }

            void setTeclas(std::string pu, std::string esq, std::string dir, std::string ata) {
                pular = pu;
                esquerda = esq;
                direita =  dir;
                atacar = ata;
            }

            void resetarTeclas();
    };
} 



#endif