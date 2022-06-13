#include "../../include/ElementosGraficos/BotaoSalvar.h"
#include "../../include/Ente/Menus/MenuGameOver.h"
namespace ElementosGraficos{
    BotaoSalvar::BotaoSalvar(Coordenada tam, Coordenada pos, Menus::MenuGameOver* pMenu,std::string nome):
        Botao(tam,  pos,Estados::IdEstado::salvarPontuacao,nome),
        inicio(true)
    {
        pMenuGameOver = pMenu;
        mapPontuacao.insert(pMenuGameOver->getMap()->begin(),pMenuGameOver->getMap()->end()); // copia os valores do menuGameOver
    }

    BotaoSalvar::~BotaoSalvar(){ }

    void BotaoSalvar::salvar() {
        //Animação do botão
        setTexture(TEX_BOTAO_SALVAR_ATIVO);
        inicio = false;
        temporizador.restart();

        std::multimap<int,std::string>::reverse_iterator itPont;
        std::ofstream pontuacaoArquivo(PONTUACAO_PATH,ios::out);
        mapPontuacao.insert(std::pair<int,std::string>(pMenuGameOver->getPontuacao(),pMenuGameOver->getNome()));
        if(!pontuacaoArquivo){
            cerr << "Arquivo de pontuação não pode ser aberto para salvar" << endl;
            return;
        }

        itPont = mapPontuacao.rbegin();
        for(int i = 0; i < 10; i++){
            pontuacaoArquivo << itPont->first << endl;
            pontuacaoArquivo << itPont->second << endl;  
            itPont++;      
        }
    }

    void BotaoSalvar::atualizarTextura() {
        if((ativo && temporizador.getElapsedTime().asSeconds() > 1) || (ativo && inicio))
            setTexture(TEX_BOTAO_ATIVO);
        else if(temporizador.getElapsedTime().asSeconds() < 1 && !inicio)
            setTexture(TEX_BOTAO_SALVAR_ATIVO);
        else
            setTexture(TEX_BOTAO_NEUTRO);
    }

}