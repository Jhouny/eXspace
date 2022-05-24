#include "../../../include/Ente/Fase/Fase.h"

Fase::Fase(int ni, int num_jog):
    Ente(ID::fase),
    nivel(ni),
    nJog(num_jog),
    pGrafico(Gerenciadores::Grafico::getInstancia()),
    pColisor(new Gerenciadores::Colisor()),
    jogador1(Coordenada(60,60),Coordenada(0,0)),
    jogador2(Coordenada(60,60),Coordenada(100,0))
{
    if(nJog == 2) {
        jogador2.setVelocidade(Coordenada(15,0));
        jogador2.setGerenciadorGrafico(pGrafico);
        lDinamicas.push(static_cast<Entidade*>(&jogador2));
    }
    
    jogador1.setVelocidade(Coordenada(10.5,0));
    jogador1.setGerenciadorGrafico(pGrafico);
    lDinamicas.push(static_cast<Entidade*>(&jogador1));

    pColisor->setDinamicas(&lDinamicas);
    pColisor->setEstatica(&lEstaticas);
}

Fase::~Fase() {}

void Fase::geraPlataformas() {
    Plataforma base1(Coordenada(COMPRIMENTO, 50), Coordenada(0, ALTURA - 100.f));
    Plataforma base2(Coordenada(150, 50), Coordenada(200, ALTURA - 200.f));
    Plataforma base3(Coordenada(150, 50), Coordenada(300, ALTURA - 300.f));
    Plataforma base4(Coordenada(150, 50), Coordenada(400, ALTURA - 400.f));
    Plataforma base5(Coordenada(150, 50), Coordenada(500, ALTURA - 500.f));
    lEstaticas.push(static_cast<Entidade*>(&base1));
    lEstaticas.push(static_cast<Entidade*>(&base2));
    lEstaticas.push(static_cast<Entidade*>(&base3));
    lEstaticas.push(static_cast<Entidade*>(&base4));
    lEstaticas.push(static_cast<Entidade*>(&base5));
}

void Fase::geraObstaculos(){

}

Inimigo* Fase::geraInimigos(){
    int i;
    InimigoTerrestre temp[3*nivel];
    for(i = 0; i < 3*nivel; i++) {
        temp[i].setPosicao(Coordenada(rand() % COMPRIMENTO, 100));
        temp[i].setJogador(&jogador1);
    }
    return temp;
}

void Fase::incluir(ListaEntidades* lista, Entidade* l) {
    int i;
    for(i = 0; i < 3*nivel; i++) {
        lista->push(static_cast<Entidade*>(&l[i]));
    }
}


void Fase::gameOver() {
    pGrafico->terminar();
}


void Fase::executar() {
    //geraPlataformas();
    //Inimigo* inigs = geraInimigos();
    // incluir(&lDinamicas, static_cast<Entidade*>(inigs));
    //lDinamicas.print();
    int i;
    /*InimigoTerrestre temp[10*nivel];
    for(i = 0; i < 3*nivel; i++) {
        temp[i].setPosicao(Coordenada(rand() % COMPRIMENTO, 100));
        temp[i].setJogador(&jogador1);
        lDinamicas.push(static_cast<Entidade*>(&temp[i]));
    }*/
    

    //seta as plataformas:
    Plataforma base1(Coordenada(1000, 50), Coordenada(0, ALTURA - 100.f));
    Plataforma base2(Coordenada(1000, 50), Coordenada(1200, ALTURA - 100.f));
    Plataforma base3(Coordenada(1000, 50), Coordenada(1400, ALTURA - 100.f));
    Plataforma base4(Coordenada(2000, 50), Coordenada(2400, ALTURA - 100.f));
    Plataforma base6(Coordenada(150, 50), Coordenada(400, ALTURA - 300.f));
    Plataforma base7(Coordenada(150, 50), Coordenada(750, ALTURA - 300.f));
    Plataforma base8(Coordenada(150, 50), Coordenada(1000, ALTURA - 400.f));
    Plataforma base9(Coordenada(150, 50), Coordenada(1400, ALTURA - 500.f));
    Plataforma base10(Coordenada(150, 50), Coordenada(1800, ALTURA - 450.f));

    Plataforma base11(Coordenada(150, 50), Coordenada(2200, ALTURA -400.f));
    lEstaticas.push(static_cast<Entidade*>(&base1));
    lEstaticas.push(static_cast<Entidade*>(&base2));
    lEstaticas.push(static_cast<Entidade*>(&base3));
    lEstaticas.push(static_cast<Entidade*>(&base4));
    lEstaticas.push(static_cast<Entidade*>(&base6));
    lEstaticas.push(static_cast<Entidade*>(&base7));
    lEstaticas.push(static_cast<Entidade*>(&base8));
    lEstaticas.push(static_cast<Entidade*>(&base9));
    lEstaticas.push(static_cast<Entidade*>(&base10));
    lEstaticas.push(static_cast<Entidade*>(&base11));

    //seta tamanho da view
    pGrafico->setTamView(Coordenada(COMPRIMENTO,ALTURA));
    pGrafico->setMinimap(Coordenada (4000,ALTURA));
    pGrafico->setMinimapViewport();
    pGrafico->atualizaMinimap(Coordenada(2000,360));

    /*       */
    while(pGrafico->isOpened()) {
    
        while (pGrafico->getWindow()->pollEvent(*pGrafico->getEvent())) {
            if (pGrafico->getEvent()->type == sf::Event::Closed)
                pGrafico->terminar();
        }
        //pGrafico->atualizaView(&jogador1);
        
        pGrafico->clear();
        // Verifica colisao entre Entidades Dinamicas e Estaticas
        pColisor->ChecarColisoes();
        
        // Draw shapes & executar
        
        Entidade *ent;
        for(i = 0; i < lDinamicas.getTamanho(); i++) {
            ent = lDinamicas[i];
            pGrafico->draw(ent->getShape());
            ent->executar();
        }
        //Seta view
        pGrafico->atualizaView(&jogador1);
        //pGrafico->setRotate();//comentar se nao quiser ficar enjoadokkkkkk

        for(i = 0; i < lEstaticas.getTamanho(); i++) {
            ent = lEstaticas[i];
            pGrafico->draw(ent->getShape());
            ent->executar();
        }

        pGrafico->display();
    }

}