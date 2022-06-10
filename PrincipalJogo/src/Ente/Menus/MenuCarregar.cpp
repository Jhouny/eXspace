#include "../../../include/Ente/Menus/MenuCarregar.h"
#include "../../../include/Ente/Menus/Fases/Fase.h"
#include "../../../include/Estados/MaquinaEstados.h"

#define SAVES_PATH "PrincipalJogo/saves/jogos"
namespace Menus{
    MenuCarregar::MenuCarregar( Entidades::Personagens::Jogador* jog1,Entidades::Personagens::Jogador* jog2):
        jogador1(jog1),
        jogador2(jog2),
        Menu(),
        pControleMenu(this)
    {
        setID(Estados::IdEstado::menuCarregar);
        setTitulo("CARREGAR JOGO:");
        getTitulo()->setContorno(sf::Color::Yellow);
        getTitulo()->setPosicao(Coordenada(COMPRIMENTO/2.f - getTitulo()->getTexto()->getLocalBounds().width/2.f, 100.f));
        getTitulo()->setCor(sf::Color(0,0,0,230));
    }
            
    MenuCarregar::~MenuCarregar(){}

    void MenuCarregar::leCaminhoArquivos(){
        for (const auto & entry : fs::directory_iterator(SAVES_PATH)){   
            vectorCaminhos.emplace_back(entry.path().string());
        }
    }

    void MenuCarregar::lerTrecho(std::string in) {
        char* ptr;
        std::vector<char*> vecChar;
        ptr = strtok((char*)in.c_str(), ";"); 

        while(ptr != NULL){
            vecChar.emplace_back(ptr);
            ptr = strtok (NULL, ";");
        } 

        Estados::IdEstado idFase = (Estados::IdEstado) strtol(vecChar[0], NULL, 10);  // 1o ID é de Fase (i.e. Estado)
        cout << "id: " << idFase << endl;
        std::map<Estados::IdEstado, Estados::Estado*> *temp = pMaq->getMapaEstados();
        std::map<Estados::IdEstado, Estados::Estado*>::iterator it3;
        for(it3 = temp->begin(); it3 != temp->end() && (it3->second)->getID() != idFase; it3++);
            
        Menus::Fases::Fase* pFase = dynamic_cast<Menus::Fases::Fase*>(it3->second);

        ID id = (ID) strtol(vecChar[0], NULL, 10);
        switch(id) {
            case ID::jogador:  // Ignora o RG
                float px = stof(vecChar[2], NULL);
                float py = stof(vecChar[3], NULL);
                jogador1->setPosicao(Coordenada(px, py));
                int v = stoi(vecChar[4], NULL, 10);
                jogador1->setVida(v);
                float vx = stof(vecChar[5], NULL);
                float vy = stof(vecChar[6], NULL);
                jogador1->setVelocidade(Coordenada(0,0));  // Seta o vetor Vel. para (0,0)
                pFase->getLista()->emplace_back(static_cast<Entidades::Entidade*>(jogador1));
                break;
            case 2:
                
            case 4:
            case 5:
            case 6:
            case 10:
        }
    }

    void MenuCarregar::carregarFase() {
        getAtivo();
        try {
            ifstream joguin;
            std::string arq = (dynamic_cast<ElementosGraficos::BotaoPath*>(it->first))->getPath();
            joguin.open(arq, std::ios::in);
            if(joguin) {
                std::string entInf;
                
                while(!joguin.eof()) {
                    std::getline(joguin, entInf);
                    lerTrecho(entInf);
                }
            } else
                throw (arq);
            
        } catch (std::string path) {
            cerr << "Arquivo indisponivel: " << path << endl;
            exit(1);
        }
    }

    void MenuCarregar::ativarControle(){
        pControleMenu.ativar();
    }

    void MenuCarregar::desativarControle(){
        pControleMenu.desativar();
    }

    void MenuCarregar::criaBotoes() {
        botoesAtivos.clear();
        for(int i = 0; i < vectorCaminhos.size(); i++){
            pBotaoPath = new ElementosGraficos::BotaoPath(Coordenada(COMPRIMENTO/2.f - 125.f, 150 + 100*i ));
            pBotaoPath->setPath(vectorCaminhos[i]);
            if(i == 0) {
                pBotaoPath->ativar();
                botoesAtivos.emplace_back(std::pair<ElementosGraficos::Botao*, bool>(static_cast<ElementosGraficos::Botao*>(pBotaoPath), true));
            }
            else
                botoesAtivos.emplace_back(std::pair<ElementosGraficos::Botao*, bool>(static_cast<ElementosGraficos::Botao*>(pBotaoPath),false));
        }

    }

    void MenuCarregar::renderizar() {
        pGrafico->draw(&fundo, false);
        //desenha os botoes na tela
        for(it = botoesAtivos.begin(); it != botoesAtivos.end(); it++){
            pGrafico->draw((it->first)->getSprite(),false);
            pGrafico->draw((it->first)->getTexto());
        }
        pGrafico->draw(titulo.getTexto()); 
    }

    void MenuCarregar::atualizar(const float dt){
        //atualiza os botoes e suas respectivas texturas
        for(it = botoesAtivos.begin(); it != botoesAtivos.end(); it++){
            (it->first)->executar();
        }
    }

    void MenuCarregar::executar(const float dt) {
        leCaminhoArquivos();
        criaBotoes();
        setFundoAleatorio();
        pGrafico->setTamView(Coordenada(COMPRIMENTO, ALTURA));
        pGrafico->atualizaView(Coordenada(COMPRIMENTO/2.f, ALTURA/2.f));
    }
}