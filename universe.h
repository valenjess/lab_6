#ifndef UNIVERSE_H
#define UNIVERSE_H
//"../lab info II/lab_6/BD/data.txt"

#include <QMainWindow>
#include <QGraphicsScene>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class Universe; }
QT_END_NAMESPACE

class Universe : public QMainWindow
{
    Q_OBJECT

public:
    Universe(QWidget *parent = nullptr);

    void lectura();
    ~Universe();

private:
    QGraphicsScene *scene;
    string filename = "../lab_6/BD/data.txt";
    vector<int> Posiciones;
    vector<int> Radios;
    vector<float> Velocidades;
    std::list<QGraphicsEllipseItem *> l;

    Ui::Universe *ui;
};
#endif // UNIVERSE_H
