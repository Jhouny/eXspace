#ifndef _ENTIDADE_H_
#define _ENTIDADE_H_

#include "../Auxiliares/stdafx.h"
#include "Ente.h"

class Entidade: public Ente {
    protected:
        Coordenada posicao;
        Coordenada tamanho;
        RectangleShape shape;
        RenderWindow *window;
    public:
        Entidade(Coordenada tam, Coordenada pos);  // CHECAR CONSTRUTORA COM DERIVADA DA CLASSE ENTE
        ~Entidade();

        void setPosicao(Coordenada pos);
        void setPosicao(float x, float y);
        
        void setWindow(RenderWindow *win) { this->window = win; };
        void draw() { this->window->draw(shape); }
        
        const Coordenada getPosicao() const {return posicao;}

        const Coordenada getTamanho() const {return tamanho;}

        virtual void executar() = 0; // movimentar? colisões?

        
};

#endif