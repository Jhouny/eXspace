#include "../../include/ElementosGraficos/BotaoSalvar.h"
#include "../../include/Ente/Menus/MenuGameOver.h"
namespace ElementosGraficos{
    BotaoSalvar::BotaoSalvar(Coordenada tam, Coordenada pos, std::string nome, Menus::MenuGameOver* pMenu):
        Botao(tam ,pos ,Estados::IdEstado::salvar,nome),
        pMenuGameOver(pMenu)
    {
        

    }

    BotaoSalvar::~BotaoSalvar(){ }

    void BotaoSalvar::salvar(){
        std::ofstream outFile(PONTUACAO_PATH,std::ios::out);
        if(!outFile){
            cerr << "Arquivo nao pode ser aberto" <<endl;
        }

        int pont = pMenuGameOver->getPontuacao();
        if(outFile){
            outFile << pont << endl;
            outFile << pMenuGameOver->getNome().c_str() << endl;
        }
        outFile.close();
    }

}