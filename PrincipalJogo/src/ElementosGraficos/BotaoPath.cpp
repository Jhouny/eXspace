#include "../../include/ElementosGraficos/BotaoPath.h"

namespace ElementosGraficos {
    BotaoPath::BotaoPath(Coordenada pos):
        Botao(TAMANHO_PADRAO_BOTAO_PATH, pos, Estados::IdEstado::carregar, ""),
        path("")
    {

    }

    BotaoPath::~BotaoPath() {

    }

    void BotaoPath::setTitulo(std::string cont) {
        texto.setConteudo(cont);
    }

    void BotaoPath::setPath(std::string cont) {
        path = cont;
    }
} // namespace ElementosGraficos

