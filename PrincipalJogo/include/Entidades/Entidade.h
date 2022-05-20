#ifndef _ENTIDADE_H_
#define _ENTIDADE_H_

#include "../Auxiliares/stdafx.h"
#include "Ente.h"

#define GRAVIDADE 3
#define PULO_Y -40


class Entidade: public Ente {
    protected:
        Coordenada posicao;  // Posicao do canto superior esquerdo do elemento
        Coordenada tamanho;  // (Comprimento, Altura) do objeto 
        sf::RectangleShape shape;
        sf::RenderWindow *window;  // Ponteiro para a janela da biblioteca gráfica

    public:
        Entidade(ID id, Coordenada tam, Coordenada pos);  // CHECAR CONSTRUTORA COM DERIVADA DA CLASSE ENTE
        ~Entidade();
        
        void setPosicao(float x, float y);
        void setPosicao(Coordenada pos);
        
        void setWindow(sf::RenderWindow *win) { this->window = win; }
        
        sf::RectangleShape* getShape() { return &shape; }
        
        Coordenada getPosicao() const { return posicao; }

        Coordenada getTamanho() const { return tamanho; }

        virtual void colisao(Entidade* outraEntidade);

        virtual void executar() = 0;

        
};

#endif