#include "../../include/Estados/MaquinaEstados.h"
#include "../../include/Ente/Menus/Menu.h"
#include "../../include/Ente/Menus/MenuTransicao.h"
#include "../../include/Ente/Menus/MenuGameOver.h"
#include "../../include/Ente/Menus/Fases/Netuno.h"

namespace Estados {
    MaquinaEstados::MaquinaEstados():
        estadoAtual(NULL),
        mapaEstados()
    {

    }

    MaquinaEstados::~MaquinaEstados() {
        mapaEstados.clear();
    }

    void MaquinaEstados::inserirEstado(Estado* est) {
        mapaEstados.insert(std::pair<IdEstado, Estado*>(est->getID(), est));
    }

    void MaquinaEstados::setEstadoAtual(IdEstado id, int pontos) {
        Estado* temp = estadoAtual;
        if(mapaEstados[id]) {
            estadoAtual = mapaEstados[id];
            if(temp != NULL) {
                temp->cegar();  // Faz o estado anterior deixar de reagir à Entrada do usuário
                estadoAtual->getMenu()->pGrafico->atualizaView(Coordenada(COMPRIMENTO/2.f, ALTURA/2.f));  // Reseta a view para o centro da tela
                temp->getMenu()->pGrafico->atualizaView(Coordenada(COMPRIMENTO/2.f, ALTURA/2.f));  // Reseta a view para o centro da tela
                
                if(temp->getID() == Estados::IdEstado::mercurio || temp->getID() == Estados::IdEstado::netuno) {
                    if(id == Estados::IdEstado::menuTransicao) {
                        Menus::MenuTransicao* menut = dynamic_cast<Menus::MenuTransicao*>(estadoAtual);
                        menut->setOrigem(temp->getID());
                        menut->setPontuacaoPrev(pontos);
                    }
                    else if(id == Estados::IdEstado::menuGameOver) {
                        Menus::MenuGameOver* menuG = dynamic_cast<Menus::MenuGameOver*>(estadoAtual);
                        menuG->setPontuacao(pontos);
                    }
                }

                else if(temp->getID() == Estados::IdEstado::menuTransicao) {
                    if(id == Estados::IdEstado::netuno) {
                        Menus::Fases::Netuno* net = dynamic_cast<Menus::Fases::Netuno*>(estadoAtual);
                        Menus::MenuTransicao* menut = dynamic_cast<Menus::MenuTransicao*>(temp);
                        if(net != NULL && menut != NULL) {
                            net->setPontuacao(menut->getPontuacaoPrev());
                        }
                    }
                }
            }

            estadoAtual->executar(0);
            estadoAtual->setAnterior(temp);
            estadoAtual->getMenu()->reiniciarRelogio();
            estadoAtual->observar();
        }
    }

    void MaquinaEstados::setEstadoAnterior() {
        if(estadoAtual->getAnterior() != NULL) {
            setEstadoAtual(estadoAtual->getAnterior()->getID());
        }
    }

    void MaquinaEstados::atualizarEstadoAtual(const float dt) {
        estadoAtual->atualizar(dt);
    }

    void MaquinaEstados::renderizarEstadoAtual() {
        estadoAtual->renderizar();
    }
} // namespace Estados