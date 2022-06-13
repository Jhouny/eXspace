#include "../../include/Estados/MaquinaEstados.h"
#include "../../include/Ente/Menus/Menu.h"
#include "../../include/Ente/Menus/MenuTransicao.h"
#include "../../include/Ente/Menus/MenuPausa.h"
#include "../../include/Ente/Menus/MenuGameOver.h"
#include "../../include/Ente/Menus/MenuJogar.h"
#include "../../include/Ente/Menus/Fases/Netuno.h"
#include "../../include/Ente/Menus/Fases/Mercurio.h"
#include "../../include/Ente/Menus/Fases/Fase.h"


namespace Estados {
    MaquinaEstados::MaquinaEstados():
        estadoAtual(NULL),
        mapaEstados(),
        tempo()
    {
        estadoAtual = NULL;
    }

    MaquinaEstados::~MaquinaEstados() {
        mapaEstados.clear();
    }

    void MaquinaEstados::inserirEstado(Estado* est) {
        if(mapaEstados.size() == 0) { // Se for o primeiro estado a ser adicionado, seta como o atual
            estadoAtual = est;
            estadoAtual->getMenu()->pGrafico->atualizaView(Coordenada(COMPRIMENTO/2.f, ALTURA/2.f));  // Reseta a view para o centro da tela
            estadoAtual->observar();
            estadoAtual->executar(0);
            estadoAtual->getMenu()->reiniciarRelogio();
        }
        mapaEstados.insert(std::pair<IdEstado, Estado*>(est->getID(), est));
    }

    void MaquinaEstados::setEstadoAtual(IdEstado id) {
        Estado* temp = estadoAtual;
        if(temp == NULL) {  // Evita acesso ao ponteiro nulo
            cout << "Ponteiro para estadoAtual=NULL em setEstadoAtual()" << endl;
            return; 
        } 

        if(mapaEstados[id] && mapaEstados[id] != estadoAtual) {  // Se existir e for diferente do atual
            estadoAtual = mapaEstados[id];  // Atualiza o estado atual
            estadoAtual->getMenu()->pGrafico->atualizaView(Coordenada(COMPRIMENTO/2.f, ALTURA/2.f));  // Reseta a view para o centro da tela
            estadoAtual->observar();
            
            temp->cegar();  // Faz o estado anterior deixar de reagir à Entrada do usuário
            //temp->getMenu()->pGrafico->atualizaView(Coordenada(COMPRIMENTO/2.f, ALTURA/2.f));  // Reseta a view para o centro da tela
            
            if(temp->getID() == IdEstado::mercurio || temp->getID() == IdEstado::netuno) {  // Se veio de uma das fases vai para o menu de transição ou gameOver
                Menus::Fases::Fase* fase = dynamic_cast<Menus::Fases::Fase*>(temp); // Determina a fase de origem
                if(id == IdEstado::menuTransicao) {
                    Menus::MenuTransicao* menut = dynamic_cast<Menus::MenuTransicao*>(estadoAtual);
                    menut->setOrigem(temp->getID());
                    menut->setPontuacaoPrev(fase->getPontuacao());
                    menut->setMultiplayer(fase->getMultiplayer());
                } else if(id == IdEstado::menuGameOver) {
                    Menus::MenuGameOver* menuG = dynamic_cast<Menus::MenuGameOver*>(estadoAtual);
                    menuG->setPontuacao(fase->getPontuacao());
                }
            } else if(temp->getID() == IdEstado::menuTransicao) {  // Se veio do menu de transição, vai para a fase Netuno
                if(id == IdEstado::netuno) {
                    Menus::Fases::Netuno* net = dynamic_cast<Menus::Fases::Netuno*>(estadoAtual);
                    Menus::MenuTransicao* menut = dynamic_cast<Menus::MenuTransicao*>(temp);
                    if(net != NULL && menut != NULL) {
                        net->setMultiplayer(menut->getMultiplayer());
                        net->resetarEstadoOriginal();
                        net->setPontuacao(menut->getPontuacaoPrev());
                        net->geraEntidades(true);
                    }
                }
            } else if(temp->getID() == IdEstado::menuJogar) {  // Se veio do menu jogar para uma das fases
                Menus::MenuJogar* mj = dynamic_cast<Menus::MenuJogar*>(temp);
                Menus::Fases::Fase* fase = dynamic_cast<Menus::Fases::Fase*>(estadoAtual);
                if(fase != NULL) {
                    fase->setMultiplayer(mj->getMultiplayer());
                    fase->resetarEstadoOriginal();
                    fase->setPontuacao(0);
                    fase->geraEntidades(true);
                }
            }

            estadoAtual->executar(0);
            estadoAtual->getMenu()->reiniciarRelogio();
        }
    }

    void MaquinaEstados::setEstadoAtual(IdEstado id, std::list<Entidades::Entidade*> *lEnt) {
        Estado* temp = estadoAtual;
        if(id == IdEstado::menuPausa && mapaEstados[id]) {
            estadoAtual = mapaEstados[id];
            temp->cegar();  // Faz o estado anterior deixar de reagir à Entrada do usuário

            Menus::MenuPausa* pausa = dynamic_cast<Menus::MenuPausa*>(estadoAtual);
            pausa->setFaseID(temp->getID());
            pausa->setFase(dynamic_cast<Menus::Fases::Fase*>(temp));
            pausa->setLista(lEnt);

            estadoAtual->setAnterior(temp);
            estadoAtual->getMenu()->pGrafico->atualizaView(Coordenada(COMPRIMENTO/2.f, ALTURA/2.f));  // Reseta a view para o centro da tela
            estadoAtual->executar(0);
            estadoAtual->getMenu()->reiniciarRelogio();
            estadoAtual->observar();
        } else if(temp->getID() == IdEstado::menuPausa && mapaEstados[id]) {
            estadoAtual = mapaEstados[id];
            temp->cegar();  // Faz o estado anterior deixar de reagir à Entrada do usuário
            estadoAtual->getMenu()->reiniciarRelogio();
            estadoAtual->observar();
        }
    }

    void MaquinaEstados::setEstadoAnterior() {
        if(estadoAtual->getAnterior() != NULL && tempo.getElapsedTime().asSeconds() > 0.2) {
            setEstadoAtual(estadoAtual->getAnterior()->getID());
            tempo.restart();
        }
    }

    void MaquinaEstados::atualizarEstadoAtual(const float dt) {
        estadoAtual->atualizar(dt);
    }

    void MaquinaEstados::renderizarEstadoAtual() {
        estadoAtual->renderizar();
    }
} // namespace Estados