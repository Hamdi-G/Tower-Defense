#include "../include/GreenTower.h"

GreenTower::GreenTower(int posX_, int posY_, int level_):Tower(posX_,posY_){
  setColor(0.0f, 0.9f, 0.0f);
  label = "Green Tower";
  level = level_;
  price = 200;
  power = 1;
  ShootingDistance = 2;
  if (level > 1) {
    level = 0;
    for (int i = 0; i < level_; i++) {
      upgradeLevel();
    }
  }
}

void GreenTower::shoot(std::vector<Monster * > *monsters){
  int i(0);
  float minDistance(1000);
  if (monsters->size()!= 0) {
    for (int j = 0; j < monsters->size(); j++) {
      float distance = sqrt(((*monsters)[j]->getPosX() - posX)*((*monsters)[j]->getPosX() - posX)+((*monsters)[j]->getPosY() - posY)*((*monsters)[j]->getPosY() - posY)) ;
      if (distance < minDistance) {
        minDistance = distance;
        i=j;
      }
    }
  }
  if (minDistance < ShootingDistance) {
    missile->move((*monsters)[i]->getPosX(),(*monsters)[i]->getPosY());
    (*monsters)[i]->ReceiveDamage(power);
    (*monsters)[i]->setSpeed((*monsters)[i]->getSpeed()-0.000008f);
  } else
  missile->move(posX,posY);
}

void GreenTower::draw(bool sample){
  Tower::draw(sample);
  if (sample) {
    std::string label_s = "   - This tower is ";
    char *cstr = new char[label_s.length() + 1];
    strcpy(cstr, label_s.c_str());
    GraphicPrimitives::drawSmallText2D(cstr,posX  * 0.1f -0.6f + 0.05f,posY  * 0.1f -0.6f - 0.05f,0.0,0.0,0.0);
    delete [] cstr;
    std::string label_s1 = "characterized by shots ";
    char *cstr1 = new char[label_s1.length() + 1];
    strcpy(cstr1, label_s1.c_str());
    GraphicPrimitives::drawSmallText2D(cstr1,posX  * 0.1f -0.6f + 0.05f,posY  * 0.1f -0.6f - 0.1f,0.0,0.0,0.0);
    delete [] cstr1;
    std::string label_s2 = "that slowdown monsters.";
    char *cstr2 = new char[label_s2.length() + 1];
    strcpy(cstr2, label_s2.c_str());
    GraphicPrimitives::drawSmallText2D(cstr2,posX  * 0.1f -0.6f + 0.035f,posY  * 0.1f -0.6f - 0.15f,0.0,0.0,0.0);
    delete [] cstr2;
  }
}

void GreenTower::upgradeLevel(){
  Tower::upgradeLevel();
  setColor(r,g-0.15f,b);
}

GreenTower::~GreenTower()
{
}
