#include "../include/Monster.h"

Monster::Monster(Map * map_):map(map_),life(650){
  posX = map->getStartPath().getX();
  posY = map->getStartPath().getY();
}
void Monster::draw(){
  GraphicPrimitives::drawFillTriangle2D((posX * 0.1f * (12/(float)map->getSize()) ) -0.6f +0.012f,(posY * 0.1f  * (12/(float)map->getSize()) ) -0.6f +0.012f,(posX * 0.1f * (12/(float)map->getSize()) ) -0.6f +0.07f+0.012f,(posY * 0.1f * (12/(float)map->getSize()) ) -0.6f +0.012f,(posX * 0.1f * (12/(float)map->getSize()) ) -0.6f +0.035f+0.012f,(posY * 0.1f * (12/(float)map->getSize()) ) -0.6f +0.07f+0.012f,r,g,b);
  GraphicPrimitives::drawFillRect2D((posX * 0.1f * (12/(float)map->getSize()) ) -0.6f +0.035f+0.012f-0.05f,(posY * 0.1f  * (12/(float)map->getSize()) ) -0.6f +0.07f+0.012f,0.1f*(12/(float)map->getSize()),0.01f,1.0f, 0.0f, 0.0f);
  GraphicPrimitives::drawFillRect2D((posX * 0.1f * (12/(float)map->getSize()) ) -0.6f +0.035f+0.012f-0.05f,(posY * 0.1f  * (12/(float)map->getSize()) ) -0.6f +0.07f+0.012f,(12/(float)map->getSize())*0.1 * (life)/650,0.01f,0.0f, 1.0f, 0.0f);
  GraphicPrimitives::drawOutlinedRect2D((posX * 0.1f * (12/(float)map->getSize()) ) -0.6f +0.035f+0.012f-0.05f,(posY * 0.1f  * (12/(float)map->getSize()) ) -0.6f +0.07f+0.012f,0.1f*(12/(float)map->getSize()),0.01f,0.0f, 0.0f, 0.0f);
}

void Monster::move(){
  if (posX < map->getSize() - 1) {
    if((map->getSquares())[posX+1][posY].getPath()){
      posX +=speed;
      travledDistance++;
    }
  }


  if (posY < map->getSize() - 1) {
    if((map->getSquares())[posX][posY+1].getPath()){
      posY +=speed;
      travledDistance++;
    }
  }
}

float Monster::getPosX(){
  return posX;
}
float Monster::getPosY(){
  return posY;
}
float Monster::getLife(){
  return life;
}
float Monster::getSpeed(){
  return speed;
}
int Monster::getCoins(){
  return coins;
}
std::string Monster::getLabel(){
  return label;
}
void Monster::setPosX(float posX_){
  posX = posX_;
}
void Monster::setPosY(float posY_){
  posY = posY_;
}
void Monster::setLife(float life_){
  life = life_;
}
void Monster::setSpeed(float speed_){
  if (speed_ < 0)
  speed = 0.0f;
  else
  speed = speed_;
}
int Monster::getTravled(){
  return travledDistance;
}
void Monster::setColor(float r_, float g_, float b_){
  r = r_;
  g = g_;
  b = b_;
}


Monster::~Monster(){}
