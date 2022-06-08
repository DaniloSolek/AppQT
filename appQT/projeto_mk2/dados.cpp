#include "dados.h"

dados::dados()
{
    setForcas();
}

void dados::setForcas(){
    std::vector<int>f{4, 7, 6, 9, 3, 6, 7, 6, 8, 5,
                     5, 9, 7, 7, 4, 6, 4, 9, 6, 8};
    for(int i=0; i<f.size(); i++){
        forcas.insert(times[i], f[i]);
    }
}
int dados::getForcas(QString t){
    QMultiMap<QString, int>::iterator it = forcas.find(t);

    return it.value();
}
dados* dados::instancia = nullptr;

QString dados::trtime;

QString dados::nome;
