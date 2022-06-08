#ifndef JANELA2_H
#define JANELA2_H

#include <QWidget>
#include <QPushButton>
#include <QListWidget>
#include "dados.h"

class Janela2 : public QWidget
{
    Q_OBJECT
    QListWidget* partidas = new QListWidget(this);

public:
    explicit Janela2(QWidget *parent = nullptr);
    QPushButton *botao_fechar;
signals:
    void menu();

public slots:
    void fechar();
};

#endif // JANELA2_H
