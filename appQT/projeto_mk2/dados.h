#ifndef DADOS_H
#define DADOS_H

#include <QFrame>
#include <QMultiMap>
#include <vector>
#include <QMultiMap>

class dados : public QFrame
{
    static QString trtime;
    static QString nome;
    std::vector<QString> times{"América-MG",
                               "Athletico-PR",
                               "Atlético-GO",
                               "Atlético-MG",
                               "Avaí",
                               "Botafogo",
                               "RB Bragantino",
                               "Ceará",
                               "Corinthians",
                               "Coritiba",
                               "Cuiabá",
                               "Flamengo",
                               "Fluminense",
                               "Fortaleza",
                               "Goiás",
                               "Internacional",
                               "Juventude",
                               "Palmeiras",
                               "Santos",
                               "São Paulo"};
    static dados* instancia;
    dados();
    QMultiMap<QString, int> forcas;
public:
    static dados* getInstancia(){
        if(instancia == nullptr){
            instancia = new dados();
        }
        return instancia;
    }

    QString getTime(int posicao){
        return times[posicao];
    }
    static void setTime(QString time){
        trtime = time;
    }
    static QString getTRtime(){
        return trtime;
    }
    static void setNome(QString entrada){
        nome = entrada;
    }
    static QString getNome(){
        return nome;
    }
    void setForcas();
    int getForcas(QString t);
    int partidaN = 0;
    int pontos = 0;

};

class jogadores{
public:
    virtual QString getGK(int x) = 0;
    virtual QString getZG(int x) = 0;
    virtual QString getLD(int x) = 0;
    virtual QString getLE(int x) = 0;
    virtual QString getMC(int x) = 0;
    virtual QString getAT(int x) = 0;
};

class j_americamg : public jogadores{
    std::vector<QString> gk{"Jailson",
                            "Jori",
                            "Matheus Cavichioli"};
    std::vector<QString> zg{"Germán Conti",
                            "Éder",
                            "Iago Maidana",
                            "Luan Patrick"};
    std::vector<QString> ld{"Patric",
                            "Raúl Cáceres"};
    std::vector<QString> le{"Danilo Avelar",
                            "João Paulo"};
    std::vector<QString> mc{"Zé Ricardo",
                            "Lucas Kal",
                            "Juninho",
                            "Juninho Valoura",
                            "Juan Pablo Ramírez",
                            "Matheusinho",
                            "Alê"};
    std::vector<QString> at{"Pedrinho",
                            "Paulinho Bóia",
                            "Everaldo",
                            "Felipe Azevedo",
                            "Orlando Berrío",
                            "Henrique Almeida"};
public:
    QString getGK(int x){
        return gk[x];
    }
    QString getZG(int x){
        return zg[x];
    }
    QString getLD(int x){
        return ld[x];
    }
    QString getLE(int x){
        return le[x];
    }
    QString getMC(int x){
        return mc[x];
    }
    QString getAT(int x){
        return at[x];
    }
};

class j_athleticopr : public jogadores{
    std::vector<QString> gk{"Bento",
                            "Anderson Paixão",
                            "Leo Linck"};
    std::vector<QString> zg{"Lucas Halter",
                            "Pedro Henrique",
                            "Lucas Fasson",
                            "Thiago Heleno"};
    std::vector<QString> ld{"Khellven",
                            "Luis Orejuela"};
    std::vector<QString> le{"Abner",
                            "Pedrinho"};
    std::vector<QString> mc{"Hugo Moura",
                            "Christian",
                            "Pablo Siles",
                            "Erick",
                            "Matheus Fernandes",
                            "David Terans",
                            "Bryan García"};
    std::vector<QString> at{"Vitinho",
                            "Tomás Cuello",
                            "Matheus Babi",
                            "Pablo",
                            "Vitor Bueno",
                            "Rômulo"};
public:
    QString getGK(int x){
        return gk[x];
    }
    QString getZG(int x){
        return zg[x];
    }
    QString getLD(int x){
        return ld[x];
    }
    QString getLE(int x){
        return le[x];
    }
    QString getMC(int x){
        return mc[x];
    }
    QString getAT(int x){
        return at[x];
    }
};

class j_atleticogo : public jogadores{
    std::vector<QString> gk{"Ronaldo",
                            "Luan Polli",
                            "Renan"};
    std::vector<QString> zg{"Gabriel Noga",
                            "Ramon Menezes",
                            "Wanderson",
                            "Michel"};
    std::vector<QString> ld{"Dudu",
                            "Hayner"};
    std::vector<QString> le{"Arthur Henrique",
                            "Jefferson"};
    std::vector<QString> mc{"Marlon Freitas",
                            "Édson",
                            "Rickson",
                            "Gabriel Baralhas",
                            "Jorginho",
                            "Shaylon",
                            "Edson Fernando"};
    std::vector<QString> at{"Wellington Rato",
                            "Airton",
                            "Léo Pereira",
                            "Brian Montenegro",
                            "Leandro Barcia",
                            "Diego Churín"};
public:
    QString getGK(int x){
        return gk[x];
    }
    QString getZG(int x){
        return zg[x];
    }
    QString getLD(int x){
        return ld[x];
    }
    QString getLE(int x){
        return le[x];
    }
    QString getMC(int x){
        return mc[x];
    }
    QString getAT(int x){
        return at[x];
    }
};

class j_atleticomg : public jogadores{
    std::vector<QString> gk{"Everson",
                            "Rafael",
                            "Matheus Mendes"};
    std::vector<QString> zg{"Nathan Silva",
                            "Júnior Alonso",
                            "Igor Rabello",
                            "Réver"};
    std::vector<QString> ld{"Guga",
                            "Mariano"};
    std::vector<QString> le{"Dodô",
                            "Guilherme Arana"};
    std::vector<QString> mc{"Otávio",
                            "Jair",
                            "Neto",
                            "Allan",
                            "Rubens",
                            "Matías Zaracho",
                            "Nacho Fernández"};
    std::vector<QString> at{"Keno",
                            "Fábio",
                            "Ademir",
                            "Hulk",
                            "Eduardo Sasha",
                            "Eduardo Vargas"};
public:
    QString getGK(int x){
        return gk[x];
    }
    QString getZG(int x){
        return zg[x];
    }
    QString getLD(int x){
        return ld[x];
    }
    QString getLE(int x){
        return le[x];
    }
    QString getMC(int x){
        return mc[x];
    }
    QString getAT(int x){
        return at[x];
    }
};

class j_avai : public jogadores{
    std::vector<QString> gk{"Douglas Friedrich",
                            "Vladimir",
                            "Glédson"};
    std::vector<QString> zg{"Bressan",
                            "Rodrigo Freitas",
                            "Betão",
                            "Raniele"};
    std::vector<QString> ld{"Kevin",
                            "Matheus Ribeiro"};
    std::vector<QString> le{"Ayrton Cougo",
                            "Bruno Cortez"};
    std::vector<QString> mc{"Lucas Ventura",
                            "Kazu",
                            "Matheus Galdezani",
                            "Bruno Silva",
                            "Jean Cleber",
                            "Jean Pyerre",
                            "Renato"};
    std::vector<QString> at{"Jonathan Copete",
                            "Muriqui",
                            "Rômulo",
                            "Willian Pottker",
                            "Morato",
                            "Bissoli"};
public:
    QString getGK(int x){
        return gk[x];
    }
    QString getZG(int x){
        return zg[x];
    }
    QString getLD(int x){
        return ld[x];
    }
    QString getLE(int x){
        return le[x];
    }
    QString getMC(int x){
        return mc[x];
    }
    QString getAT(int x){
        return at[x];
    }
};

class j_botafogo : public jogadores{
    std::vector<QString> gk{"Gatito Fernández",
                            "Diego Loureiro",
                            "Douglas Borges"};
    std::vector<QString> zg{"Victor Cuesta",
                            "Kanu",
                            "Philipe Sampaio",
                            "Klaus"};
    std::vector<QString> ld{"Renzo Saravia",
                            "Rafael"};
    std::vector<QString> le{"Jonathan Silva",
                            "Niko Hamalainen"};
    std::vector<QString> mc{"Breno",
                            "Luís Oyama",
                            "Barreto",
                            "Patrick de Paula",
                            "Tchê Tchê",
                            "Lucas Piazon",
                            "Chay"};
    std::vector<QString> at{"Victor Sá",
                            "Gustavo Sauer",
                            "Vinícius Lopes",
                            "Erison",
                            "Matheus Nascimento",
                            "Diego Gonçalves"};
public:
    QString getGK(int x){
        return gk[x];
    }
    QString getZG(int x){
        return zg[x];
    }
    QString getLD(int x){
        return ld[x];
    }
    QString getLE(int x){
        return le[x];
    }
    QString getMC(int x){
        return mc[x];
    }
    QString getAT(int x){
        return at[x];
    }
};

class j_rbbragantino : public jogadores{
    std::vector<QString> gk{"Cleiton",
                            "Lucão",
                            "Júlio César"};
    std::vector<QString> zg{"Renan",
                            "Léo Ortiz",
                            "Natan",
                            "Léo Realpe"};
    std::vector<QString> ld{"José Hurtado",
                            "Aderlan"};
    std::vector<QString> le{"Luan Cândido",
                            "Ramon"};
    std::vector<QString> mc{"Jadsom",
                            "Raul",
                            "Eric Ramires",
                            "Lucas Evangelista",
                            "Bruno Praxedes",
                            "Hyoran",
                            "Miguel"};
    std::vector<QString> at{"Bruno Tubarão",
                            "Ytalo",
                            "Artur",
                            "Helinho",
                            "Alerrandro",
                            "Sorriso"};
public:
    QString getGK(int x){
        return gk[x];
    }
    QString getZG(int x){
        return zg[x];
    }
    QString getLD(int x){
        return ld[x];
    }
    QString getLE(int x){
        return le[x];
    }
    QString getMC(int x){
        return mc[x];
    }
    QString getAT(int x){
        return at[x];
    }
};

class j_ceara : public jogadores{
    std::vector<QString> gk{"Richard",
                            "João Ricardo",
                            "Vinicius Machado"};
    std::vector<QString> zg{"Lucas Ribeiro",
                            "Messias",
                            "Gabriel Lacerda",
                            "Luiz Otávio"};
    std::vector<QString> ld{"Michel Macedo",
                            "Nino Paraíba"};
    std::vector<QString> le{"Victor Luis",
                            "Bruno Pacheco"};
    std::vector<QString> mc{"Richard",
                            "Rodrigo Lindoso",
                            "Richardson",
                            "Fernando Sobral",
                            "Vina",
                            "Wescley",
                            "Geovane"};
    std::vector<QString> at{"Stiven Mendoza",
                            "Lima",
                            "Erick",
                            "Matheus Peixoto",
                            "Cléber",
                            "Jael"};
public:
    QString getGK(int x){
        return gk[x];
    }
    QString getZG(int x){
        return zg[x];
    }
    QString getLD(int x){
        return ld[x];
    }
    QString getLE(int x){
        return le[x];
    }
    QString getMC(int x){
        return mc[x];
    }
    QString getAT(int x){
        return at[x];
    }
};

class j_corinthians : public jogadores{
    std::vector<QString> gk{"Cássio",
                            "Ivan",
                            "Matheus Donelli"};
    std::vector<QString> zg{"João Victor",
                            "Robson Bambu",
                            "Gil",
                            "Raul Gustavo"};
    std::vector<QString> ld{"Fágner",
                            "João Pedro"};
    std::vector<QString> le{"Lucas Piton",
                            "Fábio Santos"};
    std::vector<QString> mc{"Víctor Cantillo",
                            "Du Queiroz",
                            "Xavier",
                            "Paulinho",
                            "Renato Augusto",
                            "Roni",
                            "Giuliano"};
    std::vector<QString> at{"Róger Guedes",
                            "Willian",
                            "Gustavo Mantuan",
                            "Gustavo Mosquito",
                            "Jô",
                            "Adson"};
public:
    QString getGK(int x){
        return gk[x];
    }
    QString getZG(int x){
        return zg[x];
    }
    QString getLD(int x){
        return ld[x];
    }
    QString getLE(int x){
        return le[x];
    }
    QString getMC(int x){
        return mc[x];
    }
    QString getAT(int x){
        return at[x];
    }
};

class j_coritiba : public jogadores{
    std::vector<QString> gk{"Alex Muralha",
                            "Rafael William",
                            "Marcão"};
    std::vector<QString> zg{"Guillermo de los Santos",
                            "Luciano Castan",
                            "Henrique",
                            "Márcio Silva"};
    std::vector<QString> ld{"Natanael",
                            "Matheus Alexandre"};
    std::vector<QString> le{"Egídio",
                            "Guilherme Biro"};
    std::vector<QString> mc{"Andrey",
                            "Val",
                            "Willian Farias",
                            "Thonny Anderson",
                            "Régis",
                            "Robinho",
                            "Matías Galarza"};
    std::vector<QString> at{"Alef Manga",
                            "Igor Paixão",
                            "Pablo García",
                            "Warley",
                            "Léo Gamalho",
                            "Neílton"};
public:
    QString getGK(int x){
        return gk[x];
    }
    QString getZG(int x){
        return zg[x];
    }
    QString getLD(int x){
        return ld[x];
    }
    QString getLE(int x){
        return le[x];
    }
    QString getMC(int x){
        return mc[x];
    }
    QString getAT(int x){
        return at[x];
    }
};

class j_cuiaba : public jogadores{
    std::vector<QString> gk{"Walter",
                            "João Carlos",
                            "Vinicius"};
    std::vector<QString> zg{"Alan Empeureur",
                            "Marllon",
                            "Paulão",
                            "Joaquim"};
    std::vector<QString> ld{"João Lucas",
                            "Daniel Guedes"};
    std::vector<QString> le{"Uendel",
                            "Igor Cariús"};
    std::vector<QString> mc{"Marcão Silva",
                            "Christian Rivas",
                            "Rafael Gava",
                            "Pepê",
                            "Rodriguinho",
                            "Kelvin Osorio",
                            "Valdívia"};
    std::vector<QString> at{"Marquinhos",
                            "Éverton",
                            "Felipe Marques",
                            "Jonathan Cafú",
                            "Élton",
                            "Jenison"};
public:
    QString getGK(int x){
        return gk[x];
    }
    QString getZG(int x){
        return zg[x];
    }
    QString getLD(int x){
        return ld[x];
    }
    QString getLE(int x){
        return le[x];
    }
    QString getMC(int x){
        return mc[x];
    }
    QString getAT(int x){
        return at[x];
    }
};

class j_flamengo : public jogadores{
    std::vector<QString> gk{"Hugo Souza",
                            "Santos",
                            "Diego Alves"};
    std::vector<QString> zg{"Pablo",
                            "Rodrigo Caio",
                            "Fabrício Bruno",
                            "David Luís"};
    std::vector<QString> ld{"Matheuzinho",
                            "Mauricio Isla"};
    std::vector<QString> le{"Ayrton Lucas",
                            "Filipe Luís"};
    std::vector<QString> mc{"João Gomes",
                            "Willian Arão",
                            "Thiago Maia",
                            "Andreas Pereira",
                            "Giorgian de Arrascaeta",
                            "Diego",
                            "Éverton Ribeiro"};
    std::vector<QString> at{"Bruno Henrique",
                            "Vitinho",
                            "Marinho",
                            "Pedro",
                            "Gabriel Barbosa",
                            "Lázaro"};
public:
    QString getGK(int x){
        return gk[x];
    }
    QString getZG(int x){
        return zg[x];
    }
    QString getLD(int x){
        return ld[x];
    }
    QString getLE(int x){
        return le[x];
    }
    QString getMC(int x){
        return mc[x];
    }
    QString getAT(int x){
        return at[x];
    }
};

class j_fluminense : public jogadores{
    std::vector<QString> gk{"Marcos Felipe",
                            "Muriel",
                            "Fábio"};
    std::vector<QString> zg{"Nino",
                            "David Braz",
                            "Manoel",
                            "Luccas Claro"};
    std::vector<QString> ld{"Calegari",
                            "Samuel Xavier"};
    std::vector<QString> le{"Marlon",
                            "Cris Silva"};
    std::vector<QString> mc{"André",
                            "Wellington",
                            "Felipe Melo",
                            "Martinelli",
                            "Yago Felipe",
                            "Nonato",
                            "Ganso"};
    std::vector<QString> at{"Matheus Martins",
                            "Luiz Henrique",
                            "Jhon Arias",
                            "Germán Cano",
                            "Fred",
                            "Willian"};
public:
    QString getGK(int x){
        return gk[x];
    }
    QString getZG(int x){
        return zg[x];
    }
    QString getLD(int x){
        return ld[x];
    }
    QString getLE(int x){
        return le[x];
    }
    QString getMC(int x){
        return mc[x];
    }
    QString getAT(int x){
        return at[x];
    }
};

class j_fortaleza : public jogadores{
    std::vector<QString> gk{"Fernando Miguel",
                            "Marcelo Boeck",
                            "Max Walef"};
    std::vector<QString> zg{"Marcelo Benevenuto",
                            "Tinga",
                            "Titi",
                            "Brayan Ceballos"};
    std::vector<QString> ld{"Anthony Landázuri",
                            "Vitor Ricardo"};
    std::vector<QString> le{"Juninho Capixaba",
                            "Breninho"};
    std::vector<QString> mc{"Felipe",
                            "Matheus Jussa",
                            "Ronald",
                            "Yago Pikachu",
                            "Lucas Crispim",
                            "Matheus Vargas",
                            "Lucas Lima"};
    std::vector<QString> at{"Romarinho",
                            "Moisés",
                            "Robson",
                            "Renato Kayzer",
                            "Silvio Romero",
                            "Igor Torres"};
public:
    QString getGK(int x){
        return gk[x];
    }
    QString getZG(int x){
        return zg[x];
    }
    QString getLD(int x){
        return ld[x];
    }
    QString getLE(int x){
        return le[x];
    }
    QString getMC(int x){
        return mc[x];
    }
    QString getAT(int x){
        return at[x];
    }
};

class j_goias : public jogadores{
    std::vector<QString> gk{"Tadeu",
                            "Marcelo Rangel",
                            "Matheus Alves"};
    std::vector<QString> zg{"Sidnei",
                            "Reynaldo",
                            "Sidimar",
                            "Caetano"};
    std::vector<QString> ld{"Maguinho",
                            "Diego"};
    std::vector<QString> le{"Danilo Barcelos",
                            "Hugo"};
    std::vector<QString> mc{"Caio Vinicius",
                            "Matheus Sales",
                            "Auremir",
                            "Fellipe Bastos",
                            "Élvis",
                            "Nathan",
                            "Henrique Lordelo"};
    std::vector<QString> at{"Vinícius",
                            "Apodi",
                            "Pedro Raul",
                            "Nícolas",
                            "Renato Júnior",
                            "Dadá Belmonte"};
public:
    QString getGK(int x){
        return gk[x];
    }
    QString getZG(int x){
        return zg[x];
    }
    QString getLD(int x){
        return ld[x];
    }
    QString getLE(int x){
        return le[x];
    }
    QString getMC(int x){
        return mc[x];
    }
    QString getAT(int x){
        return at[x];
    }
};

class j_internacional : public jogadores{
    std::vector<QString> gk{"Daniel",
                            "Keiller",
                            "Anthoni"};
    std::vector<QString> zg{"Bruno Méndez",
                            "Vitão",
                            "Kaique Rocha",
                            "Rodrigo Moledo"};
    std::vector<QString> ld{"Fabricio Bustos",
                            "Heitor"};
    std::vector<QString> le{"Paulo Victor",
                            "Moisés"};
    std::vector<QString> mc{"Rodrigo Dourado",
                            "Gabriel",
                            "Bruno Gomes",
                            "Liziero",
                            "Alan Patrick",
                            "Gabriel Boschilia",
                            "Mauricio"};
    std::vector<QString> at{"Taison",
                            "David",
                            "Wesley",
                            "Wanderson",
                            "Alemão",
                            "Caio Vidal"};
public:
    QString getGK(int x){
        return gk[x];
    }
    QString getZG(int x){
        return zg[x];
    }
    QString getLD(int x){
        return ld[x];
    }
    QString getLE(int x){
        return le[x];
    }
    QString getMC(int x){
        return mc[x];
    }
    QString getAT(int x){
        return at[x];
    }
};

class j_juventude : public jogadores{
    std::vector<QString> gk{"Felipe Alves",
                            "César Reis",
                            "Willian"};
    std::vector<QString> zg{"Rafael Forster",
                            "Vitor Mendes",
                            "Thalisson",
                            "Paulo Miranda"};
    std::vector<QString> ld{"Rodrigo Soares",
                            "Paulo Henrique"};
    std::vector<QString> le{"Busanello",
                            "Willian Matheus"};
    std::vector<QString> mc{"Yuri",
                            "Elton",
                            "Darlan",
                            "Jádson",
                            "Marlon",
                            "Bruninho",
                            "Chico"};
    std::vector<QString> at{"Capixaba",
                            "Paulinho Moccelin",
                            "Guilherme Parede",
                            "Vitor Gabriel",
                            "Ricardo Bueno",
                            "Isidro Pitta"};
public:
    QString getGK(int x){
        return gk[x];
    }
    QString getZG(int x){
        return zg[x];
    }
    QString getLD(int x){
        return ld[x];
    }
    QString getLE(int x){
        return le[x];
    }
    QString getMC(int x){
        return mc[x];
    }
    QString getAT(int x){
        return at[x];
    }
};

class j_palmeiras : public jogadores{
    std::vector<QString> gk{"Weverton",
                            "Marcelo Lomba",
                            "Vinicius Silvestre"};
    std::vector<QString> zg{"Gustavo Gómez",
                            "Luan",
                            "Murilo Cerqueira",
                            "Henri"};
    std::vector<QString> ld{"Marcos Rocha",
                            "Mayke"};
    std::vector<QString> le{"Jorge",
                            "Joaquín Piquerez"};
    std::vector<QString> mc{"Danilo",
                            "Jailson",
                            "Gabriel Menino",
                            "Zé Rafael",
                            "Raphael Veiga",
                            "Gustavo Scarpa",
                            "Eduard Atuesta"};
    std::vector<QString> at{"Dudu",
                            "Wesley",
                            "Gabriel Veron",
                            "Rony",
                            "Rafael Navarro",
                            "Deyverson"};
public:
    QString getGK(int x){
        return gk[x];
    }
    QString getZG(int x){
        return zg[x];
    }
    QString getLD(int x){
        return ld[x];
    }
    QString getLE(int x){
        return le[x];
    }
    QString getMC(int x){
        return mc[x];
    }
    QString getAT(int x){
        return at[x];
    }
};

class j_santos : public jogadores{
    std::vector<QString> gk{"João Paulo",
                            "John",
                            "Paulo Mazoti"};
    std::vector<QString> zg{"Kaiky",
                            "Eduardo Bauermann",
                            "Luiz Felipe",
                            "Maicon"};
    std::vector<QString> ld{"Auro Jr.",
                            "Madson"};
    std::vector<QString> le{"Felipe Jonatan",
                            "Lucas Pires"};
    std::vector<QString> mc{"Sandry",
                            "Vinicius Zanocelo",
                            "Jhojan Julio",
                            "Carlos Sánchez",
                            "Bruno Oliveira",
                            "Gabriel Pirani",
                            "Guilherme Camacho"};
    std::vector<QString> at{"Marcos Guilherme",
                            "Lucas Braga",
                            "Ângelo Gabriel",
                            "Reyner",
                            "Marcos Leonardo",
                            "Bryan Angulo"};
public:
    QString getGK(int x){
        return gk[x];
    }
    QString getZG(int x){
        return zg[x];
    }
    QString getLD(int x){
        return ld[x];
    }
    QString getLE(int x){
        return le[x];
    }
    QString getMC(int x){
        return mc[x];
    }
    QString getAT(int x){
        return at[x];
    }
};

class j_saopaulo : public jogadores{
    std::vector<QString> gk{"Tiago Volpi",
                            "Jandrei",
                            "Thiago Couto"};
    std::vector<QString> zg{"Léo",
                            "Diego Costa",
                            "Miranda",
                            "Robert Arboleda"};
    std::vector<QString> ld{"Igor Vinícius",
                            "Rafinha"};
    std::vector<QString> le{"Welington",
                            "Reinaldo"};
    std::vector<QString> mc{"Luan",
                            "Pablo Maia",
                            "Rodrigo Nestor",
                            "Patrick",
                            "Talles Costa",
                            "Igor Gomes",
                            "Gabriel Sara"};
    std::vector<QString> at{"Alisson",
                            "Jonas Toró",
                            "Luciano",
                            "Calleri",
                            "Marquinhos",
                            "Rigoni"};
public:
    QString getGK(int x){
        return gk[x];
    }
    QString getZG(int x){
        return zg[x];
    }
    QString getLD(int x){
        return ld[x];
    }
    QString getLE(int x){
        return le[x];
    }
    QString getMC(int x){
        return mc[x];
    }
    QString getAT(int x){
        return at[x];
    }
};


#endif // DADOS_H
