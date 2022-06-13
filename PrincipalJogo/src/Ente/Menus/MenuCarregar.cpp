#include "../../../include/Ente/Menus/MenuCarregar.h"
#include "../../../include/Ente/Menus/Fases/Fase.h"
#include "../../../include/Estados/MaquinaEstados.h"

#define SAVES_PATH "PrincipalJogo/saves/jogos"
namespace Menus{
    MenuCarregar::MenuCarregar( Entidades::Personagens::Jogador* jog1,Entidades::Personagens::Jogador* jog2):
        jogador1(jog1),
        jogador2(jog2),
        Menu(),
        pControleMenu(this),
        pFase(NULL)
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

    void MenuCarregar::carregarLinha(std::string in) {
        char* ptr;
        std::vector<char*> vecChar;
        ptr = strtok((char*)in.c_str(), ";"); 

        while(ptr != NULL) {
            vecChar.emplace_back(ptr);
            ptr = strtok (NULL, ";");
        } 

        if(pFase == NULL) {
            Estados::IdEstado idFase = (Estados::IdEstado) strtol(vecChar[0], NULL, 10);  // 1o ID é de Fase (i.e. Estado)
            std::map<Estados::IdEstado, Estados::Estado*> tmp = *(pMaq->getMapaEstados());
            pFase = dynamic_cast<Menus::Fases::Fase*>(tmp[idFase]);
            pFase->resetarEstadoOriginal();
            pFase->setMultiplayer((bool)stoi(vecChar[1], NULL, 10));
            pFase->setPontuacao(stoi(vecChar[2], NULL, 10));
            pFase->geraEntidades(false);
            return;
        }

        Coordenada tam, pos;
        ID id = (ID) stoi(vecChar[0], NULL, 10);
        int rg = stoi(vecChar[1], NULL, 10);
        int v;
        float vx, vy;
        switch(id) {
            case ID::jogador: {  // Ignora o RG
                pos.x = stof(vecChar[2], NULL);
                pos.y = stof(vecChar[3], NULL);
                v = stoi(vecChar[4], NULL, 10);
                vx = stof(vecChar[5], NULL);
                vy = stof(vecChar[6], NULL);

                if(rg == 0) {
                    jogador1->setPosicao(pos);
                    jogador1->setVida(v);
                    jogador1->setVelocidade(Coordenada(0,0));  // Seta o vetor Vel. para (0,0)
                } else {
                    jogador2->setPosicao(pos);
                    jogador2->setVida(v);
                    jogador2->setVelocidade(Coordenada(0,0));  // Seta o vetor Vel. para (0,0)
                }
                break;
            }
            case ID::projetil: {
                pos.x = stof(vecChar[2], NULL);
                pos.y = stof(vecChar[3], NULL);
                vx = stof(vecChar[4], NULL);
                vy = stof(vecChar[5], NULL);
                int dano = stoi(vecChar[6], NULL, 10);
                ID orig = (ID) stoi(vecChar[7], NULL, 10);
                char* path = vecChar[8];

                if(orig == ID::jogador)
                    tam = TAM_PROJETIL_JOGADOR;
                else if(orig == ID::inimigoVoador)
                    tam = TAM_PROJETIL_INI_VOADOR;
                else if(orig == ID::chefe)
                    tam = TAM_PROJETIL_CHEFE;
                else
                    tam = TAM_PROJETIL_JOGADOR;  // Default para projetil de jogador

                Entidades::Projetil* proj = new Entidades::Projetil(pos, tam, vx, vy, dano, path);
                pFase->incluir(static_cast<Entidades::Entidade*>(proj));
                break;
            }
            case ID::inimigoTerrestre: {
                pos.x = stof(vecChar[2], NULL);
                pos.y = stof(vecChar[3], NULL) - 100.f;
                v = stoi(vecChar[4], NULL, 10);
                vx = stof(vecChar[5], NULL);
                vy = stof(vecChar[6], NULL);
                Entidades::Personagens::InimigoTerrestre* iniT = new Entidades::Personagens::InimigoTerrestre();
                iniT->setPosicao(pos);
                iniT->setVida(v);
                iniT->setVelocidade(Coordenada(vx,vy));
                iniT->setJogador1(jogador1);
                iniT->setJogador2(jogador2);
                pFase->incluir(static_cast<Entidades::Entidade*>(iniT));
                break;
            }
            case ID::inimigoVoador: {
                pos.x = stof(vecChar[2], NULL);
                pos.y = stof(vecChar[3], NULL);
                v = stoi(vecChar[4], NULL, 10);
                vx = stof(vecChar[5], NULL);
                vy = stof(vecChar[6], NULL);
                float pm = stof(vecChar[7], NULL);
                Entidades::Personagens::InimigoVoador* iniV = new Entidades::Personagens::InimigoVoador();
                iniV->setPosicao(pos);
                iniV->setVida(v);
                iniV->setVelocidade(Coordenada(vx,vy));
                iniV->setPontoMedio(pm);
                iniV->setJogador1(jogador1);
                iniV->setJogador2(jogador2);
                iniV->setFase(pFase);
                pFase->incluir(static_cast<Entidades::Entidade*>(iniV));
                break;
            }
            case ID::chefe: {
                pos.x = stof(vecChar[2], NULL);
                pos.y = stof(vecChar[3], NULL);
                v = stoi(vecChar[4], NULL, 10);
                vx = stof(vecChar[5], NULL);
                vy = stof(vecChar[6], NULL);
                Entidades::Personagens::Chefe* chefe = new Entidades::Personagens::Chefe();
                chefe->setPosicao(pos);
                chefe->setVida(v);
                chefe->setFase(pFase);
                chefe->setVelocidade(Coordenada(vx,vy));
                chefe->setJogador1(jogador1);
                chefe->setJogador2(jogador2);
                pFase->incluir(static_cast<Entidades::Entidade*>(chefe));
                break;
            }
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
                    if(entInf.size() > 0)
                        carregarLinha(entInf);
                }

                pMaq->setEstadoAtual((static_cast<Estados::Estado*>(pFase))->getID());
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
            pBotaoPath = new ElementosGraficos::BotaoPath(Coordenada(COMPRIMENTO/2.f, 300 + 120*i ));
            pBotaoPath->setPath(vectorCaminhos[i]);
            pBotaoPath->setTitulo(vectorCaminhos[i]);
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
        pFase = NULL;  // Força a resetar a fase
        leCaminhoArquivos();
        criaBotoes();
        setFundoAleatorio();
        pGrafico->setTamView(Coordenada(COMPRIMENTO, ALTURA));
        pGrafico->atualizaView(Coordenada(COMPRIMENTO/2.f, ALTURA/2.f));
    }
}