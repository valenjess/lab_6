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
    QPen pen2(Qt::green, 3, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);

    l.push_back(scene->addEllipse(Posiciones[0],Posiciones[1],Radios[0],Radios[0],pen1));
    l.push_back(scene->addEllipse(Posiciones[2],Posiciones[3],Radios[1],Radios[1],pen2));
    l.push_back(scene->addEllipse(Posiciones[4],Posiciones[5],Radios[2],Radios[2],pen2));

    ui->graphicsView->setScene(scene);
    ui->graphicsView->showMinimized();

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


float Cal_Distance(float Xpla,float Ypla, float XSun, float YSun )
{
    float Distance = 0;

    Distance = sqrt(pow((XSun-Xpla),2)+pow((YSun-Ypla),2));

    return Distance;

}

float Angulo(float Xpla,float Ypla, float XSun, float YSun){

    float angulo = 0;
    angulo = atan((YSun-Ypla)/(XSun-Xpla))*57,2958;

    return angulo;
}

void AceleraX(float Distance, float angulo){

    float AcelX = 0;
    float Gravity = 1;
    float MasaSun = 70000;

    AcelX = ((Gravity*MasaSun)/(pow(Distance,2)))*cos(angulo);
    cout<<AcelX;

}

void AceleraY(float Distance, float angulo){

    float AcelX = 0;
    float Gravity = 1;
    float MasaSun = 70000;

    AcelX = ((Gravity*MasaSun)/(pow(Distance,2)))*cos(angulo);
    cout<<AcelX;

}

Universe::~Universe()
{
    delete ui;
}

