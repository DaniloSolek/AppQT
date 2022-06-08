#ifndef JANELA_H
#define JANELA_H

#include <QMainWindow>
#include <QLabel>
#include <vector>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include "dados.h"
#include "pincel.h"
#include "janela2.h"

class Janela : public QMainWindow
{
    Q_OBJECT
    QLabel* label1 = new QLabel(this);
    QLabel* label2 = new QLabel(this);
    QLabel* label3 = new QLabel(this);
    QMenuBar* menu = new QMenuBar(this);
    QMenu* secaoMenu = new QMenu("Jogo", menu);
    QMenu* secaoMenu2 = new QMenu("Seu Time", menu);
    QAction* novo = new QAction("Novo Jogo", secaoMenu);
    QAction* salvar = new QAction("Salvar", secaoMenu);
    QAction* abrir = new QAction("Abrir Jogo", secaoMenu2);
    QAction* datas = new QAction("Calendário", secaoMenu2);
    QAction* simular = new QAction("Simular", secaoMenu2);
public:
    explicit Janela(QWidget *parent = nullptr);
    void load(Pincel* lista, int i);
    Pincel* lJogadores, *lTitulares;
signals:

public slots:
    void novoJogo();
    void salvarJogo();
    void abrirJogo();
    void loadJogo();
    void abrirCalendario();
    void simularPartida();
private:
    Janela2* calendario;

};

#endif // JANELA_H
