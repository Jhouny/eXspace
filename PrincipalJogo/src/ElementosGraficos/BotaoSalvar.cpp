#include "../../include/ElementosGraficos/BotaoSalvar.h"
#include "../../include/Ente/Menus/MenuGameOver.h"
namespace ElementosGraficos{
    BotaoSalvar::BotaoSalvar(Coordenada tam, Coordenada pos):
        Botao( tam,  pos,Estados::IdEstado::indefinido)
    {

    }

    BotaoSalvar::~BotaoSalvar(){ }

    void BotaoSalvar::salvar(){
        std::ofstream outFile;
        outFile.open(PONTUACAO_PATH,std::ios::in);
        int pont = pFase->getPontuacao();
        if(outFile){
            outFile << pont << endl;
            outFile << pMenuGameOver->getNome().c_str() << endl;
        }
        outFile.close();

        
    



    }

}