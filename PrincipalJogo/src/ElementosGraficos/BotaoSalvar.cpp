#include "../../include/ElementosGraficos/BotaoSalvar.h"
#include "../../include/Ente/Menus/MenuGameOver.h"
namespace ElementosGraficos{
    BotaoSalvar::BotaoSalvar(Coordenada tam, Coordenada pos, Menus::MenuGameOver* pMenu,std::string nome):
        Botao(tam,  pos,Estados::IdEstado::salvar,nome)
    {

    }

    BotaoSalvar::~BotaoSalvar(){ }

    void BotaoSalvar::salvar() {
        std::ofstream outFile;
        
        outFile.open(PONTUACAO_PATH,std::ios_base::app); 
        if(outFile) {
            
            outFile << pMenuGameOver->getNome().c_str() << ";";
        }
        outFile << endl;
        outFile.close();    
    



    }

}