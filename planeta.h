#ifndef PLANETA_H
#define PLANETA_H
#include <math.h>


class Planeta
{
private:
    float PosIniX;
    float PosIniY;
    float PosX;
    float PosY;
    float VeloIniX;
    float VeloIniY;
    float Gravity = 1;
    float MasaSun = 70000;
    float Distance;
    float Angulo;
    float AcelX;
    float AcelY;
    float VeloX;
    float VeloY;
    float tiempo = 1;

public:
    Planeta(float PosIniX,float PosIniY, float VeloIniX,float VeloIniY);
    float getVeloIniX();
    void  Cal_Distance(float XSun, float YSun );
    void  Cal_Angulo(float XSun, float YSun);
    void  AceleraX();
    void  AceleraY();
    void  Velo_X();
    void  Velo_Y();
    void  Pos_X();
    void  Pos_Y();
    float getPosX();
    float getPosY();
};

#endif // PLANETA_H
