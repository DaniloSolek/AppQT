#ifndef PINCEL_H
#define PINCEL_H

#include <QFrame>
#include <vector>
#include <QMouseEvent>
#include "itens.h"
#include "dados.h"

class Pincel : public QFrame
{
    std::vector<Itens*> elenco;
    void posicionar(Itens* item, int posicao);
    void remover(int posicao);
    void remover(Itens *item);
public:
    Pincel(QWidget* parent = nullptr);
    jogadores* trElenco;
    void inserir(QString jogador);
    int tamanho();
    void loadElenco();
    void loadGK();
    void loadZG();
    void loadLD();
    void loadLE();
    void loadMC();
    void loadAT();
    void paintEvent(QPaintEvent* event);
    void mousePressEvent(QMouseEvent *event);
    void dragEnterEvent(QDragEnterEvent *event);
    void dragMoveEvent(QDragMoveEvent *event);
    void dropEvent(QDropEvent *event);
};

#endif // PINCEL_H
