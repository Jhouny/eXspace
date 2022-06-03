#include"../../../include/Ente/Menus/MenuGameOver.h"

#include"../../../include/Controle/ControleTexto.h"

namespace Menus{
    MenuGameOver::MenuGameOver():
        Menu(),
        pControleTexto(this)
    {
        setID( Estados::IdEstado::menuGameOver);
        setTitulo("GAME OVER");
        getTitulo()->setPosicao(Coordenada(COMPRIMENTO/2.f - getTitulo()->getTexto()->getLocalBounds().width/2.f, 100.f));
        getTitulo()->setCor(sf::Color(0,0,0,230));
        getTitulo()->setContorno(sf::Color::Yellow ,5);
        executar(0);



    }

    MenuGameOver::~MenuGameOver() {}

    void MenuGameOver::criaBotoes(){
        pBotao = new ElementosGraficos::Botao(Coordenada(200, 100), Coordenada(COMPRIMENTO/2.f, 550), Estados::IdEstado::menuAbertura, "SALVAR");
        pBotao->ativar();
        botoesAtivos.insert(std::pair<ElementosGraficos::Botao*, bool>(pBotao, true));

        pBotao = new ElementosGraficos::Botao(Coordenada(200, 100), Coordenada(COMPRIMENTO/2.f, 650), Estados::IdEstado::menuAbertura, "VOLTAR");
        
        botoesAtivos.insert(std::pair<ElementosGraficos::Botao*, bool>(pBotao, false));
    }

    void MenuGameOver::criaTextos(){
        pTexto = new ElementosGraficos::Texto(Coordenada(400,250),Coordenada(0,0),"Digite seu nome:");
        pTexto->setPosicao(Coordenada(COMPRIMENTO/2.f - getTitulo()->getTexto()->getLocalBounds().width/2.f, 300));
        pTexto->setCor(sf::Color(0,0,0,230));
        pTexto->setContorno(sf::Color::Yellow, 5);
        incluir(pTexto);

        pTexto = new ElementosGraficos::Texto(Coordenada(400,150), Coordenada(COMPRIMENTO/2.f,450),"", false);
        pTexto->setCor(sf::Color(0,0,0,230));
        pTexto->setContorno(sf::Color::Yellow, 5);
        incluir(pTexto);
        

    }

    void MenuGameOver::incluir(ElementosGraficos::Texto *texto){
        if(texto)
            lTextos.push(texto);
        else
            cout << "Ponteiro para texto nulo"<< endl;
    }

    void MenuGameOver::renderizar(){
        pGrafico->draw(&fundo, false);
        int i;
        //desenha Textos na tela
        for(i = 0; i < lTextos.getTamanho(); i++ ){
            pGrafico->draw(lTextos[i]->getTexto());
        }
        //desenha os botoes na tela
        for(it = botoesAtivos.begin(); it != botoesAtivos.end(); it++){
            pGrafico->draw((it->first)->getSprite(),false);
            pGrafico->draw((it->first)->getTexto());
        }
        pGrafico->draw(titulo.getTexto());     

    }

    void MenuGameOver::atualizar(const float dt){
        //atualiza os botoes e suas respectivas texturas
        for(it = botoesAtivos.begin(); it != botoesAtivos.end(); it++){
            (it->first)->executar();
        }

        //atualiza os texto que podem ser modificados
        for(int i = 0; i < lTextos.getTamanho(); i++ ){
            if(!(lTextos[i]->ElementosGraficos::Texto::getEstatico())){
                lTextos[i]->setTexto(pControleTexto.getNome()); //ControleTexto!!
                lTextos[i]->setPosicao(Coordenada(COMPRIMENTO/2.f - getTitulo()->getTexto()->getLocalBounds().width/2.f, 450));
            }
        }

    }

    void MenuGameOver::executar(const float dt){
        criaBotoes();
        criaTextos();
        setFundoAleatorio();
        pGrafico->setTamView(Coordenada(COMPRIMENTO, ALTURA));
        pGrafico->atualizaView(Coordenada(COMPRIMENTO/2.f, ALTURA/2.f));
    }


}