#include "janela.h"
#include "dados.h"
#include <QInputDialog>
#include <QStringList>
#include <QMessageBox>
#include <fstream>

Janela::Janela(QWidget *parent)
    : QMainWindow{parent}
{
    this->setGeometry(100, 100, 800, 600);
    this->setWindowTitle("Projeto QT");

    menu->addMenu(secaoMenu);
    menu->addMenu(secaoMenu2);
    this->setMenuBar(menu);

    secaoMenu->addAction(novo);
    secaoMenu->addAction(salvar);
    secaoMenu->addAction(abrir);
    secaoMenu2->addAction(datas);
    secaoMenu2->addAction(simular);

    connect(novo, SIGNAL(triggered(bool)), this, SLOT(novoJogo()));
    connect(salvar, SIGNAL(triggered(bool)), this, SLOT(salvarJogo()));
    connect(abrir, SIGNAL(triggered(bool)), this, SLOT(abrirJogo()));
    connect(datas, SIGNAL(triggered(bool)), this, SLOT(abrirCalendario()));
    connect(simular, SIGNAL(triggered(bool)), this, SLOT(simularPartida()));

}

void Janela::novoJogo(){
    QString entrada1 = QInputDialog::getText(this, "Nome", "Insira seu nome:");
    dados::getInstancia()->setNome(entrada1);

    QStringList opcoes;
    for(int i = 0; i<20; i++){
        opcoes << dados::getInstancia()->getTime(i);
    }
    QString entrada2 = QInputDialog::getItem(this, "Time", "Escolha seu time:", opcoes, 0, false);
    dados::getInstancia()->setTime(entrada2);

    loadJogo();
}

void Janela::salvarJogo(){
    std::fstream save("save.txt", std::fstream::out);
    save << dados::getInstancia()->getNome().toStdString()<<"\n";
    save << dados::getInstancia()->getTRtime().toStdString()<<"\n";
    save << QString::number(dados::getInstancia()->pontos).toStdString()<<"\n";
    save << QString::number(dados::getInstancia()->partidaN).toStdString()<<"\n";
    save.close();
}

void Janela::abrirJogo(){
    std::fstream save("save.txt", std::fstream::in);
    int linha=1;
    for(std::string dado; std::getline(save, dado); ){
        if(linha == 1){
            dados::getInstancia()->setNome(QString::fromStdString(dado));
        }
        if(linha == 2){
            dados::getInstancia()->setTime(QString::fromStdString(dado));
        }
        if(linha == 3){
            dados::getInstancia()->pontos = std::stoi(dado);
        }
        if(linha == 4){
            dados::getInstancia()->partidaN = std::stoi(dado);
        }
        linha++;
    }
    loadJogo();
}

void Janela::loadJogo(){
    Pincel* lista1 = new Pincel(this);
    Pincel* lista2 = new Pincel(this);
    load(lista1, 1);
    load(lista2, 2);

    calendario = new Janela2();
    connect(calendario, &Janela2::menu, this, &Janela::show);


    label1->setText("Nome: " + dados::getInstancia()->getNome());
    label1->setGeometry(410, 300, 390, 50);

    label2->setText("Time: " + dados::getInstancia()->getTRtime());
    label2->setGeometry(410, 350, 390, 50);

    label3->setText("Pontos: " + QString::number(dados::getInstancia()->pontos));
    label3->setGeometry(410, 400, 390, 50);

    novo->setEnabled(false);
    abrir->setEnabled(false);
}

void Janela::abrirCalendario(){
    if(!novo->isEnabled()){
        calendario->show();
    }else{
        QMessageBox alerta;
        alerta.setText("Não é possível acessar o calendário sem estar em jogo");
        alerta.exec();
    }
}

void Janela::simularPartida(){
    try{
        int s1, s2;
        int v1, v2;
        v1 = dados::getInstancia()->getForcas(dados::getInstancia()->getTRtime());
        v2 = dados::getInstancia()->getForcas(dados::getInstancia()->getTime(dados::getInstancia()->partidaN));
        if(dados::getInstancia()->partidaN == 19){
            simular->setEnabled(false);
        }
        if(!novo->isEnabled()){
            if(lTitulares->tamanho() != 11){
                throw -1;
            }
            if(dados::getInstancia()->getTRtime() != dados::getInstancia()->getTime(dados::getInstancia()->partidaN)){
                QStringList estrategias{"Ataque Total", "Equilibrado", "Contra-Ataque"};
                QString estrategia = QInputDialog::getItem(this, "Estratégia", "Escolha seu estilo de jogo: ", estrategias, 0, false);
                int estrategiaAdv = rand()%2;
                int vantagem = 0, vantagemAdv = 0;
                if(estrategia == "Ataque Total" && estrategiaAdv == 1)
                    vantagem++;
                else if(estrategia == "Ataque Total" && estrategiaAdv == 2)
                    vantagemAdv++;
                else if(estrategia == "Equilibrado" && estrategiaAdv == 0)
                    vantagemAdv++;
                else if(estrategia == "Equilibrado" && estrategiaAdv == 2)
                    vantagem++;
                else if(estrategia == "Contra-Ataque" && estrategiaAdv == 0)
                    vantagem++;
                else if(estrategia == "Contra-Ataque" && estrategiaAdv == 1)
                    vantagemAdv++;

                if(v1 == v2){
                    s1 = vantagem + rand()% 3;
                    s2 = vantagemAdv + rand()% 3;
                }
                if(v1 > v2){
                    s1 = vantagem + rand()% 4;
                    s2 = vantagemAdv + rand()% 3;
                }
                if(v1 < v2){
                    s1 = vantagem + rand()% 3;
                    s2 = vantagemAdv + rand()% 4;
                }

                //qDebug()<<estrategia<<" x "<<estrategias[estrategiaAdv]<<"\n"<<
                //          vantagem<<" x "<< vantagemAdv<<"\n"<<
                //          v1<<" x "<< v2<<"\n"<<s1<<" x "<<s2;

                QString t1 = QString::number(s1);
                QString t2 = QString::number(s2);
                QMessageBox partida;
                partida.setText("Resultado: "
                                +
                                dados::getInstancia()->getTRtime()
                                + " " +
                                t1 + " x " + t2
                                + " " +
                                dados::getInstancia()->getTime(dados::getInstancia()->partidaN));

                if(s1>s2)
                    for(int i = 0; i<3; i++)
                        dados::getInstancia()->pontos++;
                if(s1==s2)
                    dados::getInstancia()->pontos++;
                QString pontuacao = QString::number(dados::getInstancia()->pontos);
                label3->setText("Pontos: " + pontuacao);
                dados::getInstancia()->partidaN++;
                partida.exec();
            }else{
                dados::getInstancia()->partidaN++;
                simularPartida();
            }

        }else{
            throw -2;
        }
    }catch(int erro){
        if(erro == -1){
            QMessageBox alerta;
            alerta.setText("Escale 11 jogadores");
            alerta.exec();
        }
        if(erro == -2){
            QMessageBox alerta;
            alerta.setText("Não é possível simular sem estar em jogo");
            alerta.exec();
        }
    }
}

void Janela::load(Pincel* lista, int i){
    int margem = 10;
    int largura = (this->width() - 3*margem)/2;
    int altura = this->height()-this->menuBar()->height() - 2*margem;

    if(i == 1){
        lJogadores = lista;
        lJogadores->setGeometry((i-1)*largura + i*margem,
                                this->menuBar()->height() + margem,
                                largura,
                                altura/i);
        lJogadores->show();
        lJogadores->loadElenco();
    }else if(i == 2){
        lTitulares = lista;
        lTitulares->setGeometry((i-1)*largura + i*margem,
                                this->menuBar()->height() + margem,
                                largura,
                                altura/i);
        lTitulares->show();
    }

}

