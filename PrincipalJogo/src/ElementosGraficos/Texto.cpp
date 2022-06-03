#include "../../include/ElementosGraficos/Texto.h"

namespace ElementosGraficos {
    Texto::Texto(Coordenada tam, Coordenada pos, std::string conteudo, bool est):
        tamanho(tam),
        posicao(pos),
        pGrafico(Gerenciadores::Grafico::getInstancia()),
        texto(), 
        estati(est)
    {
        setAlinhamento(Alinhamento::esquerda);
        setFonte(FONTE_PADRAO);
        setCor(sf::Color(0,0,0));

        texto.setString(sf::String::fromUtf8(conteudo.begin(), conteudo.end()));
        texto.setPosition(sf::Vector2f(posicao.x - texto.getLocalBounds().width/2.f, posicao.y - (texto.getLocalBounds().top + texto.getLocalBounds().height/2.7f)));
        texto.setCharacterSize(tamanho.y * PROPORCAO);
    }

    Texto::~Texto() {
        pGrafico = NULL;
    }

    void Texto::setTexto(const char* tex){
        texto.setString(tex);
    }

    void Texto::setPosicao(Coordenada pos) {
        texto.setPosition(pos.x, pos.y);
        posicao = pos;
    }

    void Texto::setTamanho(Coordenada tam) {
        texto.setCharacterSize(tam.y * PROPORCAO);
        tamanho = tam;
    }

    std::string Texto::getConteudo() const {
        return texto.getString();
    }

    void Texto::setConteudo(std::string cont) {
        texto.setString(cont);
    }

    void Texto::setAlinhamento(Alinhamento al) {
        switch (al) {
        case Alinhamento::esquerda:
            texto.setOrigin(0, 0);
            break;
        case Alinhamento::centro:
            texto.setOrigin(getTamanho().x / 2.f, getTamanho().y/2.f);
            break;
        case Alinhamento::direita:
            texto.setOrigin(getTamanho().x, 0);
            break;
        default:
            texto.setOrigin(0, getTamanho().y/2.f);
            break;
        }
    }

    void Texto::setFonte(const char* path) {
        sf::Font* f = pGrafico->carregaFonte(path);
        texto.setFont(*f);
    }

    void Texto::setContorno(sf::Color C, float esp) {
        texto.setOutlineColor(C);
        texto.setOutlineThickness(esp);
    }

    void Texto::setCor(sf::Color C){
        texto.setFillColor(C);
    }
}