#include "planeta.h"

Planeta::Planeta(float PosIniX,float PosIniY, float VeloIniX, float VeloIniY)
{
    this->PosIniX = PosIniX;
    this->PosIniY = PosIniY;
    this->VeloIniX = VeloIniX;
    this->VeloIniY = VeloIniY;
}

float Planeta::getVeloIniX()
{
    return this->VeloIniX;
}

void Planeta::Cal_Distance(float XSun, float YSun)
{

    Distance = sqrt(pow((XSun-PosX),2)+pow((YSun-PosY),2));
}

void Planeta::Cal_Angulo(float XSun, float YSun)
{

    Angulo = atan((YSun-PosY)/(XSun-PosX))*57,2958;
}

void Planeta::AceleraX()
{
    AcelX = ((Gravity*MasaSun)/(pow(Distance,2)))*cos(Angulo);
}

void Planeta::AceleraY()
{
    AcelY = ((Gravity*MasaSun)/(pow(Distance,2)))*sin(Angulo);
}

void Planeta::Velo_X( float tiempo)
{
    VeloX = VeloIniX + AcelX*tiempo;
}

void Planeta::Velo_Y(float tiempo)
{
    VeloY = VeloIniY + AcelY*tiempo;
}

void Planeta::Pos_X()
{
    PosX = PosIniX + VeloX*tiempo +(AcelX*(pow(tiempo,2)))/2;
}

void Planeta::Pos_Y(float tiempo)
{
    PosY = PosIniY + VeloY*tiempo +(AcelY*(pow(tiempo,2)))/2;
}

float Planeta::getPosX()
{
    return PosX;
}

float Planeta::getPosY()
{
    return PosY;
}



