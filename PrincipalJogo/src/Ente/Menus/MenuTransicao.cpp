#include "../../../include/Ente/Menus/MenuTransicao.h"
#include "../../../include/ElementosGraficos/Texto.h"

namespace Menus{
     
        MenuTransicao::MenuTransicao():
            Menu(){

        }
        MenuTransicao::~MenuTransicao();
        void MenuTransicao::ativarControle();

        void MenuTransicao::desativarControle();

        void MenuTransicao::criaBotoes();

        void MenuTransicao::renderizar();

        void MenuTransicao::atualizar(const float dt);

        void MenuTransicao::executar(const float dt);
            

    
}

