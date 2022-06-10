#ifndef _MAQUINA_ESTADOS_H_
#define _MAQUINA_ESTADOS_H_

#include "Estado.h"
#include "../Gerenciadores/Grafico.h"

namespace Entidades {
    class Entidade;
}

namespace Estados {
    class MaquinaEstados {
        protected:
            Estado* estadoAtual;
            std::map<IdEstado, Estado*> mapaEstados;
            sf::Clock tempo;

        public:
            MaquinaEstados();

            ~MaquinaEstados();

            std::map<IdEstado, Estado*>* getMapaEstados() { return &mapaEstados; }

            void inserirEstado(Estado* est);

            void setEstadoAtual(IdEstado id, int pontos = 0);
            void setEstadoAtual(IdEstado id, std::list<Entidades::Entidade*> *lEnt);

            void setEstadoAnterior();

            Estado* getEstadoAtual() { return estadoAtual; }

            void atualizarEstadoAtual(const float dt);

            void renderizarEstadoAtual();

            virtual void executar() = 0;
    };
} // namespace Estados


#endif