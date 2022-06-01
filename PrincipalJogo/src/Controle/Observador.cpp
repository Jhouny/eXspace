#include "../../include/Controle/Observador.h"

namespace Controle {
    int Observador::cont = 0;

    Observador::Observador() {
        pEntrada = Gerenciadores::Entrada::getInstancia();
        pEntrada->adicionar(this);

        id = cont;
        cont++;
    }

    Observador::~Observador() {
        pEntrada->remover(this);
    }
}
