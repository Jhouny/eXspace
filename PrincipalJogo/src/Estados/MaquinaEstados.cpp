#include "../../include/Estados/MaquinaEstados.h"
#include "../../include/Ente/Menus/Menu.h"
#include "../../include/Ente/Menus/MenuTransicao.h"

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

    void MaquinaEstados::setEstadoAtual(IdEstado id) {
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
                        cout << "setou origem" << endl;
                    }
                }
            }
            estadoAtual->setAnterior(temp);
            estadoAtual->getMenu()->reiniciarRelogio();
            estadoAtual->observar();
            estadoAtual->executar(0);
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