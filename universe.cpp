#include "universe.h"
#include "ui_universe.h"


Universe::Universe(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Universe)
{
    ui->setupUi(this);
    scene = new QGraphicsScene;

    lectura();

    QPen pen1(Qt::yellow, 3, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);

    l.push_back(scene->addEllipse(Posiciones[0],Posiciones[1],Radios[0],Radios[0],pen1));

    ui->graphicsView->setScene(scene);
    ui->graphicsView->showFullScreen();

}

void Universe::lectura()
{
    string data,Sdata;
    float Ndata = 0;
    int elem=1;

    ifstream file;


    file.open(filename);

    if(!file.is_open()){

        cout<<" Error";
        exit(1);
    }

    string line;

    while(!file.eof()){

        getline(file,line);
        data += line;

        Sdata = "";
        for(int i=0; i<line.length(); i++){
            if(data[i]!=' ') {
               Sdata += data[i];
               if(i == line.length()-1){
                   Ndata = stod(Sdata.c_str());
                   Velocidades.push_back(Ndata);
                   elem = 1;
               }
            }
            else{
                if(elem == 1 || elem == 2){
                    Ndata = stod(Sdata.c_str());
                    Posiciones.push_back(Ndata);
                    elem++;
                }
                else if(elem == 3){
                    Ndata = stod(Sdata.c_str());
                    Radios.push_back(Ndata);
                    elem++;
                }
                else{
                    Ndata = stod(Sdata.c_str());
                    Velocidades.push_back(Ndata);
                    elem++;
                }

                Sdata = "";
            }

        }
     data = "";
    }


    file.close();

}


Universe::~Universe()
{
    delete ui;
}

