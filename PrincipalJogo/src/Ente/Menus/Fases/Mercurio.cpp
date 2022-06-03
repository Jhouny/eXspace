#include "../../../../include/Ente/Menus/Fases/Mercurio.h"

namespace Menus{
    Mercurio::Mercurio():
    Fase()
    {

    }

    Mercurio::~Mercurio(){
        //pChefe=NULL;
    }

    void Mercurio::geraPlataformas() {
        pBase = new Plataforma(Coordenada(400, 32), Coordenada(0, ALTURA - 100.f));
        incluir(static_cast<Entidade*>(pBase));
        
        pBase = new Plataforma(Coordenada(2000, 32), Coordenada(400, ALTURA - 68.f));
        incluir(static_cast<Entidade*>(pBase));
        
        pBase = new Plataforma(Coordenada(200, 32), Coordenada(500, ALTURA - 350.f));
        incluir(static_cast<Entidade*>(pBase));
        
        pBase = new Plataforma(Coordenada(200, 32), Coordenada(900, ALTURA - 450.f));
        incluir(static_cast<Entidade*>(pBase));
        
        pBase = new Plataforma(Coordenada(200, 32), Coordenada(1300, ALTURA - 250.f));
        incluir(static_cast<Entidade*>(pBase));
        
        pBase = new Plataforma(Coordenada(150, 32), Coordenada(1700, ALTURA -450.f));
        incluir(static_cast<Entidade*>(pBase));
        
        pBase = new Plataforma(Coordenada(1000, 32), Coordenada(2400, ALTURA - 100.f));
        incluir(static_cast<Entidade*>(pBase));
        
        pBase = new Plataforma(Coordenada(150, 32), Coordenada(3400, ALTURA - 132.f));
        incluir(static_cast<Entidade*>(pBase));
        
        pBase = new Plataforma(Coordenada(150, 32), Coordenada(1800, ALTURA - 450.f));
        incluir(static_cast<Entidade*>(pBase));
        
        pBase = new Plataforma(Coordenada(150, 32), Coordenada(2200, ALTURA -400.f));
        incluir(static_cast<Entidade*>(pBase));
        
        

    } 

    void Mercurio:: geraObstaculos(){

    } 

    void Mercurio::geraInimigos(){

    }

}