#include "../../../include/Ente/Entidades/Inimigo.h"
#include "../../../include/Ente/Entidades/Dinamicas/Jogador.h"

namespace Entidades::Personagens {
    Inimigo::Inimigo(Coordenada tam, Coordenada pos, ID id, bool est, int v, int d): 
        Personagem(tam, pos, est, v, d, id),
        jogTaPerto(false)
    {
        pJogador = NULL;
    }


    Inimigo::~Inimigo(){
        pJogador = NULL;
    }

    void Inimigo::setJogador(Jogador* pJog) {
        if(pJog)
            pJogador = pJog;
        else
            cout << "ponteiro nulo" << endl;
    }
    void Inimigo::alarmado(int dist) {
        Coordenada centroIni,  centroJog, intersecao;
        float diferenca;
        
        centroIni.x = this->getPosicao().x + (this->getTamanho().x)/2.f;
        centroIni.y = this->getPosicao().y + (this->getTamanho().y)/2.f;
        
        centroJog.x = pJogador->getPosicao().x + (pJogador->getTamanho().x)/2.f;
        centroJog.y = pJogador->getPosicao().y + (pJogador->getTamanho().y)/2.f;;
        
        intersecao.x = fabs(centroJog.x - centroIni.x) - (this->getTamanho().x + pJogador->getTamanho().x)/2.f;
        intersecao.y = fabs(centroJog.y - centroIni.y) - (this->getTamanho().y + pJogador->getTamanho().y)/2.f;

        diferenca = sqrtf(intersecao.x*intersecao.x + intersecao.y*intersecao.y);
        
        if(fabs(diferenca) <= dist)
            jogTaPerto = true;
        else
            jogTaPerto = false;
    }
}