#include "../../../include/Ente/Menus/MenuPontuacao.h"


namespace Menus{
    MenuPontuacao::MenuPontuacao():
        Menu()
    {
        

    }

    MenuPontuacao::~MenuPontuacao(){
    }

    void MenuPontuacao::criaBotoes(){
        pBotao = new ElementosGraficos::Botao(Coordenada(100,50), Coordenada(COMPRIMENTO/2.f - 100/2.f, ALTURA/2.f- 50/2.f));
        botoesAtivos.insert(std::pair<ElementosGraficos::Botao*, bool>(pBotao, true));      
    }
    
    void MenuPontuacao::executar(const float dt){
        criaBotoes();
    }
}