#include "../../../../include/Ente/Menus/Fases/Netuno.h"
#define TEX_PAREDE "PrincipalJogo/assets/Texturas/Plataforma/1 Tiles/Tile_12.png"


namespace Menus::Fases {
    Netuno::Netuno(Entidades::Personagens::Jogador* jog1, Entidades::Personagens::Jogador* jog2):
        Fase(jog1,jog2)
    {  
        jogador1->resetar();
        jogador1->setFase(static_cast<Fase*>(this));
        if(jogador2 != NULL) {
            jogador2->resetar();
            jogador2->setFase(static_cast<Fase*>(this));
        }
        
        setID(Estados::IdEstado::netuno);
        setTexture(TEX_FUNDO_NETUNO);
    }

    Netuno::~Netuno(){

    }

    void Netuno::geraPlataformas() {
        //primeira parte
        pBase = new Entidades::Obstaculos::Plataforma(Coordenada(500, 32), Coordenada(0, ALTURA/2.f));
        incluir(static_cast<Entidades::Entidade*>(pBase)); 

        pBase = new Entidades::Obstaculos::Plataforma(Coordenada(700, 32), Coordenada(800, ALTURA/2.f));
        incluir(static_cast<Entidades::Entidade*>(pBase)); 

        //caminho de cima
        pBase = new Entidades::Obstaculos::Plataforma(Coordenada(200, 32), Coordenada(1700, ALTURA/2.f + 100.f));
        incluir(static_cast<Entidades::Entidade*>(pBase));

        pBase = new Entidades::Obstaculos::Plataforma(Coordenada(150, 32), Coordenada(2300,  ALTURA/2.f ));
        incluir(static_cast<Entidades::Entidade*>(pBase));

        pBase = new Entidades::Obstaculos:: Plataforma(Coordenada(150, 32), Coordenada(2800, ALTURA/2.f  - 100.f));
        incluir(static_cast<Entidades::Entidade*>(pBase)); 

        pBase = new Entidades::Obstaculos::Plataforma(Coordenada(150, 32), Coordenada(3500, ALTURA/2.f + 100.f));
        incluir(static_cast<Entidades::Entidade*>(pBase)); 

        pBase = new Entidades::Obstaculos::Plataforma(Coordenada(150, 32), Coordenada(4000, ALTURA/2.f - 100.f));
        incluir(static_cast<Entidades::Entidade*>(pBase)); //terminou

        /*plataformas para a lava*/
        pBase = new Entidades::Obstaculos::Plataforma(Coordenada(2800, 32), Coordenada(1500, ALTURA -68.f),false);
        incluir(static_cast<Entidades::Entidade*>(pBase)); 

        pBase = new Entidades::Obstaculos::Plataforma(Coordenada(1800, 32), Coordenada(7500, ALTURA -68.f),false);
        incluir(static_cast<Entidades::Entidade*>(pBase)); 

        /*pBase = new Entidades::Obstaculos::Plataforma(Coordenada(32, ALTURA/2.f), Coordenada(2800, ALTURA/2.f),false);
        pBase->setTexture(TEX_PAREDE,false);
        incluir(static_cast<Entidades::Entidade*>(pBase)); */

        /*segunda parte*/
        pBase = new Entidades::Obstaculos::Plataforma(Coordenada(1250, 32), Coordenada(4500, ALTURA/2.f )); //plataforma de inimigos
        incluir(static_cast<Entidades::Entidade*>(pBase)); 

        pBase = new Entidades::Obstaculos::Plataforma(Coordenada(1250, 32), Coordenada(6000, ALTURA/2.f )); //plataforma de inimigos
        incluir(static_cast<Entidades::Entidade*>(pBase)); 

        //parte parkour
        pBase = new Entidades::Obstaculos::Plataforma(Coordenada(64, 32), Coordenada(7800, ALTURA -120.f));
        incluir(static_cast<Entidades::Entidade*>(pBase)); 

        pBase = new Entidades::Obstaculos::Plataforma(Coordenada(64, 32), Coordenada(8100, ALTURA -120.f));
        incluir(static_cast<Entidades::Entidade*>(pBase)); 

        pBase = new Entidades::Obstaculos::Plataforma(Coordenada(64, 32), Coordenada(8400, ALTURA -120.f));
        incluir(static_cast<Entidades::Entidade*>(pBase)); 

        pBase = new Entidades::Obstaculos::Plataforma(Coordenada(64, 32), Coordenada(8700, ALTURA -120.f));
        incluir(static_cast<Entidades::Entidade*>(pBase)); 

        pBase = new Entidades::Obstaculos:: Plataforma(Coordenada(64, 32), Coordenada(9000, ALTURA -120.f));
        incluir(static_cast<Entidades::Entidade*>(pBase)); 

        pBase = new Entidades::Obstaculos::Plataforma(Coordenada(2000, 32), Coordenada(9300, ALTURA -120.f));
        incluir(static_cast<Entidades::Entidade*>(pBase));
    }

    void Netuno::geraObstaculos(){
        pLava = new Entidades::Obstaculos::Lava(Coordenada(2800, 32), Coordenada(1500, ALTURA - 100.f), false);
        incluir(static_cast<Entidades::Entidade*>(pLava)); 

        pLava = new Entidades::Obstaculos::Lava(Coordenada(1800, 32), Coordenada(7500, ALTURA - 100.f), false);
        incluir(static_cast<Entidades::Entidade*>(pLava)); 

        int numInstancias= (rand() % 4) + 3;  // Cria entre 3 e 6 instancias
        for (int i = 0; i < numInstancias; i++) {
            pRocha = new Entidades::Obstaculos::Rocha(&lEntidades);
            incluir(static_cast<Entidades::Entidade*> (pRocha));
        }
        int numInstanciasGas = (rand() % 5) + 3;  // Cria entre 3 e 7 instancias
        for (int i = 0; i < numInstanciasGas; i++) {
            pGas = new Entidades::Obstaculos::GasToxico(&lEntidades);
            incluir(static_cast<Entidades::Entidade*> (pGas));
        }

    }

    void Netuno::geraInimigos(){
        int i;
        bool achou ;
        int numInstanciasIniTerrestre = (rand() % 4) + 3;  // randomiza numero de instancia de InimigoTerrestre (de 3 a 6)
        std::vector<Entidades::Entidade*> temp(lEntidades.begin(), lEntidades.end());// Copia os elementos da lista para um vetor temporário
        for(i = 0; i < numInstanciasIniTerrestre ; i++){
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
            pIniVoador->setPosicao(Coordenada(rand() % (6200) + 1800, 200));
            pIniVoador->randomizarOscilacao();  // Tem que estar depois do setPosicao()
            pIniVoador->setJogador1(jogador1);
            if(multiplayer)
                pIniVoador->setJogador2(jogador2);
            pIniVoador->setFase(tmp);
            incluir(static_cast<Entidades::Entidade*>(pIniVoador));
        }        

        pChefe = new Entidades::Personagens::Chefe();
        pChefe->setPosicao(Coordenada(10000,ALTURA-100.f));
        pChefe->setJogador1(jogador1);
        if(multiplayer)
                pChefe->setJogador2(jogador2);
        pChefe->setFase(tmp);
        incluir(static_cast<Entidades::Entidade*>(pChefe));
        
    }

    void Netuno::executar(const float dt){
        jogador1->setPontuacao(pontuacaoIni);

        pGrafico->setTamView(Coordenada(COMPRIMENTO,ALTURA));
        pGrafico->setMinimap(Coordenada (COMPRIMENTO*2,ALTURA*2));
        pGrafico->atualizaMinimap(Coordenada(2000,360));
    }

}