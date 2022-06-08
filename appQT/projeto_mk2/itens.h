#ifndef ITENS_H
#define ITENS_H

#include <QLabel>

class Itens : public QLabel
{
    QString Jogador;
public:
    Itens(QWidget* parent = nullptr);
    void paintEvent(QPaintEvent *event);
    void setJogador(QString j){
        Jogador = j;
    }
    QString getJogador(){
        return Jogador;
    }
};

#endif // ITENS_H
