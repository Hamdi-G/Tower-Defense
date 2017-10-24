#include "../include/StrongMonster.h"

StrongMonster::StrongMonster(Map * map):Monster(map){
  setColor(0.0f, 0.5f, 0.5f);
  speed = 0.01f;
  coins = 60;
}
void StrongMonster::ReceiveDamage(float damage){
  life -= damage/2;
}
StrongMonster::~StrongMonster(){}
