#include "../../../../include/Ente/Menus/Fases/Netuno.h"

namespace Menus{
    Netuno::Netuno(Jogador* jog1, Jogador* jog2):
        Fase(jog1,jog2)
    {
        setID(Estados::IdEstado::netuno);
        executar(0);

    }

    Netuno::~Netuno(){

    }

    void Netuno::geraPlataformas(){
        //primeira parte
        pBase = new Plataforma(Coordenada(500, 32), Coordenada(0, ALTURA/2.f));
        incluir(static_cast<Entidade*>(pBase)); 

        pBase = new Plataforma(Coordenada(700, 32), Coordenada(800, ALTURA/2.f));
        incluir(static_cast<Entidade*>(pBase)); 

        //caminho de cima
        pBase = new Plataforma(Coordenada(200, 32), Coordenada(1700, ALTURA/2.f - 200.f));
        incluir(static_cast<Entidade*>(pBase));

        pBase = new Plataforma(Coordenada(100, 32), Coordenada(2300,  ALTURA/2.f - 100.f));
        incluir(static_cast<Entidade*>(pBase));

        pBase = new Plataforma(Coordenada(100, 32), Coordenada(2800, ALTURA/2.f - 200.f));
        incluir(static_cast<Entidade*>(pBase)); 

        pBase = new Plataforma(Coordenada(100, 32), Coordenada(3500, ALTURA/2.f - 100.f));
        incluir(static_cast<Entidade*>(pBase)); 

        pBase = new Plataforma(Coordenada(100, 32), Coordenada(4000, ALTURA/2.f - 200.f));
        incluir(static_cast<Entidade*>(pBase)); //terminou

        /*plataformas para a lava*/
        pBase = new Plataforma(Coordenada(2800, 32), Coordenada(1500, ALTURA -68.f));
        incluir(static_cast<Entidade*>(pBase)); 

        pBase = new Plataforma(Coordenada(1800, 32), Coordenada(7500, ALTURA -68.f));
        incluir(static_cast<Entidade*>(pBase)); 

        

        /*segunda parte*/
        pBase = new Plataforma(Coordenada(1250, 32), Coordenada(4500, ALTURA/2.f - 200.f)); //plataforma de inimigos
        incluir(static_cast<Entidade*>(pBase)); 

        pBase = new Plataforma(Coordenada(1250, 32), Coordenada(6250, ALTURA/2.f - 200.f)); //plataforma de inimigos
        incluir(static_cast<Entidade*>(pBase)); 

        //parte parkour
        pBase = new Plataforma(Coordenada(64, 32), Coordenada(7800, ALTURA -120.f));
        incluir(static_cast<Entidade*>(pBase)); 

        pBase = new Plataforma(Coordenada(64, 32), Coordenada(8100, ALTURA -120.f));
        incluir(static_cast<Entidade*>(pBase)); 

        pBase = new Plataforma(Coordenada(64, 32), Coordenada(8400, ALTURA -120.f));
        incluir(static_cast<Entidade*>(pBase)); 

        pBase = new Plataforma(Coordenada(64, 32), Coordenada(8700, ALTURA -120.f));
        incluir(static_cast<Entidade*>(pBase)); 

        pBase = new Plataforma(Coordenada(64, 32), Coordenada(9000, ALTURA -120.f));
        incluir(static_cast<Entidade*>(pBase)); 

        pBase = new Plataforma(Coordenada(2000, 32), Coordenada(9300, ALTURA -120.f));
        incluir(static_cast<Entidade*>(pBase)); 

        
        
    }

    void Netuno::geraObstaculos(){
        pLava = new Lava(Coordenada(2800, 32), Coordenada(1500, ALTURA -68.f),false);
        incluir(static_cast<Entidade*>(pLava)); 

        pLava = new Lava(Coordenada(1800, 32), Coordenada(7500, ALTURA -68.f),false);
        incluir(static_cast<Entidade*>(pLava)); 

    }

    void Netuno::geraInimigos(){
        int i;
        for(i = 0; i < 3; i++) {
            pIni = new InimigoTerrestre();
            pIni->setPosicao(Coordenada((rand() % 1250)+4500 , 100));
            pIni->setJogador(jogador1);
            incluir(static_cast<Entidade*>(pIni));
        }

        for(i = 0; i < 3; i++) {
            pIni = new InimigoTerrestre();
            pIni->setPosicao(Coordenada((rand() % 1250)+6250 , 100));
            pIni->setJogador(jogador1);
            incluir(static_cast<Entidade*>(pIni));
        }


    }


    void Netuno::executar(const float dt){
        resetarEstadoOriginal();    

        geraInimigos();
        geraObstaculos();
        geraPlataformas();

        pGrafico->setTamView(Coordenada(COMPRIMENTO,ALTURA));
        pGrafico->setMinimap(Coordenada (4000,ALTURA));
        pGrafico->setMinimapViewport();
        pGrafico->atualizaMinimap(Coordenada(2000,360));

        
    }

}