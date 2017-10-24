#include "../include/RedTower.h"

RedTower::RedTower(int posX_, int posY_, int level_):Tower(posX_,posY_),missile2(new Missile(posX,posY,posX,posY)){
  setColor(1.0f, 0.0f, 0.0f);
  label = "Red Tower";
  level = level_;
  price = 300;
  power = 2;
  ShootingDistance = 2;
  if (level > 1) {
    level = 0;
    for (int i = 0; i < level_; i++) {
      upgradeLevel();
    }
  }
}

void RedTower::shoot(std::vector<Monster * > *monsters){
  int i(-1);
  int k(0);
  float minDistance1(1000);
  float minDistance2(1000);
  if (monsters->size()!= 0) {
    for (int j = 0; j < monsters->size(); j++) {
      float distance = sqrt(((*monsters)[j]->getPosX() - posX)*((*monsters)[j]->getPosX() - posX)+((*monsters)[j]->getPosY() - posY)*((*monsters)[j]->getPosY() - posY)) ;
      if (distance < minDistance1) {
        minDistance1 = distance;
        i=j;
      }else if (distance < minDistance2) {
        minDistance2 = distance;
        k=j;
      }
    }
  }
  if (minDistance2 < ShootingDistance) {
    missile2->move((*monsters)[k]->getPosX(),(*monsters)[k]->getPosY());
    (*monsters)[k]->ReceiveDamage(power/2);
  } else {
    missile2->move(posX,posY);
    minDistance2 = 1000;
  }
  if (minDistance1 < ShootingDistance) {
    missile->move((*monsters)[i]->getPosX(),(*monsters)[i]->getPosY());
    (*monsters)[i]->ReceiveDamage(power/2);
    if (minDistance2 == 1000) {
      (*monsters)[i]->ReceiveDamage(power/2);
    }
  } else
  missile->move(posX,posY);
}

void RedTower::draw(bool sample){
  Tower::draw(sample);
  if (sample) {
    std::string label_s = "  - This tower can ";
    char *cstr = new char[label_s.length() + 1];
    strcpy(cstr, label_s.c_str());
    GraphicPrimitives::drawSmallText2D(cstr,posX  * 0.1f -0.6f + 0.05f,posY  * 0.1f -0.6f - 0.05f,0.0,0.0,0.0);
    delete [] cstr;
    std::string label_s1 = "shoot two monsters ";
    char *cstr1 = new char[label_s1.length() + 1];
    strcpy(cstr1, label_s1.c_str());
    GraphicPrimitives::drawSmallText2D(cstr1,posX  * 0.1f -0.6f + 0.05f,posY  * 0.1f -0.6f - 0.1f,0.0,0.0,0.0);
    delete [] cstr1;
    std::string label_s2 = "         at a time";
    char *cstr2 = new char[label_s2.length() + 1];
    strcpy(cstr2, label_s2.c_str());
    GraphicPrimitives::drawSmallText2D(cstr2,posX  * 0.1f -0.6f + 0.05f,posY  * 0.1f -0.6f - 0.15f,0.0,0.0,0.0);
    delete [] cstr2;
  }
  missile2->draw(r,g,b);
}

void RedTower::upgradeLevel(){
  Tower::upgradeLevel();
  setColor(r-0.15f,g,b);
}

RedTower::~RedTower()
{
}
