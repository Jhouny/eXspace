#include "../../../../include/Ente/Menus/Fases/Mercurio.h"
#define TEX_NAVE "PrincipalJogo/assets/Texturas/Entidades/nave.png"

namespace Menus::Fases {
    Mercurio::Mercurio(/*MenuGameOver* men,*/Entidades::Personagens::Jogador* jog1, Entidades::Personagens::Jogador* jog2 ):
        Fase(/*men,*/jog1,jog2)
    {
        jogador1->resetar();
        jogador1->setFase(static_cast<Fases::Fase*>(this));
        if(jogador2 != NULL) {
            jogador2->resetar();
            jogador2->setFase(static_cast<Fases::Fase*>(this));
        }
        setID(Estados::IdEstado::mercurio);
        setTexture(TEX_FUNDO_MERCURIO);
    }

    Mercurio::~Mercurio(){
        
    }

    void Mercurio::geraPlataformas() {
        //plataforma da lava:
        pBase = new Entidades::Obstaculos::Plataforma(Coordenada(3000,32),Coordenada(4000,ALTURA- 68.f),false);
        incluir(static_cast<Entidades::Entidade*> (pBase));

        pBase = new Entidades::Obstaculos::Plataforma(Coordenada(2000, 32), Coordenada(400, ALTURA - 68.f),false);
        incluir(static_cast<Entidades::Entidade*>(pBase));

        //plataformas normais:

        pBase = new Entidades::Obstaculos::Plataforma(Coordenada(400, 32), Coordenada(0, ALTURA - 100.f),false);
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

        pChegada = new Entidades::Obstaculos::Plataforma(Coordenada(250,240), Coordenada(9700, ALTURA - 430.f),false);
        pChegada->setTexture(TEX_NAVE);
        pChegada->getSprite()->setPosition(sf::Vector2f(9700, ALTURA - 430.f));
        incluir(static_cast<Entidades::Entidade*>(pChegada)); 
    } 

    void Mercurio:: geraObstaculos(){
        pLava = new Entidades::Obstaculos::Lava(Coordenada(2000, 32), Coordenada(400, ALTURA-100.f),true);
        incluir(static_cast<Entidades::Entidade*>(pLava)); 

        pLava = new Entidades::Obstaculos::Lava(Coordenada(3000,32),Coordenada(4000,ALTURA-100.f),true);
        incluir(static_cast<Entidades::Entidade*> (pLava));

        int numInstanciasRocha = (rand() % 4) + 3;  // Cria entre 3 e 6 instancias
        for (int i = 0; i < numInstanciasRocha; i++) {
            pRocha = new Entidades::Obstaculos::Rocha(&lEntidades);
            incluir(static_cast<Entidades::Entidade*> (pRocha));
        }

        int numInstanciasGas = (rand() % 5) + 3;  // Cria entre 3 e 7 instancias
        for (int i = 0; i < numInstanciasGas; i++) {
            pGas = new Entidades::Obstaculos::GasToxico(&lEntidades);
            incluir(static_cast<Entidades::Entidade*> (pGas));
        }
    } 

    void Mercurio::geraInimigos() {
        int i;
        bool achou;
        int numInstanciasIniTerrestre = (rand() % 4) + 3;  // randomiza numero de instancia de InimigoTerrestre (de 3 a 6)
        std::vector<Entidades::Entidade*> temp(lEntidades.begin(), lEntidades.end());// Copia os elementos da lista para um vetor temporário
        for(i = 0; i < numInstanciasIniTerrestre ; i++) {
            achou = false;
            std::random_shuffle(temp.begin(), temp.end());  // Aleatoriza a posicao dos elementos do vetor
            for(int i = 0; i < temp.size() && !achou ; i++) {
                Entidades::Entidade* ent = temp[i];
                if(ent->getID() == ID::plataforma) {
                    Entidades::Obstaculos::Plataforma* pPlat = dynamic_cast<Entidades::Obstaculos::Plataforma*>(ent);
                    if((ent->getPosicao().x > 1000 && ent->getPosicao().x < 9000) && pPlat->getNormal()) {
                        Coordenada pos;
                        pos.x = ent->getPosicao().x + (rand() % (int)(ent->getTamanho().x - 50));
                        pos.y= ent->getPosicao().y - 60;
                        pIniTerrestre = new Entidades::Personagens::InimigoTerrestre();
                        pIniTerrestre->setPosicao(pos);
                        pIniTerrestre->setJogador1(jogador1);
                        if(multiplayer)
                            pIniTerrestre->setJogador2(jogador2);
                        incluir(static_cast<Entidades::Entidade*>(pIniTerrestre));
                        achou = true;
                        
                    }
                } 
            }
        }
        temp.clear();


        Fase* tmp = static_cast<Fase*>(this);
        int numInstanciasIniVoador = (rand() % 4) + 3; // randomiza numero de instancia de InimigoVoador (de 3 a 6)
        for(i = 0; i < numInstanciasIniVoador; i++) {
            pIniVoador = new Entidades::Personagens::InimigoVoador();
            pIniVoador->setPosicao(Coordenada(rand() % (8200) + 1800, 100));
            pIniVoador->randomizarOscilacao();  // Tem que estar depois do setPosicao()
            pIniVoador->setJogador1(jogador1);
            if(multiplayer)
                pIniVoador->setJogador2(jogador2);
            pIniVoador->setFase(tmp);
            incluir(static_cast<Entidades::Entidade*>(pIniVoador));
        }        
    }

    void Mercurio::executar(const float dt) {
        jogador1->setPontuacao(pontuacaoIni);
        pGrafico->setTamView(Coordenada(COMPRIMENTO,ALTURA));
        pGrafico->setMinimap(Coordenada (COMPRIMENTO*2,ALTURA*2));
        pGrafico->atualizaMinimap(Coordenada(2000,360));
    }
}