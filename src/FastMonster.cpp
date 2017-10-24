#include "../include/FastMonster.h"

FastMonster::FastMonster(Map * map):Monster(map){
  setColor(0.5f,0.0f,0.0f);
  speed = 0.015f;
  coins = 50;
}

void FastMonster::ReceiveDamage(float damage){
  life -= damage;
}

void FastMonster::draw(){
  Monster::draw();
}

FastMonster::~FastMonster(){}
