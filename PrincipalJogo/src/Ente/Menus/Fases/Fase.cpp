#include "../../../../include/Ente/Menus/Fases/Fase.h"
#include "../../../../include/Estados/MaquinaEstados.h"

namespace Menus::Fases {
    Fase::Fase(Entidades::Personagens::Jogador* jog1, Entidades::Personagens::Jogador* jog2):
        Menu(),
        jogador1(jog1),
        jogador2(jog2),
        pControleFase(this),
        visor(jog1, jog2),
        colisor(),
        multiplayer(false),
        pontuacaoIni(0)
        {
            // Define o plano de fundo
            setTexture(TEX_BACKGROUND);

            pBase = NULL;
            pChegada = NULL;
            pIniTerrestre = NULL;
            pIniVoador = NULL;
            pLava = NULL;
            numInimigos = 0;
        
            // Inclui os jogadores
            if(jogador2 != NULL) {
                jogador2->setVelocidade(Coordenada(0,0));
                jogador2->setFase(this);
                jogador2->getControle()->setTeclas("Y","G","J","P");
                incluir(static_cast<Entidades::Entidade*>(jogador2));
            }

            jogador1->setVelocidade(Coordenada(0, 0));
            jogador1->setFase(this);
            incluir(static_cast<Entidades::Entidade*>(jogador1));
    }

    Fase::~Fase() {

    }

    void Fase::setTexture(const char* path) {
        sf::Texture *temp = pGrafico->loadTexture(path);
        fundo.setTexture(*temp);
        float sX = (float)COMPRIMENTO/temp->getSize().x;
        float sY = (float)ALTURA/temp->getSize().y;
        fundo.setScale(2*sX, sY);
    }

    void Fase::atualizarBackground() {
        // Simula o movimento relativo do background e jogador
        float pX = 0.85 * jogador1->getPosicao().x - COMPRIMENTO/2.f;
        fundo.setPosition(pX, 0);
    }

    void Fase::gameOver() {
        multiplayer = false;
        pontuacaoIni = jogador1->getPontuacao();
        pMaq->setEstadoAtual(Estados::IdEstado::menuGameOver);
    }

    void Fase::proximaFase() {
        pontuacaoIni = jogador1->getPontuacao();
        pMaq->setEstadoAtual(Estados::IdEstado::menuTransicao);
    }

    void Fase::pausarFase() {
        pontuacaoIni = jogador1->getPontuacao();
        pMaq->setEstadoAtual(Estados::IdEstado::menuPausa, &lEntidades);
    }

    void Fase::ativarControle() {
        jogador1->ativarControle();
        jogador2->ativarControle();
        pControleFase.ativar();
    }

    void Fase::desativarControle() {
        jogador1->desativarControle();
        jogador2->desativarControle();
        pControleFase.desativar();
    }

    void Fase::resetarEstadoOriginal() {
        // Retira os elementos da lista
        lEntidades.clear();
        colisor.resetar();
        numInimigos = 0;
        
        jogador1->resetar();
        jogador1->setFase(this);
        incluir(static_cast<Entidades::Entidade*>(jogador1));

        if(jogador2 != NULL && multiplayer)  {
            jogador2->resetar();
            jogador2->setFase(this);
            visor.setMultiplayer(true);
            incluir(static_cast<Entidades::Entidade*>(jogador2));
        } else {
            jogador2->desativarControle();
            visor.setMultiplayer(false);
        }

        fundo.setPosition(0, 0);

        // Resetar HUD
        visor.resetarVisor();
    }

    void Fase::incluir(Entidades::Entidade* l) {
        lEntidades.emplace_back(l);
        colisor.push(l);
        if(l->getID() == ID::inimigoTerrestre || l->getID() == ID::inimigoVoador || 
            l->getID() == ID::chefe) {
            visor.criaPontosEspacados(1, ElementosGraficos::PontoID::inimigoAbatido);
            numInimigos++;
        }
    }

    void Fase::atualizaEntidades(const float dt){
        Entidades::Entidade* ent;
        cout << "tam: " << lEntidades.size() << endl;
        for(it = lEntidades.begin(); it != lEntidades.end();) {
            ent = *it;
            ent->executar(dt);

            if(!ent->getAtivo()) {
                it = lEntidades.erase(it);
                if(ent->getID() == ID::inimigoTerrestre || ent->getID() == ID::inimigoVoador ||
                    ent->getID() == ID::chefe) {
                    numInimigos--;
                    jogador1->aumentaPontuacao(100);
                }
            } else {
                it++;
            }
        }

        visor.atualizaPontuacao(numInimigos);
    }

    void Fase::renderizar() {
        pGrafico->draw(&fundo, false);

        Entidades::Entidade *ent;
        for(it = lEntidades.begin(); it != lEntidades.end(); it++) {
            ent = *it;
            pGrafico->draw(ent->getSprite());
            //pGrafico->draw(ent->getShape());  // Fantasma shape para debuggar posicoes relativas e colisoes
        }

        visor.renderizar();
    }

    void Fase::geraEntidades(bool gIni) {
        geraPlataformas();
        geraObstaculos();
        if(gIni)
            geraInimigos();
    }

    void Fase::atualizar(const float dt) {
        // Verifica colisao entre Entidades Dinamicas e Estaticas
        colisor.ChecarColisoes();    

        // Atualiza a view para a posicao do jogador
        pGrafico->atualizaView(jogador1->getPosicao());

        pGrafico->atualizaMinimap(jogador1->getPosicao());

        // Processa o executar das entidades e remove entidades inativas
        atualizaEntidades(dt);

        // Desenha na tela os elementos
        renderizar();

        // Processa simulação de efeito Parallax
        atualizarBackground();

        //cout << "Tamanho: " << lEntidades.size() << endl;

        if(!(jogador1->estaVivo())){
            gameOver();
        } else if(pChegada != NULL && jogador1->getPosicao().x + jogador1->getTamanho().x >= pChegada->getPosicao().x - 1) {
            // Menu transição
            proximaFase();
        }
    }
}