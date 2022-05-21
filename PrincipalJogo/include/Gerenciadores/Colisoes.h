#include "ListaEntidades.h"

namespace Gerenciadores {
    class Colisor {
        private:
            ListaEntidades* lDinamicas;
            ListaEntidades* lEstaticas;
        public:
            Colisor();

            ~Colisor();

            void setEstatica(ListaEntidades* lEst) {
                lEstaticas= lEst;
            }

            void setDinamicas(ListaEntidades* lDin) {
                lDinamicas = lDin;
            }

            void ChecarColisoes();
    };
}