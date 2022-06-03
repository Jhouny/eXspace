#ifndef _TEXTO_H_
#define _TEXTO_H_

#include "../Auxiliares/stdafx.h"
#include "../Gerenciadores/Grafico.h"

#define FONTE_PADRAO "PrincipalJogo/assets/Fonts/BebasNeue-Regular.ttf"
#define FONTE_ALTERNATIVA "PrincipalJogo/assets/Fonts/Starjedi.ttf"

#define PROPORCAO 30/100.f

namespace ElementosGraficos {
    enum Alinhamento {
        esquerda = 0,
        centro,
        direita
    };

    class Texto {
        private:
            Coordenada tamanho;
            Coordenada posicao;
            sf::Text texto;
            Gerenciadores::Grafico *pGrafico;
            bool estati;

        public:
            Texto(Coordenada tam, Coordenada pos, std::string conteudo, bool est = true);

            ~Texto();
            
            bool getEstatico()  { return estati; }

            sf::Text* getTexto() { return &texto; }
            void setTexto(const char* tex);

            void setPosicao(Coordenada pos);
            Coordenada getPosicao() const { return posicao; }

            void setTamanho(Coordenada tam);
            Coordenada getTamanho() const { return tamanho; }

            std::string getConteudo() const;
            void setConteudo(std::string cont);

            void setAlinhamento(Alinhamento al);
            void setFonte(const char* path);

            void setContorno(sf::Color C, float esp = 5.f);
            void setCor(sf::Color C);

            void operator=(Texto* tex);
    };
}

#endif