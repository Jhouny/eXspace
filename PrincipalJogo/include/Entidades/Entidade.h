#ifndef _ENTIDADE_H_
#define _ENTIDADE_H_

#include "../Auxiliares/stdafx.h"
#include "Ente.h"

#define GRAVIDADE 3
#define PULO_Y -40

class Entidade: public Ente {
    protected:
        Coordenada posicao;
        Coordenada tamanho;
        sf::RectangleShape shape;
        sf::RenderWindow *window;
    public:
        Entidade(Coordenada tam, Coordenada pos);  // CHECAR CONSTRUTORA COM DERIVADA DA CLASSE ENTE
        ~Entidade();
        
        void setPosicao(float x, float y);
        void setPosicao(Coordenada pos);
        
        void setWindow(sf::RenderWindow *win) { this->window = win; }
        
        sf::RectangleShape* getShape(){ return &shape;}
        
        const Coordenada getPosicao() { return posicao;}

        const Coordenada getTamanho() { return tamanho;}

        virtual void colisao(Entidade* outraEntidade);

        virtual void executar() = 0; // movimentar? colisões?

        
};

#endif