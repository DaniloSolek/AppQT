#include "pincel.h"
#include <QPainter>
#include <QDrag>
#include <QMimeData>
#include <QInputDialog>
#include <QPainter>
#include <QMessageBox>
#include <QDebug>

Pincel::Pincel(QWidget *parent) : QFrame(parent)
{
    setAcceptDrops(true);
}

void Pincel::posicionar(Itens* item, int posicao) {
    int altura = 23;
    int margemHorizontal = 8;
    int margemVertical = 3;
    item->setGeometry(8, this->height() - margemVertical - (posicao+1)*altura,
                      this->width() - 2*margemHorizontal, this->height()/23);
}

void Pincel::remover(int posicao){
        Itens* item = elenco[posicao];
        elenco.erase(elenco.cbegin() + posicao);
        delete item;
        for (unsigned int i=posicao; i < elenco.size(); i++) {
            item = elenco[i];
            this->posicionar(item,i);
        }
        this->update();
}

void Pincel::remover(Itens* item) {
    unsigned int i;
    for (i=0; i<elenco.size() && elenco[i] != item; i++);
    this->remover(i);
}

void Pincel::inserir(QString jogador) {
    Itens* item = new Itens(this);
    item->setJogador(jogador);
    this->posicionar(item, elenco.size());
    elenco.push_back(item);
    item->show();
}

int Pincel::tamanho(){
    return elenco.size();
}

void Pincel::loadElenco() {
    if(dados::getInstancia()->getTRtime() == "América-MG"){
        trElenco = new j_americamg;
    }
    if(dados::getInstancia()->getTRtime() == "Athletico-PR"){
        trElenco = new j_athleticopr;
    }
    if(dados::getInstancia()->getTRtime() == "Atlético-GO"){
        trElenco = new j_atleticogo;
    }
    if(dados::getInstancia()->getTRtime() == "Atlético-MG"){
        trElenco = new j_atleticomg;
    }
    if(dados::getInstancia()->getTRtime() == "Avaí"){
        trElenco = new j_avai;
    }
    if(dados::getInstancia()->getTRtime() == "Botafogo"){
        trElenco = new j_botafogo;
    }
    if(dados::getInstancia()->getTRtime() == "RB Bragantino"){
        trElenco = new j_rbbragantino;
    }
    if(dados::getInstancia()->getTRtime() == "Ceará"){
        trElenco = new j_ceara;
    }
    if(dados::getInstancia()->getTRtime() == "Corinthians"){
        trElenco = new j_corinthians;
    }
    if(dados::getInstancia()->getTRtime() == "Coritiba"){
        trElenco = new j_coritiba;
    }
    if(dados::getInstancia()->getTRtime() == "Cuiabá"){
        trElenco = new j_cuiaba;
    }
    if(dados::getInstancia()->getTRtime() == "Flamengo"){
        trElenco = new j_flamengo;
    }
    if(dados::getInstancia()->getTRtime() == "Fluminense"){
        trElenco = new j_fluminense;
    }
    if(dados::getInstancia()->getTRtime() == "Fortaleza"){
        trElenco = new j_fortaleza;
    }
    if(dados::getInstancia()->getTRtime() == "Goiás"){
        trElenco = new j_goias;
    }
    if(dados::getInstancia()->getTRtime() == "Internacional"){
        trElenco = new j_internacional;
    }
    if(dados::getInstancia()->getTRtime() == "Juventude"){
        trElenco = new j_juventude;
    }
    if(dados::getInstancia()->getTRtime() == "Palmeiras"){
        trElenco = new j_palmeiras;
    }
    if(dados::getInstancia()->getTRtime() == "Santos"){
        trElenco = new j_santos;
    }
    if(dados::getInstancia()->getTRtime() == "São Paulo"){
        trElenco = new j_saopaulo;
    }
    loadGK();
    loadZG();
    loadLD();
    loadLE();
    loadMC();
    loadAT();
    for(int i = 0; i<elenco.size(); i++){
        elenco[i]->show();
    }
}

void Pincel::loadGK(){
    for(int i = 0; i<3; i++){
        Itens* item = new Itens(this);
        item->setJogador(trElenco->getGK(i));
        this->posicionar(item, elenco.size());
        elenco.push_back(item);
    }
}

void Pincel::loadZG(){
    for(int i = 0; i<4; i++){
        Itens* item = new Itens(this);
        item->setJogador(trElenco->getZG(i));
        this->posicionar(item, elenco.size());
        elenco.push_back(item);
    }
}

void Pincel::loadLD(){
    for(int i = 0; i<2; i++){
        Itens* item = new Itens(this);
        item->setJogador(trElenco->getLD(i));
        this->posicionar(item, elenco.size());
        elenco.push_back(item);
    }
}

void Pincel::loadLE(){
    for(int i = 0; i<2; i++){
        Itens* item = new Itens(this);
        item->setJogador(trElenco->getLE(i));
        this->posicionar(item, elenco.size());
        elenco.push_back(item);
    }
}

void Pincel::loadMC(){
    for(int i = 0; i<7; i++){
        Itens* item = new Itens(this);
        item->setJogador(trElenco->getMC(i));
        this->posicionar(item, elenco.size());
        elenco.push_back(item);
    }
}

void Pincel::loadAT(){
    for(int i = 0; i<6; i++){
        Itens* item = new Itens(this);
        item->setJogador(trElenco->getAT(i));
        this->posicionar(item, elenco.size());
        elenco.push_back(item);
    }
}

void Pincel::paintEvent(QPaintEvent *event){
    Q_UNUSED(event);
    QPainter painter(this);

    painter.drawRect(this->rect().x(),
                     this->rect().y(),
                     this->rect().width()-1,
                     this->rect().height()-1);
}

void Pincel::mousePressEvent(QMouseEvent *event){
    if (event->button() == Qt::LeftButton) {
        QWidget* filho = this->childAt(event->pos());

        Itens* item = static_cast<Itens*>(filho);
        QByteArray itemData;
        QDataStream dataStream(&itemData, QIODevice::WriteOnly);
        dataStream << item->getJogador();
        QMimeData *mimeData = new QMimeData;
        mimeData->setData("application/x-dnditemdata", itemData);

        QDrag *drag = new QDrag(this);
        drag->setMimeData(mimeData);
        Qt::DropAction acao = drag->exec(Qt::MoveAction | Qt::IgnoreAction);

        if (acao == Qt::MoveAction){
            this->remover(item);
        }

    }
    this->update();
}

void Pincel::dragEnterEvent(QDragEnterEvent *event){
    if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
        if (event->source() == this) {
            event->setDropAction(Qt::IgnoreAction);
            event->accept();
        } else {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        }
    } else {
        event->ignore();
    }
}

void Pincel::dragMoveEvent(QDragMoveEvent *event){
    if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
        if (event->source() == this) {
            event->setDropAction(Qt::IgnoreAction);
            event->accept();
        } else {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        }
    } else {
        event->ignore();
    }
}

void Pincel::dropEvent(QDropEvent *event)
{
    if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
        if (event->source() == this) {
            event->setDropAction(Qt::IgnoreAction);
            event->accept();
        } else {
            QByteArray itemData = event->mimeData()->data("application/x-dnditemdata");
            QDataStream dataStream(&itemData, QIODevice::ReadOnly);

            QString jogador;
            dataStream >> jogador;

            this->inserir(jogador);
            this->update();

            event->setDropAction(Qt::MoveAction);
            event->accept();
        }
    } else {
        event->ignore();
    }
}
