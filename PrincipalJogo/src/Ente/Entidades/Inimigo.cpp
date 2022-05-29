#include "../../../include/Ente/Entidades/Inimigo.h"
#include "../../../include/Ente/Entidades/Dinamicas/Jogador.h"

Inimigo::Inimigo(Coordenada tam, Coordenada pos, int v, int d, ID id): 
    Personagem(tam, pos, v, d, id),
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
void Inimigo::alarmado() {
    Coordenada centroIni,  centroJog, intersecao;
    float diferenca;
    
    centroIni.x = this->getPosicao().x + (this->getTamanho().x)/2.f;
    centroIni.y = this->getPosicao().y + (this->getTamanho().y)/2.f;
    
    centroJog.x = pJogador->getPosicao().x + (pJogador->getTamanho().x)/2.f;
    centroJog.y = pJogador->getPosicao().y + (pJogador->getTamanho().y)/2.f;;
    
    intersecao.x = fabs(centroJog.x - centroIni.x) - (this->getTamanho().x + pJogador->getTamanho().x)/2.f;
    intersecao.y = fabs(centroJog.y - centroIni.y) - (this->getTamanho().y + pJogador->getTamanho().y)/2.f;

    diferenca = sqrtf(intersecao.x*intersecao.x + intersecao.y*intersecao.y);
    
    if(fabs(diferenca) <= 300)
        jogTaPerto = true;
    else
        jogTaPerto = false;
}
