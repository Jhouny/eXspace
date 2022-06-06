#ifndef _BOTAO_H_
#define _BOTAO_H_

#include "ElementoGrafico.h"
#include "Texto.h"
#include "../Estados/Estado.h"

#define TEX_BOTAO_ATIVO "PrincipalJogo/assets/Texturas/Botoes/botao3.png"
#define TEX_BOTAO_NEUTRO "PrincipalJogo/assets/Texturas/Botoes/botao4.png"


namespace ElementosGraficos {
    class Botao: public ElementoGrafico {
        protected:
            bool ativo;
            Texto texto;
            std::string teste;  //Por algum motivo precisa disso para o BotaoAlternador funcionar
            Estados::IdEstado funcao;

        public:
            Botao(Coordenada tam, Coordenada pos, Estados::IdEstado func, std::string titulo = "" );

            ~Botao();
            
            Estados::IdEstado getFuncao() const { return funcao; }
            void setFuncao(const Estados::IdEstado func) { funcao = func;}

            void ativar();

            void desativar();

            void trocarNome();

            bool getAtivo() const { return ativo; }

            sf::Text* getTexto() { return texto.getTexto(); }
            
            virtual void atualizarTextura();

            virtual void executar();
    };

} // namespace ElementosGraficos 

#endif