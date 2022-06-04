#include "../../include/Estados/MaquinaEstados.h"
#include "../../include/Ente/Menus/Menu.h"

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
            if(temp != NULL) {
                temp->cegar();
                estadoAtual->getMenu()->pGrafico->atualizaView(Coordenada(COMPRIMENTO/2.f, ALTURA/2.f));
            }
            estadoAtual = mapaEstados[id];
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