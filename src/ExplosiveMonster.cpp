#include "../include/ExplosiveMonster.h"

ExplosiveMonster::ExplosiveMonster(Map * map):Monster(map){
  label = "ExplosiveMonster";
  setColor(1, 0.498, 0.314);
  speed = 0.01f;
  coins = 50;
}

void ExplosiveMonster::ReceiveDamage(float damage){
  life -= damage;
}

void ExplosiveMonster::draw(){
  Monster::draw();
  if (life < 300) {
    setColor(r,g - 0.005,b - 0.005);
  }
}

ExplosiveMonster::~ExplosiveMonster(){}
