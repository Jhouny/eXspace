#include "../Ente/Entidades/Entidade.h"

namespace Gerenciadores {
    class Colisor {
        private:
            std::vector<Entidades::Entidade*> enteDinamicas;
            std::list<Entidades::Entidade*> enteEstaticas;
            std::vector<Entidades::Entidade*>::iterator itDinamicas;
            std::list<Entidades::Entidade*>::iterator itEstaticas;

        public:
            Colisor();

            ~Colisor();

            void push(Entidades::Entidade* ente);
            void remove();

            void resetar();

            void ChecarColisoes();
    };
}