#include "../../../include/Ente/Menus/Fase.h"
#include "../../../include/Estados/MaquinaEstados.h"

namespace Menus{
    Fase::Fase(Jogador* jog1, Jogador* jog2):
        Menu(),
        jogador1(jog1),
        jogador2(jog2),
        pControleFase(this),
        visor(jogador1, jogador2),
        colisor()
        {
            // Define o plano de fundo
            setTexture(TEX_BACKGROUND);
            //Define o ID do Menu fase:

            // Inclui os jogadores
            if(jogador2 != NULL) {
                jogador2->setVelocidade(Coordenada(15,0));
                jogador2->setFase(this);
                incluir(static_cast<Entidade*>(jogador2));
            }

            jogador1->setVelocidade(Coordenada(10.5, 0));
            jogador1->setFase(this);
            incluir(static_cast<Entidade*>(jogador1));
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
        pMaq->setEstadoAtual(Estados::IdEstado::menuGameOver);
    }

    void Fase::ativarControle() {
        jogador1->ativarControle();
        pControleFase.ativar();
    }

    void Fase::desativarControle() {
        jogador1->desativarControle();
        pControleFase.desativar();
    }

    void Fase::resetarEstadoOriginal() {
        // Retira os elementos da lista
        lEntidades.clear();

        jogador1->setJump(false);
        jogador1->pulo(false);
        jogador1->ataque(false);
        jogador1->setVelocidade(Coordenada(0, 0));
        jogador1->setFase(this);
        jogador1->setAtivo(true);
        jogador1->setVida(100);
        jogador1->setPosicao(Coordenada(0, 100));
        incluir(static_cast<Entidade*>(jogador1));

        if(jogador2 != NULL) {
            jogador2->setVelocidade(Coordenada(10.5, 0));
            jogador2->setFase(this);
            jogador2->setAtivo(true);
            jogador2->setVida(100);
            jogador2->setPosicao(Coordenada(50,0));
            incluir(static_cast<Entidade*>(jogador2));
        }

        fundo.setPosition(0, 0);

        // Resetar HUD
        visor.resetarVisor();
    }

    void Fase::incluir(Entidade* l) {
        ID id = l->getID();
        lEntidades.emplace_back(l);
        colisor.push(l);
    }

    void Fase::atualizaEntidades(const float dt){
        Entidade* ent;
        std::vector<Entidade*>::iterator it;
        for(it = lEntidades.begin(); it != lEntidades.end();) {
            ent = *it;
            ent->executar(dt);

            if(!ent->getAtivo())
                it = lEntidades.erase(it);
            else
                it++;
        }
        
        visor.atualizaPontuacao();
    }

    void Fase::renderizar() {
        pGrafico->draw(&fundo, false);

        Entidade *ent;
        std::vector<Entidade*>::iterator it;
        for(it = lEntidades.begin(); it != lEntidades.end(); it++) {
            ent = *it;
            pGrafico->draw(ent->getSprite());
            //pGrafico->draw(ent->getShape());  // Fantasma shape para debuggar posicoes relativas e colisoes
        }

        visor.renderizar();
    }

    void Fase::atualizar(const float dt) {
        // Verifica colisao entre Entidades Dinamicas e Estaticas
        colisor.ChecarColisoes();    

        // Atualiza a view para a posicao do jogador
        pGrafico->atualizaView(jogador1->getPosicao());

        // Processa o executar das entidades e remove entidades inativas
        atualizaEntidades(dt);

        // Desenha na tela os elementos
        renderizar();

        // Processa simulação de efeito Parallax
        atualizarBackground();

        if(!(jogador1->estaVivo())){
            gameOver();
        }
    }
}