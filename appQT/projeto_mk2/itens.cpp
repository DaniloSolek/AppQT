#include "itens.h"
#include "dados.h"
#include <QPainter>

Itens::Itens(QWidget *parent) : QLabel(parent)
{

}

void Itens::paintEvent(QPaintEvent *event){
    QPainter painter(this);

    painter.fillRect(rect(), Qt::lightGray);
    painter.drawText(this->rect(), Qt::AlignCenter, Jogador);

    painter.drawRect(this->rect().x(),
                     this->rect().y(),
                     this->rect().width()-1,
                     this->rect().height()-1);


}
