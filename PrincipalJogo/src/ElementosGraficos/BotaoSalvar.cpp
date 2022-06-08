#include "../../include/ElementosGraficos/BotaoSalvar.h"
#include "../../include/Ente/Menus/MenuGameOver.h"
namespace ElementosGraficos{
    BotaoSalvar::BotaoSalvar(Coordenada tam, Coordenada pos, Menus::MenuGameOver* pMenu,std::string nome):
        Botao(tam,  pos,Estados::IdEstado::salvar,nome)
    {
        pMenuGameOver = pMenu;
        mapPontuacao.insert(pMenuGameOver->getMap()->begin(),pMenuGameOver->getMap()->end()); // copia os valores do menuGameOver
    }

    BotaoSalvar::~BotaoSalvar(){ }

    void BotaoSalvar::salvar() {
        std::multimap<int,std::string>::reverse_iterator itPont;
        std::ofstream pontuacaoArquivo(PONTUACAO_PATH,ios::out);
        mapPontuacao.insert(std::pair<int,std::string>(pMenuGameOver->getPontuacao(),pMenuGameOver->getNome()));
        if(!pontuacaoArquivo){
            cerr << "Arquivo não pode ser aberto"<< endl;
            return;
        }
        /*for(int i = 0; i < 10; i++){
            mapPontuacao.insert(std::pair<int,std::string>(i*10,"ROBERTO"));
        }*/
        itPont = mapPontuacao.rbegin();
        for(int i = 0; i < 10; i++){
            pontuacaoArquivo << itPont->first << endl;
            pontuacaoArquivo << itPont->second << endl;  
            itPont++;      
        }
    }

}