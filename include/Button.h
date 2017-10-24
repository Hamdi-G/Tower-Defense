#pragma once
#include <string>
#include "GraphicPrimitives.h"

class Button {
private:
  float posX,posY,width,height;
  std::string label;
  bool small;
public:
  Button(float posX_,float posY_,float width_,float height_,std::string label_,bool small = false);
  void draw();
  void hide();
  bool onClick(float x,float y);
  bool withLabel(std::string s);
  void erase();

};
