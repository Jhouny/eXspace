#ifndef _PONTO_H_
#define _PONTO_H_

#include "../Auxiliares/stdafx.h"
#include "../Gerenciadores/Grafico.h"
#include "../Ente/Entidades/Dinamicas/Jogador.h"

#define TEX_PONTO_VAZIO "PrincipalJogo/assets/Texturas/InimigoAbatido/inimigo_abatido_vazio.png"

namespace ElementosGraficos {
    enum PontoID {
        indef = 0,
        coracao,
        inimigoAbatido
    };
    class Ponto {
        protected:
            Coordenada tamanho;
            Coordenada posicao;
            Coordenada posicaoRelativa;
            Entidades::Personagens::Jogador* ref;  // A qual jogador se posicionar

            sf::Sprite sprite;

            Gerenciadores::Grafico* pGrafico;

            bool preenchido;
            PontoID pId;
        public:
            Ponto(Coordenada tam, Coordenada pos, Entidades::Personagens::Jogador* jog);

            ~Ponto();

            PontoID getPontoID() const { return pId; }

            Coordenada getPosicao() const { return posicao; }

            void preencher();

            void limpar();

            sf::Sprite* getSprite() { return &sprite; }

            void setTextura(const char* path);

            void atualizaPosicao(Coordenada pos);

            virtual void atualizarTextura() = 0;

            virtual void executar(Coordenada pos);
        };    
} // namespace ElementosGraficos 

#endif