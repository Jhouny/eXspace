#include "../../../include/Ente/Entidades/Inimigo.h"
#include "../../../include/Ente/Entidades/Dinamicas/Jogador.h"

namespace Entidades::Personagens {
    Inimigo::Inimigo(Coordenada tam, Coordenada pos, ID id, bool est, int v, int d): 
        Personagem(tam, pos, est, v, d, id),
        jogTaPerto(false)
    {
        pJogador1 = NULL;
        pJogador2 = NULL;
    }


    Inimigo::~Inimigo() {
        pJogador1 = NULL;
        pJogador2 = NULL;
    }

    void Inimigo::setJogador1(Jogador* pJog) {
        if(pJog)
            pJogador1 = pJog;
        else
            cout << "Ponteiro nulo" << endl;
    }
    
    void Inimigo::setJogador2(Jogador* pJog) {
        pJogador2 = pJog;
    }

    void Inimigo::alarmado(int dist) {
        Coordenada centroIni,  centroJog, intersecao;
        float diferenca = 0;
        
        if(pJogador1->estaVivo()) {
            centroIni.x = this->getPosicao().x + (this->getTamanho().x)/2.f;
            centroIni.y = this->getPosicao().y + (this->getTamanho().y)/2.f;
            
            centroJog.x = pJogador1->getPosicao().x + (pJogador1->getTamanho().x)/2.f;
            centroJog.y = pJogador1->getPosicao().y + (pJogador1->getTamanho().y)/2.f;;
            
            intersecao.x = fabs(centroJog.x - centroIni.x) - (this->getTamanho().x + pJogador1->getTamanho().x)/2.f;
            intersecao.y = fabs(centroJog.y - centroIni.y) - (this->getTamanho().y + pJogador1->getTamanho().y)/2.f;

            diferenca = sqrtf(intersecao.x*intersecao.x + intersecao.y*intersecao.y);
            if(fabs(diferenca) <= dist) {
                jogTaPerto = true;
            } else {
                jogTaPerto = false;
            }
        }
        else if(pJogador2 != NULL && pJogador2->estaVivo() && !pJogador1->estaVivo()) {
            centroIni.x = this->getPosicao().x + (this->getTamanho().x)/2.f;
            centroIni.y = this->getPosicao().y + (this->getTamanho().y)/2.f;
            
            centroJog.x = pJogador2->getPosicao().x + (pJogador2->getTamanho().x)/2.f;
            centroJog.y = pJogador2->getPosicao().y + (pJogador2->getTamanho().y)/2.f;;
            
            intersecao.x = fabs(centroJog.x - centroIni.x) - (this->getTamanho().x + pJogador2->getTamanho().x)/2.f;
            intersecao.y = fabs(centroJog.y - centroIni.y) - (this->getTamanho().y + pJogador2->getTamanho().y)/2.f;

            diferenca = sqrtf(intersecao.x*intersecao.x + intersecao.y*intersecao.y);
            if(fabs(diferenca) <= dist) {
                    jogTaPerto = true;
            } else {
                    jogTaPerto = false;
            }
        }
    }
}