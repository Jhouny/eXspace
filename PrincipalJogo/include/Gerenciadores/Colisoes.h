#include "../Ente/Entidades/Entidade.h"

namespace Gerenciadores {
    class Colisor {
        private:
            std::vector<Entidade*> enteDinamicas;
            std::list<Entidade*> enteEstaticas;
            std::vector<Entidade*>::iterator itDinamicas;
            std::list<Entidade*>::iterator itEstaticas;

        public:
            Colisor();

            ~Colisor();

            void push(Entidade* ente);

            void remove(Entidade* ente);

            void ChecarColisoes();
    };
}