#include "../../../include/Ente/Menus/MenuPontuacao.h"
#include "../../../include/ElementosGraficos/Texto.h"

namespace Menus{
    MenuPontuacao::MenuPontuacao():
        Menu(),
        pControleMenu(this)
    {
        setID(Estados::IdEstado::pontuacao);
        /*
        setTitulo("PONTUAÇÃO");
        getTitulo()->setPosicao(Coordenada(COMPRIMENTO/2.f - getTitulo()->getTexto()->getLocalBounds().width/2.f, 100.f));
        getTitulo()->setContorno(sf::Color(200, 50, 50, 230), 5);*/
        
        executar(0);
    }

    MenuPontuacao::~MenuPontuacao() {}

    void MenuPontuacao::criaBotoes(){
        botoesAtivos.clear();
        pBotao = new ElementosGraficos::Botao(Coordenada(200, 100), Coordenada(1100.f, 650.f),Estados::IdEstado::menuAbertura,"VOLTAR"); //VOLTA PARA O MENU
        pBotao->ativar();
        botoesAtivos.emplace_back(std::pair<ElementosGraficos::Botao*, bool>(pBotao, true));        
    }

    void MenuPontuacao::incluir(ElementosGraficos::Texto *texto){
        if(texto)
            vTextos.push_back(texto);
        else
            cout << "Ponteiro para texto esta nulo" << endl;

    }

    void MenuPontuacao::criaTextos() {
        vTextos.clear();

        pTexto = new ElementosGraficos::Texto(Coordenada(400,250),Coordenada((float)COMPRIMENTO/2.f-100.f,50),"Pontuação: ");
        pTexto->setCor(sf::Color (57,255,20));
        pTexto->setContorno(sf::Color(0,0,0,230), 5);
        incluir(pTexto);

        pTexto = new ElementosGraficos::Texto(Coordenada(400,150),Coordenada(COMPRIMENTO/7.f,200),"1º");
        pTexto->setCor(sf::Color::Yellow);
        pTexto->setContorno(sf::Color(0,0,0,230), 5);
        incluir(pTexto);

        pTexto = new ElementosGraficos::Texto(Coordenada(400,150),Coordenada(COMPRIMENTO/7.f,300),"2º");
        pTexto->setCor(sf::Color::Yellow);
        pTexto->setContorno(sf::Color(0,0,0,230), 5);
        incluir(pTexto);

        pTexto = new ElementosGraficos::Texto(Coordenada(400,150),Coordenada(COMPRIMENTO/7.f,400),"3º");
        pTexto->setCor(sf::Color::Yellow);
        pTexto->setContorno(sf::Color(0,0,0,230), 5);
        incluir(pTexto);

        pTexto = new ElementosGraficos::Texto(Coordenada(400,150),Coordenada(COMPRIMENTO/7.f,500),"4º");
        pTexto->setCor(sf::Color::Yellow);
        pTexto->setContorno(sf::Color(0,0,0,230), 5);
        incluir(pTexto);

        pTexto = new ElementosGraficos::Texto(Coordenada(400,150),Coordenada(COMPRIMENTO/7.f,600),"5º");
        pTexto->setCor(sf::Color::Yellow);
        pTexto->setContorno(sf::Color(0,0,0,230), 5);
        incluir(pTexto);
        
        // Le a pontuação do arquivo salvo
        std::ifstream recuperaPontuacao(PONTUACAO_PATH,ios::in);
        if(!recuperaPontuacao){
            cerr << "Arquivo de pontuação não pode ser aberto"<< endl;
            return;
        }
        std::string nome;
        std::string pontuacao;
        for(int i = 0; i < 5; i++) {
            std::getline(recuperaPontuacao,pontuacao);
            std::getline(recuperaPontuacao,nome);
            pTextoPontuacao = new ElementosGraficos::Texto(Coordenada(COMPRIMENTO/4.f,150),Coordenada (COMPRIMENTO/3.f,200+i*100),nome);
            pTextoPontuacao->setCor(sf::Color::Yellow);
            incluir(pTextoPontuacao);
            pTextoPontuacao = new ElementosGraficos::Texto(Coordenada(400,150),Coordenada(2*(COMPRIMENTO)/3.f,200+i*100),pontuacao);
            pTextoPontuacao->setCor(sf::Color::Yellow);
            incluir(pTextoPontuacao);
        }
    }

    void MenuPontuacao::atualizar(const float dt){
        for(it = botoesAtivos.begin(); it != botoesAtivos.end(); it++){
            (it->first)->executar();
        }
    }

    void MenuPontuacao::ativarControle() {
        pControleMenu.ativar();
    }

    void MenuPontuacao::desativarControle() {
        pControleMenu.desativar();
    }

    void MenuPontuacao::renderizar(){
        pGrafico->draw(&fundo, false);
        int i;
        for(i = 0; i < vTextos.size(); i++ ){
            pGrafico->draw(vTextos[i]->getTexto());
        }
         for(it = botoesAtivos.begin(); it != botoesAtivos.end(); it++){
            pGrafico->draw((it->first)->getSprite(),false);
            pGrafico->draw((it->first)->getTexto());
        }
    }

    void MenuPontuacao::executar(const float dt){
        criaBotoes();
        criaTextos();
        setFundoAleatorio();
        pGrafico->setTamView(Coordenada(COMPRIMENTO, ALTURA));
        pGrafico->atualizaView(Coordenada(COMPRIMENTO/2.f, ALTURA/2.f));
    }
}