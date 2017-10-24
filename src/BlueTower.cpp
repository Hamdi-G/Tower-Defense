#include "../include/BlueTower.h"

BlueTower::BlueTower(int posX_, int posY_, int level_):Tower(posX_,posY_){
  setColor(0.0f, 0.0f, 1.0f);
  label = "Blue Tower";
  level = level_;
  price = 100;
  power = 2;
  ShootingDistance = 2;
  if (level > 1) {
    level = 0;
    for (int i = 0; i < level_; i++) {
      upgradeLevel();
    }
  }
}

void BlueTower::shoot(std::vector<Monster * > *monsters){
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
  } else
  missile->move(posX,posY);



  /*  if (monsters->size()!= 0) {
  for (int j = 0; j < monsters->size(); j++) {
  float res = sqrt(((*monsters)[j]->getPosX() - posX)*((*monsters)[j]->getPosX() - posX)+((*monsters)[j]->getPosY() - posY)*((*monsters)[j]->getPosY() - posY)) ;
  if (res < ShootingDistance) {
  missile->move((*monsters)[j]->getPosX(),(*monsters)[j]->getPosY());
  (*monsters)[j]->ReceiveDamage(power);
}
}
}*/
}

void BlueTower::draw(bool sample){
  Tower::draw(sample);
  if (sample) {
    std::string label_s = "- This tower allows";
    char *cstr = new char[label_s.length() + 1];
    strcpy(cstr, label_s.c_str());
    GraphicPrimitives::drawSmallText2D(cstr,posX  * 0.1f -0.6f + 0.05f,posY  * 0.1f -0.6f - 0.05f,0.0,0.0,0.0);
    delete [] cstr;
    std::string label_s1 = "firing more frequent";
    char *cstr1 = new char[label_s1.length() + 1];
    strcpy(cstr1, label_s1.c_str());
    GraphicPrimitives::drawSmallText2D(cstr1,posX  * 0.1f -0.6f + 0.05f,posY  * 0.1f -0.6f - 0.1f,0.0,0.0,0.0);
    delete [] cstr1;
    std::string label_s2 = "  but less powerful.";
    char *cstr2 = new char[label_s2.length() + 1];
    strcpy(cstr2, label_s2.c_str());
    GraphicPrimitives::drawSmallText2D(cstr2,posX  * 0.1f -0.6f + 0.05f,posY  * 0.1f -0.6f - 0.15f,0.0,0.0,0.0);
    delete [] cstr2;
  }
}

void BlueTower::upgradeLevel(){
  Tower::upgradeLevel();
  setColor(r,g,b-0.15f);
}

BlueTower::~BlueTower()
{
}
