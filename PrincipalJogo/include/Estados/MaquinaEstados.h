#ifndef _MAQUINA_ESTADOS_H_
#define _MAQUINA_ESTADOS_H_

#include "Estado.h"

namespace Estados {
    class MaquinaEstados {
    private:
        Estado* estadoAtual;
        std::map<IdEstado, Estado*> mapaEstados;

    public:
        MaquinaEstados();

        ~MaquinaEstados();

        void inserirEstado(Estado* est);

        void setEstadoAtual(IdEstado id);

        Estado* getEstadoAtual() { return estadoAtual; }

        void atualizarEstadoAtual(const float dt);

        void renderizarEstadoAtual();

        virtual void executar() = 0;
    };
} // namespace Estados


#endif