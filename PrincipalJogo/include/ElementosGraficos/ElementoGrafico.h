#ifndef _ELEMENTO_GRAFICO_H_
#define _ELEMENTO_GRAFICO_H_

#include "../Auxiliares/stdafx.h"
#include "../Gerenciadores/Grafico.h"


namespace ElementosGraficos {
    enum ID {
        vazio = 0,
        botao,
        coracaoElGr
    };

    class ElementoGrafico {
        protected:
            Coordenada posicao;
            Coordenada tamanho;
            sf::Sprite sprite;
            Gerenciadores::Grafico* pGrafico;
            ID id;

        public:
            ElementoGrafico(Coordenada tam, Coordenada pos, const char* pathTextura, ID Id = vazio);

            ~ElementoGrafico();

            Coordenada getPosicao() const { return posicao; }
            void setPosicao(Coordenada pos) { posicao = pos; }

            Coordenada getTamanho() const { return tamanho; }
            void setTamanho(Coordenada tam) { tamanho = tam; }

            sf::Sprite* getSprite() { return &sprite; }
            virtual void setTexture(const char* path);

            ID getID() const { return id; }

            virtual void ativar() {};

            virtual void executar() = 0;
    };
} // namespace ElementosGraficos

#endif