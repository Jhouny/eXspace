#ifndef _BOTAO_ALTERNADOR_H_
#define _BOTAO_ALTERNADOR_H_

#include "Botao.h"

#define TEX_BOTAO_ALTERNADOR_ATIVO "PrincipalJogo/assets/Texturas/Botoes/botao3.png"
#define TEX_BOTAO_ALTERNADOR_NEUTRO "PrincipalJogo/assets/Texturas/Botoes/botao4.png"

namespace ElementosGraficos {
    class BotaoAlternador: public Botao {
        private:
            int indice;
            std::vector<std::pair<Texto*, int>> escolha;
            Botao* alvo;
        public:
            BotaoAlternador(Coordenada tam, Coordenada pos);

            ~BotaoAlternador();

            void setAlvo(Botao* pb) { alvo = pb;}

            void setAtivo(int ind);

            void inserirEscolha(std::string conteudo, int num);

            void proximo();

            void anterior();

            void atualizarTextura();
    };
} // namespace ElementosGraficos 

#endif