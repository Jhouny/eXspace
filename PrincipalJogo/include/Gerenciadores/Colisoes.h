#include "ListaEntidades.h"

namespace Gerenciadores {
    class Colisor {
        private:
            ListaEntidades* lDinamicas;
            ListaEntidades* lEstaticas;

        public:
            Colisor(ListaEntidades* lDin, ListaEntidades* lEst);

            ~Colisor();

            void ChecarColisoes();
    };
}