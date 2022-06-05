#include "../../../../include/Ente/Entidades/Dinamicas/InimigoVoador.h"
#include "../../../../include/Ente/Entidades/Dinamicas/Projetil.h"
#include "../../Menus/Fase.h"

#define VELOCIDADE_JOGADOR 76800 * TICK_RATE 

InimigoVoador::InimigoVoador():
    Inimigo(Coordenada (50,50),Coordenada(0,0),ID::inimigoVoador,false,150,15)
{

}

InimigoVoador::~InimigoVoador(){


}

void InimigoVoador::colisao(Entidade* outraEntidade, Coordenada intersecao){
    if(outraEntidade->getID() == ID::projetil){
        Projetil *tmp = dynamic_cast<Projetil*>(outraEntidade);
        this->receberDano(tmp->getDano());
    }

}
void InimigoVoador::atacar(){//ERRADO
    Coordenada distancia;
    int velocidadeX;
    distancia.x= this->getPosicao().x - pJogador->getPosicao().x;
    distancia.y = this->getPosicao().y - pJogador->getPosicao().y;
    
    /*velocidadeP.x^2 + velocidadeP.y^2 =  velocidadeTotalP^2*/

    

    if(distancia.x<0){//jogador esta na frente
        if(distancia.y<0)
            pProj = new Projetil(Coordenada (this->getPosicao().x + this->getTamanho().x,this->getPosicao().y+this->getTamanho().y/2.f)); // jogador esta abaixo
        else if(distancia.y > 0)
            pProj = new Projetil(Coordenada (this->getPosicao().x + this->getTamanho().x,this->getPosicao().y+this->getTamanho().y/2.f));
        else
            pProj = new Projetil(Coordenada (this->getPosicao().x + this->getTamanho().x,this->getPosicao().y+this->getTamanho().y/2.f));
    } else if(distancia.x == 0){//jogador esta atras
        if(distancia.y<0)
            pProj = new Projetil(Coordenada (this->getPosicao().x + this->getTamanho().x,this->getPosicao().y+this->getTamanho().y/2.f),0,VELOCIDADE_JOGADOR*3);    
        else if(distancia.y>0)
            pProj = new Projetil(Coordenada (this->getPosicao().x + this->getTamanho().x,this->getPosicao().y+this->getTamanho().y/2.f),0,-VELOCIDADE_JOGADOR*3);
        else
            pProj = new Projetil(Coordenada (this->getPosicao().x + this->getTamanho().x,this->getPosicao().y+this->getTamanho().y/2.f));
    } else{ //jogador esta em cima ou embaixo 
        if(distancia.y<0)
            pProj = new Projetil(Coordenada (this->getPosicao().x ,this->getPosicao().y+this->getTamanho().y/2.f));
        else if(distancia.y>0)
            pProj = new Projetil(Coordenada (this->getPosicao().x ,this->getPosicao().y+this->getTamanho().y/2.f));
    }      


    pFase->incluir(static_cast<Entidade*>(pProj));
    this->reiniciarClock();
}




void InimigoVoador::movimentar(const float dt){

}

void InimigoVoador::executar(const float dt){

}