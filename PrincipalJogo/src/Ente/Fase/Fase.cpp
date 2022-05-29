#include "../../../include/Ente/Fase/Fase.h"

Fase::Fase(int ni, int num_jog):
    Ente(ID::fase),
    nivel(ni),
    nJog(num_jog),
    pGrafico(Gerenciadores::Grafico::getInstancia()),
    pColisor(new Gerenciadores::Colisor()),
    jogador1(Coordenada(100,0), this),
    jogador2(Coordenada(200,0), this)
{
    setTexture(TEX_BACKGROUND);

    if(nJog == 2) {
        jogador2.setVelocidade(Coordenada(15,0));
        lDinamicas.push(static_cast<Entidade*>(&jogador2));
    }
    
    jogador1.setVelocidade(Coordenada(10.5,0));
    lDinamicas.push(static_cast<Entidade*>(&jogador1));

    pColisor->setDinamicas(&lDinamicas);
    pColisor->setEstatica(&lEstaticas);
}

Fase::~Fase() {}

void Fase::setTexture(const char* path) {
    sf::Texture *temp = pGrafico->loadTexture(path);
    backGround.setTexture(*temp);
    float sX = (float)COMPRIMENTO/temp->getSize().x;
    float sY = (float)ALTURA/temp->getSize().y;
    backGround.setScale(2*sX, sY);
}

void Fase::atualizarBackground() {
    // Simula o movimento relativo do background e jogador
    float pX = 0.85 * jogador1.getPosicao().x - COMPRIMENTO/2.f;
    backGround.setPosition(pX, 0);
}

void Fase::gameOver() {
    pGrafico->terminar();
}

void Fase::incluir(Entidade* l) {
    ID id = l->getID();
    if(id == ID::jogador ||
       id == ID::inimigoTerrestre ||
       id == ID::projetil ||
       id == ID::inimigoVoador ||
       id == ID::chefe) {
        lDinamicas.push(l);
    } else
        lEstaticas.push(l);
       
        /*// Lista de Entidades Dinamicas
        case ID::jogador:
            lDinamicas.push(l);
            break;
        case ID::inimigoTerrestre:
            lDinamicas.push(l);
            break;
        case ID::projetil:
            cout << "idIncl: " << l->getID() << endl;
            lDinamicas.push(l);
            break;
        case ID::inimigoVoador:
            lDinamicas.push(l);
            break;
        case ID::chefe:
            lDinamicas.push(l);
            break;
        // Lista de Entidades Estaticas
        case ID::plataforma:
            lEstaticas.push(l);
            break;
        case ID::lava:
            lEstaticas.push(l);
            break;
        case ID::gasToxico:
            lEstaticas.push(l);
            break;
        case ID::rocha:
            lEstaticas.push(l);
            break;
    }*/
}


void Fase::executar() {
    int i;
    InimigoTerrestre temp[10*nivel];
    for(i = 0; i < 3*nivel; i++) {
        temp[i].setPosicao(Coordenada(rand() % COMPRIMENTO, 100));
        temp[i].setJogador(&jogador1);
        this->incluir(static_cast<Entidade*>(&temp[i]));
    }
    

    //seta as plataformas:
    Plataforma base1(Coordenada(1000, 32), Coordenada(0, ALTURA - 100.f));
    Plataforma base2(Coordenada(1000, 32), Coordenada(1200, ALTURA - 100.f));
    Plataforma base3(Coordenada(1000, 32), Coordenada(1400, ALTURA - 100.f));
    Plataforma base4(Coordenada(2000, 32), Coordenada(2400, ALTURA - 100.f));
    Plataforma base6(Coordenada(150, 32), Coordenada(400, ALTURA - 300.f));
    Plataforma base7(Coordenada(150, 32), Coordenada(750, ALTURA - 300.f));
    Plataforma base8(Coordenada(150, 32), Coordenada(1000, ALTURA - 400.f));
    Plataforma base9(Coordenada(150, 32), Coordenada(1400, ALTURA - 500.f));
    Plataforma base10(Coordenada(150, 32), Coordenada(1800, ALTURA - 450.f));
    Plataforma base11(Coordenada(150, 32), Coordenada(2200, ALTURA -400.f));
    
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
        
        pGrafico->clear();
        // Verifica colisao entre Entidades Dinamicas e Estaticas
        pColisor->ChecarColisoes();
        
        // Draw shapes & executar
        pGrafico->draw(&backGround, false);

        Entidade *ent;
        for(i = 0; i < lDinamicas.getTamanho(); i++) {
            ent = lDinamicas[i];
            pGrafico->draw(ent->getSprite());
            ent->executar();
            if(!ent->getAtivo())
                lDinamicas.removeIndice(i);
        }
        
        for(i = 0; i < lEstaticas.getTamanho(); i++) {
            ent = lEstaticas[i];
            pGrafico->draw(ent->getSprite());
            ent->executar();
        }


        // VAI NO JOGADOR
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && jogador1.getSegundos() > 0.5) {
            Projetil *proj = new Projetil(Coordenada(jogador1.getPosicao().x + 60, jogador1.getPosicao().y + jogador1.getTamanho().y/2.f));  // ADICIONAR VELOCIDADE
            if(jogador1.getVelocidade().x<0){
                proj->setDirecaoX();
            }
            
            this->incluir(static_cast<Entidade*>(proj));
            jogador1.reiniciarClock();
        }  


        //Seta view
        pGrafico->atualizaView(&jogador1);
        atualizarBackground();
        

        pGrafico->display();
    }

}