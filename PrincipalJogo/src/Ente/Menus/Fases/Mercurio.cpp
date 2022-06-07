#include "../../../../include/Ente/Menus/Fases/Mercurio.h"

namespace Menus::Fases {
    Mercurio::Mercurio(Entidades::Personagens::Jogador* jog1, Entidades::Personagens::Jogador* jog2 ):
        Fase(jog1,jog2)
    {
        jogador1->resetar();
        jogador1->setFase(static_cast<Fases::Fase*>(this));
        if(jogador2 != NULL) 
            jogador2->setFase(static_cast<Fases::Fase*>(this));
        
        setID(Estados::IdEstado::mercurio);
        setTexture(TEX_FUNDO_MERCURIO);
    }

    Mercurio::~Mercurio(){
        
    }

    void Mercurio::geraPlataformas() {
        //plataforma da lava:
        pBase = new Entidades::Obstaculos::Plataforma(Coordenada(3000,32),Coordenada(4000,ALTURA- 68.f));
        incluir(static_cast<Entidades::Entidade*> (pBase));

        pBase = new Entidades::Obstaculos::Plataforma(Coordenada(2000, 32), Coordenada(400, ALTURA - 68.f));
        incluir(static_cast<Entidades::Entidade*>(pBase));

        //plataformas normais:

        pBase = new Entidades::Obstaculos::Plataforma(Coordenada(400, 32), Coordenada(0, ALTURA - 100.f));
        incluir(static_cast<Entidades::Entidade*>(pBase));
        
        pBase = new Entidades::Obstaculos::Plataforma(Coordenada(200, 32), Coordenada(500, ALTURA - 350.f));
        incluir(static_cast<Entidades::Entidade*>(pBase));
        
        pBase = new Entidades::Obstaculos::Plataforma(Coordenada(200, 32), Coordenada(900, ALTURA - 450.f));
        incluir(static_cast<Entidades::Entidade*>(pBase));
        
        pBase = new Entidades::Obstaculos::Plataforma(Coordenada(200, 32), Coordenada(1300, ALTURA - 250.f));
        incluir(static_cast<Entidades::Entidade*>(pBase));
        
        pBase = new Entidades::Obstaculos::Plataforma(Coordenada(150, 32), Coordenada(1700, ALTURA -450.f));
        incluir(static_cast<Entidades::Entidade*>(pBase));
        
        pBase = new Entidades::Obstaculos::Plataforma(Coordenada(1000, 32), Coordenada(2400, ALTURA - 100.f));
        incluir(static_cast<Entidades::Entidade*>(pBase));
        
        pBase = new Entidades::Obstaculos::Plataforma(Coordenada(200, 32), Coordenada(3400, ALTURA - 132.f));
        incluir(static_cast<Entidades::Entidade*>(pBase));
        
        pBase = new Entidades::Obstaculos::Plataforma(Coordenada(200, 32), Coordenada(3600, ALTURA -164.f));
        incluir(static_cast<Entidades::Entidade*>(pBase));
        
        pBase = new Entidades::Obstaculos::Plataforma(Coordenada(200, 32), Coordenada(3800, ALTURA -196.f));
        incluir(static_cast<Entidades::Entidade*>(pBase));

        pBase = new Entidades::Obstaculos::Plataforma(Coordenada(150, 32), Coordenada(4300, ALTURA - 300.f));
        incluir(static_cast<Entidades::Entidade*>(pBase));

        pBase = new Entidades::Obstaculos::Plataforma(Coordenada(150, 32), Coordenada(4800, ALTURA -400.f));
        incluir(static_cast<Entidades::Entidade*>(pBase));


        pBase = new Entidades::Obstaculos::Plataforma(Coordenada(500, 32), Coordenada(5250, ALTURA -400.f));
        incluir(static_cast<Entidades::Entidade*>(pBase));

        
        //plataforma voadora 3:
        pBase = new Entidades::Obstaculos::Plataforma(Coordenada(150, 32), Coordenada(6000, ALTURA -200.f));
        incluir(static_cast<Entidades::Entidade*>(pBase));

        pBase = new Entidades::Obstaculos::Plataforma(Coordenada(150, 32), Coordenada(6500, ALTURA- 350.f));
        incluir(static_cast<Entidades::Entidade*>(pBase));

        pBase = new Entidades::Obstaculos::Plataforma(Coordenada(150, 32), Coordenada(6900, ALTURA -400.f));
        incluir(static_cast<Entidades::Entidade*>(pBase));
        //terminou a voadora 3

        pBase = new Entidades::Obstaculos::Plataforma(Coordenada(500, 32), Coordenada(7300, ALTURA - 300.f));
        incluir(static_cast<Entidades::Entidade*>(pBase));

        pBase = new Entidades::Obstaculos::Plataforma(Coordenada(200, 32), Coordenada(7800, ALTURA - 268.f));
        incluir(static_cast<Entidades::Entidade*>(pBase));

        pBase = new Entidades::Obstaculos::Plataforma(Coordenada(200, 32), Coordenada(8000, ALTURA - 236.f));
        incluir(static_cast<Entidades::Entidade*>(pBase));

        pBase = new Entidades::Obstaculos::Plataforma(Coordenada(200, 32), Coordenada(8200, ALTURA - 204.f));
        incluir(static_cast<Entidades::Entidade*>(pBase));

        pBase = new Entidades::Obstaculos::Plataforma(Coordenada(500, 32), Coordenada(8700, ALTURA - 200.f));
        incluir(static_cast<Entidades::Entidade*>(pBase));

        pBase = new Entidades::Obstaculos::Plataforma(Coordenada(600, 32), Coordenada(9400, ALTURA - 200.f));
        incluir(static_cast<Entidades::Entidade*>(pBase));

        pChegada = new Entidades::Obstaculos::Plataforma(Coordenada(250,240), Coordenada(9700, ALTURA - 500.f));
        pChegada->setTexture("PrincipalJogo/assets/Texturas/Entidades/nave.png");
        pChegada->getSprite()->setPosition(sf::Vector2f(9700, ALTURA - 500.f));
        incluir(static_cast<Entidades::Entidade*>(pChegada)); 

    } 

    void Mercurio:: geraObstaculos(){
        pLava = new Entidades::Obstaculos::Lava(Coordenada(2000, 32), Coordenada(400, ALTURA-100.f),true);
        incluir(static_cast<Entidades::Entidade*>(pLava)); 

        pLava = new Entidades::Obstaculos::Lava(Coordenada(3000,32),Coordenada(4000,ALTURA-100.f),true);
        incluir(static_cast<Entidades::Entidade*> (pLava));

        int numInstancias= (rand() % 4) + 3;  // Cria entre 3 e 6 instancias
        for (int i = 0; i < numInstancias; i++) {
            pRocha = new Entidades::Obstaculos::Rocha(&lEntidades);
            incluir(static_cast<Entidades::Entidade*> (pRocha));
        }
    } 

    void Mercurio::geraInimigos() {
        int i;
        for(i = 0; i < 3; i++) {
            pIniTerrestre = new Entidades::Personagens::InimigoTerrestre();
            pIniTerrestre->setPosicao(Coordenada(rand() % (4000-2400)+2400 , 100));
            pIniTerrestre->setJogador(jogador1);
            incluir(static_cast<Entidades::Entidade*>(pIniTerrestre));
        }
        for(i = 0; i < 3; i++) {
            pIniTerrestre = new Entidades::Personagens::InimigoTerrestre();
            pIniTerrestre->setPosicao(Coordenada(rand() % (500) + 5250 , 100));
            pIniTerrestre->setJogador(jogador1);
            incluir(static_cast<Entidades::Entidade*>(pIniTerrestre));
        }

        for(i = 0; i < 3; i++) {
            pIniTerrestre = new Entidades::Personagens::InimigoTerrestre();
            pIniTerrestre->setPosicao(Coordenada(rand() % (500) + 8700 , 100));
            pIniTerrestre->setJogador(jogador1);
            incluir(static_cast<Entidades::Entidade*>(pIniTerrestre));
        }
        Fase* tmp = static_cast<Fase*>(this);
        for(i = 0; i < 3; i++) {
            pIniVoador = new Entidades::Personagens::InimigoVoador();
            pIniVoador->setPosicao(Coordenada(rand() % (8200) + 1800, 100));
            pIniVoador->setJogador(jogador1);
            pIniVoador->setFase(tmp);
            incluir(static_cast<Entidades::Entidade*>(pIniVoador));
        }
        if(jogador1->getPosicao().x == 9700)
            proximaFase();
        
   }

    void Mercurio::executar(const float dt) {
        resetarEstadoOriginal();
        
        geraPlataformas();
        geraObstaculos();
        geraInimigos();

        pGrafico->setTamView(Coordenada(COMPRIMENTO,ALTURA));
        pGrafico->setMinimap(Coordenada (COMPRIMENTO*2,ALTURA*2));  
        pGrafico->setMinimapViewport();
        pGrafico->atualizaMinimap(Coordenada(2000,360));
    }
}