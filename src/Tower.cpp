#include "../include/Tower.h"

Tower::Tower(int posX_, int posY_):posX(posX_),posY(posY_),box(false),missile(new Missile(posX,posY,posX,posY)){}

void Tower::draw(bool sample){
  GraphicPrimitives::drawFillTower2D(posX * 0.1f -0.6f,posY * 0.1f -0.6f,1,r,g,b);
  if (!sample) {
    //GraphicPrimitives::drawOutlinedRect2D(posX  * 0.1f -0.6f + 0.012f,posY  * 0.1f -0.6f + 0.012f +0.075,0.07f,0.01f,r-0.1,g-0.1,b);
    GraphicPrimitives::drawFillRect2D(posX  * 0.1f -0.6f + 0.012f,posY  * 0.1f -0.6f + 0.012f + 0.075 ,0.07* (level)/10,0.01,0.8,0.2,0.1);
    //box
    if (box == true) {
      GraphicPrimitives::drawOutlinedRect2D(0.65f,-0.2,0.3f,0.42f,0,0,0);

      char *cstr2 = new char[label.length() + 1];
      strcpy(cstr2, label.c_str());
      GraphicPrimitives::drawSmallText2D(cstr2,0.65f + 0.08f,-0.2 + 0.35f,r,g,b);
      delete [] cstr2;

      std::string level_s = std::to_string(level);
      level_s = "Level : " + level_s;
      char *cstr3 = new char[level_s.length() + 1];
      strcpy(cstr3, level_s.c_str());
      GraphicPrimitives::drawSmallText2D(cstr3,0.65f + 0.02f,-0.2 + 0.3f,0.0,0.0,0.0);
      delete [] cstr3;

      std::string power_s = std::to_string(power);
      power_s = "Power : " + power_s;
      char *cstr4 = new char[power_s.length() + 1];
      strcpy(cstr4, power_s.c_str());
      GraphicPrimitives::drawSmallText2D(cstr4,0.65f + 0.02f,-0.2 + 0.25f,0.0,0.0,0.0);
      delete [] cstr4;

      std::string Shooting_s = std::to_string(ShootingDistance);
      Shooting_s = "Shooting Distance : " + Shooting_s;
      char *cstr5 = new char[Shooting_s.length() + 1];
      strcpy(cstr5, Shooting_s.c_str());
      GraphicPrimitives::drawSmallText2D(cstr5,0.65f + 0.02f,-0.2 + 0.2f,0.0,0.0,0.0);
      delete [] cstr5;

      std::string upgrade_s = std::to_string(price * 2);
      upgrade_s = "upgrade : " + upgrade_s + "$";
      char *cstr1 = new char[upgrade_s.length() + 1];
      strcpy(cstr1, upgrade_s.c_str());
      GraphicPrimitives::drawSmallText2D(cstr1,0.65f + 0.02f,-0.2 + 0.15f,0.0,0.0,0.0);
      delete [] cstr1;
    }
    missile->draw(r,g,b);
  }
  else{
    GraphicPrimitives::drawOutlinedRect2D(posX  * 0.1f -0.6f - 0.005f,posY  * 0.1f -0.6f - 0.275f,0.35f,0.37f,0.0,0.0,0.0);

    char *cstr3 = new char[label.length() + 1];
    strcpy(cstr3, label.c_str());
    GraphicPrimitives::drawSmallText2D(cstr3,posX  * 0.1f -0.6f + 0.012f + 0.1f, posY  * 0.1f -0.6f + 0.012f + 0.02, r, g, b);
    delete [] cstr3;

    std::string price_s = std::to_string(price);
    price_s = "Price : " + price_s + "$";
    char *cstr4 = new char[price_s.length() + 1];
    strcpy(cstr4, price_s.c_str());
    GraphicPrimitives::drawSmallText2D(cstr4,posX  * 0.1f -0.6f + 0.1f,posY  * 0.1f -0.6f - 0.23f,0.0,0.0,0.0);
    delete [] cstr4;
  }
}


int Tower::getPosX(){
  return posX;
}
int Tower::getPosY(){
  return posY;
}
float Tower::getPower(){
  return power;
}
int Tower::getLevel(){
  return level;
}
int Tower::getPrice(){
  return price;
}

bool Tower::getBox(){
  return box;
}
char Tower::getType(){
  if (label == "Blue Tower") {
    return 'B';
  } else if (label == "Green Tower") {
    return 'G';
  } else if (label == "Red Tower") {
    return 'R';
  }

}
void Tower::setPosX(int posX_){
  posX = posX_;
}
void Tower::setPosY(int posY_){
  posY = posY_;
}
void Tower::setPower(float power_){
  power = power_;
}
void Tower::upgradeLevel(){
  level++;
  power *= 1.5;
  ShootingDistance *= 1.2;
  upgradePrice();
}
void Tower::upgradePrice(){
  //price = static_cast<int>(price * (3/2));
  price *= 2;
}
void Tower::setBox(bool box_){
  box = box_;
}
void Tower::setColor(float r_, float g_, float b_){
  r = r_;
  g = g_;
  b = b_;
}

Tower::~Tower()
{
}
