#include "janela2.h"

Janela2::Janela2(QWidget *parent)
    : QWidget{parent}
{
    this->setGeometry(100, 100, 800, 600);
    this->setWindowTitle("Calendário");

    botao_fechar = new QPushButton("Fechar", this);
    botao_fechar->setGeometry(350, 550, 100, 40);
    connect(botao_fechar, SIGNAL(clicked(bool)),
            this, SLOT(fechar()));
    partidas->setGeometry(10, 10, 780, 500);

    for(int i = 0; i<20; i++){
        if(dados::getInstancia()->getTime(i) != dados::getInstancia()->getTRtime()){
            partidas->insertItem(i,
                                 dados::getInstancia()->getTRtime()
                                 +
                                 " x "
                                 +
                                 dados::getInstancia()->getTime(i));
            }
        }

}

void Janela2::fechar(){
    this->close();
}
