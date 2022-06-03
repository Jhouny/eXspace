#ifndef _BOTAO_ALTERNADOR_H_
#define _BOTAO_ALTERNADOR_H_

#include "Botao.h"

#define TEX_BOTAO_ALTERNADOR_ATIVO "PrincipalJogo/assets/Texturas/Botoes/botao3.png"
#define TEX_BOTAO_ALTERNADOR_NEUTRO "PrincipalJogo/assets/Texturas/Botoes/botao4.png"

namespace ElementosGraficos {
    class BotaoAlternador: public Botao {
        private:
            int indice;
            std::vector<Texto*> escolha;
        public:
            BotaoAlternador(Coordenada tam, Coordenada pos);

            ~BotaoAlternador();

            void setAtivo(int ind);

            void inserirEscolha(std::string conteudo);

            void proximo();

            void anterior();

            void atualizarTextura();
    };
} // namespace ElementosGraficos 

#endif