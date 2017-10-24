#include "../include/Missile.h"

Missile::Missile(float x1_,float y1_,float x2_,float y2_):x1(x1_),y1(y1_),x2(x2_),y2(y2_){}

void Missile::draw(float r, float g, float b){
  GraphicPrimitives::drawLine2D(x1 * 0.1f -0.6f +0.05f,y1 * 0.1f -0.6f +0.05f,x2 * 0.1f -0.6f +0.05f,y2 * 0.1f -0.6f +0.05f,r,g,b);
}

void Missile::move(float x ,float y){
  x2 = x;
  y2 = y;
}

Missile::~Missile()
{
}
