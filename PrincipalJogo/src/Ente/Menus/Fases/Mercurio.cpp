#include "../../../../include/Ente/Menus/Fases/Mercurio.h"

namespace Menus{
    Mercurio::Mercurio(Jogador* jog1,Jogador* jog2 ):
    Fase(jog1,jog2)
    {
        setID(Estados::IdEstado::fase);
        setTexture(TEX_BACKGROUND);
        
        executar(0);
    }

    Mercurio::~Mercurio(){
        //pChefe=NULL;
    }

    void Mercurio::geraPlataformas() {
        
        //plataforma da lava:
        pBase = new Plataforma(Coordenada(1250, 64), Coordenada(4000, ALTURA -68.f));
        incluir(static_cast<Entidade*>(pBase)); 

        pBase = new Plataforma(Coordenada(1250, 64), Coordenada(5750, ALTURA -68.f));
        incluir(static_cast<Entidade*>(pBase));

        pBase = new Plataforma(Coordenada(2000, 64), Coordenada(400, ALTURA - 68.f));
        incluir(static_cast<Entidade*>(pBase));
        //plataformas normais:

        pBase = new Plataforma(Coordenada(400, 64), Coordenada(0, ALTURA - 100.f));
        incluir(static_cast<Entidade*>(pBase));
        
        pBase = new Plataforma(Coordenada(200, 64), Coordenada(500, ALTURA - 350.f));
        incluir(static_cast<Entidade*>(pBase));
        
        pBase = new Plataforma(Coordenada(200, 64), Coordenada(900, ALTURA - 450.f));
        incluir(static_cast<Entidade*>(pBase));
        
        pBase = new Plataforma(Coordenada(200, 64), Coordenada(1300, ALTURA - 250.f));
        incluir(static_cast<Entidade*>(pBase));
        
        pBase = new Plataforma(Coordenada(150, 64), Coordenada(1700, ALTURA -450.f));
        incluir(static_cast<Entidade*>(pBase));
        
        pBase = new Plataforma(Coordenada(1000, 64), Coordenada(2400, ALTURA - 100.f));
        incluir(static_cast<Entidade*>(pBase));
        
        pBase = new Plataforma(Coordenada(200, 64), Coordenada(3400, ALTURA - 164.f));
        incluir(static_cast<Entidade*>(pBase));
        
        pBase = new Plataforma(Coordenada(200, 64), Coordenada(3600, ALTURA -164.f));
        incluir(static_cast<Entidade*>(pBase));
        
        pBase = new Plataforma(Coordenada(200, 64), Coordenada(3800, ALTURA -196.f));
        incluir(static_cast<Entidade*>(pBase));

        pBase = new Plataforma(Coordenada(150, 64), Coordenada(4300, ALTURA - 300.f));
        incluir(static_cast<Entidade*>(pBase));

        pBase = new Plataforma(Coordenada(150, 64), Coordenada(4800, ALTURA -400.f));
        incluir(static_cast<Entidade*>(pBase));

        pBase = new Plataforma(Coordenada(150, 64), Coordenada(5100, ALTURA - 200.f));
        incluir(static_cast<Entidade*>(pBase));

        pBase = new Plataforma(Coordenada(500, 64), Coordenada(5250, ALTURA -400.f));
        incluir(static_cast<Entidade*>(pBase));

        
        //plataforma voadora 3:
        pBase = new Plataforma(Coordenada(150, 64), Coordenada(6000, ALTURA -200.f));
        incluir(static_cast<Entidade*>(pBase));

        pBase = new Plataforma(Coordenada(150, 64), Coordenada(6500, ALTURA- 350.f));
        incluir(static_cast<Entidade*>(pBase));

        pBase = new Plataforma(Coordenada(150, 64), Coordenada(6900, ALTURA -400.f));
        incluir(static_cast<Entidade*>(pBase));
        //terminou a voadora 3

        pBase = new Plataforma(Coordenada(500, 64), Coordenada(7300, ALTURA - 300.f));
        incluir(static_cast<Entidade*>(pBase));

        pBase = new Plataforma(Coordenada(200, 64), Coordenada(7800, ALTURA - 268.f));
        incluir(static_cast<Entidade*>(pBase));

        pBase = new Plataforma(Coordenada(200, 64), Coordenada(8000, ALTURA - 236.f));
        incluir(static_cast<Entidade*>(pBase));

        pBase = new Plataforma(Coordenada(200, 64), Coordenada(8200, ALTURA - 204.f));
        incluir(static_cast<Entidade*>(pBase));

        pBase = new Plataforma(Coordenada(500, 64), Coordenada(8700, ALTURA - 200.f));
        incluir(static_cast<Entidade*>(pBase));

        pBase = new Plataforma(Coordenada(600, 64), Coordenada(9400, ALTURA - 200.f));
        incluir(static_cast<Entidade*>(pBase));     
        

    } 

    void Mercurio:: geraObstaculos(){

    } 

    void Mercurio::geraInimigos(){

    }

    void Mercurio::executar(const float dt){
        // Seta tamanho da view
        geraPlataformas();
        pGrafico->setTamView(Coordenada(COMPRIMENTO,ALTURA));
        pGrafico->setMinimap(Coordenada (4000,ALTURA));
        pGrafico->setMinimapViewport();
        pGrafico->atualizaMinimap(Coordenada(2000,360));
    }
}